#ifndef AS_MAINWINDOW_H
#define AS_MAINWINDOW_H

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
namespace items
{
    class VisGraphicsScene;
    class VisGraphicsView;
    class ThumbnailGraphicsScene;
    class ThumbnailGraphicsView;
}
// Qt
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

    Ui::MainWindow* m_ui;
private:

};

#endif