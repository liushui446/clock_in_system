#include "as/CoorTrans.hpp"
namespace as 
{

	CoordinateTransfParameters::CoordinateTransfParameters()
	{
		SourceR = 0;														//�����������ǰ����ϵ�Ƕ�R
		BlockNum = 1;														//������������		
		ArrayNum = 1;														//���������ƴ���
		CoordinateKind = CoordinateType::RIGHT_DOWN;						//�������������ϵ����
		TargetR = 0;														//���������Ŀ������Ƕ�R
		station = Station::StationF2;

		SourceCoorSystem = CoordinateSystem::MechanicalCoorSystem;			//�����������ǰ����ϵ
		TargetCoorSystem = CoordinateSystem::MechanicalCoorSystem;			//���������Ŀ������ϵ
		m_cBaseBoard = as::ASContext::GetInstance().GetBaseBoard();

	}
	CoordinateTransfParameters::~CoordinateTransfParameters()
	{

	}
	/**
		*��������	GetSourceCoorSystem
		*�������ã�	��õ�ǰ����ϵ
		*
		*����˵����
		*	��
		*
		*����ֵ��
		*	@retrun ����ϵ
		*/
	CoordinateSystem CoordinateTransfParameters::GetSourceCoorSystem()
	{
		return SourceCoorSystem;
	}
	/**
		*��������	GetTargetCoorSystem
		*�������ã�	���Ŀ������ϵ
		*
		*����˵����
		*	��
		*
		*����ֵ��
		*	@retrun ����ϵ
		*/
	CoordinateSystem CoordinateTransfParameters::GetTargetCoorSystem()
	{
		return TargetCoorSystem;
	}
	/**
		*��������	SetCoordinateSystem
		*�������ã�	��������ϵת���ĵ�ǰ����ϵ��Ŀ������ϵ
		*
		*����˵����
		*	@param 	const CoordinateSystem : �����������ǰ����ϵ��
		*	@param 	const CoordinateSystem : ���������Ŀ������ϵ��
		*
		*����ֵ��
		*	@retrun ��
		*/
	void CoordinateTransfParameters::SetCoordinateSystem(const CoordinateSystem source_coor, const CoordinateSystem target_coor)
	{
		SourceCoorSystem = source_coor;
		TargetCoorSystem = target_coor;
	}

	/**
		*��������	CoordinateTransform
		*�������ã�	����ת��
		*
		*����˵����
		*	@param 	InXY : ����������������������ϵ������(x,y)��
		*	@param 	InR : ����������������������ϵ������(r)��
		*	@param 	ReXY : �����������������ϵ������������ϵ��ƽ������(x,y)��SMT��ʵ������ָ�ֲ�����ϵ�����ȫ������ϵ������ȫ������ϵ��ֲ�����ϵת��ʱ���ں����ж�Re�����˱任ʹ֮��Ϊȫ������ϵ����ھֲ�����ϵ��
		*	@param 	ReR : �����������������ϵ������������ϵ����ת����(r)��SMT��ʵ������ָ�ֲ�����ϵ�����ȫ������ϵ������ȫ������ϵ��ֲ�����ϵת��ʱ���ں����ж�Re�����˱任ʹ֮��Ϊȫ������ϵ����ھֲ�����ϵ��
		*	@param 	OutXY : ���������������������ϵ������(x,y)��
		*	@param 	OutR : ���������������������ϵ������(r)��
		*	@param 	CoordinateKind : ���������0��ʾ����ϵ��1��ʾ����ϵ��
		*	@param 	Direction : �������������ת������ture��ʾ�Ӿֲ�����ϵ��ȫ������ϵת������ƴ������ϵ-->������ϵ-->��������ϵ-->ϵͳPCB����ϵ��false��ʾ��ȫ������ϵ��ֲ�����ϵת������PCBϵͳ����ϵ-->��������ϵ-->������ϵ-->ƴ������ϵ��
		*
		*����ֵ��
		*	@return �ա�
		*/

