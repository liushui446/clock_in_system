#include "as/BaseBoardCore.hpp"
#include <as/CoorTrans.hpp>

namespace as
{
	OFFSET::OFFSET()
	{
		m_x = 0;
		m_y = 0;
		m_r = 0;
	}

	OFFSET::~OFFSET()
	{
	}

	double OFFSET::GetOffsetX()
	{
		return m_x;
	}

	OFFSET& OFFSET::operator=(OFFSET& ref)
	{
		this->m_x = ref.GetOffsetX();
		this->m_y = ref.GetOffsetY();
		this->m_r = ref.GetOffsetR();
		return *this;
	}

	/*OFFSET& OFFSET::operator=(sm::OFFSET& ref)
	{
		this->m_x = ref.X;
		this->m_y = ref.Y;
		this->m_r = ref.R;
		return *this;
	}*/

	void OFFSET::SetOffsetX(double offset_x)
	{
		m_x = offset_x;
	}

	double OFFSET::GetOffsetY()
	{
		return m_y;
	}

	void OFFSET::SetOffsetY(double offset_y)
	{
		m_y = offset_y;
	}

	double OFFSET::GetOffsetR()
	{
		return m_r;
	}

	void OFFSET::SetOffsetR(double offset_r)
	{
		m_r = offset_r;
	}

	FiducialMark::FiducialMark()
	{
		m_fid_num = 0;
		m_FiducialType = BoardMarkType::FIDUCIAL_NONE;
		m_MarkFlag = APIErrCode::MarkNotCal;
	}

	FiducialMark& FiducialMark::operator=(FiducialMark& ref)
	{
		this->m_fid_num = ref.GetFidMarkNum();
		this->m_FiducialType = ref.GetFidMarkType();
		this->m_vec_fid_pos.clear();	
		this->m_vec_fid_pos = ref.GetAllFiducialPos();
		this->m_MarkFlag = ref.GetFiducialMarkFlag();
		return *this;
	}

	/*FiducialMark& FiducialMark::operator=(sm::FiducialMark& ref)
	{
		this->m_fid_num = ref.GetFidMarkNum();
		this->m_FiducialType = static_cast<BoardMarkType>((int)ref.GetFidMarkType());
		this->m_vec_fid_pos.clear();
		for (int index = 0; index < ref.GetFidMarkNum(); index++)
		{
			FiducialMark::FiducialPos fid_pos;
			fid_pos.x = ref.GetFiducialXYPos(index).x;
			fid_pos.y = ref.GetFiducialXYPos(index).y;
			this->m_vec_fid_pos.push_back(fid_pos);
		}
		this->m_MarkFlag = ref.GetFiducialMarkFlag();
		return *this;
	}*/

	int FiducialMark::GetFidMarkNum()
	{
		return m_fid_num;
	}

	void FiducialMark::SetFidMarkNum(int num)
	{
		m_fid_num = num;
	}

	BoardMarkType FiducialMark::GetFidMarkType()
	{
		return m_FiducialType;
	}
	void FiducialMark::SetFidMarkType(BoardMarkType Mark_type)
	{
		m_FiducialType = Mark_type;
		return;
	}

	APIErrCode FiducialMark::GetFiducialMarkFlag()
	{
		return m_MarkFlag;
	}

	void FiducialMark::SetFiducialMarkFlag(APIErrCode mark_flag)
	{
		m_MarkFlag = mark_flag;
		return;
	}

	vector<FiducialMark::FiducialPos> FiducialMark::GetAllFiducialPos()
	{
		return m_vec_fid_pos;
	}

	void FiducialMark::ClearAllFiducialPos()
	{
		m_vec_fid_pos.clear();
	}

	Point FiducialMark::GetFiducialXYPos(int num)
	{
		Point pos = Point(0, 0);
		if (num < m_vec_fid_pos.size())
		{
			pos.setPointX(m_vec_fid_pos[num].x);
			pos.setPointY(m_vec_fid_pos[num].y);
		}
		return pos;
	}

	Point FiducialMark::GetFiducialCalXYPos(int num)
	{
		Point pos = Point(0, 0);
		if (num < m_vec_fid_pos.size())
		{
			pos.setPointX(m_vec_fid_pos[num].mark_cal_posx);
			pos.setPointY(m_vec_fid_pos[num].mark_cal_posy);
		}
		return pos;
	}

	void FiducialMark::SetFiducialPos(int num, double x, double y)
	{
		if (num < m_vec_fid_pos.size())
		{
			m_vec_fid_pos[num].x = x;
			m_vec_fid_pos[num].y = y;
		}
	}

	void FiducialMark::SetFiducialXPos(int num, double x)
	{
		if (num < m_vec_fid_pos.size())
		{
			m_vec_fid_pos[num].x = x;
		}
	}

	void FiducialMark::SetFiducialYPos(int num, double y)
	{
		if (num < m_vec_fid_pos.size())
		{
			m_vec_fid_pos[num].y = y;
		}
	}

	void FiducialMark::SetFiducialCalPos(int num, double x, double y)
	{
		if (num < m_vec_fid_pos.size())
		{
			m_vec_fid_pos[num].mark_cal_posx = x;
			m_vec_fid_pos[num].mark_cal_posy = y;
		}
	}

	void FiducialMark::SetFiducialCalXPos(int num, double x)
	{
		if (num < m_vec_fid_pos.size())
		{
			m_vec_fid_pos[num].mark_cal_posx = x;
		}
	}

	void FiducialMark::SetFiducialCalYPos(int num, double y)
	{
		if (num < m_vec_fid_pos.size())
		{
			m_vec_fid_pos[num].mark_cal_posy = y;
		}
	}

	MarkPart& FiducialMark::GetMarkPart(int mun)
	{
		return m_vec_fid_pos[mun].m_cMarkPart;
	}
	void FiducialMark::InsertFiducialPos()
	{
		FiducialPos pos;
		m_vec_fid_pos.push_back(pos);
	}

	void FiducialMark::SetImageData(int num, vector<unsigned char> image_data)
	{
		m_vec_fid_pos[num].m_vImageData = image_data;
	}

	vector<unsigned char> FiducialMark::GetImageData(int num)
	{
		return m_vec_fid_pos[num].m_vImageData;
	}

	//void FiducialMark::SetStandImageFileName(int num, string file_name)
	//{
	//	m_vec_fid_pos[num].m_strFileName = file_name;
	//}

	//string FiducialMark::GetStandImageFileName(int num)
	//{
	//	return m_vec_fid_pos[num].m_strFileName;
	//}

	AcceptMark::AcceptMark()
	{
		m_AcceptMarkLogic = LogicType::LOGIC_WHITE;
		m_MarkFlag = MarkNotCal;
	}

	AcceptMark::~AcceptMark()
	{
	}

	AcceptMark& AcceptMark::operator=(AcceptMark& ref)
	{
		this->m_AcceptMarkLogic = ref.GetAcceptMarkLogic();
		this->m_AcceptMarkPos = ref.GetAcceptMarkPos();
		this->m_MarkFlag = ref.GetAcceptMarkFlag();
		this->m_AcceptMarkPart = ref.GetAcceptMarkPart();
		return *this;
	}

	/*AcceptMark& AcceptMark::operator=(sm::AcceptMark& ref)
	{
		this->m_AcceptMarkLogic = static_cast<LogicType>((int)ref.GetAcceptMarkLogic());
		this->m_AcceptMarkPos = ref.GetAcceptMarkPos();
		this->m_MarkFlag = ref.GetAcceptMarkFlag();
		return *this;
	}*/

	LogicType AcceptMark::GetAcceptMarkLogic()
	{
		return m_AcceptMarkLogic;
	}

	void AcceptMark::SetAcceptMarkLogic(LogicType logic_type)
	{
		m_AcceptMarkLogic = logic_type;
		return;
	}

	Point AcceptMark::GetAcceptMarkPos()
	{
		return m_AcceptMarkPos;
	}

	void AcceptMark::SetAcceptMarkPos(double pos_x, double pos_y)
	{
		m_AcceptMarkPos.x = pos_x;
		m_AcceptMarkPos.y = pos_y;
		return;
	}

	APIErrCode AcceptMark::GetAcceptMarkFlag()
	{
		return m_MarkFlag;
	}

	void AcceptMark::SetAcceptMarkFlag(APIErrCode mark_flag)
	{
		m_MarkFlag = mark_flag;
		return;
	}

	MarkPart& AcceptMark::GetAcceptMarkPart()
	{
		return m_AcceptMarkPart;
	}

	BadMark::BadMark()
	{
		m_BadMarkLogic = LogicType::LOGIC_WHITE;
		m_BadMarkOffset.X = 0;
		m_BadMarkOffset.Y = 0;
		m_MarkFlag = MarkNotCal;
	}

