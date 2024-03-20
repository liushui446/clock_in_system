#include "NGStatsWidgetRight.h"
#include "ui_NGStatsWidgetRight.h"

NGStatsWidgetRight::NGStatsWidgetRight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NGStatsWidgetRight)
{
    ui->setupUi(this);
}

NGStatsWidgetRight::~NGStatsWidgetRight()
{
    delete ui;
}
