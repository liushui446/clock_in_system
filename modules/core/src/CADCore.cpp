#include "as/CADCore.hpp"
#include "as/ASContext.hpp"
#include "as/CoorTrans.hpp"
namespace as
{
	DetectionDataBase::DetectionDataBase()
	{
		m_nBlockId = 1;
		m_nArrayId = 1;
		m_dBodyWidth = 0;
		m_dBodyHeight = 0;
		m_dAngle = 0;
		m_bSkip = false;
		m_bCompleteDetection = false;
	}

	DetectionDataBase& DetectionDataBase::operator=(DetectionDataBase& ref)
	{
		this->m_nBlockId = ref.GetBlockId();
		this->m_nArrayId = ref.GetArrayId();
		this->m_BodyPosition = ref.GetBodyPosition();
		this->m_dBodyWidth = ref.GetBodyWidth();
		this->m_dBodyHeight = ref.GetBodyHeight();
		this->m_dAngle = ref.GetAngle();
		this->m_bSkip = ref.GetSkip();
		this->m_bCompleteDetection = ref.GetCompleteDetection();
		return *this;
	}

	int DetectionDataBase::GetBlockId()
	{
		return m_nBlockId;
	}

	void DetectionDataBase::SetBlockId(int id)
	{
		m_nBlockId = id;
	}

	int DetectionDataBase::GetArrayId()
	{
		return m_nArrayId;
	}

	void DetectionDataBase::SetArrayId(int id)
	{
		m_nArrayId = id;
	}

	Point DetectionDataBase::GetBodyPosition()
	{
		return m_BodyPosition;
	}

	void DetectionDataBase::SetBodyPosition(Point pos)
	{
		m_BodyPosition = pos;
	}

	double DetectionDataBase::GetBodyWidth()
	{
		return m_dBodyWidth;
	}

	void DetectionDataBase::SetBodyWidth(double width)
	{
		m_dBodyWidth = width;
	}

	double DetectionDataBase::GetBodyHeight()
	{
		return m_dBodyHeight;
	}

	void DetectionDataBase::SetBodyHeight(double height)
	{
		m_dBodyHeight = height;
	}

	double DetectionDataBase::GetAngle()
	{
		return m_dAngle;
	}

	void DetectionDataBase::SetAngle(double angle)
	{
		m_dAngle = angle;
	}

	bool DetectionDataBase::GetSkip()
	{
		return m_bSkip;
	}

	void DetectionDataBase::SetSkip(bool skip)
	{
		m_bSkip = skip;
	}

	bool DetectionDataBase::GetCompleteDetection()
	{
		return m_bCompleteDetection;
	}

	void DetectionDataBase::SetCompleteDetection(bool complete_detection)
	{
		m_bCompleteDetection = complete_detection;
	}

	DetectionPointData::DetectionPointData()
	{
		m_nId = 0;
		m_strRef = "";
		m_nCompId = 1;
		m_strCompType = "";
		m_strCompName = "";
		m_strSmtName = "";
		m_nSlotNum = 0;
		m_strNozzleName = "";
		m_dRoiWidth = 0;
		m_dRoiHeight = 0;
		//m_cComponent = nullptr;
		m_bEnroll = false;
		m_bflagimportCad = false;
	}

	DetectionPointData& DetectionPointData::operator=(DetectionPointData& ref)
	{
		this->m_nId = ref.GetID();
		this->m_strRef = ref.GetStrRef();
		this->m_nCompId = ref.GetComponentId();
		this->m_strCompType = ref.GetComponentType();
		this->m_strCompName = ref.GetComponentName();
		this->m_Position = ref.GetCompPosition();
		this->m_strSmtName = ref.GetSmtName();
		this->m_nSlotNum = ref.GetSlotNum();
		this->m_strNozzleName = ref.GetNozzleName();
		this->m_dAngle = ref.GetAngle();
		this->m_bSkip = ref.GetSkip();
		this->m_bCompleteDetection = ref.GetCompleteDetection();
		//this->m_dRoiWidth = ref.GetRoiWidth();
		//this->m_dRoiHeight = ref.GetRoiHeight();
		/*if (ref.GetComponent() != nullptr)
		{
			this->m_cComponent = make_shared<Component>();
			*this->m_cComponent = *ref.GetComponent();
		}
		else
		{
			this->m_cComponent = nullptr;
		}*/
		return *this;
	}

	int DetectionPointData::GetID()
	{
		return m_nId;
	}

	void DetectionPointData::SetID(int id)
	{
		m_nId = id;
	}

	string DetectionPointData::GetStrRef()
	{
		return m_strRef;
	}

	void DetectionPointData::SetStrRef(string ref)
	{
		m_strRef = ref;
	}

	int DetectionPointData::GetComponentId()
	{
		return m_nCompId;
	}

	void DetectionPointData::SetComponentId(int id)
	{
		m_nCompId = id;
	}

