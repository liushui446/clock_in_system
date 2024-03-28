#include "LoadDialog.h"
#include "ui_LoadDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>
#include <common/CustomDataStreamOperators.h>
#include <QNetworkInterface>

#include <io.h>
#include <fcntl.h>

#pragma comment(lib, "ws2_32.lib")


char* GetIp(char* szhostname)
{
    char* szip = NULL;
    char* ipbit = NULL;
    hostent* ipstr = NULL;

    szip = new char[30];
    if (!szip)
        goto Err;
    ZeroMemory(szip, 30);
    ipstr = gethostbyname(szhostname);
    if (ipstr == NULL)
        goto Err;
    ipbit = inet_ntoa(*(in_addr*)ipstr->h_addr);
    if (ipbit == NULL)
        goto Err;
    memcpy(szip, ipbit, strlen(ipbit));

    return szip;
Err:
    return NULL;
}

//连接HTTP服务器（OK,Connected）
SOCKET ConnectHttpServer(char* szip)
{
    SOCKET szclient_socket = 0;

    szclient_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == szclient_socket)
        goto Err;
    //连接服务器
    SOCKADDR_IN info;
    info.sin_port = htons(80);
    info.sin_family = AF_INET;
    info.sin_addr.S_un.S_addr = inet_addr(szip);
    if (0 != connect(szclient_socket, (SOCKADDR*)&info, sizeof(SOCKADDR)))
        goto Err;

    //返回
    return szclient_socket;
Err:
    if (szclient_socket != NULL && szclient_socket != INVALID_SOCKET)
    {
        closesocket(szclient_socket);
        szclient_socket = 0;
    }
    return 0;
}

//设置套接字缓冲区大小（OK）
bool SetSocketInfo(SOCKET szsocket, int uBufferSize)
{
    if (SOCKET_ERROR == setsockopt(szsocket, SOL_SOCKET, SO_RCVBUF, (char*)&uBufferSize, sizeof(int)))
        goto Err;
    if (SOCKET_ERROR == setsockopt(szsocket, SOL_SOCKET, SO_SNDBUF, (char*)&uBufferSize, sizeof(int)))
        goto Err;
    return TRUE;
Err:
    return FALSE;
}


//UTF8转ANSI字符串(OK,New)
char* Utf8ToAnsi(char* utf8, int len, char szcc)
{
    BOOL szok = FALSE;
    int szlen = 0;
    char* szretstr = NULL;
    wchar_t* whar_str = NULL;
    //UTF8转UNICODE
    szlen = MultiByteToWideChar(CP_UTF8, 0, utf8, len, NULL, 0);
    if (szlen <= 0)
        goto Err;
    szlen += 1;
    whar_str = new wchar_t[szlen];
    if (!whar_str)
        goto Err;
    ZeroMemory(whar_str, szlen * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, utf8, len, whar_str, szlen);
    if (GetLastError() != 0)
        goto Err;
    //UNICODE转ANSI
    szlen = WideCharToMultiByte(CP_ACP, 0, whar_str, len, NULL, 0, &szcc, &szok);
    if (szlen <= 0)
        goto Err;
    szlen += 1;
    szretstr = new char[szlen];
    if (!szretstr)
        goto Err;
    ZeroMemory(szretstr, szlen * sizeof(char));
    WideCharToMultiByte(CP_ACP, 0, whar_str, len, szretstr, szlen, &szcc, &szok);
    if (GetLastError() != 0)
        goto Err;
    if (whar_str)
    {
        delete[] whar_str;
        whar_str = NULL;
    }
    return szretstr;
Err:
    if (whar_str)
    {
        delete[]whar_str;
        whar_str = NULL;
    }
    return NULL;
}

char* StrStrA(char* str1, char* str2)
{
    if (str1 == "" || str2 == "")
        return nullptr;
    int size = strlen(str1);

    for (int i = 0; i < size; i++, str1++)
    {
        char* p = str1;

        for (char* q = str2; ; q++, p++)
        {

            if (*q == '\0') return str1;
            if (*q != *p) break;
        }
    }
    return nullptr;
}

