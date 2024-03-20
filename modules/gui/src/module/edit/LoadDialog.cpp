#include "LoadDialog.h"
#include "ui_LoadDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>


//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

LoadDialog::LoadDialog(QWidget *parent)
    : ASQDialog(parent, Qt::CustomizeWindowHint | Qt::WindowTitleHint), 
	m_ui(new Ui::LoadDialog)
{
	m_ui->setupUi(this);

    InitUI();
    InitConnect();
}

LoadDialog::~LoadDialog()
{
	delete m_ui;
}

void LoadDialog::InitUI()
{
    //================块拼初始化===============//

    ////外光内光数值初始化
    //m_ui->label_10->setText(QString::number(0));
    //m_ui->label_26->setText(QString::number(0));

    ////旋转角度初始化
    //m_ui->comboBox_Rotate->addItem(QString::number(0));
    //m_ui->comboBox_Rotate->addItem(QString::number(90));
    //m_ui->comboBox_Rotate->addItem(QString::number(180));
    //m_ui->comboBox_Rotate->addItem(QString::number(270));
    //m_ui->comboBox_Rotate->setCurrentIndex(0);

    ////================按钮初始化设置===============//
    ////确认按钮图标设置
    //m_ui->toolButton_ok->setIconSize(QSize(32, 32));
    //m_ui->toolButton_ok->setIcon(QIcon("res/button/checkall.svg"));
    //m_ui->toolButton_ok->setText(QString::fromLocal8Bit("更新"));
    //m_ui->toolButton_ok->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ////===================Mark点形状====================//
    //m_ui->comboBox_Shape->addItems(MarkTypeList);

    ////=============== MARK点类型 ==================//
    //m_ui->comboBox_positioningType->addItem(QIcon(QString::fromLocal8Bit("res/dialog/Board/位置类型1.png")), "");
    //m_ui->comboBox_positioningType->addItem(QIcon(QString::fromLocal8Bit("res/dialog/Board/位置类型2.png")), "");
    //m_ui->comboBox_positioningType->addItem(QIcon(QString::fromLocal8Bit("res/dialog/Board/位置类型3.png")), "");

}

void LoadDialog::InitConnect()
{
    // ==== 位置类型 下拉选择 更新标记位置 ====
    

        ////==== 块选择 刷新界面 ====
        //connect(m_ui->comboBox_Block, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index)
        //    {
        //        as::OperateLogfunc::GetInstance().InfoComRecord("块选择", m_ui->comboBox_Block->currentText().toLocal8Bit().data(), __LINE__);
        //    });


        ////临界值
        //connect(m_ui->lineEdit_CriticalValue, static_cast<void (QLineEdit::*)()>(&QLineEdit::editingFinished), this, [this]()
        //    {
        //        as::OperateLogfunc::GetInstance().InfoDataChangeRecord("临界值", m_ui->lineEdit_CriticalValue->text().toDouble(), __LINE__);
        //        int val = m_ui->lineEdit_CriticalValue->text().toDouble();
        //        //m_cBenchMarkProcess.
        //    });

        ////自动
        //connect(m_ui->checkBox_auto, static_cast<void (QCheckBox::*)(int)>(&QCheckBox::stateChanged), this, [this](int value)
        //    {
        //        as::OperateLogfunc::GetInstance().InfoClickRecord(m_ui->checkBox_auto->text().toLocal8Bit().data(), __LINE__);
        //        int val = value;

        //    });

        ////位置
        //connect(m_ui->lineEdit_Position, static_cast<void (QLineEdit::*)()>(&QLineEdit::editingFinished), this, [this]()
        //    {
        //        as::OperateLogfunc::GetInstance().InfoDataChangeRecord("位置", m_ui->lineEdit_Position->text().toDouble(), __LINE__);
        //        int val = m_ui->lineEdit_Position->text().toDouble();

        //    });

}

