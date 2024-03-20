#include "as/CoorTrans.hpp"
namespace as 
{

	CoordinateTransfParameters::CoordinateTransfParameters()
	{
		SourceR = 0;														//输入参数：当前坐标系角度R
		BlockNum = 1;														//输入参数：块号		
		ArrayNum = 1;														//输入参数：拼板号
		CoordinateKind = CoordinateType::RIGHT_DOWN;						//输入参数：坐标系类型
		TargetR = 0;														//输出参数：目标坐标角度R
		station = Station::StationF2;

		SourceCoorSystem = CoordinateSystem::MechanicalCoorSystem;			//输入参数：当前坐标系
		TargetCoorSystem = CoordinateSystem::MechanicalCoorSystem;			//输入参数：目标坐标系
		m_cBaseBoard = as::ASContext::GetInstance().GetBaseBoard();

	}
	CoordinateTransfParameters::~CoordinateTransfParameters()
	{

	}
	/**
		*函数名：	GetSourceCoorSystem
		*函数作用：	获得当前坐标系
		*
		*参数说明：
		*	无
		*
		*返回值：
		*	@retrun 坐标系
		*/
	CoordinateSystem CoordinateTransfParameters::GetSourceCoorSystem()
	{
		return SourceCoorSystem;
	}
	/**
		*函数名：	GetTargetCoorSystem
		*函数作用：	获得目标坐标系
		*
		*参数说明：
		*	无
		*
		*返回值：
		*	@retrun 坐标系
		*/
	CoordinateSystem CoordinateTransfParameters::GetTargetCoorSystem()
	{
		return TargetCoorSystem;
	}
	/**
		*函数名：	SetCoordinateSystem
		*函数作用：	设置坐标系转换的当前坐标系和目标坐标系
		*
		*参数说明：
		*	@param 	const CoordinateSystem : 输入参数。当前坐标系。
		*	@param 	const CoordinateSystem : 输入参数。目标坐标系。
		*
		*返回值：
		*	@retrun 无
		*/
	void CoordinateTransfParameters::SetCoordinateSystem(const CoordinateSystem source_coor, const CoordinateSystem target_coor)
	{
		SourceCoorSystem = source_coor;
		TargetCoorSystem = target_coor;
	}

	/**
		*函数名：	CoordinateTransform
		*函数作用：	坐标转换
		*
		*参数说明：
		*	@param 	InXY : 输入参数。相对于输入坐标系的坐标(x,y)。
		*	@param 	InR : 输入参数。相对于输入坐标系的坐标(r)。
		*	@param 	ReXY : 输入参数。输入坐标系相对于输出坐标系的平移坐标(x,y)，SMT中实际上是指局部坐标系相对于全局坐标系，当从全局坐标系向局部坐标系转换时，在函数中对Re进行了变换使之成为全局坐标系相对于局部坐标系。
		*	@param 	ReR : 输入参数。输入坐标系相对于输出坐标系的旋转坐标(r)，SMT中实际上是指局部坐标系相对于全局坐标系，当从全局坐标系向局部坐标系转换时，在函数中对Re进行了变换使之成为全局坐标系相对于局部坐标系。
		*	@param 	OutXY : 输入参数。相对于输出坐标系的坐标(x,y)。
		*	@param 	OutR : 输入参数。相对于输出坐标系的坐标(r)。
		*	@param 	CoordinateKind : 输入参数。0表示右手系，1表示左手系。
		*	@param 	Direction : 输入参数。坐标转换方向，ture表示从局部坐标系向全局坐标系转换，即拼板坐标系-->块坐标系-->基板坐标系-->系统PCB坐标系，false表示从全局坐标系向局部坐标系转换，即PCB系统坐标系-->基板坐标系-->块坐标系-->拼板坐标系。
		*
		*返回值：
		*	@return 空。
		*/

	CoorTrans::CoorTrans()
	{
	}

