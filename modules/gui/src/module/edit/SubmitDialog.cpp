#include "SubmitDialog.h"
#include "ui_SubmitDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>


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
    QStringList paddata_headrs = { "Leave Message" };

    //设置表格列数
    m_ui->tableWidget_1->setColumnCount(paddata_headrs.size());
    m_ui->tableWidget_1->setHorizontalHeaderLabels(paddata_headrs);
    m_ui->tableWidget_1->verticalHeader()->setVisible(true);
    m_ui->tableWidget_1->horizontalHeader()->setHighlightSections(false); 
    m_ui->tableWidget_1->setFocusPolicy(Qt::NoFocus);

    m_ui->tableWidget_1->clearContents();
    m_ui->tableWidget_1->setRowCount(0);

    m_ui->tableWidget_1->setRowCount(1);
    int index = 0;
    string message = "student_1 Leave Message";
    //表格内容设置
    m_ui->tableWidget_1->setItem(index, 0, new QTableWidgetItem(QString::fromLocal8Bit(message.c_str())));
    m_ui->tableWidget_1->item(index, 0)->setTextAlignment(Qt::AlignCenter);
    m_ui->tableWidget_1->item(index, 0)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

}

void SubmitDialog::InitConnect()
{
    connect(m_ui->toolButton_previous, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
        {
            Q_UNUSED(checked);
            this->reject();
        });

    connect(m_ui->toolButton_handin, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
        {
            Q_UNUSED(checked);
            this->accept();
        });

}

