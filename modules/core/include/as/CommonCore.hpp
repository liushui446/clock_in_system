#ifndef COMMONCORE_HPP
#define COMMONCORE_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <mutex>
#include <fstream>
#include <unordered_map>

#include "as/core/def.h"
#include "as/ErrorCode.hpp"

using std::cout;
using std::endl;
using std::map;
using std::set;
using std::pair;
using std::deque;
using std::vector;
using std::string;
using std::to_string;
using std::shared_ptr;
using std::make_shared;
using std::for_each;
using std::mutex;
using std::function;
using std::condition_variable;
using std::ifstream;
using std::ofstream;
using std::thread;
using std::dynamic_pointer_cast;
using std::tuple;

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef double				DOUBLE;
typedef int                 INT;
typedef unsigned int        UINT;

#define PI 3.1415926
namespace as
{
	class Point;
}

namespace boost
{
	namespace serialization
	{
		//template <class Archive>
		//void serialize(Archive& ar, aoi::Point& val, const unsigned int version);
	}
}


namespace as
{
	//AOIע��Ԫ����׼��������Ӧ��ģʽ(���ģʽ)
	enum class DefectMode
	{
		SMTMode = 1,        //SMT���ģʽ
		WaveSolderMode = 2, //���庸���ģʽ
		HGMode = 3,         //�콺���ģʽ
		HASLMode = 4,       //��������ģʽ
		FurnaceFront = 5,   //¯ǰ���ģʽ
	};

	// ����ϵͳ����
	enum class CoordinateType
	{
		RIGHT_DOWN = 0,         // ���·���
		LEFT_DOWN = 1,				// ���·���
		RIGHT_UP = 2,				// ���Ϸ���
		LEFT_UP = 3				// ���Ϸ���
	};

	enum class CoordinateSystem
	{
		MechanicalCoorSystem = 0,	//��е����ϵ
		PCBCoorSystem,				//�궨����ϵ
		MountOriginCoorSystem,		//��װԭ������
		BlockCoorSystem,			//������ϵ
		ArrayCoorSystem				//ƴ������ϵ
	};

	//���ʹ�վ��
	enum class Station
	{
		StationF1 = 0,       // ǰ���վ1
		StationF2,
		StationF3,
		size
	};

	//��������
	enum class Orbit
	{
		Orbit_FRONT = 1,
		Orbit_BEHIND,
	};

	class  AS_EXPORTS Point
	{
	public:
		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, Point& val, const unsigned int version);

		Point();
		Point(double _x, double _y);
		Point(const Point& pt);
		Point& operator = (const Point& pt);
		Point operator + (const Point& pt);
		Point& operator += (const Point& pt);
		Point operator - (const Point& pt);
		Point& operator -= (const Point& pt);
		Point operator * (const int val);
		Point& operator *= (const int val);
		Point operator / (const int val);
		Point& operator /= (const int val);
		bool operator==(const Point p);
		void setPoint(double _x, double _y);
		void setPointX(double _x);
		void setPointY(double _y);
		void setPoint(Point pos);
		double getPintX();
		double getPintY();

		double x;
		double y;
	};
}
#endif