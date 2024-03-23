#include "TakeLeaveDialog.h"
#include "ui_TakeLeaveDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>


//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

TakeLeaveDialog::TakeLeaveDialog(QWidget *parent)
    : ASQDialog(parent),
	m_ui(new Ui::TakeLeaveDialog)
{
	m_ui->setupUi(this);

    InitUI();
    InitConnect();
}

TakeLeaveDialog::~TakeLeaveDialog()
{
	delete m_ui;
}

void TakeLeaveDialog::InitUI()
{



}

void TakeLeaveDialog::InitConnect()
{
    
    connect(m_ui->toolButton_look, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
        {
            Q_UNUSED(checked);
            m_cSubmitDialog = new SubmitDialog(this);
            m_cSubmitDialog->setGeometry(this->geometry().x(), this->geometry().y(), this->geometry().width(), this->geometry().height());
            if (m_cSubmitDialog->exec() == QDialog::Accepted)
            {
                
            }
        });
}