//获取物理地址(OK,ip.chinaz.com,New)
char* GetPoint(char* ip_address, char* get_ip_de_host_name)
{
    int szlen = 0;
    char* szPoint = NULL;
    char* szTemp = NULL;
    char* szTemp2 = NULL;
    char* szTemp3 = NULL;
    char* get_host_name_ip = NULL;
    SOCKET http_client_socket = NULL;
    char packet[400] = "GET /";
    strcat(packet, "?IP=");
    strcat(packet, ip_address);
    strcat(packet, " HTTP/1.1\r\n" \
        "Host: "
    );
    strcat(packet, get_ip_de_host_name);
    strcat(packet, "\r\n"
        "Connection: keep-alive\r\n"
        "Cache-Control: max-age=0\r\n"
        "Upgrade-Insecure-Requests: 1\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
        "Accept-Language: zh-CN,zh;q=0.8\r\n\r\n"
    );


    char* recv_buffer = NULL;
    //代码开始
    recv_buffer = new char[50000];
    if (!recv_buffer)
        goto Err;
    ZeroMemory(recv_buffer, 50000);
    //返回解析物理地址的主机的IP地址
    get_host_name_ip = GetIp(get_ip_de_host_name);
    //get_host_name_ip = get_ip_de_host_name;
    if (get_host_name_ip == NULL)
        goto Err;

    //连接服务器
    http_client_socket = ConnectHttpServer(get_host_name_ip);
    if (http_client_socket == 0)
        goto Err;

    //设置缓冲区大小
    if (!SetSocketInfo(http_client_socket, 30000))
        goto Err;
    if (send(http_client_socket, packet, strlen(packet), 0) <= 0)
        goto Err;
    if (recv(http_client_socket, recv_buffer, 50000, 0) <= 0)
        goto Err;
    szTemp3 = Utf8ToAnsi(recv_buffer, -1, '.');
    if (szTemp3 == NULL)
        goto Err;
    szTemp = StrStrA(szTemp3, "IP的物理位置");
    if (szTemp == NULL)
        goto Err;
    szTemp = StrStrA(szTemp, "w50");
    if (szTemp == NULL)
        goto Err;
    szTemp += strlen("w50-0\">"); //???
    if (szTemp == NULL)
        goto Err;
    szTemp2 = strchr(szTemp, '<');
    if (szTemp2 == NULL)
        goto Err;
    szlen = szTemp2 - szTemp;
    if (szlen <= 0)
        goto Err;
    szlen += 1;
    szPoint = new char[szlen];
    if (!szPoint)
        goto Err;
    ZeroMemory(szPoint, szlen);
    memcpy(szPoint, szTemp, szlen - 1);

    if (get_host_name_ip)
    {
        delete[]get_host_name_ip;
        get_host_name_ip = NULL;
    }
    if (http_client_socket)
    {
        closesocket(http_client_socket);
        http_client_socket = 0;
    }
    if (recv_buffer)
    {
        delete[]recv_buffer;
        recv_buffer = NULL;
    }
    if (szTemp3)
    {
        delete[]szTemp3;
        szTemp3 = NULL;
    }
    return szPoint;
Err:
    if (get_host_name_ip)
    {
        delete[]get_host_name_ip;
        get_host_name_ip = NULL;
    }
    if (http_client_socket)
    {
        closesocket(http_client_socket);
        http_client_socket = 0;
    }
    if (recv_buffer)
    {
        delete[]recv_buffer;
        recv_buffer = NULL;
    }
    if (szTemp3)
    {
        delete[]szTemp3;
        szTemp3 = NULL;
    }
    return NULL;
}