	BadMark::~BadMark()
	{
	}

	BadMark& BadMark::operator=(BadMark& ref)
	{
		this->m_BadMarkLogic = ref.GetBadMarkLogic();
		this->m_BadMarkOffset.X = ref.GetBadMarkOffsetX();
		this->m_BadMarkOffset.Y = ref.GetBadMarkOffsetY();
		this->m_BadMarkPos = ref.GetBadMarkPos();
		this->m_MarkFlag = ref.GetBadMarkFlag();
		this->m_badMarkPart = ref.GetBadMarkPart();
		return *this;
	}

	/*BadMark& BadMark::operator=(sm::BadMark& ref)
	{
		this->m_BadMarkLogic = static_cast<LogicType>((int)ref.GetBadMarkLogic());
		this->m_BadMarkOffset.X = ref.GetBadMarkOffsetX();
		this->m_BadMarkOffset.Y = ref.GetBadMarkOffsetY();
		this->m_BadMarkPos = ref.GetBadMarkPos();
		this->m_MarkFlag = ref.GetBadMarkFlag();
		return *this;
	}*/

	LogicType BadMark::GetBadMarkLogic()
	{
		return m_BadMarkLogic;
	}

	void BadMark::SetBadMarkLogic(LogicType logic_type)
	{
		m_BadMarkLogic = logic_type;
		return;
	}

	double BadMark::GetBadMarkOffsetX()
	{
		return m_BadMarkOffset.X;
	}

	double BadMark::GetBadMarkOffsetY()
	{
		return m_BadMarkOffset.Y;
	}

	void BadMark::SetBadBadMarkOffset(double x_offset, double y_offset)
	{
		m_BadMarkOffset.X = x_offset;
		m_BadMarkOffset.Y = y_offset;
		return;
	}

	bool FiducialMark::GetFiducialPosReachFlag(int num)
	{
		return m_vec_fid_pos[num].Reachable;
	}

	void FiducialMark::SetFiducialPosReachFlag(int num, bool reach)
	{
		m_vec_fid_pos[num].Reachable = reach;
	}

	Point FiducialMark::GetFidMechStandardXYPos(int blockid, int arryid, int index, Station station)
	{
		Point Tar_point = { 0,0 };
		// 基准点坐标 
		Point Fid_pos = { m_vec_fid_pos[index].x, m_vec_fid_pos[index].y };

		// 基准点坐标转换到机械坐标
		as::CoorTrans coor_trans;
		CoordinateTransfParameters coor_param;
		coor_param.SourceCoor = Fid_pos;
		coor_param.SourceR = 0;
		coor_param.BlockNum = blockid;
		coor_param.ArrayNum = arryid;
		coor_param.m_cBaseBoard = ASContext::GetInstance().GetBaseBoard();
		coor_param.CoordinateKind = ASContext::GetInstance().GetBaseBoard()->GetCoordinateType();
		coor_param.station = station;
		if (m_FiducialType == BoardMarkType::FIDUCIAL_ARRAY)
		{
			coor_param.SetCoordinateSystem(CoordinateSystem::ArrayCoorSystem, CoordinateSystem::MechanicalCoorSystem);
			coor_trans.ArrayToMechanicalStageConvert(coor_param);
			Tar_point = coor_param.TargetCoor;
		}
		else if (m_FiducialType == BoardMarkType::FIDUCIAL_GLOBAL) 
		{
			coor_param.SetCoordinateSystem(CoordinateSystem::BlockCoorSystem, CoordinateSystem::MechanicalCoorSystem);
			coor_trans.ArrayToMechanicalStageConvert(coor_param);
			Tar_point = coor_param.TargetCoor;
		}
		return Tar_point;
	}

