#include "as/MarkCore.hpp"

namespace as
{
	MarkPart::MarkPart()
	{
		/*this->SetAlgorithmTypeData(AlgorithmType::Match);
		this->SetColorChannelData(ColorChannel::RGB);
		this->SetColorMethodData(ColorMethod::average);
		this->SetDetectionTypeData(DetectionType::BodyDot);
		this->SetCorrectiontype(CorrectionType::graphic);*/

		mcorrectiontype = CorrectionType::rect;
		mark_Criticalvalue = 0;
		mark_Deviationvalue = 0;
		mcenterX = -2;
		mcenterY = -2;
		mwidth = 4;
		mheight = 4;
		mbrightness = 50;
		mcontrast = 50;
		Threshold = 40;
	}

	MarkPart::~MarkPart()
	{
	}

	MarkPart& MarkPart::operator=(MarkPart& ref)
	{
		/*this->SetAlgorithmTypeData(ref.getAlgorithmTypeData());
		this->SetColorChannelData(ref.getColorChannelData());
		this->SetColorMethodData(ref.getColorMethodData());
		this->SetDetectionTypeData(ref.getDetectionTypeData());
		this->SetSearchScopeData(ref.getSearchScopeData());
		this->SetAllowOffsetData(ref.getAllowOffsetData());
		this->SetReturnValue(ref.getReturnValue());
		this->SetReturnValue(ref.getReturnValue());
		this->SetColorStandard(ref.getColorStandard());*/

		this->mark_Criticalvalue = ref.getCriticalvalue();
		this->mark_Deviationvalue = ref.getDeviationvalue();
		this->mbrightness = ref.getBrightness();
		this->mcontrast = ref.getContrast();
		this->mcenterX = ref.getCenterX();
		this->mcenterY = ref.getCenterY();
		this->mwidth = ref.getWidth();
		this->mheight = ref.getHeight();
		this->mcorrectiontype = ref.getCorrectiontype();
		this->mMarkTestResult = ref.getMarkTestResult();
		this->mMarkoffset = ref.getMarkOffset();
		return *this;
	}

	int MarkPart::getBrightness() 
	{ 
		return mbrightness;
	}

	void MarkPart::SetBrightness(int val) 
	{ 
		mbrightness = val; 
	}

	int MarkPart::getContrast() 
	{ 
		return mcontrast; 
	}

	void MarkPart::SetContrast(int val)
	{ 
		mcontrast = val; 
	}

	double MarkPart::getCenterX()
	{
		return mcenterX;
	}

	void MarkPart::SetCenterX(double val)
	{ 
		mcenterX = val; 
	}

	double MarkPart::getCenterY()
	{ 
		return mcenterY;
	}

	void MarkPart::SetCenterY(double val)
	{ 
		mcenterY = val; 
	}

	double MarkPart::getWidth()
	{ 
		return mwidth;
	}

	void MarkPart::SetWidth(double val)
	{ 
		mwidth = val;
	}

	double MarkPart::getHeight()
	{ 
		return mheight; 
	}

	void MarkPart::SetHeight(double val)
	{
		mheight = val; 
	}

	CorrectionType MarkPart::getCorrectiontype() 
	{ 
		return mcorrectiontype; 
	}

	void MarkPart::SetCorrectiontype(CorrectionType val)
	{ 
		mcorrectiontype = val; 
	}

	MarkTestResult& MarkPart::getMarkTestResult()
	{
		return mMarkTestResult;
	}

	void MarkPart::SetMarkTestResult(MarkTestResult val)
	{ 
		mMarkTestResult = val;
	}

	MarkOffset& MarkPart::getMarkOffset() 
	{ 
		return mMarkoffset;
	}

	void MarkPart::SetMarkOffset(MarkOffset val)
	{ 
		mMarkoffset = val; 
	}

	int MarkPart::getCriticalvalue() 
	{ 
		return mark_Criticalvalue; 
	}

	void MarkPart::SetCriticalvalue(int val) 
	{ 
		mark_Criticalvalue = val;
	}

	inline int MarkPart::getThresholdvalue()
	{
		return Threshold;
	}

	inline void MarkPart::SetThresholdvalue(int val)
	{
		Threshold = val;
	}

	int MarkPart::getDeviationvalue()
	{ 
		return mark_Deviationvalue; 
	}

	void MarkPart::SetDeviationvalue(int val) 
	{ 
		mark_Deviationvalue = val;
	}
}