int ggetadress()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    SOCKET ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET) {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    struct hostent* host;
    host = gethostbyname("ip.chinaz.com");
    if (host == NULL) {
        std::cerr << "gethostbyname failed" << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN SockAddr;
    SockAddr.sin_port = htons(80);
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    if (connect(ConnectSocket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect" << std::endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    const char* request = "GET /?IP=156.59.17.7 HTTP/1.1\r\n"
        "Host: ip.chinaz.com\r\n"
        "Connection: keep-alive\r\n"
        "Upgrade-Insecure-Requests: 1\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
        "Accept-Language: zh-CN,zh;q=0.8\r\n\r\n"
        "Cookie: qHistory=aHR0cDovL2lwLmNoaW5hei5jb21fSVAvSVB2Nuafpeivou+8jOacjeWKoeWZqOWcsOWdgOafpeivog==;cz_statistics_visitor=784084ce-8f41-3e4d-e442-cc02ccf85a0c;Hm_lvt_ca96c3507ee04e182fb6d097cb2a1a4c=1711415988;_clck=16i1sen%7C2%7Cfkg%7C0%7C1546;Hm_lpvt_ca96c3507ee04e182fb6d097cb2a1a4c=1711595701\r\n";

    send(ConnectSocket, request, strlen(request), 0);

    char buffer[10000];
    int nDataLength;
    std::string responseData;
    while ((nDataLength = recv(ConnectSocket, buffer, 10000, 0)) > 0) {
        // 处理接收到的数据，这里简单打印出来
        //std::cout.write(buffer, nDataLength);
        responseData.append(buffer, nDataLength);
    }

    closesocket(ConnectSocket);
    WSACleanup();
    // 在 responseData 中查找 "IP的物理位置" 部分的信息
    std::string searchString = "IP的物理位置";
    size_t pos = responseData.find(searchString);
    if (pos != std::string::npos) {
        // 打印出 "IP的物理位置" 部分的信息
        std::cout << responseData.substr(pos, 200) << std::endl; // 输出位置后的200个字符作为示例
    }
    else {
        std::cout << "未找到IP的物理位置信息" << std::endl;
    }
}

void getIPAndAddress()
{
    QNetworkAccessManager manager_;
    //QNetworkReply* m_reply = manager_.get(QNetworkRequest(QUrl("http://whois.pconline.com.cn/ipJson.jsp?json=true")));
    QNetworkReply* m_reply = manager_.get(QNetworkRequest(QUrl("https://ip.chinaz.com/ajaxsync.aspx?at=IpLocation&callback=jQuery1113016954657027229914_1711595701088")));
    QEventLoop loop;
    QObject::connect(m_reply, &QNetworkReply::finished, [&]() {
        if (m_reply->error() == QNetworkReply::NoError) {
            QString data = QString::fromLocal8Bit(m_reply->readAll());
            QJsonDocument jsonDocument = QJsonDocument::fromJson(data.toUtf8());
            QJsonObject jsonObject = jsonDocument.object();
            QString ip = jsonObject.value("ip").toString();
            QString address = jsonObject.value("addr").toString();

            qDebug() << "ip:" << ip;
            qDebug() << "location:" << address;
        }
        else {
            qDebug() << "Error occurred: " << m_reply->errorString();
        }

        m_reply->deleteLater();
        loop.quit();
        });
    loop.exec();
}

//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

LoadDialog::LoadDialog(QWidget *parent)
    : ASQDialog(parent),
	m_ui(new Ui::LoadDialog)
{
	m_ui->setupUi(this);

    InitUI();
    InitConnect();
}

LoadDialog::~LoadDialog()
{
	delete m_ui;
}

void LoadDialog::InitUI()
{
    m_eSelectMode = UserType::Teacher;
    m_LoadDialogProcess.SetUsertype(m_eSelectMode);
    // 创建一个 QLabel 用于显示背景图
    QLabel* backgroundLabel = new QLabel();
    QImage Image;
    Image.load(QString::fromLocal8Bit("res/bg/bg_sign_in.png"));
    QPixmap pixmap = QPixmap::fromImage(Image);
    QPixmap fitpixmap = pixmap.scaled(m_ui->widget_1->width(), m_ui->widget_1->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    backgroundLabel->setPixmap(fitpixmap);
    backgroundLabel->setAlignment(Qt::AlignCenter);
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(backgroundLabel, 0, Qt::AlignCenter);	//居中
    layout->setMargin(0);							//左右间距
    m_ui->widget_1->setLayout(layout);

    m_ui->lineEdit_Position->setEchoMode(QLineEdit::Password);

    m_socket = new QTcpSocket(this);
    QString ip = QString::fromLocal8Bit("127.0.0.1");//获取ip
    //QString ip = QString::fromLocal8Bit("192.168.124.18");//获取ip
    int port = 1122;//获取端口数据
    m_socket->connectToHost(ip, port);//连接服务器
    /*if (m_socket->waitForConnected(3000) == false) {
        qDebug() << "connect error:" << m_socket->errorString();
    }*/
    m_manager = new QNetworkAccessManager(this);
    //GetOutNetIp();
    //m_manager_ = new QNetworkAccessManager(this);
    //QString ipadd = QString("156.59.17.7");
    ////getPublicIp();
    ////ggetadress();
    ////getIPAndAddress();
    ////BaiDuIpQuery(m_manager, ipadd);
    //getOnlineIPs();
    //char* txt = "192.168.124.18";
    ////QHostInfo::lookupHost(txt, this, SLOT(onHostLookedUp(QHostInfo)));
    //string ip_;
    //ip_ = GetIp(txt);
    //qDebug() << QString::fromLocal8Bit(ip_.c_str());
}

void LoadDialog::InitConnect()
{
    // ==== 位置类型 下拉选择 更新标记位置 ====
    

    connect(m_ui->radioButton_1, static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::toggled), this, [this](bool checked)
        {
            if (checked)
            {
                m_eSelectMode = as::UserType::Teacher;
                m_LoadDialogProcess.SetUsertype(m_eSelectMode);
            }
        });

    connect(m_ui->radioButton_2, static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::toggled), this, [this](bool checked)
        {
            if (checked)
            {
                m_eSelectMode = as::UserType::Student;
                m_LoadDialogProcess.SetUsertype(m_eSelectMode);
            }
        });


        connect(m_ui->lineEdit_CriticalValue, static_cast<void (QLineEdit::*)()>(&QLineEdit::editingFinished), this, [this]()
            {
                string val = m_ui->lineEdit_CriticalValue->text().toLocal8Bit();
                //m_LoadDialogProcess.SetUsername(val);
            });


        connect(m_ui->lineEdit_Position, static_cast<void (QLineEdit::*)()>(&QLineEdit::editingFinished), this, [this]()
            {
                string val = m_ui->lineEdit_Position->text().toLocal8Bit();
                //m_LoadDialogProcess.SetUserpwd(val);
            });


        connect(m_ui->checkBox, static_cast<void (QCheckBox::*)(int)>(&QCheckBox::stateChanged), this, [this](bool checked)
            {
                bool val = checked;

            });

        connect(m_ui->toolButton_get_2, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
            {
                Q_UNUSED(checked);
                string name = m_ui->lineEdit_CriticalValue->text().toStdString();
                string pwd = m_ui->lineEdit_Position->text().toStdString();
                if (name == "")
                {
                    OperationCheckDialog tip_dialog(as::WidgetType::Tip, QString::fromLocal8Bit("用户名不能为空！"), 1, this);
                    tip_dialog.exec();
                    return;
                }
                else if (pwd == "")
                {
                    OperationCheckDialog tip_dialog(as::WidgetType::Tip, QString::fromLocal8Bit("密码不能为空！"), 1, this);
                    tip_dialog.exec();
                    return;
                }
                if (m_LoadDialogProcess.identifyUsername(name))
                {
                    if (m_LoadDialogProcess.identifyUserpwd(pwd))
                    {
                        m_LoadDialogProcess.SetUsername(name);
                        this->accept();
                        return;
                    }
                }
                OperationCheckDialog tip_dialog(as::WidgetType::Tip, QString::fromLocal8Bit("密码错误,请重试！"), 1, this);
                tip_dialog.exec();
                return;
            });
}

QTcpSocket*& LoadDialog::GetSocket()
{
    return m_socket;
}

string LoadDialog::GetUsername()
{
    //return m_LoadDialogProcess.GetUsername();
    return m_ui->lineEdit_CriticalValue->text().toStdString();
}

UserType LoadDialog::GetUserType()
{
    return m_eSelectMode;
}

void LoadDialog::getPublicIp()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://api.ipify.org"));
    m_reply = manager->get(request);

    QObject::connect(m_reply, &QNetworkReply::finished, [=]() {
        if (m_reply->error() == QNetworkReply::NoError) {
            QByteArray data = m_reply->readAll();
            m_ipAddress = data.toStdString();
            GetPoint(m_ipAddress.data(), "ip.chinaz.com");
            qDebug() << "Public IP Address: " << data;
        }
        else {
            qDebug() << "Error occurred: " << m_reply->errorString();
        }
         m_reply->deleteLater();
        manager->deleteLater();
        });
}

void LoadDialog::BaiDuIpQuery(QNetworkAccessManager* manager, const QString& ip) {
    QNetworkRequest request;
    request.setUrl(QUrl("http://api.map.baidu.com/location/ip?ip=" + ip + "&ak=PeR9Utg7G9MNLltViPXhw0xhUtabELu8"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    connect(manager, &QNetworkAccessManager::finished, this, &LoadDialog::onFinished);
    manager->get(request);
}

void LoadDialog::onFinished(QNetworkReply* m_reply) {
    if (m_reply->error()) {
        qDebug() << "Error:" << m_reply->errorString();
    }
    else {
        QString answer = m_reply->readAll();
        qDebug() << "Answer:" << answer;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray contentArray = jsonObject["content"].toArray();
        for (auto& var : contentArray)
        {
            QJsonObject contentObject = var.toObject();
            qDebug() << "Address:" << contentObject["address"].toString();
            qDebug() << "Address_detail:" << contentObject["address_detail"].toObject();
            break; // 只获取第一个结果
        }
    }
    m_reply->deleteLater();
}

void LoadDialog::onHostLookedUp(const QHostInfo& host)
{
    if (host.error() != QHostInfo::NoError) {
        QMessageBox::information(this, QStringLiteral("提示"), host.errorString());
        return;
    }
    QList<QHostAddress> adds = host.addresses();
    if (adds.size()) {
        const QHostAddress& addr = adds.first();

        queryLocationOfIP(addr.toString());
        qDebug() << addr.toString();
    }
}

void LoadDialog::queryLocationOfIP(const QString& strIp)
{
    //string ip = strIp.toStdString();
    //QString ssst = QString("112.14.29.174");
   // const QString& strUrl = QString("http://api.map.baidu.com/location/ip?ak=%1&ip=PeR9Utg7G9MNLltViPXhw0xhUtabELu8&coor=bd09ll").
        //arg(strIp);
    const QString& strUrl = QString("http://api.map.baidu.com/location/ip?ak=PeR9Utg7G9MNLltViPXhw0xhUtabELu8&coor=bd09ll&ip=%1").arg(strIp);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setUrl(QUrl(strUrl));

    m_reply_1 = m_manager->get(request);
    connect(m_reply_1, SIGNAL(finished()), this, SLOT(replyFinished()));
}

void LoadDialog::querySpecialLocation()
{
    // 创建请求
    QUrl url("http://api.map.baidu.com/reverse_geocoding/v3/?ak=PeR9Utg7G9MNLltViPXhw0xhUtabELu8&output=json&coordtype=bd09ll&location=" + m_lat + "," + m_lon);
    QNetworkRequest request(url);

    // 发送请求
    m_reply_1 = m_manager->get(request);

    // 接收响应
    QObject::connect(m_reply_1, &QNetworkReply::finished, [&]() {
        if (m_reply_1->error() == QNetworkReply::NoError) {
            // 读取响应数据
            QByteArray response = m_reply_1->readAll();
            QJsonParseError error;
            // 解析JSON
            QJsonDocument doc = QJsonDocument::fromJson(response, &error);
            if (error.error != QJsonParseError::NoError) {
                QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("JSON:数据结构有问题！"));
                return QVariantMap();
            }
            QJsonObject jsonObject = doc.object();
            int status = jsonObject.value("status").toInt();
            if (status != 0) {
                QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("状态码：%1").arg(status));
                return QVariantMap();
            }
            // 提取位置信息
            QJsonObject result = jsonObject["result"].toObject();
            QString formattedAddress = result["formatted_address"].toString();
            qDebug() << "country: " << jsonObject["result"].toObject()["addressComponent"].toObject()["country"].toString();
            qDebug() << "province: " << jsonObject["result"].toObject()["addressComponent"].toObject()["province"].toString();
            qDebug() << "city: " << jsonObject["result"].toObject()["addressComponent"].toObject()["city"].toString();
            qDebug() << "district: " << jsonObject["result"].toObject()["addressComponent"].toObject()["district"].toString();
            qDebug() << "town: " << jsonObject["result"].toObject()["addressComponent"].toObject()["town"].toString();
            qDebug() << "street: " << jsonObject["result"].toObject()["addressComponent"].toObject()["street"].toString();
            qDebug() << "Formatted Address: " << formattedAddress;
            m_reply_1->deleteLater();
            m_manager->deleteLater();
        }
        else {
            qDebug() << "Error: " << m_reply_1->errorString();
            // 释放资源
            m_reply_1->deleteLater();
        }
        });
}


void LoadDialog::replyFinished()
{
    m_reply_1 = qobject_cast<QNetworkReply*>(sender());

    if (m_reply_1->error() != QNetworkReply::NoError) {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("请求出错:%1").arg(m_reply_1->errorString()));
    }
    const QByteArray& bytes = m_reply_1->readAll();
    const QVariantMap& varMap = parseLocationData(bytes);
    showLocation(varMap);
}

