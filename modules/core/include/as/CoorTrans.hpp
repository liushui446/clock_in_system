#ifndef AS_COORTRANS_HPP
#define AS_COORTRANS_HPP

#include "as/CommonCore.hpp"
#include "as/ASContext.hpp"

namespace as
{
	/*
	* ������CoordinateTransfParameters
	* �������ڣ� 2023/5/18
	* By czn
	*	@file	FCoordinateTransf.hpp
	*	@brief	����ת��������
	*	@version 1.0
	*/
	class AS_EXPORTS CoordinateTransfParameters
	{
	public:
		CoordinateTransfParameters();
		~CoordinateTransfParameters();

		Point SourceCoor;					//���������Դ����λ��
		double SourceR;						//�����������ǰ����ϵ�Ƕ�R
		int BlockNum;						//������������		
		int ArrayNum;						//���������ƴ���
		shared_ptr<BaseBoard> m_cBaseBoard; //����ָ��
		CoordinateType CoordinateKind;		//�������������ϵ����
		Station station;                    //���������վ��
		Point TargetCoor;					//���������Ŀ������λ��
		double TargetR;						//���������Ŀ������Ƕ�

		CoordinateSystem GetSourceCoorSystem();
		CoordinateSystem GetTargetCoorSystem();
		void SetCoordinateSystem(const CoordinateSystem source_coor, const CoordinateSystem target_coor = CoordinateSystem::MechanicalCoorSystem);

	private:
		CoordinateSystem SourceCoorSystem;			//�����������ǰ����ϵ
		CoordinateSystem TargetCoorSystem;			//���������Ŀ������ϵ
	};

	class AS_EXPORTS CoorTrans
	{
	private:
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
		void CoordinateTransform(Point InXY, double InR, Point ReXY, double ReR, Point& OutXY, double& OutR, CoordinateType CoordinateKind, bool direction);

		/**
		*��������	CoordinateTransform
		*�������ã�	����ת��,������װԭ������ϵ��ϵͳPCB����ϵ֮���ת��
		*
		*����˵����
		*	@param 	InXY : ����������������������ϵ������(x,y)��
		*	@param 	InR : ����������������������ϵ������(r)��
		*	@param 	ReXY : �����������������ϵ������������ϵ��ƽ������(x,y)��SMT��ʵ������ָ�ֲ�����ϵ�����ȫ������ϵ������ȫ������ϵ��ֲ�����ϵת��ʱ���ں����ж�Re�����˱任ʹ֮��Ϊȫ������ϵ����ھֲ�����ϵ��
		*	@param 	InitAngle : �������������ƫת�Ƕȡ�
		*	@param 	Type : ��������������������͡�
		*	@param 	OutXY : ���������������������ϵ������(x,y)��
		*	@param 	OutR : ���������������������ϵ������(r)��
		*	@param 	Direction : �������������ת������ture��ʾ�Ӿֲ�����ϵ��ȫ������ϵת������ƴ������ϵ-->������ϵ-->��������ϵ-->ϵͳPCB����ϵ��false��ʾ��ȫ������ϵ��ֲ�����ϵת������PCBϵͳ����ϵ-->��������ϵ-->������ϵ-->ƴ������ϵ��
		*
		*����ֵ��
		*	@return �ա�
		*/
		void CoordinateTransform(Point InXY, double InR, Point ReXY, double InitAngle, CoordinateType Type, Point& OutXY, double& OutR, bool direction);

	public:
		CoorTrans();
		/**
		*��������	ArrayToMechanicalStageConvert
		*�������ã�	ƴ������ϵ����е����ϵ�����׶�ת�����̣���ͨ��Point�е�����ϵ���ͣ��������Դ����ϵ��SourceCoor��ת����Ŀ������ϵ��TargetCoor��
		*
		*����˵����
		*	@param 	m_CoorPara : ������
		*
		*����ֵ��
		*	@return �ա�
		*/
		void ArrayToMechanicalStageConvert(CoordinateTransfParameters& m_CoorPara);

		/**
		*��������	MechanicalToArrayStageConvert
		*�������ã�	��е����ϵ��ƴ������ϵ�����׶�ת�����̣�ͨ��Point�е�����ϵ���ͣ��������Դ����ϵ��SourceCoor��ת����Ŀ������ϵ��TargetCoor��
		*
		*����˵����
		*	@param 	m_CoorPara : ������
		*
		*����ֵ��
		*	@return �ա�
		*/
		void MechanicalToArrayStageConvert(CoordinateTransfParameters& m_CoorPara);
	};

}
#endif