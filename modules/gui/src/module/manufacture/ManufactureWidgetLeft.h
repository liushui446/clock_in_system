#ifndef MANUFACTUREWIDGETLEFT_H
#define MANUFACTUREWIDGETLEFT_H

#include <QWidget>

namespace Ui {
class ManufactureWidgetLeft;
}

class ManufactureWidgetLeft : public QWidget
{
    Q_OBJECT

public:
    explicit ManufactureWidgetLeft(QWidget *parent = nullptr);
    ~ManufactureWidgetLeft();

private:
    Ui::ManufactureWidgetLeft *ui;
};

#endif // MANUFACTUREWIDGETLEFT_H
