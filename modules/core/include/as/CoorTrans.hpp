#ifndef AS_COORTRANS_HPP
#define AS_COORTRANS_HPP

#include "as/CommonCore.hpp"
#include "as/ASContext.hpp"

namespace as
{
	/*
	* 类名：CoordinateTransfParameters
	* 创建日期： 2023/5/18
	* By czn
	*	@file	FCoordinateTransf.hpp
	*	@brief	坐标转换参数类
	*	@version 1.0
	*/
	class AS_EXPORTS CoordinateTransfParameters
	{
	public:
		CoordinateTransfParameters();
		~CoordinateTransfParameters();

		Point SourceCoor;					//输入参数：源坐标位置
		double SourceR;						//输入参数：当前坐标系角度R
		int BlockNum;						//输入参数：块号		
		int ArrayNum;						//输入参数：拼板号
		shared_ptr<BaseBoard> m_cBaseBoard; //板子指针
		CoordinateType CoordinateKind;		//输入参数：坐标系类型
		Station station;                    //输入参数：站号
		Point TargetCoor;					//输出参数：目标坐标位置
		double TargetR;						//输出参数：目标坐标角度

		CoordinateSystem GetSourceCoorSystem();
		CoordinateSystem GetTargetCoorSystem();
		void SetCoordinateSystem(const CoordinateSystem source_coor, const CoordinateSystem target_coor = CoordinateSystem::MechanicalCoorSystem);

	private:
		CoordinateSystem SourceCoorSystem;			//输入参数：当前坐标系
		CoordinateSystem TargetCoorSystem;			//输入参数：目标坐标系
	};

	class AS_EXPORTS CoorTrans
	{
	private:
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
		void CoordinateTransform(Point InXY, double InR, Point ReXY, double ReR, Point& OutXY, double& OutR, CoordinateType CoordinateKind, bool direction);

		/**
		*函数名：	CoordinateTransform
		*函数作用：	坐标转换,用于贴装原点坐标系与系统PCB坐标系之间的转换
		*
		*参数说明：
		*	@param 	InXY : 输入参数。相对于输入坐标系的坐标(x,y)。
		*	@param 	InR : 输入参数。相对于输入坐标系的坐标(r)。
		*	@param 	ReXY : 输入参数。输入坐标系相对于输出坐标系的平移坐标(x,y)，SMT中实际上是指局部坐标系相对于全局坐标系，当从全局坐标系向局部坐标系转换时，在函数中对Re进行了变换使之成为全局坐标系相对于局部坐标系。
		*	@param 	InitAngle : 输入参数。基板偏转角度。
		*	@param 	Type : 输入参数。基板坐标类型。
		*	@param 	OutXY : 输入参数。相对于输出坐标系的坐标(x,y)。
		*	@param 	OutR : 输入参数。相对于输出坐标系的坐标(r)。
		*	@param 	Direction : 输入参数。坐标转换方向，ture表示从局部坐标系向全局坐标系转换，即拼板坐标系-->块坐标系-->基板坐标系-->系统PCB坐标系，false表示从全局坐标系向局部坐标系转换，即PCB系统坐标系-->基板坐标系-->块坐标系-->拼板坐标系。
		*
		*返回值：
		*	@return 空。
		*/
		void CoordinateTransform(Point InXY, double InR, Point ReXY, double InitAngle, CoordinateType Type, Point& OutXY, double& OutR, bool direction);

	public:
		CoorTrans();
		/**
		*函数名：	ArrayToMechanicalStageConvert
		*函数作用：	拼板坐标系到机械坐标系各个阶段转换过程，，通过Point中的坐标系类型，将坐标从源坐标系（SourceCoor）转换到目标坐标系（TargetCoor）
		*
		*参数说明：
		*	@param 	m_CoorPara : 参数类
		*
		*返回值：
		*	@return 空。
		*/
		void ArrayToMechanicalStageConvert(CoordinateTransfParameters& m_CoorPara);

		/**
		*函数名：	MechanicalToArrayStageConvert
		*函数作用：	机械坐标系到拼板坐标系各个阶段转换过程，通过Point中的坐标系类型，将坐标从源坐标系（SourceCoor）转换到目标坐标系（TargetCoor）
		*
		*参数说明：
		*	@param 	m_CoorPara : 参数类
		*
		*返回值：
		*	@return 空。
		*/
		void MechanicalToArrayStageConvert(CoordinateTransfParameters& m_CoorPara);
	};

}
#endif