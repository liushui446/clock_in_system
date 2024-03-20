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
	/// У����ʽ
	/// </summary>
	enum CorrectionType
	{
		graphic = 0,				// ͼ��
		barycenter = 1,          // ����
		ellipse = 2,                 // ��Բ
		rect = 3,                     // ����
	};

	/// <summary>
	/// ���ؽ��(Mark�����ʱ���ʹ��)
	/// </summary>
	struct MarkTestResult
	{
		std::string error_exp = "";      // ��NG��/��OK��
		float return_value = -1;            // ����ֵ
		float error_range = 0;             //��Χ
		int polarity;                    //0����ɫ��1����ɫ+

	};

	struct MarkOffset
	{
		float m_offset_x;                 //x�����ƫ��
		float m_offset_y;                 //y�����ƫ��
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
		int mark_Criticalvalue;			//�ٽ�ֵ
		int mark_Deviationvalue;		//ƫ��ֵ
		int mbrightness;      //����
		int mcontrast;        //�Աȶ�
		int Threshold ;	      //��ֵ
		double mcenterX;      //����X
		double mcenterY;      //����Y
		double mwidth;        //��
		double mheight;       //��
		CorrectionType mcorrectiontype;
		MarkTestResult mMarkTestResult;
		MarkOffset mMarkoffset;
	};

	typedef std::shared_ptr<MarkPart> MarkPartPtr;
	typedef std::shared_ptr<const MarkPart> MarkPartConstPtr;

}

#endif