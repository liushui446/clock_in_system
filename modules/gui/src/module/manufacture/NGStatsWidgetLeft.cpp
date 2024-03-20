#include "NGStatsWidgetLeft.h"
#include "ui_NGStatsWidgetLeft.h"

NGStatsWidgetLeft::NGStatsWidgetLeft(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NGStatsWidgetLeft)
{
    ui->setupUi(this);
}

NGStatsWidgetLeft::~NGStatsWidgetLeft()
{
    delete ui;
}
