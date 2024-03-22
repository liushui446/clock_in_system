#include "LoadDialog.h"
#include "ui_LoadDialog.h"
#include "src/module/common/OperationCheckDialog.h"
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>
#include <Qtimer>
#include <QStandardItemModel>
#include <QtWidgets>


//#include "signal_transmitter.h"
//#include "as/IniPara.hpp"

LoadDialog::LoadDialog(QWidget *parent)
    : ASQDialog(parent),
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
    m_eSelectMode = UserType::Teacher;
    m_LoadDialogProcess.SetUsertype(m_eSelectMode);
    // 创建一个 QLabel 用于显示背景图
    QLabel* backgroundLabel = new QLabel();
    QImage Image;
    Image.load(QString::fromLocal8Bit("res/bg/bg_sign_in.png"));
    QPixmap pixmap = QPixmap::fromImage(Image);
    QPixmap fitpixmap = pixmap.scaled(m_ui->widget_1->width(), m_ui->widget_1->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    backgroundLabel->setPixmap(fitpixmap);
    backgroundLabel->setAlignment(Qt::AlignCenter);
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(backgroundLabel, 0, Qt::AlignCenter);	//居中
    layout->setMargin(0);							//左右间距
    m_ui->widget_1->setLayout(layout);

   


}

void LoadDialog::InitConnect()
{
    // ==== 位置类型 下拉选择 更新标记位置 ====
    

    connect(m_ui->radioButton_1, static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::toggled), this, [this](bool checked)
        {
            if (checked)
            {
                m_eSelectMode = as::UserType::Teacher;
                m_LoadDialogProcess.SetUsertype(m_eSelectMode);
            }
        });

    connect(m_ui->radioButton_2, static_cast<void (QRadioButton::*)(bool)>(&QRadioButton::toggled), this, [this](bool checked)
        {
            if (checked)
            {
                m_eSelectMode = as::UserType::Student;
                m_LoadDialogProcess.SetUsertype(m_eSelectMode);
            }
        });


        connect(m_ui->lineEdit_CriticalValue, static_cast<void (QLineEdit::*)()>(&QLineEdit::editingFinished), this, [this]()
            {
                string val = m_ui->lineEdit_CriticalValue->text().toLocal8Bit();
                //m_LoadDialogProcess.SetUsername(val);
            });


        connect(m_ui->lineEdit_Position, static_cast<void (QLineEdit::*)()>(&QLineEdit::editingFinished), this, [this]()
            {
                string val = m_ui->lineEdit_Position->text().toLocal8Bit();
                //m_LoadDialogProcess.SetUserpwd(val);
            });


        connect(m_ui->checkBox, static_cast<void (QCheckBox::*)(int)>(&QCheckBox::stateChanged), this, [this](bool checked)
            {
                bool val = checked;

            });

        connect(m_ui->toolButton_get_2, static_cast<void (QToolButton::*)(bool)>(&QToolButton::clicked), this, [this](bool checked)
            {
                Q_UNUSED(checked);
                string name = m_ui->lineEdit_CriticalValue->text().toStdString();
                string pwd = m_ui->lineEdit_Position->text().toStdString();
                if (name == "")
                {
                    OperationCheckDialog tip_dialog(as::WidgetType::Tip, QString::fromLocal8Bit("用户名不能为空！"), 1, this);
                    tip_dialog.exec();
                    return;
                }
                else if (pwd == "")
                {
                    OperationCheckDialog tip_dialog(as::WidgetType::Tip, QString::fromLocal8Bit("密码不能为空！"), 1, this);
                    tip_dialog.exec();
                    return;
                }
                if (m_LoadDialogProcess.identifyUsername(name))
                {
                    if (m_LoadDialogProcess.identifyUserpwd(pwd))
                    {
                        this->accept();
                        return;
                    }
                }
                OperationCheckDialog tip_dialog(as::WidgetType::Tip, QString::fromLocal8Bit("密码错误,请重试！"), 1, this);
                tip_dialog.exec();
                return;
            });
}

