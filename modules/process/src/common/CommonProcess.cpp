#include "as/common/CommonProcess.h"
#include <comdef.h>
#include "as/io.hpp"

#include "opencv2/core/mat.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <as/ASContext.hpp>

namespace as
{
	string wstringastring(const std::wstring& ws)
	{
		_bstr_t t = ws.c_str();
		char* pchar = (char*)t;
		string result = pchar;
		return result;
	}

	CommonProcess::CommonProcess()
	{
		m_strProgramName = "无标题";

		//判断文件夹是否存在、不存在则创建
		/*m_strDataSavePath = GetCurrentProgeramPath() + "\\AOIData\\";
		if (_access(m_strDataSavePath.c_str(), 0) == -1)
			_mkdir(m_strDataSavePath.c_str());

		m_strDataSavePath += m_strProgramName;
		if (_access(m_strDataSavePath.c_str(), 0) == -1)
			_mkdir(m_strDataSavePath.c_str());*/
	}

	CommonProcess& CommonProcess::GetInstance()
	{
		static CommonProcess instance;
		return instance;
	}

	string CommonProcess::intToHex(int n)
	{
		string hex = "0x";
		hex += hexUnit((n & 0xF0000000) >> 28);
		hex += hexUnit((n & 0x0F000000) >> 24);
		hex += hexUnit((n & 0x00F00000) >> 20);
		hex += hexUnit((n & 0x000F0000) >> 16);
		hex += hexUnit((n & 0x0000F000) >> 12);
		hex += hexUnit((n & 0x00000F00) >> 8);
		hex += hexUnit((n & 0x000000F0) >> 4);
		hex += hexUnit((n & 0x0000000F));

		return hex;
	}

	char CommonProcess::hexUnit(unsigned char unit)
	{
		if (0 <= unit && unit <= 9)
			return unit + '0';
		else if (10 <= unit && unit <= 15)
			return unit - 10 + 'A';

		return '0';
	}

	string CommonProcess::string_To_UTF8(const string& str)
	{
		int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

		wchar_t* pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
		ZeroMemory(pwBuf, nwLen * 2 + 2);

		::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

		int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

		char* pBuf = new char[nLen + 1];
		ZeroMemory(pBuf, nLen + 1);

		::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

		std::string retStr(pBuf);

		delete[]pwBuf;
		delete[]pBuf;

		pwBuf = NULL;
		pBuf = NULL;

		return retStr;
	}

	bool CommonProcess::isChineseChar(char c)
	{
		if ((unsigned short)c > 128)
		{
			return true;
		}
		return false;
	}

	vector<string> CommonProcess::SplitString(string str, bool isSplit)
	{
		vector<string> info;
		if (isSplit)
		{
			vector<int> start_flag;
			vector<int> end_flag;
			for (int i = 0; i < str.size(); i++)
			{
				char cur = str.c_str()[i];
				if (i != 0)
				{
					char pre = str.c_str()[i - 1];
					if (isChineseChar(cur) && !isChineseChar(pre))
					{
						start_flag.push_back(i);
						continue;
					}
					if (i < str.size() - 1)
					{
						char next = str.c_str()[i + 1];
						if (isChineseChar(cur) && !isChineseChar(next))
						{
							end_flag.push_back(i);
						}
					}
					else
					{
						if (isChineseChar(cur))
						{
							end_flag.push_back(i);
						}
					}			
				}
				else
				{
					if (isChineseChar(cur))
					{
						start_flag.push_back(i);
						continue;
					}
					if (isChineseChar(cur) && i == str.size() - 1)
					{
						end_flag.push_back(i);
					}
				}			
			}
			for (int i = 0; i < start_flag.size(); i++)
			{
				if (i == 0)
				{
					string temp = string_To_UTF8(str.substr(0, start_flag.at(i))).c_str();
					info.push_back(temp);
				}
				string temp = string_To_UTF8(str.substr(start_flag.at(i), end_flag.at(i) - start_flag.at(i) + 1)).c_str();
				info.push_back(temp);
				if (i < start_flag.size() - 1)
				{
					string temp_2 = string_To_UTF8(str.substr(end_flag.at(i) + 1, start_flag.at(i + 1) - end_flag.at(i) - 1)).c_str();
					info.push_back(temp_2);
				}
			}
			if (start_flag.size() != 0)
			{
				string temp = string_To_UTF8(str.substr(end_flag.at(end_flag.size() - 1) + 1, str.size() - end_flag.at(end_flag.size() - 1) - 1)).c_str();
				info.push_back(temp);
			}
			else
			{
				info.push_back(string_To_UTF8(str).c_str());
			}
		}
		else
		{
			info.push_back(string_To_UTF8(str).c_str());
		}
		return info;
	}

	bool CommonProcess::JudgeValueRange(string valueOfMin, string valueOfMax, string input)
	{
		if (atof(input.c_str()) > atof(valueOfMax.c_str()) || atof(input.c_str()) < atof(valueOfMin.c_str()))
		{
			return false;
		}
		else if (input == "")
		{
			return false;
		}
		return true;
	}

	bool CommonCheck::StateMachineCheck(bool moveaction)
	{
		//StateID state = StateMachineCore::GetInstance().GetStateID();
		//if (moveaction)
		//{
		//	if (state == StateID::StateID_Idle_0)
		//	{
		//		//as::CommonProcess::GetInstance().SoftSendQMessage(MsgLevel::WARNING, SoftErrCode::UnReady);
		//		return false;
		//	}
		//	else if (state == StateID::StateID_Idle_1)
		//	{
		//		//as::CommonProcess::GetInstance().SendQMessage(as::MsgLevel::WARNING, as::WorkInErrState);
		//		return false;
		//	}
		//	else if (state == StateID::StateID_Wait)
		//	{
		//		return true;
		//	}
		//	else if (state == StateID::StateID_Idle_2)
		//	{
		//		return true;
		//	}
		//	else
		//	{	
		//		//as::CommonProcess::GetInstance().SendQMessage(as::MsgLevel::WARNING, as::WorkInErrState);
		//		return false;
		//	}
		//}
		//else
		//{
		//	if (state == StateID::StateID_Idle_0)
		//	{
		//		//as::CommonProcess::GetInstance().SoftSendQMessage(MsgLevel::WARNING, SoftErrCode::UnReady);
		//		return false;
		//	}
		//	else if (state == StateID::StateID_Idle_1)
		//	{
		//		//as::CommonProcess::GetInstance().SendQMessage(as::MsgLevel::WARNING, as::WorkInErrState);
		//		return false;
		//	}
		//	else if (state == StateID::StateID_Idle_2)
		//	{
		//		return true;
		//	}
		//	else
		//	{
		//		//as::CommonProcess::GetInstance().SendQMessage(as::MsgLevel::WARNING, as::WorkInErrState);
		//		return false;
		//	}
		//}
		return true;
	}
}