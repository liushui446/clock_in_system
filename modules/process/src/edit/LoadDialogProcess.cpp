#include "as/edit/LoadDialogProcess.hpp"

namespace as
{
	LoadDialogProcess::LoadDialogProcess()
	{
		m_pUserManagedata = *ASContext::GetInstance().GetUserManagedata();
	}


}