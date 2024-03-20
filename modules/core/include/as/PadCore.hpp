#ifndef AS_PADCORE_HPP
#define AS_PADCORE_HPP
#include "as/CommonCore.hpp"
#include "as/CADCore.hpp"

namespace as
{
	class PadGroupManager;
	class PadDataSet;
	class DetectionPadData;
	class PadGroupManager;
	enum class PadShape;
}

namespace as
{

	/* 类名：ImportPadData
	* 创建日期： 2023/10/17
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	待预处理焊盘数据类
	*	@version 1.0
	*/
	class AS_EXPORTS ImportPadData
	{
	public:
		ImportPadData();
		ImportPadData& operator=(ImportPadData& ref);

	private:
		string m_PadId;		//焊盘ID
		PadShape m_shape;	//焊盘形状
		double m_angle;		//焊盘角度
		Point m_pos;		//焊盘位置
		double m_dlength;	//焊盘长
		double m_dwidth;    //焊盘宽
	};


	/* 类名：PadGroupManager
	* 创建日期： 2023/10/13
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	焊盘分组管理类
	*	@version 1.0
	*/
	class AS_EXPORTS PadGroupManager
	{
	public:

		enum class PadShape
		{
			Rect = 1,
			Circle = 2,
			Oval = 3,	  //椭圆形
			Polygon = 4   //多边形
		};

		//焊盘特定分组
		struct PadSpecialGroup
		{

		};

		//焊盘属元件封装类型分组
		struct PadPackageGroup
		{

		};

		//焊盘形状分组
		struct PadShapeGroup
		{
			PadShape m_padshape;     //焊盘形状
			vector<string> m_vPadNameSet;  //焊盘名称集合
		};

		//焊盘自定义分组
		struct PadCustomizeGroup
		{
			string m_CustomizeGroupName;
			vector<string> m_vPadNameSet;  //焊盘名称集合
		};

	public:
		PadGroupManager();
		PadGroupManager& operator=(PadGroupManager& ref);
		map<PadShape, PadShapeGroup> GetAllPadShapeGroup();
		map<string, PadCustomizeGroup> GetAllCustomizeGroup();
	private:
		map<PadShape, PadShapeGroup> m_pPadShapeGroupMger;          //形状分组管理
		map<string, PadCustomizeGroup> m_pPadCustomizeGroupMger;	//自定义分组管理

	};

	/*
	* 类名：DetectionPadData
	* 创建日期： 2023/10/13
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	焊盘参数类
	*	@version 1.0
	*/
	class AS_EXPORTS DetectionPadData :public DetectionDataBase
	{
	public:
		DetectionPadData();
		DetectionPadData& operator=(DetectionPadData& ref);

		//焊盘分组标识
		struct Groupflag
		{
			bool m_FlagofPadCustomizeGroup;
			bool m_FlagofPadShapeGroup;
			Groupflag()
			{
				m_FlagofPadCustomizeGroup = false;
				m_FlagofPadShapeGroup = false;
			}
		};
		void SetPadName(string string);
		string GetPadName();
		void SetPadArea(double area);
		double GetPadArea();

	private:
		string m_PadName;	//焊盘名称
		double m_PadArea;   //焊盘面积
		PadGroupManager::PadShape m_padshape_grpname; //焊盘形状组标识
		string m_custom_grpname;     //焊盘自定义组标识
		Groupflag m_groupcondition;  //分组情况
	};

	/*
	* 类名：PadDataSet
	* 创建日期： 2023/10/13
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	焊盘数据集类
	*	@version 1.0
	*/
	class AS_EXPORTS PadDataSet
	{
	public:
		PadDataSet();
		map<string, shared_ptr<DetectionPadData>> GetAllPadData();
		shared_ptr<DetectionPadData> GetSinglePadData(string name);
		bool FindSinglePadData(string name);
		void InsertSinglePadData(string name, shared_ptr<DetectionPadData> padData);
		void DeleteSinglePadData(string name);

		shared_ptr<PadGroupManager> GetPadGroupManager();
	private:
		map<string, shared_ptr<DetectionPadData>> m_pDetectionPadDataSet;
		shared_ptr<PadGroupManager> m_pPadGroupManager;
		map<string, shared_ptr<ImportPadData>> m_pImportPadDataSet;
	};
}

#endif