	void CoorTrans::CoordinateTransform(Point InXY, double InR, Point ReXY, double ReR, Point& OutXY, double& OutR, CoordinateType Coordinatetype, bool direction)
	{
		int CoordinateKind = 0;
		if (Coordinatetype == CoordinateType::LEFT_UP || Coordinatetype == CoordinateType::RIGHT_DOWN)
		{
			CoordinateKind = 0;//右手系
		}
		else
		{
			CoordinateKind = 1;//左手系
		}

		switch (CoordinateKind)
		{
		case 0://右手系
		{
			double angle;
			if (!direction)
			{
				// 全局到局部，先平移再旋转
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
				// 局部到全局，先旋转在平移
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
		case 1:// 左手系
		{
			double angle;
			if (!direction)
			{
				// 全局到局部，先平移再旋转
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
				// 局部到全局，先旋转在平移
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
			if (direction)//局部到全局
			{
				//从贴装原点坐标系到中间过渡坐标系
				//Point TempXY;
				//double TempR;
				//TempXY.x = InXY.y;
				//TempXY.y = InXY.x;
				//TempR = InR - 90;
				//从中间坐标系到系统PCB坐标系
				//CoordinateTransform(TempXY, TempR, ReXY, ReR + 90, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				InXY.x = -InXY.x;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			}
			else//全局到局部
			{
				//系统PCB坐标系到中间过渡坐标系
				//Point TempXY;
				//double TempR;
				//CoordinateTransform(InXY, InR, ReXY, ReR + 90, TempXY, TempR, CoordinateType::RIGHT_DOWN, direction);
				//OutXY.x = TempXY.y;
				//OutXY.y = TempXY.x;
				//OutR = TempR - 90;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				//从中间坐标系到贴装原点坐标系
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
			if (direction)//局部到全局
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
			if (direction)//局部到全局
			{
				//从贴装原点坐标系到中间过渡坐标系
				//Point TempXY;
				//double TempR;
				//TempXY.x = InXY.y;
				//TempXY.y = InXY.x;
				//TempR = InR - 90;
				//从中间坐标系到系统PCB坐标系
				//CoordinateTransform(TempXY, TempR, ReXY, ReR - 90, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				InXY.y = -InXY.y;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
			}
			else//全局到局部
			{
				//系统PCB坐标系到中间过渡坐标系
				//Point TempXY;
				//double TempR;
				//CoordinateTransform(InXY, InR, ReXY, ReR - 90, TempXY, TempR, CoordinateType::RIGHT_DOWN, direction);
				//OutXY.x = TempXY.y;
				//OutXY.y = TempXY.x;
				//OutR = TempR + 90;
				CoordinateTransform(InXY, InR, ReXY, ReR, OutXY, OutR, CoordinateType::RIGHT_DOWN, direction);
				//从中间坐标系到贴装原点坐标系
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
		//源坐标系类型
		switch (m_CoorPara.GetSourceCoorSystem())
		{
		case CoordinateSystem::ArrayCoorSystem:
		{
			//判断目标坐标系
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::ArrayCoorSystem)
			{
				break;
			}

			//获取拼板原点坐标
			Point TempPoint;
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetY();
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetX();
			//获取拼板旋转角度
			double Theta = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetR();

			//坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, true);

			//修改源坐标位置
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			//拼板坐标系转换到块坐标系
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::BlockCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::BlockCoorSystem:
		{
			//判断目标坐标系
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::BlockCoorSystem)
			{
				break;
			}

			//获取块原点坐标
			Point TempPoint;
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetX();
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetY();
			//块旋转角度
			double BlockR = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetR();

			//坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, BlockR, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, true);

			//修改源坐标位置
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			//块坐标系转换贴装原点坐标系
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::MountOriginCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::MountOriginCoorSystem:
		{
			//判断目标坐标系
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::MountOriginCoorSystem)
			{
				break;
			}

			//获取贴装原点坐标
			Point TempPoint = m_CoorPara.m_cBaseBoard->GetBaseBoardOrigin();

			//获取贴装原点坐标系类型
			CoordinateType Type = m_CoorPara.m_cBaseBoard->GetCoordinateType();

			//获取板子初始化角度
			double Theta = m_CoorPara.m_cBaseBoard->GetBaseBoardInitinalTheta() * 180 / PI;

			//坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, Type, m_CoorPara.TargetCoor, m_CoorPara.TargetR, true);

			//修改源坐标位置
			m_CoorPara.SourceCoor = m_CoorPara.TargetCoor;

			//贴装原点坐标系转换到PCB坐标系
			m_CoorPara.SetCoordinateSystem(CoordinateSystem::PCBCoorSystem, m_CoorPara.GetTargetCoorSystem());
			m_CoorPara.SourceR = m_CoorPara.TargetR;
		}
		[[fallthrough]];

		case CoordinateSystem::PCBCoorSystem:
		{
			//判断目标坐标系
			/*if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::PCBCoorSystem)
			{
				break;
			}
			获取止档块的坐标
			Point pStopper = ASContext::GetInstance().GetMountMachine()->GetConveyorPara().GetSensorPos(m_CoorPara.station);

			坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, pStopper, 0, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, true);

			m_CoorPara.SetCoordinateSystem(CoordinateSystem::MechanicalCoorSystem, m_CoorPara.GetTargetCoorSystem());*/
		}
		[[fallthrough]];

		case CoordinateSystem::MechanicalCoorSystem:
		{
			//判断目标坐标系
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
			//判断目标坐标系是否相等
			if (m_CoorPara.GetTargetCoorSystem() == CoordinateSystem::MechanicalCoorSystem)
			{
				break;
			}

			//获取止档块的坐标
			//Point pStopper = ASContext::GetInstance().GetMountMachine()->GetConveyorPara().GetSensorPos(m_CoorPara.station);

			//坐标转换
			//CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, pStopper, 0, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, false);

			//修改源坐标位置
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

			//获取贴装原点坐标
			Point TempPoint = m_CoorPara.m_cBaseBoard->GetBaseBoardOrigin();

			//获取贴装原点坐标系类型
			CoordinateType Type = m_CoorPara.m_cBaseBoard->GetCoordinateType();

			//获取板子初始化角度
			double Theta = m_CoorPara.m_cBaseBoard->GetBaseBoardInitinalTheta() * 180 / PI;

			//坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, Type, m_CoorPara.TargetCoor, m_CoorPara.TargetR, false);

			//修改源坐标位置
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

			//获取块原点坐标
			Point TempPoint;
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetX();
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetY();

			//块旋转角度
			double BlockR = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetOriginOffsetR();

			//坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, BlockR, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, false);

			//修改源坐标位置
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

			//获取拼板原点坐标
			Point TempPoint;
			TempPoint.x = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetX();
			TempPoint.y = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetY();

			//获取拼板旋转角度
			double Theta = m_CoorPara.m_cBaseBoard->GetBlockContent(m_CoorPara.BlockNum)->GetArrayContent(m_CoorPara.ArrayNum)->GetOriginOffsetR();

			//坐标转换
			CoordinateTransform(m_CoorPara.SourceCoor, m_CoorPara.SourceR, TempPoint, Theta, m_CoorPara.TargetCoor, m_CoorPara.TargetR, m_CoorPara.CoordinateKind, false);

			//修改源坐标位置
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