QVariantMap LoadDialog::parseLocationData(const QByteArray& data)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError) {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("JSON:数据结构有问题！"));
        return QVariantMap();
    }
    QJsonObject obj = doc.object();
    int status = obj.value("status").toInt();
    if (status != 0) {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("状态码：%1").arg(status));
        return QVariantMap();
    }
    QJsonObject contentObj = obj.value("content").toObject();
    QJsonObject contentArray = contentObj.value("address_detail").toObject();
    qDebug() << contentObj.value("address").toString();
    qDebug() << contentArray.value("province").toString();
    return contentObj.toVariantMap();
}


void LoadDialog::showLocation(const QVariantMap& varMap)
{
    const QString& addrStr = varMap.value("address").toString();
    //string ad = addrStr.toStdString();
    const QVariantMap& ptMap = varMap.value("point").toMap();
    QString longitudeStr = ptMap.value("x").toString(); //经度
    QString latitudeStr = ptMap.value("y").toString(); //纬度
    const QString& txt = QStringLiteral("城市：%1 \n经度：%2   纬度：%3").arg(addrStr).arg(longitudeStr).arg(latitudeStr);
    m_lat = latitudeStr;
    m_lon = longitudeStr;
    qDebug() << txt;
    querySpecialLocation();
    //m_manager->deleteLater();
}

