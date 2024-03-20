#ifndef _COMMONPART_H
#define _COMMONPART_H
#include <QDialog>
#include <QCloseEvent>

class ASQDialog :public QDialog
{
public:

	ASQDialog(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags()) :QDialog(parent, f)
	{

	}

	void show();

	int exec();

	virtual void closeEvent(QCloseEvent* event);
	
};
#endif // !_COMMONPART_H

