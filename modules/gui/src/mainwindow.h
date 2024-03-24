#ifndef AS_MAINWINDOW_H
#define AS_MAINWINDOW_H

#include "HomePageDialog.h"
#include "TakeLeaveDialog.h"
#include "SubmitDialog.h"
#include "ApproveLeaveDialog.h"

//QT
#include <QLabel>
#include <QMutex>
#include <QMainWindow>
#include <QStackedWidget>
#include <QStringList>
#include <QLineEdit>
#include <QMenuBar>

#include "qtcpsocket.h"

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

    void SetSocket(QTcpSocket* socket);

    void HandinMess(string mess);

    void SetUserNa(string mess);

    void SetAuthority(string mess, UserType auth);

    void ShowUserNa();

    void handleSendOutData(const sendStruct& data);

    void handleGetRecieveData();

    Ui::MainWindow* m_ui;
private:
    HomePageDialog* m_cHomePageDialog;
    TakeLeaveDialog* m_cTakeLeaveDialog;
    ApproveLeaveDialog* m_cApproveLeaveDialog;
    SubmitDialog* m_cSubmitDialog;


    DialogType m_CurDialogType;
    QMenuBar* menuBar;
    QMenu* fileMenu;

    QTcpSocket* m_socket;

    string m_curusername;
    UserType m_curauthority;

    bool m_isGetPartData;
    int m_requestDataSize;
};

#endif