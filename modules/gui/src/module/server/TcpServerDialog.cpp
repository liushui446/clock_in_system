#include "TcpServerDialog.h"
#include "ui_TcpServerDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>


//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

TcpServerDialog::TcpServerDialog(QWidget *parent)
    : ASQDialog(parent),
	m_ui(new Ui::TcpServerDialog)
{
	m_ui->setupUi(this);

    InitUI();
    InitConnect();
}

TcpServerDialog::~TcpServerDialog()
{
    m_server->close();
    m_server->deleteLater();
	delete m_ui;
}

void TcpServerDialog::InitUI()
{
    m_socket = nullptr;
    m_isGetPartData = false;
    m_requestDataSize = 0;
    m_server = new QTcpServer(this);
    //监听1122端口的ip
    m_server->listen(QHostAddress::Any, 1122);
}

void TcpServerDialog::InitConnect()
{
    //如果有用户连接触发槽函数
    connect(m_server, &QTcpServer::newConnection, this, &TcpServerDialog::hasConnect);
    
    connect(m_ui->toolButton_close, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
        {
            Q_UNUSED(checked);
            this->close();
        });
}

void TcpServerDialog::hasConnect()
{
    while (m_server->hasPendingConnections() > 0)//判断当前连接了多少人
    {
        //用socket和我们的客户端连接，一个客户端对应一个套接字socket
        m_socket = m_server->nextPendingConnection();
        //服务器界面上输出客户端信息
        m_ui->textEdit_show->append(QString::fromLocal8Bit("[%1:%2]:新用户连接").arg(m_socket->peerAddress().toString()).arg(m_socket->peerPort()));
        
        //如果客户端发送信息过来了，触发匿名函数
        if (m_socket)
        {
            connect(m_socket, &QTcpSocket::readyRead, [=]() {
                //QByteArray buf = m_socket->readAll();
                handleGetRecieveData();
                });
        }
    }
}

void TcpServerDialog::handleSendOutData(const sendStruct& data)
{
    if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
        return;
    QDataStream out(m_socket);
    out << data.size() << data;//先发送了数据大小，在发送数据
    m_socket->flush();
}

void TcpServerDialog::handleGetRecieveData()
{
    if ((!m_socket) || m_socket->state() != QAbstractSocket::ConnectedState)
        return;
    if (m_isGetPartData == false) {
        if (m_socket->bytesAvailable() < sizeof(int))//先要得到数据的大小
            return;
        else
        {
            QDataStream in(m_socket);
            in >> m_requestDataSize;//数据大小写入这个变量中
            m_isGetPartData = true;//只获得了数据的大小，数据内容还未获得
        }
    }
    if (m_isGetPartData == true) {
        if (m_socket->bytesAvailable() < m_requestDataSize)//判断是否数据接收完整了，不完整就返回等待下一次判断
            return;
        else
        {
            QDataStream in(m_socket);
            sendStruct receiveData;
            in >> receiveData;//接收到了发送端的数据
            m_requestDataSize = 0;//清空大小
            m_isGetPartData = false;//清空标志
            /*
            数据接收成功，放置在receiveData中，可以做其他处理
            doSomething(receiveData);
            */
            /*qDebug() << "receiveData type" << receiveData.Type;
            qDebug() << "receiveData Description" << receiveData.Description;
            qDebug() << "receiveData ByteData" << receiveData.ByteData;*/
            if (m_socket->bytesAvailable())//如果缓存区还存在数据，继续执行
                handleGetRecieveData();
        }
    }
}
