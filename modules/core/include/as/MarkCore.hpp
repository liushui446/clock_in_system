#ifndef AS_MARKCORE_HPP
#define AS_MARKCORE_HPP
//#include"aoi/ComponentCommonCore.hpp"
#include "as/CommonCore.hpp"

namespace as
{
	class MarkPart;
}

namespace boost
{
	namespace serialization
	{
		//template <class Archive>
		//extern void serialize(Archive& ar, aoi::MarkPart& val, const unsigned int version);
	}
}

namespace as
{
	/// <summary>
	/// 校正方式
	/// </summary>
	enum CorrectionType
	{
		graphic = 0,				// 图像
		barycenter = 1,          // 重心
		ellipse = 2,                 // 椭圆
		rect = 3,                     // 矩形
	};

	/// <summary>
	/// 返回结果(Mark点测试时输出使用)
	/// </summary>
	struct MarkTestResult
	{
		std::string error_exp = "";      // “NG”/“OK”
		float return_value = -1;            // 返回值
		float error_range = 0;             //误差范围
		int polarity;                    //0：白色，1：黑色+

	};

	struct MarkOffset
	{
		float m_offset_x;                 //x方向的偏移
		float m_offset_y;                 //y方向的偏移
	};

	class AS_EXPORTS MarkPart //:public AlgorithmParam
	{
	public:
		MarkPart();
		~MarkPart();
		MarkPart& operator=(MarkPart& ref);

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, MarkPart& val, const unsigned int version);

		inline int getBrightness();
		inline void SetBrightness(int val);

		inline int getContrast();
		inline void SetContrast(int val);

		inline double getCenterX();
		inline void SetCenterX(double val);

		inline double getCenterY();
		inline void SetCenterY(double val);

		inline double getWidth();
		inline void SetWidth(double val);

		inline double getHeight();
		inline void SetHeight(double val);

		inline CorrectionType getCorrectiontype();
		inline void SetCorrectiontype(CorrectionType val);

		inline MarkTestResult& getMarkTestResult();
		inline void SetMarkTestResult(MarkTestResult val);

		inline MarkOffset& getMarkOffset();
		inline void SetMarkOffset(MarkOffset val);

		inline int getCriticalvalue();
		inline void SetCriticalvalue(int val);

		inline int getThresholdvalue();
		inline void SetThresholdvalue(int val);

		inline int getDeviationvalue();
		inline void SetDeviationvalue(int val);
	private:
		int mark_Criticalvalue;			//临界值
		int mark_Deviationvalue;		//偏差值
		int mbrightness;      //亮度
		int mcontrast;        //对比度
		int Threshold ;	      //阈值
		double mcenterX;      //中心X
		double mcenterY;      //中心Y
		double mwidth;        //宽
		double mheight;       //高
		CorrectionType mcorrectiontype;
		MarkTestResult mMarkTestResult;
		MarkOffset mMarkoffset;
	};

	typedef std::shared_ptr<MarkPart> MarkPartPtr;
	typedef std::shared_ptr<const MarkPart> MarkPartConstPtr;

}

#endif