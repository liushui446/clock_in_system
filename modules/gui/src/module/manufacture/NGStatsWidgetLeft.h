#ifndef NGSTATSWIDGETLEFT_H
#define NGSTATSWIDGETLEFT_H

#include <QWidget>

namespace Ui {
class NGStatsWidgetLeft;
}

class NGStatsWidgetLeft : public QWidget
{
    Q_OBJECT

public:
    explicit NGStatsWidgetLeft(QWidget *parent = nullptr);
    ~NGStatsWidgetLeft();

private:
    Ui::NGStatsWidgetLeft *ui;
};

#endif // NGSTATSWIDGETLEFT_H
