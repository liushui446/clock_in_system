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

//����
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
	//���
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
			// �Ӳ������Ƴ�����
			QLayoutItem* item = m_ui->verticalLayout_2->itemAt(0); // ��ȡ��һ������Ĵ���
			if (item) {
				QWidget* widgetToRemove = item->widget();
				if (widgetToRemove) {
					m_ui->verticalLayout_2->removeWidget(widgetToRemove);
					delete widgetToRemove; // ɾ�����ڶ���
				}
			}
			m_CurDialogType = DialogType::Home_Page;
			m_cHomePageDialog = new HomePageDialog(this);
			//���
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
			// �Ӳ������Ƴ�����
			QLayoutItem* item = m_ui->verticalLayout_2->itemAt(0); // ��ȡ��һ������Ĵ���
			if (item) {
				QWidget* widgetToRemove = item->widget();
				if (widgetToRemove) {
					m_ui->verticalLayout_2->removeWidget(widgetToRemove);
					delete widgetToRemove; // ɾ�����ڶ���
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
			// �Ӳ������Ƴ�����
			QLayoutItem* item = m_ui->verticalLayout_2->itemAt(0); // ��ȡ��һ������Ĵ���
			if (item) {
				QWidget* widgetToRemove = item->widget();
				if (widgetToRemove) {
					m_ui->verticalLayout_2->removeWidget(widgetToRemove);
					delete widgetToRemove; // ɾ�����ڶ���
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
	string temp = "���,";
	m_ui->label_user->setText(QString::fromLocal8Bit((temp + m_curusername).c_str()));

	if (m_curauthority == UserType::Student)
	{
		m_ui->toolButton_page_2->setText(QString::fromLocal8Bit("���"));
	}
	else
	{
		m_ui->toolButton_page_2->setText(QString::fromLocal8Bit("����"));
	}
}

void MainWindow::handleSendOutData(const sendStruct& data)
{
	if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
		return;
	QDataStream out(m_socket);
	out << data.size() << data;//�ȷ������ݴ�С���ڷ������ݱ���
	m_socket->flush();
	/*����Ҫ���͵����ݷ�װ�ڽṹ�����淢��*/
}

void MainWindow::handleGetRecieveData()
{
	if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
		return;
	if (m_isGetPartData == false) {
		if (m_socket->bytesAvailable() < sizeof(int))//�Ƚ������ݵĴ�С
			return;
		else
		{
			QDataStream in(m_socket);
			in >> m_requestDataSize;//���ݴ�Сд�����
			m_isGetPartData = true;//���ñ�־��ֻ���յ������ݴ�С��û���յ�����ȫ��
		}
	}
	if (m_isGetPartData == true) {
		if (m_socket->bytesAvailable() < m_requestDataSize)//�ж��Ƿ���յ�������������
			return;
		else
		{
			QDataStream in(m_socket);
			sendStruct receiveData;
			in >> receiveData;//���յ�������
			m_requestDataSize = 0;//��մ�С
			m_isGetPartData = false;//��ձ�־
			/*
			���ݽ��ճɹ���������receiveData�У���������������
			doSomething(receiveData);
			*/
			
			if (m_socket->bytesAvailable())//������������������ݣ��ݹ�ִ��
				handleGetRecieveData();
		}
	}
}