	string DetectionPointData::GetComponentType()
	{
		return m_strCompType;
	}

	void DetectionPointData::SetComponentType(string type)
	{
		m_strCompType = type;
	}

	string DetectionPointData::GetComponentName()
	{
		return m_strCompName;
	}

	void DetectionPointData::SetComponentName(string name)
	{
		m_strCompName = name;
	}

	Point DetectionPointData::GetCompPosition()
	{
		return m_Position;
	}

	void DetectionPointData::SetCompPosition(Point pos)
	{
		m_Position = pos;
	}

	string DetectionPointData::GetSmtName()
	{
		return m_strSmtName;
	}

	void DetectionPointData::SetSmtName(string name)
	{
		m_strSmtName = name;
	}

	int DetectionPointData::GetSlotNum()
	{
		return m_nSlotNum;
	}

	void DetectionPointData::SetSlotNum(int num)
	{
		m_nSlotNum = num;
	}

	string DetectionPointData::GetNozzleName()
	{
		return m_strNozzleName;
	}

	void DetectionPointData::SetNozzleName(string nozzle_name)
	{
		m_strNozzleName = nozzle_name;
	}

	/*double DetectionPointData::GetRoiWidth()
	{
		if (m_cComponent != nullptr)
		{
			return m_cComponent->ComputeCompoentWidth();
		}
		else
		{
			return 0;
		}
	}*/

	/*void DetectionPointData::SetRoiWidth(double width)
	{
		m_dRoiWidth = width;
	}*/

	/*double DetectionPointData::GetRoiHeight()
	{
		if (m_cComponent != nullptr)
		{
			return m_cComponent->ComputeCompoentHeight();
		}
		else
		{
			return 0;
		}
	}*/

	/*void DetectionPointData::SetRoiHeight(double height)
	{
		m_dRoiHeight = height;
	}*/

	/*void DetectionPointData::SetComponent(shared_ptr<Component> component_data)
	{
		m_cComponent = component_data;
	}

	shared_ptr<Component> DetectionPointData::GetComponent()
	{
		return m_cComponent;
	}*/

	/*vector<DefectType> DetectionPointData::GetAllDefectType()
	{
		vector<DefectType> defect_type;
		map<string, NoGoodParam> temp_ngparam = m_cComponent->GetAllNoGoodParam();
		for (auto iter = temp_ngparam.begin(); iter != temp_ngparam.end(); iter++)
		{
			defect_type.push_back(iter->second.GetDefectType());
		}
		return defect_type;
	}*/

	void DetectionPointData::ComputeCompoSizeActualRange(double& comp_rangesize_width, double& comp_rangesize_height)
	{
		//旋转计算角度
		double temp_angle = 0;
		int num = abs(m_dAngle) / 180;
		if (m_dAngle > 0)
		{
			temp_angle = m_dAngle - num * 180;
		}
		else
		{
			temp_angle = -(abs(m_dAngle) - num * 180);
			temp_angle = 180 - abs(temp_angle);
		}

		if (temp_angle - 90 > 1e-3)
		{
			temp_angle = 180 - temp_angle;
		}

		//重新计算元件大小
		//comp_rangesize_width = cos(temp_angle * PI / 180) * GetRoiWidth() + sin(temp_angle * PI / 180) * GetRoiHeight();
		//comp_rangesize_height = sin(temp_angle * PI / 180) * GetRoiWidth() + cos(temp_angle * PI / 180) * GetRoiHeight();
	}

	CADDetectionData::CADDetectionData()
	{
		map<int, DetectionDataList> single_detection_data_list;
		single_detection_data_list.insert(pair<int, DetectionDataList>(1, DetectionDataList()));
		m_mDetectionDataList.insert(pair<int, map<int, DetectionDataList>>(1, single_detection_data_list));
	}

	CADDetectionData& CADDetectionData::operator=(CADDetectionData& ref)
	{
		this->m_mDetectionDataList.clear();
		map<int, map<int, DetectionDataList>> all_detect_data_list = ref.GetAllDetectionDataList();
		for (auto all_detect_data_iter = all_detect_data_list.begin(); all_detect_data_iter != all_detect_data_list.end(); all_detect_data_iter++)
		{
			if (!FindSingleBlockDetectionDataList(all_detect_data_iter->first))
			{
				//创建块数据
				map<int, DetectionDataList> single_detection_data_list;
				single_detection_data_list.insert(pair<int, DetectionDataList>(1, DetectionDataList()));
				InsertBlockDetectionPointData(all_detect_data_iter->first, single_detection_data_list);
			}

			map<int, DetectionDataList> single_detect_data_list = all_detect_data_iter->second;
			for (auto single_detect_data_iter = single_detect_data_list.begin(); single_detect_data_iter != single_detect_data_list.end(); single_detect_data_iter++)
			{
				if (!FindSingleArrayDetectionPointData(all_detect_data_iter->first, single_detect_data_iter->first))
				{
					//创建拼板数据
					this->m_mDetectionDataList.find(all_detect_data_iter->first)->second.insert(pair<int, DetectionDataList>(single_detect_data_iter->first, DetectionDataList()));
				}

				for (int index = 0; index < single_detect_data_iter->second.size(); index++)
				{
					shared_ptr<DetectionPointData> data = make_shared<DetectionPointData>();
					*data = *single_detect_data_iter->second[index];
					//插入检测点数据
					InsertDetectionPointData(all_detect_data_iter->first, single_detect_data_iter->first, data);
				}
			}
		}
		return *this;
	}