	void FiducialMark::MarkCompensationCal(Point& tar_point, double& angle_offset, int blockid, int arryid, Station station)
	{
		vector<int> compens_vec;
		for (int i = 0; i < m_fid_num; i++)
		{
			if (m_vec_fid_pos[i].Reachable)
			{
				compens_vec.push_back(i);
			}
		}

		switch (compens_vec.size())
		{
		case 1:
		{
			int first = compens_vec[0];

			//单Mark点补偿角度输出为0
			//元件位置+实际Mark点位置-理论Mark点位置(机械坐标系)	
			tar_point.x = tar_point.x + m_vec_fid_pos.at(first).mark_cal_posx - GetFidMechStandardXYPos(blockid, arryid, first, station).x;
			tar_point.y = tar_point.y + m_vec_fid_pos.at(first).mark_cal_posy - GetFidMechStandardXYPos(blockid, arryid, first, station).y;
			break;
		}
		case 2:
		{
			int first = compens_vec[0];
			int second = compens_vec[1];
			//两个Mark点所在直线实际倾斜角以及理论倾斜角
			double actual_angle = MarkAngleArctanCal(m_vec_fid_pos.at(first).mark_cal_posx - m_vec_fid_pos.at(second).mark_cal_posx, m_vec_fid_pos.at(first).mark_cal_posy - m_vec_fid_pos.at(second).mark_cal_posy);
			double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
			angle_offset = angle_offset + (actual_angle - theoretical_angle) * 180 / PI;
			//计算补偿后元件坐标
			double mount_theoretical_angle = MarkAngleArctanCal(tar_point.x - GetFidMechStandardXYPos(blockid, arryid, first, station).x, tar_point.y - GetFidMechStandardXYPos(blockid, arryid, first, station).y);
			double mount_actual_angle = actual_angle - theoretical_angle + mount_theoretical_angle;
			double twopoint_distance = sqrt(pow(tar_point.x - GetFidMechStandardXYPos(blockid, arryid, first, station).x, 2) + pow(tar_point.y - GetFidMechStandardXYPos(blockid, arryid, first, station).y, 2));
			double dis_actual = sqrt(pow(m_vec_fid_pos.at(first).mark_cal_posx - m_vec_fid_pos.at(second).mark_cal_posx, 2) + pow(m_vec_fid_pos.at(first).mark_cal_posy - m_vec_fid_pos.at(second).mark_cal_posy, 2));
			double dis_theroy = sqrt(pow(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, 2) + pow(GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y, 2));
			double ratio = 1;
			if (!(dis_actual - 0 < 1e-3 || dis_theroy - 0 < 1e-3))
			{
				ratio = dis_actual / dis_theroy;
			}
			if (ratio < 0.5 || ratio > 1.5)
			{
				ratio = 1;
			}
			tar_point.x = twopoint_distance * ratio * cos(mount_actual_angle) + m_vec_fid_pos.at(first).mark_cal_posx;
			tar_point.y = twopoint_distance * ratio * sin(mount_actual_angle) + m_vec_fid_pos.at(first).mark_cal_posy;
			break;
		}
		case 3:
		{
			int first = compens_vec[0];
			int second = compens_vec[1];
			int third = compens_vec[2];
			//三个Mark点确定所在圆的圆心
			Point actual_center = MarkCircleCenterCal(GetFiducialCalXYPos(first), GetFiducialCalXYPos(second), GetFiducialCalXYPos(third));
			Point theoretical_center = MarkCircleCenterCal(GetFidMechStandardXYPos(blockid, arryid, first, station), GetFidMechStandardXYPos(blockid, arryid, second, station), GetFidMechStandardXYPos(blockid, arryid, third, station));

			if (fabs(actual_center.x - DBL_MAX) < 1e-3 || fabs(theoretical_center.x - DBL_MAX) < 1e-3)
			{
				double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFiducialCalXYPos(first).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
				double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
				angle_offset = angle_offset + (actual_angle - theoretical_angle) * 180 / PI;
				//计算补偿后元件坐标
				double mount_theoretical_angle = MarkAngleArctanCal(tar_point.x - GetFidMechStandardXYPos(blockid, arryid, first, station).x, tar_point.y - GetFidMechStandardXYPos(blockid, arryid, first, station).y);
				double mount_actual_angle = actual_angle - theoretical_angle + mount_theoretical_angle;
				double twopoint_distance = sqrt(pow(tar_point.x - GetFidMechStandardXYPos(blockid, arryid, first, station).x, 2) + pow(tar_point.y - GetFidMechStandardXYPos(blockid, arryid, first, station).y, 2));
				tar_point.x = twopoint_distance * cos(mount_actual_angle) + GetFiducialCalXYPos(first).x;
				tar_point.y = twopoint_distance * sin(mount_actual_angle) + GetFiducialCalXYPos(first).y;
				return;
			}


			double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - actual_center.x, GetFiducialCalXYPos(first).y - actual_center.y);
			double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - theoretical_center.x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - theoretical_center.y);
			angle_offset = angle_offset + (actual_angle - theoretical_angle) * 180 / PI;

			tar_point.x += actual_center.x - theoretical_center.x;
			tar_point.y += actual_center.y - theoretical_center.y;

			break;
		}
		case 4:
		{
			int first = compens_vec[0];
			int second = compens_vec[1];
			int third = compens_vec[2];
			int forth = compens_vec[3];
			//四个Mark点补偿
			vector<Point> actual_center_set;
			vector<Point> theoretical_center_set;
			for (size_t i = 0; i < 4; i++)
			{
				vector<int> fidindex = { first,second,third,forth };
				fidindex.erase(fidindex.begin() + i);

				Point actual_center = MarkCircleCenterCal(GetFiducialCalXYPos(fidindex.at(0)), GetFiducialCalXYPos((fidindex.at(1))), GetFiducialCalXYPos(fidindex.at(2)));
				Point theoretical_center = MarkCircleCenterCal(GetFidMechStandardXYPos(blockid, arryid, fidindex.at(first), station), GetFidMechStandardXYPos(blockid, arryid, fidindex.at(second), station), GetFidMechStandardXYPos(blockid, arryid, fidindex.at(third), station));

				if (fabs(actual_center.x - DBL_MAX) < 1e-3 || fabs(theoretical_center.x - DBL_MAX) < 1e-3)
					continue;

				actual_center_set.push_back(actual_center);
				theoretical_center_set.push_back(theoretical_center);
			}

			if (actual_center_set.size() == 0 || theoretical_center_set.size() == 0)
			{
				double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFiducialCalXYPos(first).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
				double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
				angle_offset = angle_offset + (actual_angle - theoretical_angle) * 180 / PI;
				//计算补偿后元件坐标
				double mount_theoretical_angle = MarkAngleArctanCal(tar_point.x - GetFidMechStandardXYPos(blockid, arryid, first, station).x, tar_point.y - GetFidMechStandardXYPos(blockid, arryid, first, station).y);
				double mount_actual_angle = actual_angle - theoretical_angle + mount_theoretical_angle;
				double twopoint_distance = sqrt(pow(tar_point.x - GetFidMechStandardXYPos(blockid, arryid, first, station).x, 2) + pow(tar_point.y - GetFidMechStandardXYPos(blockid, arryid, first, station).y, 2));
				tar_point.x = twopoint_distance * cos(mount_actual_angle) + GetFiducialCalXYPos(first).x;
				tar_point.y = twopoint_distance * sin(mount_actual_angle) + GetFiducialCalXYPos(first).y;
				return;
			}

			Point actual_center;
			Point theoretical_center;
			for (size_t i = 0; i < actual_center_set.size(); i++)
			{
				actual_center = actual_center + actual_center_set[i];
				theoretical_center = theoretical_center + theoretical_center_set[i];
			}
			actual_center.x /= actual_center_set.size(), actual_center.y /= actual_center_set.size();
			theoretical_center.x /= theoretical_center_set.size(), theoretical_center.y /= theoretical_center_set.size();

			double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - actual_center.x, GetFiducialCalXYPos(first).y - actual_center.y);
			double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - theoretical_center.x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - theoretical_center.y);
			angle_offset = angle_offset + (actual_angle - theoretical_angle) * 180 / PI;

			tar_point.x += actual_center.x - theoretical_center.x;
			tar_point.y += actual_center.y - theoretical_center.y;
			break;
		}
		default:
			break;
		}
	}

	/**
	 * @brief 求解反正切函数，即arctan(y/x)
	 * @param x 三角形x方向边长
	 * @param y 三角形y方向边长
	 * @return 返回反正切所计算的角度 theat范围:[0,2PI]
	*/
	double FiducialMark::MarkAngleArctanCal(double x, double y)
	{
		//处于坐标轴上
		if ((x < 1e-4) && (x > -1e-4)) {
			if ((y < 1e-4) && (y > -1e-4)) {
				return 0.0;
			}
			else if (y > 0.0) {
				return PI / 2.0;
			}
			else {
				return 3.0 * PI / 2.0;
			}
		}
		double result_angle = atan(y / x);
		if (result_angle >= 0.0) {
			//一、三象限
			if (x < 0.0) {
				result_angle += PI;
			}
		}
		else {
			//二、四象限
			if (y > 0.0) {
				result_angle += PI;
			}
			else {
				result_angle += 2.0 * PI;
			}
		}
		return result_angle;
	}

	void FiducialMark::MarkInverseCompensationCal(Point& tar_point, int blockid, int arryid, Station station)
	{
		vector<int> compens_vec;
		for (int i = 0; i < m_fid_num; i++)
		{
			if (m_vec_fid_pos[i].Reachable)
			{
				compens_vec.push_back(i);
			}
		}

		switch (compens_vec.size())
		{
		case 1:
		{
			int first = compens_vec[0];
			// 单Mark点补偿角度输出为0
			// 实际元件位置 - 实际Mark点位置 = 理论元件位置 - 理论Mark点位置(机械坐标系)	
			tar_point.x = tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx + GetFidMechStandardXYPos(blockid, arryid, first, station).x;
			tar_point.y = tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy + GetFidMechStandardXYPos(blockid, arryid, first, station).y;
			break;
		}
		case 2:
		{
			int first = compens_vec[0];
			int second = compens_vec[1];
			//两个Mark点所在直线实际倾斜角以及理论倾斜角
			double actual_angle = MarkAngleArctanCal(m_vec_fid_pos.at(first).mark_cal_posx - m_vec_fid_pos.at(second).mark_cal_posx, m_vec_fid_pos.at(first).mark_cal_posy - m_vec_fid_pos.at(second).mark_cal_posy);
			double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);

			//计算补偿后元件坐标
			double mount_actual_angle = MarkAngleArctanCal(tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx, tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy);
			double mount_theoretical_angle = mount_actual_angle - actual_angle + theoretical_angle;
			double twopoint_distance = sqrt(pow(tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx, 2) + pow(tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy, 2));
			double dis_actual = sqrt(pow(m_vec_fid_pos.at(first).mark_cal_posx - m_vec_fid_pos.at(second).mark_cal_posx, 2) + pow(m_vec_fid_pos.at(first).mark_cal_posy - m_vec_fid_pos.at(second).mark_cal_posy, 2));
			double dis_theroy = sqrt(pow(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, 2) + pow(GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y, 2));
			double ratio = 1;
			if (!(dis_actual - 0 < 1e-3 || dis_theroy - 0 < 1e-3))
			{
				ratio = dis_theroy / dis_actual;
			}
			if (ratio < 0.5 || ratio > 1.5)
			{
				ratio = 1;
			}
			tar_point.x = twopoint_distance * ratio * cos(mount_theoretical_angle) + GetFidMechStandardXYPos(blockid, arryid, first, station).x;
			tar_point.y = twopoint_distance * ratio * sin(mount_theoretical_angle) + GetFidMechStandardXYPos(blockid, arryid, first, station).y;
			break;
		}
		case 3:
		{
			int first = compens_vec[0];
			int second = compens_vec[1];
			int third = compens_vec[2];
			//三个Mark点确定所在圆的圆心
			Point actual_center = MarkCircleCenterCal(GetFiducialCalXYPos(first), GetFiducialCalXYPos(second), GetFiducialCalXYPos(third));
			Point theoretical_center = MarkCircleCenterCal(GetFidMechStandardXYPos(blockid, arryid, first, station), GetFidMechStandardXYPos(blockid, arryid, second, station), GetFidMechStandardXYPos(blockid, arryid, third, station));

			if (fabs(actual_center.x - DBL_MAX) < 1e-3 || fabs(theoretical_center.x - DBL_MAX) < 1e-3)
			{
				double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFiducialCalXYPos(first).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
				double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);

				//计算补偿后元件坐标
				double mount_actual_angle = MarkAngleArctanCal(tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx, tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy);
				double mount_theoretical_angle = mount_actual_angle - actual_angle + theoretical_angle;
				double twopoint_distance = sqrt(pow(tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx, 2) + pow(tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy, 2));

				tar_point.x = twopoint_distance * cos(mount_theoretical_angle) + GetFidMechStandardXYPos(blockid, arryid, first, station).x;
				tar_point.y = twopoint_distance * sin(mount_theoretical_angle) + GetFidMechStandardXYPos(blockid, arryid, first, station).y;
				return;
			}


			double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - actual_center.x, GetFiducialCalXYPos(first).y - actual_center.y);
			double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - theoretical_center.x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - theoretical_center.y);

			tar_point.x -= (actual_center.x - theoretical_center.x);
			tar_point.y -= (actual_center.y - theoretical_center.y);

			break;
		}
		case 4:
		{
			int first = compens_vec[0];
			int second = compens_vec[1];
			int third = compens_vec[2];
			int forth = compens_vec[3];
			//四个Mark点补偿
			vector<Point> actual_center_set;
			vector<Point> theoretical_center_set;
			for (size_t i = 0; i < 4; i++)
			{
				vector<int> fidindex = { first,second,third,forth };
				fidindex.erase(fidindex.begin() + i);

				Point actual_center = MarkCircleCenterCal(GetFiducialCalXYPos(fidindex.at(first)), GetFiducialCalXYPos(fidindex.at(second)), GetFiducialCalXYPos(fidindex.at(third)));
				Point theoretical_center = MarkCircleCenterCal(GetFidMechStandardXYPos(blockid, arryid, fidindex.at(first), station), GetFidMechStandardXYPos(blockid, arryid, fidindex.at(second), station), GetFidMechStandardXYPos(blockid, arryid, fidindex.at(third), station));

				if (fabs(actual_center.x - DBL_MAX) < 1e-3 || fabs(theoretical_center.x - DBL_MAX) < 1e-3)
					continue;

				actual_center_set.push_back(actual_center);
				theoretical_center_set.push_back(theoretical_center);
			}

			if (actual_center_set.size() == 0 || theoretical_center_set.size() == 0)
			{
				double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFiducialCalXYPos(third).y - GetFidMechStandardXYPos(blockid, arryid, second, station).y);
				double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - GetFidMechStandardXYPos(blockid, arryid, second, station).x, GetFidMechStandardXYPos(blockid, arryid, third, station).y - GetFidMechStandardXYPos(blockid, arryid, forth, station).y);

				//计算补偿后元件坐标
				double mount_actual_angle = MarkAngleArctanCal(tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx, tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy);
				double mount_theoretical_angle = mount_actual_angle - actual_angle + theoretical_angle;
				double twopoint_distance = sqrt(pow(tar_point.x - m_vec_fid_pos.at(first).mark_cal_posx, 2) + pow(tar_point.y - m_vec_fid_pos.at(first).mark_cal_posy, 2));

				tar_point.x = twopoint_distance * cos(mount_theoretical_angle) + GetFidMechStandardXYPos(blockid, arryid, first, station).x;
				tar_point.y = twopoint_distance * sin(mount_theoretical_angle) + GetFidMechStandardXYPos(blockid, arryid, first, station).y;
				return;
			}

			Point actual_center;
			Point theoretical_center;
			for (size_t i = 0; i < actual_center_set.size(); i++)
			{
				actual_center = actual_center + actual_center_set[i];
				theoretical_center = theoretical_center + theoretical_center_set[i];
			}
			actual_center.x /= actual_center_set.size(), actual_center.y /= actual_center_set.size();
			theoretical_center.x /= theoretical_center_set.size(), theoretical_center.y /= theoretical_center_set.size();

			double actual_angle = MarkAngleArctanCal(GetFiducialCalXYPos(first).x - actual_center.x, GetFiducialCalXYPos(first).y - actual_center.y);
			double theoretical_angle = MarkAngleArctanCal(GetFidMechStandardXYPos(blockid, arryid, first, station).x - theoretical_center.x, GetFidMechStandardXYPos(blockid, arryid, first, station).y - theoretical_center.y);

			tar_point.x -= (actual_center.x - theoretical_center.x);
			tar_point.y -= (actual_center.y - theoretical_center.y);
			break;
		}
		default:
			break;
		}
	}

	Point FiducialMark::MarkCircleCenterCal(Point pt1, Point pt2, Point pt3)
	{
		double a = pt1.x - pt2.x;
		double b = pt1.y - pt2.y;
		double c = pt1.x - pt3.x;
		double d = pt1.y - pt3.y;
		double e = ((pt1.x * pt1.x - pt2.x * pt2.x) + (pt1.y * pt1.y - pt2.y * pt2.y)) / 2.0;
		double f = ((pt1.x * pt1.x - pt3.x * pt3.x) + (pt1.y * pt1.y - pt3.y * pt3.y)) / 2.0;
		double det = b * c - a * d;
		if (fabs(det) < 1e-5)
		{
			return Point(DBL_MAX, DBL_MAX);
		}

		double x0 = -(d * e - b * f) / det;
		double y0 = -(a * f - c * e) / det;
		return Point(x0, y0);
	}

	Point FiducialMark::GetFidMechStandardXYPos(int blockid, int arryid, Station station)
	{
		Point Tar_point = { 0,0 };
		// 基准点坐标 
		Point Fid_pos = { m_vec_fid_pos[1].x, m_vec_fid_pos[1].y };

		// 基准点坐标转换到机械坐标
		as::CoorTrans coor_trans;
		CoordinateTransfParameters coor_param;
		coor_param.SourceCoor = Fid_pos;
		coor_param.SourceR = 0;
		coor_param.BlockNum = blockid;
		coor_param.ArrayNum = arryid;
		coor_param.m_cBaseBoard = ASContext::GetInstance().GetBaseBoard();
		coor_param.CoordinateKind = ASContext::GetInstance().GetBaseBoard()->GetCoordinateType();
		coor_param.station = station;
		if (m_FiducialType == BoardMarkType::FIDUCIAL_ARRAY)
		{
			coor_param.SetCoordinateSystem(CoordinateSystem::MechanicalCoorSystem, CoordinateSystem::ArrayCoorSystem);
			coor_trans.MechanicalToArrayStageConvert(coor_param);
			Tar_point = coor_param.TargetCoor;
		}
		else if (m_FiducialType == BoardMarkType::FIDUCIAL_GLOBAL)
		{
			coor_param.SetCoordinateSystem(CoordinateSystem::MechanicalCoorSystem, CoordinateSystem::BlockCoorSystem);
			coor_trans.MechanicalToArrayStageConvert(coor_param);
			Tar_point = coor_param.TargetCoor;
		}
		else if (m_FiducialType == BoardMarkType::FIDUCIAL_NONE) {
			Tar_point = { 0,0 };
		}
		return Tar_point;
	}

	void BadMark::SetBadBadMarkOffsetX(double x_offset)
	{
		m_BadMarkOffset.X = x_offset;
		return;
	}

	void BadMark::SetBadBadMarkOffsetY(double y_offset)
	{
		m_BadMarkOffset.Y = y_offset;
		return;
	}

	Point BadMark::GetBadMarkPos()
	{
		return m_BadMarkPos;
	}

	void BadMark::SetBadMarkPos(double pos_x, double pos_y)
	{
		m_BadMarkPos.x = pos_x;
		m_BadMarkPos.y = pos_y;
		return;
	}

	void BadMark::SetBadMarkPosX(double pos_x)
	{
		m_BadMarkPos.x = pos_x;
		return;
	}

	void BadMark::SetBadMarkPosY(double pos_y)
	{
		m_BadMarkPos.y = pos_y;
		return;
	}

	APIErrCode BadMark::GetBadMarkFlag()
	{
		return m_MarkFlag;
	}

	void BadMark::SetBadMarkFlag(APIErrCode mark_flag)
	{
		m_MarkFlag = mark_flag;
		return;
	}

	MarkPart& BadMark::GetBadMarkPart()
	{
		return m_badMarkPart;
	}

	Array::Array()
	{
		m_bSkip = false;
		m_array_id = 0;
		m_BlockID = 0;
		m_FidMark = make_shared<FiducialMark>();
		m_BadMark = make_shared<BadMark>();
		m_AcceptMark = make_shared<AcceptMark>();
	}

	Array::~Array()
	{
	}

	Array& Array::operator=(Array& ref)
	{
		this->m_array_id = ref.GetArrayId();
		this->m_originoffset = ref.GetOriginOffset();
		this->m_bSkip = ref.GetSkip();
		this->m_BlockID = ref.GetBlockID();
		*this->m_AcceptMark = *ref.GetAcceptMark();
		*this->m_FidMark = *ref.GetFidMark();
		*this->m_BadMark = *ref.GetBadMark();
		return *this;
	}

	/*Array& Array::operator=(sm::Array& ref)
	{
		this->m_array_id = ref.GetArrayID();
		this->m_originoffset = ref.GetOffset();
		this->m_bSkip = ref.GetSkip();
		this->m_BlockID = ref.GetBlockID();
		*this->m_AcceptMark = *ref.GetAcceptMark();
		*this->m_FidMark = *ref.GetFidMark();
		*this->m_BadMark = *ref.GetBadMark();
		return *this;
	}*/

	bool Array::GetSkip()
	{
		return m_bSkip;
	}

	void Array::SetSkip(bool skFlag)
	{
		m_bSkip = skFlag;
		return;
	}

	int Array::GetArrayId()
	{
		return m_array_id;
	}

	void Array::SetArrayId(int id)
	{
		m_array_id = id;
	}

	int Array::GetBlockID()
	{
		return m_BlockID;
	}

	void Array::SetBlockID(int id)
	{
		m_BlockID = id;
		return;
	}

	OFFSET& Array::GetOriginOffset()
	{
		return m_originoffset;
	}

	double Array::GetOriginOffsetX()
	{
		return m_originoffset.GetOffsetX();
	}

	double Array::GetOriginOffsetY()
	{
		return m_originoffset.GetOffsetY();
	}

	double Array::GetOriginOffsetR()
	{
		return m_originoffset.GetOffsetR();
	}

	void Array::SetOriginOffset(OFFSET circuit_offset)
	{
		m_originoffset = circuit_offset;
	}

	void Array::SetOriginOffsetX(double x)
	{
		m_originoffset.SetOffsetX(x);
	}

	void Array::SetOriginOffsetY(double y)
	{
		m_originoffset.SetOffsetY(y);
	}

	void Array::SetOriginOffsetR(double r)
	{
		m_originoffset.SetOffsetR(r);
	}

	shared_ptr<FiducialMark>& Array::GetFidMark()
	{
		return m_FidMark;
	}

	shared_ptr<AcceptMark>& Array::GetAcceptMark()
	{
		return m_AcceptMark;
	}

	shared_ptr<BadMark>& Array::GetBadMark()
	{
		return m_BadMark;
	}

	Block::Block()
	{
		m_Skip = false;
		m_block_id = 1;
		m_bkContentSize.X = 1;
		m_bkContentSize.Y = 1;
		m_bkContentSize.Direction = DirectionType::DIRECTION_X;
		m_DirectionOffset.X = 0;
		m_DirectionOffset.Y = 0;
		m_board_array.push_back(make_shared<Array>());
		m_BadNum = 0;
		m_BadMarkUse = false;
		m_BadMarkType = BoardMarkType::FIDUCIAL_NONE;
		m_AcceptMarkUse = false;
	}

	Block::~Block()
	{

	}

	Block& Block::operator=(Block& ref)
	{
		this->m_block_id = ref.GetBlockID();
		this->m_Skip = ref.GetSkip();
		this->m_originoffset = ref.GetOriginOffset();
		this->m_BadNum = ref.GetBadMarkNum();
		this->m_BadMarkUse = ref.GetBadMarkUse();
		this->m_BadMarkType = ref.GetBadMarkType();
		this->m_AcceptMarkUse = ref.GetAcceptMarkUse();
		this->m_bkContentSize.Direction = ref.GetDir();
		this->m_bkContentSize.X = ref.GetXNum();
		this->m_bkContentSize.Y = ref.GetYNum();
		this->m_DirectionOffset.X = ref.GetDeltaX();
		this->m_DirectionOffset.Y = ref.GetDeltaY();
		this->m_board_array.clear();
		//区分MarkType
		if (ref.GetArrayContent(1)->GetFidMark()->GetFidMarkType() == BoardMarkType::FIDUCIAL_GLOBAL)
		{
			shared_ptr<FiducialMark> fdm = make_shared<FiducialMark>();
			for (int index = 1; index <= ref.GetALLArrayContent().size(); index++)
			{
				shared_ptr<Array> temp_array = make_shared<Array>();
				*fdm = *ref.GetArrayContent(index)->GetFidMark();
				*temp_array = *ref.GetArrayContent(index);
				temp_array->GetFidMark() = fdm;
				this->m_board_array.push_back(temp_array);
			}
		}
		else
		{
			for (int index = 1; index <= ref.GetALLArrayContent().size(); index++)
			{
				shared_ptr<Array> temp_array = make_shared<Array>();
				*temp_array = *ref.GetArrayContent(index);
				this->m_board_array.push_back(temp_array);
			}
		}
		return *this;
	}

	//Block& Block::operator=(sm::Block& ref)
	//{
	//	this->m_block_id = ref.GetBlockID();
	//	this->m_Skip = ref.GetSkip();
	//	this->m_originoffset = ref.GetOffset();
	//	this->m_BadNum = ref.GetBadMarkNum();
	//	this->m_BadMarkUse = ref.GetBadMarkUse();
	//	this->m_BadMarkType = static_cast<BoardMarkType>((int)ref.GetBadMarkType());
	//	this->m_AcceptMarkUse = ref.GetAcceptMarkUse();
	//	this->m_bkContentSize.Direction = static_cast<DirectionType>((int)ref.GetDir());
	//	this->m_bkContentSize.X = ref.GetXNum();
	//	this->m_bkContentSize.Y = ref.GetYNum();
	//	this->m_DirectionOffset.X = ref.GetDeltaX();
	//	this->m_DirectionOffset.Y = ref.GetDeltaY();
	//	this->m_board_array.clear();
	//	//区分MarkType
	//	if (ref.GetCircuitContent(1)->GetFidMark()->GetFidMarkType() == sm::BoardMarkType::FIDUCIAL_GLOBAL)
	//	{
	//		shared_ptr<FiducialMark> fdm = make_shared<FiducialMark>();
	//		for (int index = 1; index <= ref.GetAllCircuitContents().size(); index++)
	//		{
	//			shared_ptr<Array> temp_array = make_shared<Array>();
	//			*fdm = *ref.GetCircuitContent(index)->GetFidMark();
	//			*temp_array = *ref.GetCircuitContent(index);
	//			temp_array->GetFidMark() = fdm;
	//			this->m_board_array.push_back(temp_array);
	//		}
	//	}
	//	else
	//	{
	//		for (int index = 1; index <= ref.GetAllCircuitContents().size(); index++)
	//		{
	//			shared_ptr<Array> temp_array = make_shared<Array>();
	//			*temp_array = *ref.GetCircuitContent(index);
	//			this->m_board_array.push_back(temp_array);
	//		}
	//	}
	//	return *this;
	//}

	bool Block::GetSkip()
	{
		return m_Skip;
	}

	void Block::SetSkip(bool skFlag)
	{
		m_Skip = skFlag;
	}
	
	void Block::SetBlockID(int block_id)
	{
		m_block_id = block_id;
	}

	int Block::GetBlockID()
	{
		return m_block_id;
	}

	void Block::SetOriginOffset(OFFSET offset_pos)
	{
		m_originoffset = offset_pos;
	}

	void Block::SetOriginOffsetX(double x)
	{
		m_originoffset.SetOffsetX(x);
	}

	void Block::SetOriginOffsetY(double y)
	{
		m_originoffset.SetOffsetY(y);
	}

	void Block::SetOriginOffsetR(double r)
	{
		m_originoffset.SetOffsetR(r);
	}

	OFFSET Block::GetOriginOffset()
	{
		return m_originoffset;
	}

	double Block::GetOriginOffsetX()
	{
		return m_originoffset.GetOffsetX();
	}

	double Block::GetOriginOffsetY()
	{
		return m_originoffset.GetOffsetY();
	}

	double Block::GetOriginOffsetR()
	{
		return m_originoffset.GetOffsetR();
	}

	int Block::GetBadMarkNum()
	{
		return m_BadNum;
	}

	void Block::SetBadMarkNum()
	{
		switch (m_BadMarkType)
		{
		case as::BoardMarkType::FIDUCIAL_NONE:
			m_BadNum = 0;
			break;
		case as::BoardMarkType::FIDUCIAL_ARRAY:
		case as::BoardMarkType::FIDUCIAL_GLOBAL:
			m_BadNum = m_board_array.size();
			break;
		default:
			break;
		}
		return;
	}

	bool Block::GetBadMarkUse()
	{
		return m_BadMarkUse;
	}

	void Block::SetBadMarkUse(bool bad_use)
	{
		m_BadMarkUse = bad_use;
		return;
	}

	BoardMarkType Block::GetBadMarkType()
	{
		return m_BadMarkType;
	}
	void Block::SetBadMarkType(BoardMarkType badMark_type)
	{
		m_BadMarkType = badMark_type;
		return;
	}

	void Block::SetBadMark(int array_id)
	{
		switch (m_BadMarkType)
		{
		case as::BoardMarkType::FIDUCIAL_NONE:
		{
			for (int i = 0; i < m_board_array.size(); i++)
			{
				m_board_array.at(i)->GetBadMark() = nullptr;
			}
			break;
		}
		case as::BoardMarkType::FIDUCIAL_ARRAY:
		{
			for (int i = 0; i < m_board_array.size(); i++)
			{
				m_board_array.at(i)->GetBadMark() = make_shared<BadMark>();
			}
			break;
		}
		case as::BoardMarkType::FIDUCIAL_GLOBAL:
		{
			shared_ptr<BadMark> bdm = make_shared<BadMark>();
			for (int i = 0; i < m_board_array.size(); i++)
			{
				m_board_array.at(i)->GetBadMark() = bdm;
			}
			break;
		}
		default:
			break;
		}
	}

	shared_ptr<BadMark> Block::GetBadMark(int array_id)
	{
		return m_board_array.at(array_id - 1)->GetBadMark();
	}

	bool Block::GetAcceptMarkUse()
	{
		return m_AcceptMarkUse;
	}

	void Block::SetAcceptMarkUse(bool accept_use)
	{
		m_AcceptMarkUse = accept_use;
		return;
	}

	void Block::SetAcceptpMark(int array_id)
	{
		shared_ptr<AcceptMark> acm = make_shared<AcceptMark>();
		for (int i = 0; i < m_board_array.size(); i++)
		{
			m_board_array.at(i)->GetAcceptMark() = acm;
		}
	}

	shared_ptr<AcceptMark> Block::GetAcceptMark(int array_id)
	{
		return m_board_array.at(array_id - 1)->GetAcceptMark();
	}

	void Block::SetXYDir(int X, int Y, double offset_x, double offset_y, DirectionType Direction)
	{
		m_bkContentSize.Direction = Direction;
		m_bkContentSize.X = X;
		m_bkContentSize.Y = Y;
		SetDeltaXY(offset_x, offset_y);
		return;
	}

	void Block::SetXY(int X, int Y)
	{
		m_bkContentSize.X = X;
		m_bkContentSize.Y = Y;
		//m_board_array.clear();
		SetDeltaXY(m_originoffset.GetOffsetX(), m_originoffset.GetOffsetY());
	}

	void Block::GetXYDir(int& X, int& Y, DirectionType& Direction)
	{
		X = m_bkContentSize.X;
		Y = m_bkContentSize.Y;
		Direction = m_bkContentSize.Direction;
		return;
	}

	DirectionType Block::GetDir()
	{
		return m_bkContentSize.Direction;
	}

	int Block::GetXNum()
	{
		return m_bkContentSize.X;
	}
	void Block::SetXNum(int x)
	{
		m_bkContentSize.X = x;
	}

	int Block::GetYNum()
	{
		return m_bkContentSize.Y;
	}

	void Block::SetYNum(int y)
	{
		m_bkContentSize.Y = y;
	}

	void Block::SetDeltaXY(double dx, double dy)
	{
		m_DirectionOffset.X = dx;
		m_DirectionOffset.Y = dy;
		if (m_bkContentSize.Direction == DirectionType::DIRECTION_X)
		{
			// 若拼板个数减小
			if (m_board_array.size() > m_bkContentSize.X * m_bkContentSize.Y)
			{
				m_board_array.erase(m_board_array.begin() + m_bkContentSize.X * m_bkContentSize.Y, m_board_array.end());
				for (int j = 0; j < m_bkContentSize.Y; j++)
				{
					for (int i = 0; i < m_bkContentSize.X; i++)
					{
						m_board_array[j * m_bkContentSize.X + i]->GetOriginOffset().m_x = i * dx;
						m_board_array[j * m_bkContentSize.X + i]->GetOriginOffset().m_y = j * dy;
						m_board_array[j * m_bkContentSize.X + i]->GetOriginOffset().m_r = 0.0;
						m_board_array[j * m_bkContentSize.X + i]->SetSkip(false);
						m_board_array[j * m_bkContentSize.X + i]->SetArrayId(j * m_bkContentSize.X + i + 1);
					}
				}
			}
			// 拼板个数增加
			else if (m_board_array.size() <= m_bkContentSize.X * m_bkContentSize.Y)
			{
				int boardArray_size = m_board_array.size();
				for (int j = 0; j < m_bkContentSize.Y; j++)
				{
					for (int i = 0; i < m_bkContentSize.X; i++)
					{
						//当该块数小于m_board_array容量
						if (j * m_bkContentSize.X + i < boardArray_size)
						{
							m_board_array[j * m_bkContentSize.X + i]->GetOriginOffset().m_x = i * dx;
							m_board_array[j * m_bkContentSize.X + i]->GetOriginOffset().m_y = j * dy;
							m_board_array[j * m_bkContentSize.X + i]->GetOriginOffset().m_r = 0.0;
							m_board_array[j * m_bkContentSize.X + i]->SetSkip(false);
							m_board_array[j * m_bkContentSize.X + i]->SetArrayId(j * m_bkContentSize.X + i + 1);
						}
						// 块数超过m_board_array容量且m_board_array容量不为0
						else if (boardArray_size > 0)
						{
							shared_ptr < Array> circu_ = make_shared<Array>();
							circu_->GetOriginOffset().m_x = i * dx;
							circu_->GetOriginOffset().m_y = j * dy;
							circu_->GetOriginOffset().m_r = 0.0;
							circu_->SetSkip(false);
							circu_->SetArrayId(j * m_bkContentSize.X + j + 1);
							circu_->GetFidMark() = m_board_array[0]->GetFidMark();
							circu_->GetAcceptMark() = m_board_array[0]->GetAcceptMark();
							circu_->GetBadMark() = m_board_array[0]->GetBadMark();
							m_board_array.push_back(circu_);
						}
						else if (boardArray_size == 0)
						{
							shared_ptr < Array> circu_ = make_shared<Array>();
							circu_->GetOriginOffset().m_x = i * dx;
							circu_->GetOriginOffset().m_y = j * dy;
							circu_->GetOriginOffset().m_r = 0.0;
							circu_->SetSkip(false);
							circu_->SetArrayId(j * m_bkContentSize.X + j + 1);
							m_board_array.push_back(circu_);
						}
					}
				}
			}
		}
		else
		{

			if (m_board_array.size() > m_bkContentSize.X * m_bkContentSize.Y)
			{

				m_board_array.erase(m_board_array.begin() + m_bkContentSize.X * m_bkContentSize.Y, m_board_array.end());
				for (int j = 0; j < m_bkContentSize.X; j++)
				{
					for (int i = 0; i < m_bkContentSize.Y; i++)
					{
						m_board_array[j * m_bkContentSize.Y + i]->GetOriginOffset().m_x = j * dx;
						m_board_array[j * m_bkContentSize.Y + i]->GetOriginOffset().m_y = i * dy;
						m_board_array[j * m_bkContentSize.Y + i]->GetOriginOffset().m_r = 0.0;
						m_board_array[j * m_bkContentSize.Y + i]->SetSkip(false);
						m_board_array[j * m_bkContentSize.Y + i]->SetArrayId(j * m_bkContentSize.Y + i + 1);
					}
				}
			}
			else if (m_board_array.size() <= m_bkContentSize.X * m_bkContentSize.Y)
			{
				int boardArray_size = m_board_array.size();
				for (int j = 0; j < m_bkContentSize.X; j++)
				{
					for (int i = 0; i < m_bkContentSize.Y; i++)
					{
						if (j * m_bkContentSize.Y + i < boardArray_size)
						{
							m_board_array[j * m_bkContentSize.Y + i]->GetOriginOffset().m_x = j * dx;
							m_board_array[j * m_bkContentSize.Y + i]->GetOriginOffset().m_y = i * dy;
							m_board_array[j * m_bkContentSize.Y + i]->GetOriginOffset().m_r = 0.0;
							m_board_array[j * m_bkContentSize.Y + i]->SetSkip(false);
							m_board_array[j * m_bkContentSize.Y + i]->SetArrayId(j * m_bkContentSize.Y + i + 1);
						}
						else if (boardArray_size > 0)
						{
							shared_ptr < Array> circu_ = make_shared<Array>();
							circu_->GetOriginOffset().m_x = j * dx;
							circu_->GetOriginOffset().m_y = i * dy;
							circu_->GetOriginOffset().m_r = 0.0;
							circu_->SetSkip(false);
							circu_->SetArrayId(j * m_bkContentSize.Y + i + 1);
							circu_->GetFidMark() = m_board_array[0]->GetFidMark();
							circu_->GetAcceptMark() = m_board_array[0]->GetAcceptMark();
							circu_->GetBadMark() = m_board_array[0]->GetBadMark();
							m_board_array.push_back(circu_);
						}
						else if (boardArray_size == 0)
						{
							shared_ptr < Array> circu_ = make_shared<Array>();
							circu_->GetOriginOffset().m_x = j * dx;
							circu_->GetOriginOffset().m_y = i * dy;
							circu_->GetOriginOffset().m_r = 0.0;
							circu_->SetSkip(false);
							circu_->SetArrayId(j * m_bkContentSize.Y + i + 1);
							m_board_array.push_back(circu_);
						}
					}
				}
			}
		}
		return;
	}

	void Block::GetDeltaXY(double& dx, double& dy)
	{
		dx = m_DirectionOffset.X;
		dy = m_DirectionOffset.Y;
		return;
	}

	double Block::GetDeltaX()
	{
		return m_DirectionOffset.X;
	}

	double Block::GetDeltaY()
	{
		return m_DirectionOffset.Y;
	}

	void Block::SetFidMark(int array_id)
	{
		BoardMarkType m_FiducialType = m_board_array.at(array_id - 1)->GetFidMark()->GetFidMarkType();
		switch (m_FiducialType)
		{
		case as::BoardMarkType::FIDUCIAL_NONE:
		{
			for (int i = 0; i < m_board_array.size(); i++)
			{
				m_board_array.at(i)->GetFidMark()->SetFidMarkNum(0);
			}
			break;
		}
		case as::BoardMarkType::FIDUCIAL_ARRAY:
		{
			for (int i = 0; i < m_board_array.size(); i++)
			{
				shared_ptr<FiducialMark> fdm = make_shared<FiducialMark>();
				m_board_array.at(i)->GetFidMark() = fdm;
			}
			break;
		}
		case as::BoardMarkType::FIDUCIAL_GLOBAL:
		{
			shared_ptr<FiducialMark> fdm = make_shared<FiducialMark>();
			for (int i = 0; i < m_board_array.size(); i++)
			{
				m_board_array.at(i)->GetFidMark() = fdm;
			}
			break;
		}
		default:
			break;
		}
	}

	void Block::SetFidMark_ptr(int array_id)
	{
		if (m_board_array.at(array_id - 1)->GetFidMark() == nullptr)
		{
			for (int i = 0; i < m_board_array.size(); i++)
			{
				m_board_array.at(i)->GetFidMark() = make_shared<FiducialMark>();
			}
			return;
		}
	}

	shared_ptr<FiducialMark>& Block::GetFidMark(int array_id)
	{
		return m_board_array.at(array_id - 1)->GetFidMark();
	};

	shared_ptr<Array> Block::GetArrayContent(int array_id)
	{
		return m_board_array[array_id - 1];
	}

	void Block::InsertArrayContent(shared_ptr<Array> array)
	{
		return m_board_array.push_back(array);
	}

	vector<shared_ptr<Array>>& Block::GetALLArrayContent()
	{
		return m_board_array;
	}

	void Block::DeleteArrayContent(int array_id)
	{
		if (array_id <= m_board_array.size())
		{
			m_board_array.erase(m_board_array.begin() + array_id - 1);
		}
	}

	int Block::GetNumOfCircuits()
	{
		return m_board_array.size();
	}

	BaseBoard::BaseBoard()
	{
		m_coordinate = CoordinateType::RIGHT_DOWN;
		m_DefectMode = DefectMode::SMTMode;
		m_InitialTheta = DBL_MAX;
		m_size.X = 100;
		m_size.Y = 100;
		m_bUse = false;
		m_Type = BlockType::BLOCK_AAAA;
		m_NumX = 1;
		m_NumY = 1;
		m_DeltaX = 0;
		m_DeltaY = 0;
		m_BlockContents.push_back(make_shared<Block>());
	}

	BaseBoard& BaseBoard::operator=(BaseBoard& ref)
	{
		this->m_origin = ref.GetBaseBoardOrigin();
		this->m_scanPoint1 = ref.GetBaseBoardScanPoint1();
		this->m_scanPoint2 = ref.GetBaseBoardScanPoint2();
		this->m_coordinate = ref.GetCoordinateType();
		this->m_DefectMode = ref.GetDefectModeData();
		this->m_InitialTheta = ref.GetBaseBoardInitinalTheta();
		this->m_size.X = ref.GetBaseBoardSizeX();
		this->m_size.Y = ref.GetBaseBoardSizeY();
		this->m_bUse = ref.GetUse();
		this->m_Type = ref.GetBlockType();
		this->m_NumX = ref.GetBlockXNum();
		this->m_NumY = ref.GetBlockYNum();
		this->m_DeltaX = ref.GetXDelta();
		this->m_DeltaY = ref.GetYDelta();		
		this->m_BlockContents.clear();
		for (int index = 1; index <= ref.GetALLBlockContent().size(); index++)
		{
			shared_ptr<Block> temp_block = make_shared<Block>();
			*temp_block = *ref.GetBlockContent(index);
			this->m_BlockContents.push_back(temp_block);
		}
		return *this;
	}

	/*BaseBoard& BaseBoard::operator=(sm::BaseBoard& ref)
	{
		Point origin_pos;
		ref.GetBaseBoardOrigin(origin_pos);
		this->m_origin = origin_pos;
		this->m_coordinate = ref.GetCoordinateType();
		this->m_InitialTheta = ref.GetBaseBoardInitinalTheta();
		this->m_size.X = ref.GetBaseBoardSizeX();
		this->m_size.Y = ref.GetBaseBoardSizeY();
		this->m_bUse = ref.GetUse();
		this->m_Type = static_cast<BlockType>((int)ref.GetBlockType());
		this->m_NumX = ref.GetXNum();
		this->m_NumY = ref.GetYNum();
		this->m_DeltaX = ref.GetXDelta();
		this->m_DeltaY = ref.GetYDelta();
		this->m_BlockContents.clear();
		for (int index = 1; index <= ref.GetALLBlockContent().size(); index++)
		{
			shared_ptr<Block> temp_block = make_shared<Block>();
			*temp_block = *ref.GetBlockContent(index);
			this->m_BlockContents.push_back(temp_block);
		}
		return *this;
	}*/

	void BaseBoard::SetBaseBoardOriginX(double X)
	{
		m_origin.x = X;
		return;
	}

	void BaseBoard::SetBaseBoardOriginY(double Y)
	{
		m_origin.y = Y;
		return;
	}

	Point BaseBoard::GetBaseBoardOrigin()
	{
		return m_origin;
	}

	void BaseBoard::SetBaseBoardOrigin(Point point)
	{
		
		m_origin = point;
	}

	void BaseBoard::SetBaseBoardScanX1(double X)
	{
		m_scanPoint1.x = X;
		return;
	}

	void BaseBoard::SetBaseBoardScanY1(double Y)
	{
		m_scanPoint1.y = Y;
		return;
	}

	void BaseBoard::SetBaseBoardScanX2(double X)
	{
		m_scanPoint2.x = X;
		return;
	}

	void BaseBoard::SetBaseBoardScanY2(double Y)
	{
		m_scanPoint2.y = Y;
		return;
	}

	Point BaseBoard::GetBaseBoardScanPoint1()
	{
		return m_scanPoint1;
	}

	void BaseBoard::SetBaseBoardScanPoint1(Point point)
	{

		m_scanPoint1 = point;
	}

	Point BaseBoard::GetBaseBoardScanPoint2()
	{
		return m_scanPoint2;
	}

	void BaseBoard::SetBaseBoardScanPoint2(Point point)
	{

		m_scanPoint2 = point;
	}

	void BaseBoard::SetCoordinateType(CoordinateType coor_type)
	{
		m_coordinate = coor_type;
	}

	CoordinateType BaseBoard::GetCoordinateType()
	{
		return m_coordinate;
	}

	DefectMode BaseBoard::GetDefectModeData()
	{
		return m_DefectMode;
	}

	void BaseBoard::SetDefectModeData(DefectMode val)
	{
		m_DefectMode = val;
	}

	double BaseBoard::GetBaseBoardInitinalTheta()
	{
		if (abs(m_InitialTheta - DBL_MAX) < 1e-6)
			return .0;
		return m_InitialTheta;
	}

	bool BaseBoard::CheckBaseBoardInitinalTheta()
	{
		return abs(m_InitialTheta - DBL_MAX) < 1e-6;
	}

	void BaseBoard::SetBaseBoardInitinalTheta(double theta)
	{
		m_InitialTheta = theta;
		return;
	}

	void BaseBoard::SetBaseBoardSize(double x, double y)
	{
		m_size.X = x;
		m_size.Y = y;
	}

	void BaseBoard::SetBaseBoardSizeX(double x)
	{
		m_size.X = x;
	}

	void BaseBoard::SetBaseBoardSizeY(double y)
	{
		m_size.Y = y;
	}

	double BaseBoard::GetBaseBoardSizeX()
	{
		return m_size.X;
	}

	double BaseBoard::GetBaseBoardSizeY()
	{
		return m_size.Y;
	}

	bool BaseBoard::GetUse()
	{
		return m_bUse;
	}

	void BaseBoard::SetUse(bool u)
	{
		m_bUse = u;
		return;
	}

	BlockType BaseBoard::GetBlockType()
	{
		return m_Type;
	}

	void BaseBoard::SetBlockType(BlockType bt)
	{
		m_Type = bt;
		return;
	}

	void BaseBoard::SetXY(int X, int Y, double deltaX, double deltaY, BlockType preblocktype, BlockType currblocktype)
	{
		m_NumX = X;
		m_NumY = Y;
		m_DeltaX = deltaX;
		m_DeltaY = deltaY;

		if (m_BlockContents.size() > X * Y && preblocktype == currblocktype)
		{
			auto blockContentsize = m_BlockContents.size();
			m_BlockContents.erase(m_BlockContents.begin() + X * Y, m_BlockContents.end());
			for (int j = 0; j < Y; j++)
			{
				for (int i = 0; i < X; i++)
				{
					OFFSET offset;
					offset.m_x = i * deltaX;
					offset.m_y = j * deltaY;
					offset.m_r = 0.0;
					m_BlockContents.at(j * X + i)->SetOriginOffset(offset);
					m_BlockContents.at(j * X + i)->SetBlockID(j * X + i + 1);
					m_BlockContents.at(j * X + i)->SetSkip(false);
				}
			}
		}
		else if (m_BlockContents.size() <= X * Y && preblocktype == currblocktype)
		{
			for (int j = 0; j < Y; j++)
			{
				for (int i = 0; i < X; i++)
				{
					if (j * X + i < m_BlockContents.size())
					{
						OFFSET offset;
						offset.m_x = i * deltaX;
						offset.m_y = j * deltaY;
						offset.m_r = 0.0;
						m_BlockContents.at(j * X + i)->SetOriginOffset(offset);
						m_BlockContents.at(j * X + i)->SetBlockID(j * X + i + 1);
						m_BlockContents.at(j * X + i)->SetSkip(false);
					}
					else
					{
						if (currblocktype == BlockType::BLOCK_AAAA)
						{
							OFFSET offset;
							Block block;
							block = *m_BlockContents.at(0);
							offset.m_x = i * deltaX;
							offset.m_y = j * deltaY;
							offset.m_r = 0.0;
							block.SetOriginOffset(offset);
							block.SetBlockID(j * X + i + 1);
							shared_ptr< Block> block_(new Block);
							*block_ = block;
							m_BlockContents.push_back(block_);
						}
						else
						{
							OFFSET offset;
							shared_ptr< Block> block(new Block);
							offset.m_x = i * deltaX;
							offset.m_y = j * deltaY;
							offset.m_r = 0.0;
							block->SetOriginOffset(offset);
							block->SetBlockID(j * X + i + 1);
							m_BlockContents.push_back(block);
						}
					}
				}
			}
		}
		// 从ABCD 切换至AAAA 
		else if (preblocktype == BlockType::BLOCK_ABCD && currblocktype == BlockType::BLOCK_AAAA)
		{
			m_BlockContents.erase(m_BlockContents.begin() + 1, m_BlockContents.end());
			for (int j = 0; j < Y; j++)
			{
				for (int i = 0; i < X; i++)
				{
					if (i == 0 && j == 0)
						continue;
					// 创建块
					OFFSET offset;
					offset.m_x = i * deltaX;
					offset.m_y = j * deltaY;
					offset.m_r = 0.0;
					shared_ptr< Block> block(new Block);
					block->SetOriginOffset(offset);
					block->SetBlockID(j * X + i + 1);
					double DeltaX_, DeltaY_;
					m_BlockContents.at(0)->GetDeltaXY(DeltaX_, DeltaY_);
					// 计算偏移量存入block中
					block->SetXYDir(m_BlockContents.at(0)->GetXNum(), m_BlockContents.at(0)->GetYNum(), DeltaX_, DeltaY_, m_BlockContents.at(0)->GetDir());
					// 设置坏板可接受点
					/*block->SetSequenceType(m_BlockContents.at(0)->GetSequenceType());*/
					block->SetBadMarkUse(m_BlockContents.at(0)->GetBadMarkUse());
					block->SetBadMarkType(m_BlockContents.at(0)->GetBadMarkType());
					block->SetBadMarkNum();
					block->SetAcceptMarkUse(m_BlockContents.at(0)->GetAcceptMarkUse());
					shared_ptr<FiducialMark> temp_FidMark = make_shared<FiducialMark>();
					for (int arr_id = 1; arr_id <= block->GetNumOfCircuits(); arr_id++)
					{
						block->GetArrayContent(arr_id)->SetOriginOffset(m_BlockContents.at(0)->GetArrayContent(arr_id)->GetOriginOffset());
						block->GetArrayContent(arr_id)->SetSkip(m_BlockContents.at(0)->GetArrayContent(arr_id)->GetSkip());
						// 坏板可接受点深拷贝
						block->GetArrayContent(arr_id)->GetBadMark() = make_shared<BadMark>(*m_BlockContents.at(0)->GetBadMark(arr_id));
						block->GetArrayContent(arr_id)->GetAcceptMark() = make_shared<AcceptMark>(*m_BlockContents.at(0)->GetAcceptMark(arr_id));
						// 基准点分类型确定深拷贝指针指向
						if (m_BlockContents.at(0)->GetFidMark(arr_id) != nullptr)
						{
							if (m_BlockContents.at(0)->GetFidMark(arr_id)->GetFidMarkType() == BoardMarkType::FIDUCIAL_GLOBAL)
							{
								*temp_FidMark = *m_BlockContents.at(0)->GetFidMark(arr_id);
								block->GetArrayContent(arr_id)->GetFidMark() = temp_FidMark;
							}
							else
							{
								shared_ptr<FiducialMark> temp_FidMark = make_shared<FiducialMark>(*m_BlockContents.at(0)->GetFidMark(arr_id));
								block->GetArrayContent(arr_id)->GetFidMark() = temp_FidMark;
							}
						}
						else
							block->GetArrayContent(arr_id)->GetFidMark() = m_BlockContents.at(0)->GetFidMark(arr_id);
					}
					m_BlockContents.push_back(block);
				}
			}
		}
		else if (preblocktype == BlockType::BLOCK_AAAA && currblocktype == BlockType::BLOCK_ABCD)
		{
			m_BlockContents.erase(m_BlockContents.begin() + 1, m_BlockContents.end());
			for (int j = 0; j < Y; j++)
			{
				for (int i = 0; i < X; i++)
				{
					if (j * X + i + 1 > 1)
					{
						OFFSET offset;
						shared_ptr< Block> block(new Block);
						offset.m_x = i * deltaX;
						offset.m_y = j * deltaY;
						offset.m_r = 0.0;
						block->SetOriginOffset(offset);
						block->SetBlockID(j * X + i + 1);
						m_BlockContents.push_back(block);
					}
				}
			}
		}
		return;
	}

	double BaseBoard::GetBlockXNum()
	{
		return m_NumX;
	}

	void BaseBoard::SetBlockXNum(int num)
	{
		m_NumX = num;
	}

	double BaseBoard::GetBlockYNum()
	{
		return m_NumY;
	}

	void BaseBoard::SetBlockYNum(int num)
	{
		m_NumY = num;
	}

	double BaseBoard::GetXDelta()
	{
		return m_DeltaX;
	}

	double BaseBoard::GetYDelta()
	{
		return m_DeltaY;
	}

	shared_ptr<Block> BaseBoard::GetBlockContent(int block_id)
	{
		return m_BlockContents[block_id - 1];
	}

	void BaseBoard::InsertBlockContent(shared_ptr<Block> block)
	{
		m_BlockContents.push_back(block);
	}

	vector<shared_ptr<Block>>& BaseBoard::GetALLBlockContent()
	{
		return m_BlockContents;
	}

	void BaseBoard::DeleteBlockContent(int block_id)
	{
		if (block_id <= m_BlockContents.size())
		{
			m_BlockContents.erase(m_BlockContents.begin() + block_id - 1);
		}
	}

	shared_ptr<Array> BaseBoard::GetCircuitContent(int blockID, int circuitID)
	{
		shared_ptr<Array> bkCircuit = GetBlockContent(blockID)->GetArrayContent(circuitID);
		return bkCircuit;
	}

	int BaseBoard::GetNumOfBlocks()
	{
		int blockNum = m_NumX * m_NumY;
		return blockNum;
	}
	
	int BaseBoard::GetAllBlockArrayNum()
	{
		int m_nAllBlockArrayNum = 0;
		for (int block_id = 0; block_id < m_BlockContents.size(); block_id++)
		{
			m_nAllBlockArrayNum += m_BlockContents[block_id]->GetNumOfCircuits();
		}
		return m_nAllBlockArrayNum;
	}

	void BaseBoard::UpdateMarkCalFlag()
	{
		for (int block_id = 1; block_id <= GetNumOfBlocks(); block_id++)
		{
			for (int arr_id = 1; arr_id <= GetBlockContent(block_id)->GetNumOfCircuits(); arr_id++)
			{
				if (GetBlockContent(block_id)->GetFidMark(arr_id) != nullptr)
				{
					GetBlockContent(block_id)->GetFidMark(arr_id)->SetFiducialMarkFlag(MarkNotCal);
				}
			}
		}
	}
}