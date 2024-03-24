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
    int  Type;//�������ַ��͵Ĳ�ͬ���ݵ����ݣ���Ӧ��ͬ�Ľ�������
    QString Description;//�������ݵ�����
    QByteArray ByteData;//���巢�ͻ��߽��ܵ����ݣ����Խ����л�������int��char��vector��map�Ȼ����Զ���Ľṹ��ͨ��
                        //QDataStream���л���ByteData�У����ն�ͬ���ķ�����QDataStream�н�������ԭ����
    sendStruct() { Type = 0; Description = ""; ByteData = QByteArray(0); }
    int size()
    {
        int size = 0;
        size = sizeof(int) + Description.size() * 2 + 4 + ByteData.size() + 4;
        //���л���QString��СΪԭ�д�С����2��4��QByteArry���л����СΪԭʼ��С��4��QStringΪUnicode����ÿ���ַ�ռ�����ֽ�,
        //QString��QByteArry���л������У��������л��˱����С����������(qint32)�������У�Ȼ����Ǿ������ݡ�
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

