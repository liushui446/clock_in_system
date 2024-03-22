#ifndef AS_MAINWINDOW_H
#define AS_MAINWINDOW_H

#include "HomePageDialog.h"
#include "TakeLeaveDialog.h"
#include "SubmitDialog.h"

//QT
#include <QLabel>
#include <QMutex>
#include <QMainWindow>
#include <QStackedWidget>
#include <QStringList>
#include <QLineEdit>
#include <QMenuBar>

namespace Ui {
    class MainWindow;
}

// Qt
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

    void iniUI();
    void iniConnect();

    Ui::MainWindow* m_ui;
private:
    HomePageDialog* m_cHomePageDialog;
    TakeLeaveDialog* m_cTakeLeaveDialog;
    SubmitDialog* m_cSubmitDialog;


    DialogType m_CurDialogType;
    QMenuBar* menuBar;
    QMenu* fileMenu;
};

#endif