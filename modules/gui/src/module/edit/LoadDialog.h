#ifndef AS_LoadDIALOG_H
#define AS_LoadDIALOG_H

#include "common/CommonPart.h"
#include "as/CommonCore.hpp"
#include "as/common/UiCallback.h"

#include "as/common/CommonProcess.h"


#include <QLineEdit>

namespace Ui
{
	class LoadDialog;
}
using namespace as;

class LoadDialog : public ASQDialog
{
    Q_OBJECT
public:
	LoadDialog(QWidget* parent = nullptr);
	~LoadDialog();

	void InitUI();
	
	void InitConnect();
	
signals:

private slots:

private:
    Ui::LoadDialog *m_ui;
	//BenchMarkProcess m_cBenchMarkProcess;

	as::CommonCheck statecheck;

};

#endif
