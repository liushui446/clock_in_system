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
