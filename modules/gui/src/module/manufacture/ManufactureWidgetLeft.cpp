#include "ManufactureWidgetLeft.h"
#include "ui_ManufactureWidgetLeft.h"

ManufactureWidgetLeft::ManufactureWidgetLeft(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManufactureWidgetLeft)
{
    ui->setupUi(this);
}

ManufactureWidgetLeft::~ManufactureWidgetLeft()
{
    delete ui;
}
