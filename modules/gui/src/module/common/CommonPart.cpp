#include "CommonPart.h"

void ASQDialog::show()
{
	this->setFixedSize(this->size());
	QWidget::show();
}

int ASQDialog::exec()
{
	this->setFixedSize(this->size());
	this->setWindowModality(Qt::WindowModality::WindowModal);
	return QDialog::exec();
}

void ASQDialog::closeEvent(QCloseEvent* event)
{
	event->setAccepted(!event->spontaneous());
}

//��ȡCheckBox
QCheckBox* ASQDialog::CreateCheckBox(QTableWidget* table, int row, int column)
{
	QWidget* temp_widget = 0;
	temp_widget = table->cellWidget(row, column); //�ҵ���Ԫ��
	QCheckBox* temp_CheckBox = 0;
	bool bFlag = true;
	if (temp_widget != 0) //
	{
		bFlag = false;
	}
	if (bFlag)
	{
		temp_widget = new QWidget(table); //����һ��widget
		QHBoxLayout* hLayout = new QHBoxLayout(temp_widget); //��������
		temp_CheckBox = new QCheckBox(temp_widget);
		temp_CheckBox->setChecked(false);
		temp_CheckBox->setFont(table->font());
		temp_CheckBox->setFocusPolicy(Qt::NoFocus);
		temp_CheckBox->setEnabled(true);
		hLayout->addWidget(temp_CheckBox); //���
		hLayout->setMargin(0); //���ñ�Ե����
		hLayout->setAlignment(temp_CheckBox, Qt::AlignCenter); //����
		hLayout->setSpacing(0);
		temp_widget->setLayout(hLayout); //����widget�Ĳ���
		table->setCellWidget(row, column, temp_widget);
	}
	return temp_CheckBox;
}

sendStruct::sendStruct(int Type, QString Description, QByteArray ByteData)
{

}

UserLeaveMessageData::UserLeaveMessageData(string m_username, int m_type, string m_datetime, string m_reason, as::leaveStatus m_status, string m_adress)
{
}
