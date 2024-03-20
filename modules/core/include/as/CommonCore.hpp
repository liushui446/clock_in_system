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
	//AOI注册元件标准、生产的应用模式(检测模式)
	enum class DefectMode
	{
		SMTMode = 1,        //SMT检测模式
		WaveSolderMode = 2, //波峰焊检测模式
		HGMode = 3,         //红胶检测模式
		HASLMode = 4,       //喷锡板检测模式
		FurnaceFront = 5,   //炉前检测模式
	};

	// 坐标系统方向
	enum class CoordinateType
	{
		RIGHT_DOWN = 0,         // 右下方向
		LEFT_DOWN = 1,				// 左下方向
		RIGHT_UP = 2,				// 右上方向
		LEFT_UP = 3				// 左上方向
	};

	enum class CoordinateSystem
	{
		MechanicalCoorSystem = 0,	//机械坐标系
		PCBCoorSystem,				//标定坐标系
		MountOriginCoorSystem,		//贴装原点坐标
		BlockCoorSystem,			//块坐标系
		ArrayCoorSystem				//拼板坐标系
	};

	//传送带站点
	enum class Station
	{
		StationF1 = 0,       // 前轨道站1
		StationF2,
		StationF3,
		size
	};

	//多轨道定义
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