	CoorTrans::CoorTrans()
	{
	}

	void CoorTrans::CoordinateTransform(Point InXY, double InR, Point ReXY, double ReR, Point& OutXY, double& OutR, CoordinateType Coordinatetype, bool direction)
	{
		int CoordinateKind = 0;
		if (Coordinatetype == CoordinateType::LEFT_UP || Coordinatetype == CoordinateType::RIGHT_DOWN)
		{
			CoordinateKind = 0;//����ϵ
		}
		else
		{
			CoordinateKind = 1;//����ϵ
		}

		switch (CoordinateKind)
		{
		case 0://����ϵ
		{
			double angle;
			if (!direction)
			{
				// ȫ�ֵ��ֲ�����ƽ������ת
				angle = ReR / 180 * PI;
				//OutXY.x = (InXY.x - ReXY.x) * cos(angle) + (InXY.y - ReXY.y) * sin(angle);
				//OutXY.y = (-(InXY.x - ReXY.x)) * sin(angle) + (InXY.y - ReXY.y) * cos(angle);
				//OutR = InR + ReR;
				OutXY.x = (InXY.x - ReXY.x) * cos(angle) - (InXY.y - ReXY.y) * sin(angle);
				OutXY.y = (InXY.x - ReXY.x) * sin(angle) + (InXY.y - ReXY.y) * cos(angle);
				OutR = InR - ReR;
			}
			else
			{
				// �ֲ���ȫ�֣�����ת��ƽ��
				angle = ReR / 180 * PI;
				//OutXY.x = ReXY.x + InXY.x * cos(angle) - InXY.y * sin(angle);
				//OutXY.y = ReXY.y + InXY.x * sin(angle) + InXY.y * cos(angle);
				//OutR = InR - ReR;
				OutXY.x = ReXY.x + InXY.x * cos(angle) + InXY.y * sin(angle);
				OutXY.y = ReXY.y - InXY.x * sin(angle) + InXY.y * cos(angle);
				OutR = InR + ReR;
			}
		}
		break;
		case 1:// ����ϵ
		{
			double angle;
			if (!direction)
			{
				// ȫ�ֵ��ֲ�����ƽ������ת
				angle = ReR / 180 * PI;
				//OutXY.x = (InXY.x - ReXY.x) * cos(angle) - (InXY.y - ReXY.y) * sin(angle);
				//OutXY.y = (InXY.x - ReXY.x) * sin(angle) + (InXY.y - ReXY.y) * cos(angle);
				//OutR = InR + ReR;
				OutXY.x = (InXY.x - ReXY.x) * cos(angle) + (InXY.y - ReXY.y) * sin(angle);
				OutXY.y = (-(InXY.x - ReXY.x)) * sin(angle) + (InXY.y - ReXY.y) * cos(angle);
				OutR = InR - ReR;
			}
			else
			{
				// �ֲ���ȫ�֣�����ת��ƽ��
				angle = ReR / 180 * PI;
				//OutXY.x = ReXY.x + InXY.x * cos(angle) + InXY.y * sin(angle);
				//OutXY.y = ReXY.y - InXY.x * sin(angle) + InXY.y * cos(angle);
				//OutR = InR - ReR;
				OutXY.x = ReXY.x + InXY.x * cos(angle) - InXY.y * sin(angle);
				OutXY.y = ReXY.y + InXY.x * sin(angle) + InXY.y * cos(angle);
				OutR = InR + ReR;
			}
		}
		break;
		default:
			break;
		}
	}

