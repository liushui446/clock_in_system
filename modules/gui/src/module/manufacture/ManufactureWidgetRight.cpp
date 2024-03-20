#include "ManufactureWidgetRight.h"
#include "ui_ManufactureWidgetRight.h"

ManufactureWidgetRight::ManufactureWidgetRight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManufactureWidgetRight)
{
    ui->setupUi(this);
}

ManufactureWidgetRight::~ManufactureWidgetRight()
{
    delete ui;
}
