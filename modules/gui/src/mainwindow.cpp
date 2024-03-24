#include "mainwindow.h"
#include "ui_mainwindow.h"

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


}

void MainWindow::iniConnect()
{
	connect(m_socket, &QTcpSocket::readyRead, this, &MainWindow::handleGetRecieveData);
	//connect(m_socket, &QTcpSocket::disconnected, this, &MainWindow::handleSocketConnected);

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
			if (m_curauthority == UserType::Student)
			{
				m_cTakeLeaveDialog = new TakeLeaveDialog(this);
				m_ui->verticalLayout_2->insertWidget(0, m_cTakeLeaveDialog);
			}
			else
			{
				m_cApproveLeaveDialog = new ApproveLeaveDialog(this);
				m_ui->verticalLayout_2->insertWidget(0, m_cApproveLeaveDialog);
			}
			
			
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
				if (m_curauthority == UserType::Student)
				{
					m_cTakeLeaveDialog = nullptr;
					delete m_cTakeLeaveDialog;
				}
				else
				{
					m_cApproveLeaveDialog = nullptr;
					delete m_cApproveLeaveDialog;
				}
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
				m_socket->disconnectFromHost();
				this->close();
			}
		});
	
}

void MainWindow::SetSocket(QTcpSocket* socket)
{
	m_socket = socket;
	QByteArray data = QString::fromLocal8Bit("sign in success").toUtf8();
	m_socket->write(data);
}

void MainWindow::HandinMess(string mess)
{
	QByteArray data = QString::fromLocal8Bit(mess.c_str()).toUtf8();
	m_socket->write(data);
}

void MainWindow::SetUserNa(string mess)
{
	m_curusername = mess;
}

void MainWindow::SetAuthority(string mess, UserType auth)
{
	m_curusername = mess;
	m_curauthority = auth;
}

void MainWindow::ShowUserNa()
{
	string temp = "你好,";
	m_ui->label_user->setText(QString::fromLocal8Bit((temp + m_curusername).c_str()));

	if (m_curauthority == UserType::Student)
	{
		m_ui->toolButton_page_2->setText(QString::fromLocal8Bit("请假"));
	}
	else
	{
		m_ui->toolButton_page_2->setText(QString::fromLocal8Bit("审批"));
	}
}

void MainWindow::handleSendOutData(const sendStruct& data)
{
	if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
		return;
	QDataStream out(m_socket);
	out << data.size() << data;//先发送数据大小，在发送数据本身
	m_socket->flush();
	/*把需要发送的数据封装在结构体里面发送*/
}

void MainWindow::handleGetRecieveData()
{
	if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
		return;
	if (m_isGetPartData == false) {
		if (m_socket->bytesAvailable() < sizeof(int))//先接收数据的大小
			return;
		else
		{
			QDataStream in(m_socket);
			in >> m_requestDataSize;//数据大小写入变量
			m_isGetPartData = true;//设置标志，只接收到了数据大小，没接收到数据全部
		}
	}
	if (m_isGetPartData == true) {
		if (m_socket->bytesAvailable() < m_requestDataSize)//判断是否接收到了完整的数据
			return;
		else
		{
			QDataStream in(m_socket);
			sendStruct receiveData;
			in >> receiveData;//接收到了数据
			m_requestDataSize = 0;//清空大小
			m_isGetPartData = false;//清空标志
			/*
			数据接收成功，放置在receiveData中，可以做其他处理
			doSomething(receiveData);
			*/
			
			if (m_socket->bytesAvailable())//如果缓存区还存在数据，递归执行
				handleGetRecieveData();
		}
	}
}