	void CoorTrans::CoordinateTransform(Point InXY, double InR, Point ReXY, double InitAngle, CoordinateType Type, Point& OutXY, double& OutR, bool direction)
	{
		double ReR;
		double tempX;
		double tempY;
		switch (Type)
		{
		case CoordinateType::RIGHT_DOWN:
			ReR = InitAngle;
			if (direction)//�ֲ���ȫ��
			{
				//����װԭ������ϵ���м��������ϵ
				//Point TempXY;
				//double TempR;
				//TempXY.x = InXY.y;
				//TempXY.y = InXY.x;
				//TempR = InR - 90;
				//���м�����ϵ��ϵͳPCB����ϵ
				//CoordinateTransform(TempXY, TempR, ReXY, ReR + 90, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				InXY.x = -InXY.x;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			}
			else//ȫ�ֵ��ֲ�
			{
				//ϵͳPCB����ϵ���м��������ϵ
				//Point TempXY;
				//double TempR;
				//CoordinateTransform(InXY, InR, ReXY, ReR + 90, TempXY, TempR, CoordinateType::RIGHT_DOWN, direction);
				//OutXY.x = TempXY.y;
				//OutXY.y = TempXY.x;
				//OutR = TempR - 90;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				//���м�����ϵ����װԭ������ϵ
				OutXY.x = -OutXY.x;
			}
			break;
		case CoordinateType::LEFT_DOWN:
			ReR = InitAngle;
			CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			break;
		case CoordinateType::RIGHT_UP:
			//ReR = InitAngle - 180;
			//CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			ReR = InitAngle;
			if (direction)//�ֲ���ȫ��
			{
				InXY.x = -InXY.x;
				InXY.y = -InXY.y;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			}
			else
			{
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				OutXY.x = -OutXY.x;
				OutXY.y = -OutXY.y;
			}
			break;
		case CoordinateType::LEFT_UP:
			ReR = InitAngle;
			if (direction)//�ֲ���ȫ��
			{
				//����װԭ������ϵ���м��������ϵ
				//Point TempXY;
				//double TempR;
				//TempXY.x = InXY.y;
				//TempXY.y = InXY.x;
				//TempR = InR - 90;
				//���м�����ϵ��ϵͳPCB����ϵ
				//CoordinateTransform(TempXY, TempR, ReXY, ReR - 90, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				InXY.y = -InXY.y;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			}
			else//ȫ�ֵ��ֲ�
			{
				//ϵͳPCB����ϵ���м��������ϵ
				//Point TempXY;
				//double TempR;
				//CoordinateTransform(InXY, InR, ReXY, ReR - 90, TempXY, TempR, CoordinateType::RIGHT_DOWN, direction);
				//OutXY.x = TempXY.y;
				//OutXY.y = TempXY.x;
				//OutR = TempR + 90;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				//���м�����ϵ����װԭ������ϵ
				OutXY.y = -OutXY.y;
			}
			break;
		default:
			break;
		}
	}

	void CoorTrans::ArrayToMechanicalStageConvert(CoordinateTransfParameters& m_CoorPara)
	{
		m_CoorPara.TargetCoor = m_CoorPara.SourceCoor;
		m_CoorPara.TargetR = m_CoorPara.SourceR;
		//Դ����ϵ����
		switch (m_CoorPara.GetSourceCoorSystem())
		{
		case CoordinateSystem::ArrayCoorSystem:
		{
			//�ж�Ŀ������ϵ
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::ArrayCoorSystem)
			{
				break;
			}

			//��ȡƴ��ԭ������
			Point TempPoint;
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetY();
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetX();
			//��ȡƴ����ת�Ƕ�
			double Theta = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetR();

			//����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, true);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			//ƴ������ϵת����������ϵ
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::BlockCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::BlockCoorSystem:
		{
			//�ж�Ŀ������ϵ
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::BlockCoorSystem)
			{
				break;
			}

			//��ȡ��ԭ������
			Point TempPoint;
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetX();
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetY();
			//����ת�Ƕ�
			double BlockR = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetR();

			//����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, BlockR, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, true);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			//������ϵת����װԭ������ϵ
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::MountOriginCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::MountOriginCoorSystem:
		{
			//�ж�Ŀ������ϵ
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::MountOriginCoorSystem)
			{
				break;
			}

			//��ȡ��װԭ������
			Point TempPoint = m_CoorPara.m_cBaseBoard->GetBaseBoardOrigin();

			//��ȡ��װԭ������ϵ����
			CoordinateType Type = m_CoorPara.m_cBaseBoard->GetCoordinateType();

			//��ȡ���ӳ�ʼ���Ƕ�
			double Theta = m_CoorPara.m_cBaseBoard->GetBaseBoardInitinalTheta() * 180 / PI;

			//����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, Type, m_CoorPara.TargetCoor, m_CoorPara.TargetR, true);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			//��װԭ������ϵת����PCB����ϵ
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::PCBCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::PCBCoorSystem:
		{
			//�ж�Ŀ������ϵ
			/*if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::PCBCoorSystem)
			{
				break;
			}
			��ȡֹ���������
			Point pStopper = ASContext::GetInstance().GetMountMachine()->GetConveyorPara().GetSensorPos(m_CoorPara.station);

			����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, pStopper, 0, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, true);

			m_CoorPara.SetCoordinateSystem(CoordinateSystem::MechanicalCoorSystem, m_CoorPara.GetTargetCoorSystem());*/
		}
		[[fallthrough]];

		case CoordinateSystem::MechanicalCoorSystem:
		{
			//�ж�Ŀ������ϵ
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::MechanicalCoorSystem)
			{
				break;
			}
		}
		break;
		default:
			break;
		}
	}

	void CoorTrans::MechanicalToArrayStageConvert(CoordinateTransfParameters& m_CoorPara)
	{
		m_CoorPara.TargetCoor = m_CoorPara.SourceCoor;
		m_CoorPara.TargetR = m_CoorPara.SourceR;
		switch (m_CoorPara.GetSourceCoorSystem())
		{
		case CoordinateSystem::MechanicalCoorSystem:
		{
			//�ж�Ŀ������ϵ�Ƿ����
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::MechanicalCoorSystem)
			{
				break;
			}

			//��ȡֹ���������
			//Point pStopper = ASContext::GetInstance().GetMountMachine()->GetConveyorPara().GetSensorPos(m_CoorPara.station);

			//����ת��
			//CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, pStopper, 0, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, false);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			m_CoorPara.SetCoordinateSystem(CoordinateSystem::PCBCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;

		}
		[[fallthrough]];

		case CoordinateSystem::PCBCoorSystem:
		{
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::PCBCoorSystem)
			{
				break;
			}

			//��ȡ��װԭ������
			Point TempPoint = m_CoorPara.m_cBaseBoard->GetBaseBoardOrigin();

			//��ȡ��װԭ������ϵ����
			CoordinateType Type = m_CoorPara.m_cBaseBoard->GetCoordinateType();

			//��ȡ���ӳ�ʼ���Ƕ�
			double Theta = m_CoorPara.m_cBaseBoard->GetBaseBoardInitinalTheta() * 180 / PI;

			//����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, Type, m_CoorPara.TargetCoor, m_CoorPara.TargetR, false);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			m_CoorPara.SetCoordinateSystem(CoordinateSystem::MountOriginCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::MountOriginCoorSystem:
		{
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::MountOriginCoorSystem)
			{
				break;
			}

			//��ȡ��ԭ������
			Point TempPoint;
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetX();
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetY();

			//����ת�Ƕ�
			double BlockR = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetR();

			//����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, BlockR, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, false);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::BlockCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::BlockCoorSystem:
		{
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::BlockCoorSystem)
			{
				break;
			}

			//��ȡƴ��ԭ������
			Point TempPoint;
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetX();
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetY();

			//��ȡƴ����ת�Ƕ�
			double Theta = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetR();

			//����ת��
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, false);

			//�޸�Դ����λ��
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			m_CoorPara.SetCoordinateSystem(CoordinateSystem::ArrayCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::ArrayCoorSystem:
		{
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::ArrayCoorSystem)
			{
				break;
			}
		}
		[[fallthrough]];

		break;

		default:
			break;
		}
	}
}
