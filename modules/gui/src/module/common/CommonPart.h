#ifndef _COMMONPART_H
#define _COMMONPART_H
#include <QDialog>
#include <QCloseEvent>
#include <QCheckBox>
#include <QTableWidget>
#include <QHBoxLayout>

class ASQDialog :public QDialog
{
public:

	ASQDialog(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags()) :QDialog(parent, f)
	{

	}

	void show();

	int exec();

	virtual void closeEvent(QCloseEvent* event);

	QCheckBox* CreateCheckBox(QTableWidget* table, int row, int column);
	
};

class sendStruct
{
public:
    explicit sendStruct(int Type, QString Description, QByteArray ByteData = QByteArray(0));
    int  Type;//用于区分发送的不同内容的数据，对应不同的解析方法
    QString Description;//发送内容的描述
    QByteArray ByteData;//具体发送或者接受的内容，可以将所有基本类型int，char，vector，map等或者自定义的结构体通过
                        //QDataStream序列化到ByteData中，接收端同样的方法从QDataStream中解析出来原数据
    sendStruct() { Type = 0; Description = ""; ByteData = QByteArray(0); }
    int size()
    {
        int size = 0;
        size = sizeof(int) + Description.size() * 2 + 4 + ByteData.size() + 4;
        //序列化后QString大小为原有大小乘以2加4，QByteArry序列化后大小为原始大小加4，QString为Unicode编码每个字符占两个字节,
        //QString和QByteArry序列化过程中，首先序列化了本身大小的整形数据(qint32)到序列中，然后才是具体数据。
        return size;
    }
    int size() const
    {
        int size = 0;
        size = sizeof(int) + Description.size() * 2 + 4 + ByteData.size() + 4;
        return size;
    }
    sendStruct& operator=(const sendStruct& other)
    {
        Type = other.Type;
        Description = other.Description;
        ByteData = QByteArray(other.ByteData);
        return *this;
    }
#ifndef QT_NO_DATASTREAM
    friend QDataStream& operator <<(QDataStream& out, const sendStruct& senstruct)
    {
        out << senstruct.Type
            << senstruct.Description
            << senstruct.ByteData;
        return out;
    }
    friend QDataStream& operator >>(QDataStream& in, sendStruct& senstruct)
    {
        in >> senstruct.Type
            >> senstruct.Description
            >> senstruct.ByteData;
        return in;
    }
#endif
};
#endif // !_COMMONPART_H

