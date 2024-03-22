#include "mainwindow.h"
#include "ui_mainwindow.h"

// 3rdpart


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

//其他
//#include "as/CommonProcess.h"

//using namespace items;
using namespace cv;

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	m_ui(new Ui::MainWindow)
{
	m_ui->setupUi(this);

	iniUI();
	iniConnect();
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::iniUI()
{
	m_CurDialogType = DialogType::Home_Page;
	m_cHomePageDialog = new HomePageDialog(this);
	//添加
	m_ui->verticalLayout_2->insertWidget(0, m_cHomePageDialog);

	//// 创建
	//menuBar = new QMenuBar(this);
	////menuBar->set(m_ui->centralwidget->geometry().width(), m_ui->centralwidget->geometry().height());
	//fileMenu = menuBar->addMenu("#");
	//fileMenu->addAction(QString::fromLocal8Bit("注销"));
	//fileMenu->addAction(QString::fromLocal8Bit("退出"));
	//m_ui->verticalLayout_3->setMenuBar(menuBar);
}

void MainWindow::iniConnect()
{
	connect(m_ui->toolButton_page_1, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
		{
			Q_UNUSED(checked);
			switch (m_CurDialogType)
			{
			case DialogType::Home_Page:
				return;
				break;
			case DialogType::Take_Leave:
				m_cTakeLeaveDialog = nullptr;
				delete m_cTakeLeaveDialog;
				break;
			case DialogType::Submit:
				//m_cSubmitDialog = nullptr;
				//delete m_cSubmitDialog;
				break;
			default:
				break;
			}
			// 从布局中移除窗口
			QLayoutItem* item = m_ui->verticalLayout_2->itemAt(0); // 获取第一个插入的窗口
			if (item) {
				QWidget* widgetToRemove = item->widget();
				if (widgetToRemove) {
					m_ui->verticalLayout_2->removeWidget(widgetToRemove);
					delete widgetToRemove; // 删除窗口对象
				}
			}
			m_CurDialogType = DialogType::Home_Page;
			m_cHomePageDialog = new HomePageDialog(this);
			//添加
			m_ui->verticalLayout_2->insertWidget(0, m_cHomePageDialog);
			
		});

	connect(m_ui->toolButton_page_2, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
		{
			Q_UNUSED(checked);
			
			switch (m_CurDialogType)
			{
			case DialogType::Home_Page:
				m_cHomePageDialog = nullptr;
				delete m_cHomePageDialog;
				break;
			case DialogType::Take_Leave:
				return;
				break;
			case DialogType::Submit:
				//m_cSubmitDialog = nullptr;
				//delete m_cSubmitDialog;
				break;
			default:
				break;
			}
			// 从布局中移除窗口
			QLayoutItem* item = m_ui->verticalLayout_2->itemAt(0); // 获取第一个插入的窗口
			if (item) {
				QWidget* widgetToRemove = item->widget();
				if (widgetToRemove) {
					m_ui->verticalLayout_2->removeWidget(widgetToRemove);
					delete widgetToRemove; // 删除窗口对象
				}
			}
			m_CurDialogType = DialogType::Take_Leave;
			m_cTakeLeaveDialog = new TakeLeaveDialog(this);
			//添加
			m_ui->verticalLayout_2->insertWidget(0, m_cTakeLeaveDialog);
		});

	connect(m_ui->toolButton_page_3, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
		{
			Q_UNUSED(checked);
			switch (m_CurDialogType)
			{
			case DialogType::Home_Page:
				m_cHomePageDialog = nullptr;
				delete m_cHomePageDialog;
				break;
			case DialogType::Take_Leave:
				m_cTakeLeaveDialog = nullptr;
				delete m_cTakeLeaveDialog;
				break;
			case DialogType::Submit:
				return;
				break;
			default:
				break;
			}
			// 从布局中移除窗口
			QLayoutItem* item = m_ui->verticalLayout_2->itemAt(0); // 获取第一个插入的窗口
			if (item) {
				QWidget* widgetToRemove = item->widget();
				if (widgetToRemove) {
					m_ui->verticalLayout_2->removeWidget(widgetToRemove);
					delete widgetToRemove; // 删除窗口对象
				}
			}
			m_CurDialogType = DialogType::Submit;

		});

	connect(m_ui->comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, [this](int index)
		{
			if (index == 1)
			{
				this->close();
			}
		});

	//// 连接信号和槽
	//connect(fileMenu, &QMenu::triggered, this, [this](QAction* action) {
	//	if (action->text() == QString::fromLocal8Bit("注销")) {
	//		// 处理注销操作

	//	}
	//	else if (action->text() == QString::fromLocal8Bit("退出")) {
	//		// 处理退出操作
	//		this->close();
	//	}
	//	});

	
}
