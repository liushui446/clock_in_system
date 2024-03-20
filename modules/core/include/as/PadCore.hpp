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

	/* ������ImportPadData
	* �������ڣ� 2023/10/17
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	��Ԥ������������
	*	@version 1.0
	*/
	class AS_EXPORTS ImportPadData
	{
	public:
		ImportPadData();
		ImportPadData& operator=(ImportPadData& ref);

	private:
		string m_PadId;		//����ID
		PadShape m_shape;	//������״
		double m_angle;		//���̽Ƕ�
		Point m_pos;		//����λ��
		double m_dlength;	//���̳�
		double m_dwidth;    //���̿�
	};


	/* ������PadGroupManager
	* �������ڣ� 2023/10/13
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	���̷��������
	*	@version 1.0
	*/
	class AS_EXPORTS PadGroupManager
	{
	public:

		enum class PadShape
		{
			Rect = 1,
			Circle = 2,
			Oval = 3,	  //��Բ��
			Polygon = 4   //�����
		};

		//�����ض�����
		struct PadSpecialGroup
		{

		};

		//������Ԫ����װ���ͷ���
		struct PadPackageGroup
		{

		};

		//������״����
		struct PadShapeGroup
		{
			PadShape m_padshape;     //������״
			vector<string> m_vPadNameSet;  //�������Ƽ���
		};

		//�����Զ������
		struct PadCustomizeGroup
		{
			string m_CustomizeGroupName;
			vector<string> m_vPadNameSet;  //�������Ƽ���
		};

	public:
		PadGroupManager();
		PadGroupManager& operator=(PadGroupManager& ref);
		map<PadShape, PadShapeGroup> GetAllPadShapeGroup();
		map<string, PadCustomizeGroup> GetAllCustomizeGroup();
	private:
		map<PadShape, PadShapeGroup> m_pPadShapeGroupMger;          //��״�������
		map<string, PadCustomizeGroup> m_pPadCustomizeGroupMger;	//�Զ���������

	};

	/*
	* ������DetectionPadData
	* �������ڣ� 2023/10/13
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	���̲�����
	*	@version 1.0
	*/
	class AS_EXPORTS DetectionPadData :public DetectionDataBase
	{
	public:
		DetectionPadData();
		DetectionPadData& operator=(DetectionPadData& ref);

		//���̷����ʶ
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
		string m_PadName;	//��������
		double m_PadArea;   //�������
		PadGroupManager::PadShape m_padshape_grpname; //������״���ʶ
		string m_custom_grpname;     //�����Զ������ʶ
		Groupflag m_groupcondition;  //�������
	};

	/*
	* ������PadDataSet
	* �������ڣ� 2023/10/13
	* By ypk
	*	@file	PadCore.hpp
	*	@brief	�������ݼ���
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