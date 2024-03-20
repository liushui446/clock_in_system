#ifndef MANUFACTUREDIALOG_H
#define MANUFACTUREDIALOG_H

#include <QMainWindow>

namespace Ui {
class ManufactureDialog;
}

class ManufactureDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManufactureDialog(QWidget *parent = nullptr);
    ~ManufactureDialog();

private:
    Ui::ManufactureDialog *ui;
};

#endif // MANUFACTUREDIALOG_H
