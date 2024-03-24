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
#include "src/utils/include/AutoLoadQss.h"

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

//QDataStream& operator<<(QDataStream& out, const as::UserLeaveMessageData& s)
//{
//	out << QString::fromLocal8Bit(s.m_username.c_str())
//		<< s.m_type
//		<< QString::fromLocal8Bit(s.m_datetime.c_str())
//		<< QString::fromLocal8Bit(s.m_reason.c_str())
//		<< (int)s.m_status
//		<< QString::fromLocal8Bit(s.m_adress.c_str());
//	return out;
//}
//
//QDataStream& operator>>(QDataStream& in, as::UserLeaveMessageData& s) {
//
//	QString data_1;
//	QString data_2;
//	QString data_3;
//	int data_4;
//	QString data_5;
//
//	in >> data_1
//		>> s.m_type
//		>> data_2
//		>> data_3
//		>> data_4
//		>> data_5;
//	s.m_username = data_1.toStdString();
//	s.m_datetime = data_2.toStdString();
//	s.m_reason = data_3.toStdString();
//	s.m_status = static_cast<as::leaveStatus>(data_4);
//	s.m_adress = data_5.toStdString();
//	return in;
//}

void MainWindow::iniUI()
{
	m_isGetPartData = false;
	m_requestDataSize = 0;
	auto qssLoader = new as::AutoLoadQss(this);
	qssLoader->bindAppAndQss(this, "res/SpiStyleSheet.qss");

	m_CurDialogType = DialogType::Home_Page;
	m_cHomePageDialog = new HomePageDialog(this);
	//���
	m_ui->verticalLayout_2->insertWidget(0, m_cHomePageDialog);

	m_ui->toolButton_page_3->setEnabled(false);

	m_socket = NULL;
}

void MainWindow::iniConnect()
{
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
			case DialogType::Authority:
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
			case DialogType::Authority:
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
			case DialogType::Authority:
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
			m_CurDialogType = DialogType::Authority;

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
	if (m_socket)
	{
		connect(m_socket, &QTcpSocket::readyRead, this, &MainWindow::handleGetRecieveData);
	}
	UserLeaveMessageData tem_data;
	string des = "sign in success";
	tem_data.m_username = m_curusername;
	handleSendOutData(tem_data, des);
	//QByteArray data = QString::fromLocal8Bit("sign in success").toUtf8();
	//m_socket->write(data);
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

void MainWindow::handleSendOutData(UserLeaveMessageData& data, string des)
{
	QByteArray byteData;
	QDataStream stream(&byteData, QIODevice::WriteOnly);
	data.m_username = m_curusername;
	stream << data;
	sendStruct senddata;
	if (m_curauthority == UserType::Student)
		senddata.Type = 0;
	else
		senddata.Type = 1;
	senddata.Description = QString::fromLocal8Bit(des.c_str());
	senddata.ByteData = byteData;

	if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
		return;

	QDataStream out(m_socket);
	out << senddata.size() << senddata;//�ȷ������ݴ�С���ڷ������ݱ���
	m_socket->flush();
}

void MainWindow::handleSendOutData()
{
	QByteArray byteData;
	QDataStream stream(&byteData, QIODevice::WriteOnly);
	vector<UserLeaveMessage> mess_list = ASContext::GetInstance().GetUserManagedata()->GetLeavemess();
	if (mess_list.size() == 0)
	{
		return;
	}
	//����ת��
	vector<UserLeaveMessageData> tmp_data;
	for (auto& data1 : mess_list)
	{
		UserLeaveMessageData data_;
		MessToData(data1, data_);
		tmp_data.push_back(data_);
	}
	for (auto& data1 : tmp_data)
	{
		stream << data1;
	}
	sendStruct senddata;
	if (m_curauthority == UserType::Student)
		senddata.Type = 0;
	else
		senddata.Type = 1;
	senddata.Description = QString("this is approval");
	senddata.ByteData = byteData;

	if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
		return;

	QDataStream out(m_socket);
	out << senddata.size() << senddata;//�ȷ������ݴ�С���ڷ������ݱ���
	m_socket->flush();
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
			
			//���ݽ��ճɹ���������receiveData�У���������������
			//doSomething(receiveData);
			if (receiveData.Type == 0)
			{

			}
			else
			{
				QDataStream mess(receiveData.ByteData);
				UserLeaveMessageData temp_usermess;
				mess >> temp_usermess;
				vector<UserLeaveMessage> datalist;
				UserLeaveMessage tmp_mess;
				DataToMess(temp_usermess, tmp_mess);
				datalist.push_back(tmp_mess);
				//���浱ǰ����
				ASContext::GetInstance().GetUserManagedata()->InsertLeavemess(datalist);

				//����
				if (m_CurDialogType == DialogType::Take_Leave && m_curauthority == UserType::Teacher)
				{
					m_cApproveLeaveDialog->RefLeaveDataListview();
				}
				else if(m_cHomePageDialog != nullptr){

				}
			}
			
			if (m_socket->bytesAvailable())//������������������ݣ��ݹ�ִ��
				handleGetRecieveData();
		}
	}
}

//����ת��
void MainWindow::DataToMess(UserLeaveMessageData data, UserLeaveMessage& mess)
{
	mess.m_username = data.m_username;
	mess.m_type = data.m_type;
	mess.m_datetime = data.m_datetime;
	mess.m_reason = data.m_reason;
	mess.m_status = data.m_status;
	mess.m_adress = data.m_adress;
}

//����ת��
void MainWindow::MessToData(UserLeaveMessage data, UserLeaveMessageData& mess)
{
	mess.m_username = data.m_username;
	mess.m_type = data.m_type;
	mess.m_datetime = data.m_datetime;
	mess.m_reason = data.m_reason;
	mess.m_status = data.m_status;
	mess.m_adress = data.m_adress;
}

