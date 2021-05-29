#include "GUI.h"
#include <QtWidgets/QApplication>
#include "controller.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller actionController;
    actionController.loadProductsFromFile();
    Model* idea_model = new Model(actionController);
    std::vector<GUI*> windows;
    int i = 0;
    for (auto product : actionController.getAllProducts())
    {
        GUI* gui = new GUI(idea_model, actionController, product);
        windows.push_back(gui);
        //service.add(gui);
        windows[i]->show();
        i++;

    }
    return a.exec();
}
