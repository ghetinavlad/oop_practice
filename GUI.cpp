#include "GUI.h"
#include <qmessagebox.h>
#include <qboxlayout.h>

GUI::GUI(Model* idea_model, Controller& controller, Product product, QWidget* parent)
    : controller{ controller }, product{ product }, idea_model{ idea_model }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(product.getType()));
	this->ui.typeCounterLabel->setText(QString::fromStdString(to_string(this->controller.getTypeCounter(product.getType()))));
	this->connectSignals();
    this->ui.tableView->setModel(idea_model);
    ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void GUI::update()
{
}

void GUI::connectSignals()
{
	QObject::connect(this->ui.pushButton, &QPushButton::clicked, this, &GUI::add_product);
	QObject::connect(this->ui.priceSlider, &QSlider::valueChanged, this, &GUI::filter_products);

}

void GUI::add_product() //takes what it needs from the window and calls Service::add_star() if no exceptions are thrown
{


	try
	{
		int id = std::stoi(this->ui.id_line_edit->text().toStdString());
		std::string name = this->ui.name_line_edit->text().toStdString();
		std::string type = this->ui.type_line_edit->text().toStdString();
		double price = std::stod(this->ui.price_line_edit->text().toStdString());
		
		try {
			this->controller.addProduct(id, name, type, price);
			this->ui.typeCounterLabel->setText(QString::fromStdString(to_string(this->controller.getTypeCounter(product.getType()))));
		}
		catch (const std::exception& exception)
		{
			QMessageBox::critical(this, "Error", "Invalid Input!");

		}
		this->idea_model->insert_row();
		emit this->idea_model->dataChanged(this->idea_model->index(0, 0), this->idea_model->index(this->controller.getAllProducts().size() + 1, 4));
	}
	catch (const std::exception& exception)
	{
		QMessageBox::critical(this, "Error", "Invalid Input!");

	}

}

void GUI::filter_products()
{
	this->controller.setSliderValue(this->ui.priceSlider->value());
	this->ui.sliderLabel->setText(QString::fromStdString(to_string(this->controller.getSliderValue())));

}