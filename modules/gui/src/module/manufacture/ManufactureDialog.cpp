#include "ManufactureDialog.h"
#include "ui_ManufactureDialog.h"

ManufactureDialog::ManufactureDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManufactureDialog)
{
    ui->setupUi(this);
}

ManufactureDialog::~ManufactureDialog()
{
    delete ui;
}
