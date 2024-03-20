#include "mainwindow.h"
#include "ui_mainwindow.h"

// 3rdpart
//#include "items/VisGraphicsScene.h"
//#include "items/VisGraphicsView.h"

// Qt
#include <QTimer>
#include <QMenuBar>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QToolBar>
#include <QWheelEvent>
#include <QtMath>
#include <QGraphicsSceneMouseEvent>
#include <QHeaderView>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QDesktopWidget>
#include <QPolygonF>
#include <QStatusBar>
#include <QApplication>
#include <QTableWidgetItem>

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

//ÆäËû
//#include "aoi/CommonProcess.h"

//using namespace items;
using namespace cv;

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	delete m_ui;
}
