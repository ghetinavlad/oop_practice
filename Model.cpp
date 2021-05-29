#include "Model.h"

int Model::rowCount(const QModelIndex& parent) const
{

	return controller.getAllProducts().size() + 1;
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int line = index.row();
	int column = index.column();

	if (line == rowCount() - 1)
	{
		return QVariant();
	}

	Product product = this->controller.getAllProducts().at(line);
	int sliderValue = this->controller.getSliderValue();

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		if (column == 0)
		{
			return QString::fromStdString(std::to_string(product.getID()));
		}
		else if (column == 1)
		{
			return QString::fromStdString(product.getName());
		}

		else if (column == 2)
		{
			return QString::fromStdString(product.getType());
		}

		else if (column == 3)
		{
			return QString::fromStdString(std::to_string(product.getPrice()));
		}
		else if (column == 4)
		{
			return QString::fromStdString(std::to_string(product.getVowels()));
		}


	}
	if (role == Qt::BackgroundRole && product.getPrice() < sliderValue)
	{
		return QColor(255, 0, 0);
	}
	
	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section)
		{
		case 0:
			return QString::fromStdString("ID");
		case 1:
			return QString::fromStdString("Name");
		case 2:
			return QString::fromStdString("Type");
		case 3:
			return QString::fromStdString("Price");
		case 4:
			return QString::fromStdString("Vowels");
		default:
			break;
		}
	}

	return QVariant();
}

void Model::insert_row()
{
	beginInsertRows(QModelIndex(), this->controller.getAllProducts().size(), this->controller.getAllProducts().size());
	endInsertRows();
}