#include "SubmitDialog.h"
#include "ui_SubmitDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>


//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

SubmitDialog::SubmitDialog(QWidget *parent)
    : ASQDialog(parent),
	m_ui(new Ui::SubmitDialog)
{
	m_ui->setupUi(this);

    InitUI();
    InitConnect();
}

SubmitDialog::~SubmitDialog()
{
	delete m_ui;
}

void SubmitDialog::InitUI()
{


}

void SubmitDialog::InitConnect()
{
    
}

