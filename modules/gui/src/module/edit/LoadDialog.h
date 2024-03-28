#ifndef AS_LoadDIALOG_H
#define AS_LoadDIALOG_H

#include "common/CommonPart.h"
#include "as/CommonCore.hpp"
#include "as/common/UiCallback.h"

//process
#include "as/common/CommonProcess.h"
#include "as/edit/LoadDialogProcess.hpp"

//Qt
#include <QLineEdit>
#include "qtcpsocket.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QHostInfo>

namespace Ui
{
	class LoadDialog;
}
using namespace as;

class LoadDialog : public ASQDialog
{
    Q_OBJECT
public:
	LoadDialog(QWidget* parent = nullptr);
	~LoadDialog();

	void InitUI();
	
	void InitConnect();

	QTcpSocket*& GetSocket();

	string GetUsername();

	UserType GetUserType();

	void getPublicIp();

	void BaiDuIpQuery(QNetworkAccessManager* manager, const QString& ip);
	
	void queryLocationOfIP(const QString& strIp);

	void querySpecialLocation();

	QVariantMap parseLocationData(const QByteArray& data);

	void showLocation(const QVariantMap& varMap);

	void getOnlineIPs();

	void GetOutNetIp();
signals:

private slots:
	void onFinished(QNetworkReply* reply);
	void onHostLookedUp(const QHostInfo& host);
	void replyFinished();
private:
    Ui::LoadDialog *m_ui;
	
	LoadDialogProcess m_LoadDialogProcess;

	as::UserType m_eSelectMode;
	QTcpSocket* m_socket;

	QNetworkReply* m_reply;
	QNetworkReply* m_reply_1;
	QNetworkReply* m_reply_2;
	QNetworkReply* m_reply_3;

	QNetworkAccessManager* m_manager;
	QNetworkAccessManager* m_manager_;


	string m_ipAddress;
	QString m_ipnet = "";

	QString m_lat;
	QString m_lon;
};

#endif
