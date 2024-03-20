#ifndef NGSTATSWIDGETRIGHT_H
#define NGSTATSWIDGETRIGHT_H

#include <QWidget>

namespace Ui {
class NGStatsWidgetRight;
}

class NGStatsWidgetRight : public QWidget
{
    Q_OBJECT

public:
    explicit NGStatsWidgetRight(QWidget *parent = nullptr);
    ~NGStatsWidgetRight();

private:
    Ui::NGStatsWidgetRight *ui;
};

#endif // NGSTATSWIDGETRIGHT_H