	void CADDetectionData::InitDetectionDataList()
	{
		m_mDetectionDataList.clear();
		map<int, DetectionDataList> single_detection_data_list;
		single_detection_data_list.insert(pair<int, DetectionDataList>(1, DetectionDataList()));
		m_mDetectionDataList.insert(pair<int, map<int, DetectionDataList>>(1, single_detection_data_list));
	}

	map<int, map<int, DetectionDataList>>& CADDetectionData::GetAllDetectionDataList()
	{
		return m_mDetectionDataList;
	}

	map<int, DetectionDataList>& CADDetectionData::GetBlockDetectionDataList(int block_id)
	{
		return m_mDetectionDataList.find(block_id)->second;
	}

	void CADDetectionData::InsertBlockDetectionPointData(int block_id, map<int, DetectionDataList> data)
	{
		m_mDetectionDataList.insert(pair<int, map<int, DetectionDataList>>(block_id, data));
	}

	void CADDetectionData::DeleteBlockDetectionDataList(int block_id)
	{
		m_mDetectionDataList.erase(m_mDetectionDataList.find(block_id));
	}

	bool CADDetectionData::FindSingleBlockDetectionDataList(int block_id)
	{
		if (m_mDetectionDataList.find(block_id) == m_mDetectionDataList.end())
		{
			return false;
		}
		return true;
	}

	DetectionDataList& CADDetectionData::GetSingleArrayDetectionDataList(int block_id, int array_id)
	{
		return m_mDetectionDataList.find(block_id)->second.find(array_id)->second;
	}

	void CADDetectionData::InsertSingleArrayDetectionPointData(int block_id, int array_id, DetectionDataList detected_data)
	{
		m_mDetectionDataList.find(block_id)->second.insert(pair<int, DetectionDataList>(array_id, detected_data));
	}

	void CADDetectionData::DeleteSingleArrayDetectionDataList(int block_id, int array_id)
	{
		m_mDetectionDataList.find(block_id)->second.erase(m_mDetectionDataList.find(block_id)->second.find(array_id));
	}

	bool CADDetectionData::FindSingleArrayDetectionPointData(int block_id, int array_id)
	{
		if (!FindSingleBlockDetectionDataList(block_id) || GetBlockDetectionDataList(block_id).find(array_id) == GetBlockDetectionDataList(block_id).end())
		{
			return false;
		}
		return true;
	}

	shared_ptr<DetectionPointData> CADDetectionData::GetDetectionPointData(int block_id, int array_id, int serial_num)
	{
		if (FindDetectionPointData(block_id, array_id, serial_num))
		{
			serial_num -= 1;
			return GetSingleArrayDetectionDataList(block_id, array_id)[serial_num];
		}
		return nullptr;
	}

	void CADDetectionData::InsertDetectionPointData(int block_id, int array_id, shared_ptr<DetectionPointData> detection_data)
	{
		m_mDetectionDataList.find(block_id)->second.find(array_id)->second.push_back(detection_data);
	}

	void CADDetectionData::DeleteDetectionPointData(int block_id, int array_id, int serial_num)
	{
		if (FindDetectionPointData(block_id, array_id, serial_num))
		{
			m_mDetectionDataList.find(block_id)->second.find(array_id)->second.erase(m_mDetectionDataList.find(block_id)->second.find(array_id)->second.begin() + serial_num - 1);
		}
	}

	bool CADDetectionData::FindDetectionPointData(int block_id, int array_id, int serial_num)
	{
		if (!FindSingleArrayDetectionPointData(block_id, array_id) || GetSingleArrayDetectionDataList(block_id, array_id).size() < serial_num)
		{
			return false;
		}
		return true;
	}
	//查询CAD中是否存在某个元件
	bool CADDetectionData::FindDetectionPointName(int block_id, int array_id, string compname)
	{
		if (FindSingleArrayDetectionPointData(block_id, array_id))
		{
			vector<shared_ptr<DetectionPointData>> DPlist = m_mDetectionDataList.find(block_id)->second.find(array_id)->second;
			for (int ind = 0;ind < DPlist.size();ind++)
			{
				if (DPlist[ind]->GetComponentName() == compname)
				{
					return true;
				}
			}
		}
		return false;
	}
}