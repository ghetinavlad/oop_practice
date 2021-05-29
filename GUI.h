#pragma once
#include "Controller.h"
#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "Model.h"

class GUI : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    GUI(Model* idea_model, Controller& controller, Product product, QWidget* parent = Q_NULLPTR);
    void update() override;

private:
    Ui::GUIClass ui;
    Controller& controller;
    Product product;
    Model* idea_model;
    void connectSignals();
public slots:
    void add_product();
    void filter_products();
   
};
