#ifndef AS_CADCORE_HPP
#define AS_CADCORE_HPP

//#include "as/ComponentCore.hpp"
#include "as/BaseBoardCore.hpp"

namespace as
{
	class DetectionPointData;
	class CADDetectionData;
}
namespace boost
{
	namespace serialization
	{
		template <class Archive>
		extern void serialize(Archive& ar, as::DetectionPointData& val, const unsigned int version);

		template <class Archive>
		extern void serialize(Archive& ar, as::CADDetectionData& val, const unsigned int version);
	}
}

namespace as
{
	/*
	* ������DetectionDataBase
	* �������ڣ� 2023/10/13
	* By ypk
	*	@file	CADCore.hpp
	*	@brief	CAD���ݻ���
	*	@version 1.0
	*/
	class AS_EXPORTS DetectionDataBase
	{
	public:
		DetectionDataBase();
		DetectionDataBase& operator = (DetectionDataBase& ref);

		int GetBlockId();
		void SetBlockId(int id);

		int GetArrayId();
		void SetArrayId(int id);

		Point GetBodyPosition();
		void SetBodyPosition(Point pos);

		double GetBodyWidth();
		void SetBodyWidth(double width);

		double GetBodyHeight();
		void SetBodyHeight(double height);

		double GetAngle();
		void SetAngle(double angle);

		bool GetSkip();
		void SetSkip(bool skip);

		bool GetCompleteDetection();
		void SetCompleteDetection(bool complete_detection);

	protected:
		int m_nBlockId;						//��ID
		int m_nArrayId;						//ƴ��ID
		Point m_BodyPosition;				//��������
		double m_dBodyWidth;				//�����
		double m_dBodyHeight;				//�����
		double m_dAngle;					//�Ƕ�
		bool m_bSkip;						//����
		bool m_bCompleteDetection;			//PL
	};

	class AS_EXPORTS DetectionPointData : public DetectionDataBase
	{
	public:
		template <class Archive>
		friend void boost::serialization::serialize(Archive& ar, DetectionPointData& val, const unsigned int version);

		DetectionPointData();
		DetectionPointData& operator=(DetectionPointData& ref);

		int GetID();
		void SetID(int id);

		string GetStrRef();
		void SetStrRef(string ref);

		int GetComponentId();
		void SetComponentId(int id);

		string GetComponentType();
		void SetComponentType(string type);

		string GetComponentName();
		void SetComponentName(string name);

		Point GetCompPosition();
		void SetCompPosition(Point pos);

		string GetSmtName();
		void SetSmtName(string name);

		int GetSlotNum();
		void SetSlotNum(int num);

		string GetNozzleName();
		void SetNozzleName(string nozzle_name);

		//double GetRoiWidth();
		//void SetRoiWidth(double width);

		//double GetRoiHeight();
		//void SetRoiHeight(double height);

		/*void SetComponent(shared_ptr<Component> component_data);
		shared_ptr<Component> GetComponent();

		vector<DefectType> GetAllDefectType();*/

		void ComputeCompoSizeActualRange(double& comp_rangesize_width, double& comp_rangesize_height);
	private:
		int m_nId;							//ID
		string m_strRef;					//���
		int m_nCompId;						//Ԫ��ID
		string m_strCompType;				//Ԫ������
		string m_strCompName;               //Ԫ����
		Point m_Position;					//����
		string m_strSmtName;				//��Ƭ����
		int m_nSlotNum;						//վλ��
		string m_strNozzleName;				//����
		double m_dRoiWidth;					//��ѡ�������ã�
		double m_dRoiHeight;				//��ѡ�ߣ������ã�
		//shared_ptr<Component> m_cComponent; //Ԫ��
		vector<string> m_vPadNameList;      //�������Ƽ���
		bool m_bEnroll;                     //�Ƿ�ע��(������)
		bool m_bflagimportCad;              //�Ƿ�ΪCad��������ע���׼(������)
	};

	typedef vector<shared_ptr<DetectionPointData>> DetectionDataList;

	class AS_EXPORTS CADDetectionData
	{
	public:	
		template <class Archive>
		friend void boost::serialization::serialize(Archive& ar, CADDetectionData& val, const unsigned int version);

		CADDetectionData();
		CADDetectionData& operator=(CADDetectionData& ref);

		void InitDetectionDataList();
		map<int, map<int, DetectionDataList>>& GetAllDetectionDataList();

		map<int, DetectionDataList>& GetBlockDetectionDataList(int block_id);
		void InsertBlockDetectionPointData(int block_id, map<int, DetectionDataList> data);
		void DeleteBlockDetectionDataList(int block_id);
		bool FindSingleBlockDetectionDataList(int block_id);

		DetectionDataList& GetSingleArrayDetectionDataList(int block_id, int array_id);
		void InsertSingleArrayDetectionPointData(int block_id, int array_id, DetectionDataList detected_data);
		void DeleteSingleArrayDetectionDataList(int block_id, int array_id);
		bool FindSingleArrayDetectionPointData(int block_id, int array_id);

		shared_ptr<DetectionPointData> GetDetectionPointData(int block_id, int array_id, int serial_num);
		void InsertDetectionPointData(int block_id, int array_id, shared_ptr<DetectionPointData> detection_data);
		void DeleteDetectionPointData(int block_id, int array_id, int serial_num);
		bool FindDetectionPointData(int block_id, int array_id, int serial_num);
		bool FindDetectionPointName(int block_id, int array_id, string compname);
	private:	
		map<int, map<int, DetectionDataList>> m_mDetectionDataList;	//CAD�������� 
	};
}

#endif
