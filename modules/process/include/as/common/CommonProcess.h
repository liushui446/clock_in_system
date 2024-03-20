#ifndef AS_COMMONPROCESS_H
#define AS_COMMONPROCESS_H

#include "as/CommonCore.hpp"

namespace as
{
	

	enum class LanguegeType
	{
		CHS = 0,
		ENG,
		KOR
	};

	class AS_EXPORTS CommonProcess
	{
	public:
		CommonProcess();
		~CommonProcess() {};

		static CommonProcess& GetInstance();
		string string_To_UTF8(const string& str);
		bool isChineseChar(char c);
		vector<string> SplitString(string str, bool isSplit=true);
		//判断值范围
		bool JudgeValueRange(string valueOfMin, string valueOfMax, string input);

		//工具接口
		string intToHex(int n);
		char hexUnit(unsigned char unit);


	private:
		mutex mtx;
		std::function<void(int)> m_GUIFunc;
		std::function<void(int block_id, int array_id, int index, bool ref_flag)> m_RefCompListFunc;
		std::function<void(std::string, std::string, int error_code)> m_MessageBoardFunc;
		string m_strProgramName; //项目名称
		string m_strDataSavePath;//数据保存路径
	};

	

	// 共有检查类
	class AS_EXPORTS CommonCheck
	{
	public:
		static bool StateMachineCheck(bool moveaction);  // true：Move动作，false：Get动作
	};
}

#endif