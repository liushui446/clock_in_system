#ifndef AS_CONTEXT_HPP
#define AS_CONTEXT_HPP

#include "as/core/def.h"
#include "as/BaseBoardCore.hpp"
#include "as/PadCore.hpp"
namespace as
{
	class ASContext;
	class FileSerialize;
}

namespace boost
{
	/*namespace serialization
	{
		template <class Archive>
		void serialize(Archive& ar, aoi::AOIContext& val, const unsigned int version);
	}*/
}

namespace as
{
	/*
	* ������ASContext
	* �������ڣ� 2023/10/13
	* By ypk
	*	@file	ASContext.hpp
	*	@brief	SPI&AOI��Ҫ���ݴ洢��
	*	@version 1.0
	*/
	class AS_EXPORTS ASContext
	{
	public:
		/*template <class Archive>
		friend void boost::serialization::serialize(Archive& ar, AOIContext& val, const unsigned int version);*/

		ASContext();
		static ASContext& GetInstance();

		shared_ptr<BaseBoard> GetBaseBoard();
		//shared_ptr<MountMachine> GetMountMachine();
		//shared_ptr<CADDetectionData> GetCADDetectionData();
		//shared_ptr<ComponentData> GetComponentData();
		shared_ptr<PadDataSet> GetPadDataSet();
	private:
		shared_ptr<BaseBoard> m_baseboard;			//����
		//shared_ptr<MountMachine> m_mountmachine;	//����
		//shared_ptr<CADDetectionData> m_cad_detection_data;	//CAD����
		//shared_ptr<ComponentData> m_componentData;	//Ԫ������
		shared_ptr<PadDataSet> m_padDataset;        //��������
	};
}


#endif