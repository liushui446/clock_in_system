#include "TakeLeaveDialog.h"
#include "ui_TakeLeaveDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>
#include "mainwindow.h"

//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

TakeLeaveDialog::TakeLeaveDialog(QWidget *parent)
    : ASQDialog(parent),
	m_ui(new Ui::TakeLeaveDialog)
{
	m_ui->setupUi(this);
    m_cmain = (MainWindow*)parentWidget();
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
            if (m_cSubmitDialog->exec() == QDialog::Accepted)
            {
                m_cmain->HandinMess("student_1 Leave Message");
                OperationCheckDialog tip_dialog(as::WidgetType::Tip, tr(as::CommonProcess::GetInstance().string_To_UTF8("提交成功!").c_str()), 2, this);
                tip_dialog.exec();
                //清空信息
            }
        });
}

