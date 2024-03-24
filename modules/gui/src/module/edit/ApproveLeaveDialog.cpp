#include "ApproveLeaveDialog.h"
#include "ui_ApproveLeaveDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>
#include "mainwindow.h"

//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

ApproveLeaveDialog::ApproveLeaveDialog(QWidget *parent)
    : ASQDialog(parent),
	m_ui(new Ui::ApproveLeaveDialog)
{
	m_ui->setupUi(this);
    m_cmain = (MainWindow*)parentWidget();
    InitUI();
    InitConnect();
}

ApproveLeaveDialog::~ApproveLeaveDialog()
{
	delete m_ui;
}

void ApproveLeaveDialog::InitUI()
{
    QStringList paddata_headrs = { QString::fromLocal8Bit("序号") ,QString::fromLocal8Bit("姓名"), QString::fromLocal8Bit("类型"), \
        QString::fromLocal8Bit("原因"), QString::fromLocal8Bit("时间"), QString::fromLocal8Bit("状态"), QString::fromLocal8Bit("通过"),\
        QString::fromLocal8Bit("退回") };

    //设置表格列数
    m_ui->tableWidget->setColumnCount(paddata_headrs.size());
    m_ui->tableWidget->setHorizontalHeaderLabels(paddata_headrs);
    m_ui->tableWidget->verticalHeader()->setVisible(true);
    m_ui->tableWidget->horizontalHeader()->setHighlightSections(false);
    m_ui->tableWidget->setFocusPolicy(Qt::NoFocus);


}

void ApproveLeaveDialog::InitConnect()
{
    connect(m_ui->toolButton_make, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
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

void ApproveLeaveDialog::RefLeaveDataListview()
{
    /*m_ui->tableWidget->setItem(index, 0, new QTableWidgetItem(tr(aoi::CommonProcess::GetInstance().string_To_UTF8(m_compoName).c_str())));
    m_ui->tableWidget->item(index, 0)->setTextAlignment(Qt::AlignCenter);
    m_ui->tableWidget->item(index, 0)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    m_ui->tableWidget->setItem(index, 1, new QTableWidgetItem(package_name));
    m_ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignCenter);
    m_ui->tableWidget->item(index, 1)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    m_ui->tableWidget->setItem(index, 2, new QTableWidgetItem(type_name));
    m_ui->tableWidget->item(index, 2)->setTextAlignment(Qt::AlignCenter);
    m_ui->tableWidget->item(index, 2)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    m_ui->tableWidget->setItem(index, 3, new QTableWidgetItem(ng_number));1
    m_ui->tableWidget->item(index, 3)->setTextAlignment(Qt::AlignCenter);
    m_ui->tableWidget->item(index, 3)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    m_ui->tableWidget->setItem(index, 4, new QTableWidgetItem(algorithm_name));
    m_ui->tableWidget->item(index, 4)->setTextAlignment(Qt::AlignCenter);
    m_ui->tableWidget->item(index, 4)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);*/

}

