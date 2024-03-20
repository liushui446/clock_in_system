#ifndef MANUFACTUREWIDGETRIGHT_H
#define MANUFACTUREWIDGETRIGHT_H

#include <QWidget>

namespace Ui {
class ManufactureWidgetRight;
}

class ManufactureWidgetRight : public QWidget
{
    Q_OBJECT

public:
    explicit ManufactureWidgetRight(QWidget *parent = nullptr);
    ~ManufactureWidgetRight();

private:
    Ui::ManufactureWidgetRight *ui;
};

#endif // MANUFACTUREWIDGETRIGHT_H
