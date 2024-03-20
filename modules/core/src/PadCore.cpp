#include "as/PadCore.hpp"

namespace as
{
	DetectionPadData::DetectionPadData()
	{
		m_PadArea = 0;
	}

	DetectionPadData& DetectionPadData::operator=(DetectionPadData& ref)
	{
		this->m_PadArea = ref.GetPadArea();
		this->m_PadName = ref.GetPadName();
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

	void DetectionPadData::SetPadName(string name)
	{
		m_PadName = name;
	}

	string DetectionPadData::GetPadName()
	{
		return m_PadName;
	}

	void DetectionPadData::SetPadArea(double area)
	{
		m_PadArea = area;
	}

	double DetectionPadData::GetPadArea()
	{
		return m_PadArea;
	}

	PadDataSet::PadDataSet()
	{
		m_pDetectionPadDataSet.clear();
	}

	map<string, shared_ptr<DetectionPadData>> PadDataSet::GetAllPadData()
	{
		return m_pDetectionPadDataSet;
	}

	shared_ptr<DetectionPadData> PadDataSet::GetSinglePadData(string name)
	{
		if (m_pDetectionPadDataSet.find(name) != m_pDetectionPadDataSet.end())
		{
			return m_pDetectionPadDataSet.find(name)->second;
		}
		else
		{
			return nullptr;
		}
	}

	bool PadDataSet::FindSinglePadData(string name)
	{
		if (m_pDetectionPadDataSet.find(name) != m_pDetectionPadDataSet.end())
		{
			return true;
		}
		return false;
	}

	void PadDataSet::InsertSinglePadData(string name, shared_ptr<DetectionPadData> padData)
	{
		if (m_pDetectionPadDataSet.find(name) == m_pDetectionPadDataSet.end())
		{
			m_pDetectionPadDataSet.insert(pair<string, shared_ptr<DetectionPadData>>(name, padData));
		}
	}

	void PadDataSet::DeleteSinglePadData(string name)
	{
		if (m_pDetectionPadDataSet.find(name) != m_pDetectionPadDataSet.end())
		{
			m_pDetectionPadDataSet.erase(m_pDetectionPadDataSet.find(name));
		}
	}
	shared_ptr<PadGroupManager> PadDataSet::GetPadGroupManager()
	{
		return m_pPadGroupManager;
	}

	PadGroupManager::PadGroupManager()
	{
		m_pPadShapeGroupMger.clear();
		m_pPadCustomizeGroupMger.clear();
	}
	map<PadGroupManager::PadShape, PadGroupManager::PadShapeGroup> PadGroupManager::GetAllPadShapeGroup()
	{
		return m_pPadShapeGroupMger;
	}

	PadGroupManager& PadGroupManager::operator=(PadGroupManager& ref)
	{
		this->m_pPadCustomizeGroupMger = ref.GetAllCustomizeGroup();
		this->m_pPadShapeGroupMger = ref.GetAllPadShapeGroup();
		return *this;
	}

	map<string, PadGroupManager::PadCustomizeGroup> PadGroupManager::GetAllCustomizeGroup()
	{
		return m_pPadCustomizeGroupMger;
	}
}