void LoadDialog::getOnlineIPs() {
    for(QNetworkInterface inter: QNetworkInterface::allInterfaces()) {
        // 跳过本地回环接口
        if (inter.flags().testFlag(QNetworkInterface::IsLoopBack)) {
            continue;
        }
        // 跳过不活跃的接口
        if (!inter.flags().testFlag(QNetworkInterface::IsUp)) {
            continue;
        }
        // 遍历每个接口的地址
        for(QNetworkAddressEntry entry: inter.addressEntries()) {
            // 只获取IPv4地址
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                qDebug() << "Online IP:" << entry.ip().toString();
            }
        }
    }
}

void LoadDialog::GetOutNetIp()
{
    //QNetworkAccessManager m_manager;
    QUrl url("http://ifconfig.me/ip");
    QNetworkRequest request(url);

    m_reply_1 = m_manager->get(request);
    QObject::connect(m_reply_1, &QNetworkReply::finished, [&]() {
        if (m_reply_1->error() == QNetworkReply::NoError) {
            m_ipnet = m_reply_1->readAll();
            std::cout << "External IP: " << m_ipnet.toStdString() << std::endl;
        }
        else {
            std::cerr << "Error: " << m_reply_1->errorString().toStdString() << std::endl;
            return;
        }
        queryLocationOfIP(m_ipnet);
        });
}

