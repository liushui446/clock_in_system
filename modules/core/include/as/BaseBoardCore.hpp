//#pragma once
#ifndef AS_BASEBOARDCORE_HPP
#define AS_BASEBOARDCORE_HPP

#include "as/CommonCore.hpp"
#include "as/MarkCore.hpp"
//#include "aoi/smt/BaseBoardCore.hpp"

namespace as
{
	class BaseBoard;
	class Block;
	class Array;
	class BadMark;
	class AcceptMark;
	class OFFSET;
	class FiducialMark;
}

namespace boost
{
	/*namespace serialization
	{
		template <class Archive>
		void serialize(Archive& ar, aoi::BaseBoard& val, const unsigned int version);
		template <class Archive>
		void serialize(Archive& ar, aoi::Block& val, const unsigned int version);
		template <class Archive>
		void serialize(Archive& ar, aoi::Array& val, const unsigned int version);
		template <class Archive>
		void serialize(Archive& ar, aoi::BadMark& val, const unsigned int version);
		template <class Archive>
		void serialize(Archive& ar, aoi::AcceptMark& val, const unsigned int version);
		template <class Archive>
		void serialize(Archive& ar, aoi::OFFSET& val, const unsigned int version);
		template <class Archive>
		void serialize(Archive& ar, aoi::FiducialMark& val, const unsigned int version);
	}*/
}

namespace as
{
	class AS_EXPORTS OFFSET {
	public:		
		OFFSET();
		~OFFSET();
		OFFSET& operator=(OFFSET& ref);
		//OFFSET& operator=(sm::OFFSET& ref);

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, OFFSET& val, const unsigned int version);

		double GetOffsetX();
		void SetOffsetX(double offset_x);

		double GetOffsetY();
		void SetOffsetY(double offset_y);

		double GetOffsetR();
		void SetOffsetR(double offset_r);
	//private:	//private:
		double m_x;				// ƫ��X
		double m_y;				// ƫ��Y
		double m_r;             // ��ת�Ƕ�R
	};

	//block ���Ͷ���
	enum class BlockType
	{
		BLOCK_AAAA = 0,         // ��ͬ�飬������������ȫ��ͬ
		BLOCK_ABCD,             // ��ͬ�飬���������ݲ���ͬ
	};

	enum class AS_EXPORTS BoardMarkType
	{
		FIDUCIAL_NONE = 0,		// �޻�׼��
		FIDUCIAL_ARRAY,			// ��׼��Ӧ����ÿ����·
		FIDUCIAL_GLOBAL,		// ��׼��Ӧ����ÿ��block
	};

	// ��������
	enum  class DirectionType
	{
		DIRECTION_X = 0,        // X �������
		DIRECTION_Y             // Y �������
	};

	enum class AS_EXPORTS LogicType
	{
		LOGIC_WHITE = 0,		// ��ɫ
		LOGIC_BLACK				// ��ɫ    
	};
	/*enum class AOI_EXPORTS Orbit
	{
		TRACK_ONE=0,
		TRACK_TWO,
	};*/

	//��׼��
	class AS_EXPORTS FiducialMark
	{
	public:
		FiducialMark();
		FiducialMark& operator=(FiducialMark& ref);
		//FiducialMark& operator=(sm::FiducialMark& ref);

		struct FiducialPos
		{
			double x = 0;					//��׼��λ��X
			double y = 0;					//��׼��λ��Y
			double mark_cal_posx = 0;		//��׼��궨λ��X
			double mark_cal_posy = 0;		//��׼��궨λ��Y
			MarkPart m_cMarkPart;
			vector<unsigned char> m_vImageData;
			bool Reachable = true;                 // ��ǰվ�£���mark��ɷ񵽴�			
		};

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, FiducialMark& val, const unsigned int version);

		int GetFidMarkNum();
		void SetFidMarkNum(int num);

		BoardMarkType GetFidMarkType();
		void SetFidMarkType(BoardMarkType Mark_type);

		APIErrCode GetFiducialMarkFlag();
		void SetFiducialMarkFlag(APIErrCode mark_flag);

		vector<FiducialMark::FiducialPos> GetAllFiducialPos();
		void ClearAllFiducialPos();
		Point GetFiducialXYPos(int num);
		Point GetFiducialCalXYPos(int num);
		void SetFiducialPos(int num, double x, double y);
		void SetFiducialXPos(int num, double x);
		void SetFiducialYPos(int num, double y);
		void SetFiducialCalPos(int num, double x, double y);
		void SetFiducialCalXPos(int num, double x);
		void SetFiducialCalYPos(int num, double y);
		MarkPart& GetMarkPart(int num);
		void InsertFiducialPos();
		void SetImageData(int num, vector<unsigned char> img_data);
		vector<unsigned char> GetImageData(int num);
		bool GetFiducialPosReachFlag(int num);
		void SetFiducialPosReachFlag(int num, bool reach);
		Point GetFidMechStandardXYPos(int blockid, int arryid, int index, Station station);  //��ȡ����ת����Ļ���Mark�����꣨��е���꣩
		// Mark��궨����  
		void MarkCompensationCal(Point& tar_point, double& angle_offset, int blockid, int arryid, Station station = Station::StationF2);
		double MarkAngleArctanCal(double x, double y);
		void FiducialMark::MarkInverseCompensationCal(Point& tar_point, int blockid, int arryid, Station station= Station::StationF2);
		Point MarkCircleCenterCal(Point pt1, Point pt2, Point pt3);
		Point GetFidMechStandardXYPos(int blockid, int arryid,Station station);
	private:
		int m_fid_num;						//��׼������	
		BoardMarkType m_FiducialType;
		APIErrCode m_MarkFlag;			     // �궨������ 
		vector<FiducialPos> m_vec_fid_pos;	//��׼��λ�ü�ID��Ϣ��ÿ��block�������3����ͬ��MarkPra�㣩			
	};

	//  AcceptMark �ɽ��ܵ�
	class AS_EXPORTS AcceptMark
	{
	private:
		LogicType m_AcceptMarkLogic;	// �ɽ��ܵ�ĺڰ�����
		Point m_AcceptMarkPos;			// �ɽ��ܵ�λ��
		APIErrCode m_MarkFlag;			// �ɽ��ܵ�궨������
		MarkPart m_AcceptMarkPart;
	public:
		AcceptMark();
		~AcceptMark();
		AcceptMark& operator=(AcceptMark& ref);
		//AcceptMark& operator=(sm::AcceptMark& ref);

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, AcceptMark& val, const unsigned int version);

		LogicType GetAcceptMarkLogic();
		void SetAcceptMarkLogic(LogicType logic_type);

		Point GetAcceptMarkPos();
		void SetAcceptMarkPos(double pos_x, double pos_y);

		APIErrCode GetAcceptMarkFlag();
		void SetAcceptMarkFlag(APIErrCode mark_flag);

		MarkPart& GetAcceptMarkPart();
	};

	// ������ɽ��ܵ������ͬ�����ݽṹ
	class AS_EXPORTS BadMark
	{
	private:
		LogicType m_BadMarkLogic;	// ����ĺڰ�����
		struct BadMarkOffset
		{
			double X;
			double Y;
		} m_BadMarkOffset;			// ���ƫ��
		Point m_BadMarkPos;			// ����λ��
		APIErrCode m_MarkFlag;		// ����ɨ����
		MarkPart m_badMarkPart;
	public:
		 BadMark();
		 ~BadMark();
		 BadMark& operator=(BadMark& ref);
		 //BadMark& operator=(sm::BadMark& ref);

		 //template <class Archive>
		 //friend void boost::serialization::serialize(Archive& ar, BadMark& val, const unsigned int version);

		LogicType GetBadMarkLogic();
		void SetBadMarkLogic(LogicType logic_type);

		double GetBadMarkOffsetX();
		double GetBadMarkOffsetY();
		void SetBadBadMarkOffset(double x_offset, double y_offset);
		void SetBadBadMarkOffsetX(double x_offset);
		void SetBadBadMarkOffsetY(double y_offset);

		Point GetBadMarkPos();
		void SetBadMarkPos(double pos_x, double pos_y);
		void SetBadMarkPosX(double pos_x);
		void SetBadMarkPosY(double pos_y);

		APIErrCode GetBadMarkFlag();
		void SetBadMarkFlag(APIErrCode mark_flag);

		MarkPart& GetBadMarkPart();
	};

	//ƴ��
	class AS_EXPORTS Array
	{
	public:
		Array();
		~Array();
		Array& operator=(Array& ref);
		//Array& operator=(sm::Array& ref);

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, Array& val, const unsigned int version);

		bool GetSkip();
		void SetSkip(bool skFlag);

		int GetArrayId();
		void SetArrayId(int id);

		int GetBlockID();
		void SetBlockID(int block_id);

		OFFSET& GetOriginOffset();
		double GetOriginOffsetX();
		double GetOriginOffsetY();
		double GetOriginOffsetR();
		void SetOriginOffset(OFFSET circuit_offset);
		void SetOriginOffsetX(double x);
		void SetOriginOffsetY(double y);
		void SetOriginOffsetR(double r);

		shared_ptr<FiducialMark>& GetFidMark();
		shared_ptr<AcceptMark>& GetAcceptMark();
		shared_ptr<BadMark>& GetBadMark();

	private:
		bool m_bSkip;				// �Ƿ���Ը�Circuit
		int m_array_id;				//Array��Ӧ��ƴ���
		int m_BlockID;				// ��Circuit��Ӧ�Ŀ��
		OFFSET m_originoffset;		//Array��Ӧ��ԭ��ƫ��
		shared_ptr<FiducialMark> m_FidMark;		// ��׼��
		shared_ptr<AcceptMark> m_AcceptMark;	// �ɽ��ܵ�
		shared_ptr<BadMark> m_BadMark;
	};

	class AS_EXPORTS Block
	{
	public:
		Block();
		~Block();
		Block& operator=(Block& ref);
		//Block& operator=(sm::Block& ref);

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, Block& val, const unsigned int version);

		bool GetSkip();
		void SetSkip(bool skFlag);

		void SetBlockID(int block_id);
		int GetBlockID();

		void SetOriginOffset(OFFSET offset_pos);
		void SetOriginOffsetX(double x);
		void SetOriginOffsetY(double y);
		void SetOriginOffsetR(double r);
		OFFSET GetOriginOffset();
		double GetOriginOffsetX();
		double GetOriginOffsetY();
		double GetOriginOffsetR();

		int GetBadMarkNum();
		void SetBadMarkNum();
		bool GetBadMarkUse();
		void SetBadMarkUse(bool bad_use);
		BoardMarkType GetBadMarkType();
		void SetBadMarkType(BoardMarkType badMark_type);
		void SetBadMark(int array_id);
		shared_ptr<BadMark> GetBadMark(int array_id);

		bool GetAcceptMarkUse();
		void SetAcceptMarkUse(bool accept_use);
		void SetAcceptpMark(int array_id);
		shared_ptr<AcceptMark> GetAcceptMark(int array_id);

		void SetXYDir(int X, int Y, double offset_x, double offset_y, DirectionType Direction);
		void SetXY(int X, int Y);
		void GetXYDir(int& X, int& Y, DirectionType& Direction);
		DirectionType GetDir();
		//Block ��С��ƴ�������
		int GetXNum();
		void SetXNum(int x);
		int GetYNum();
		void SetYNum(int y);
		//ƫ�ƣ�ƴ��֮���ƫ����Ϣ��
		void SetDeltaXY(double dx, double dy);
		void GetDeltaXY(double& dx, double& dy);
		double GetDeltaX();
		double GetDeltaY();

		void SetFidMark(int array_id);
		void SetFidMark_ptr(int array_id);
		shared_ptr<FiducialMark>& GetFidMark(int array_id);

		shared_ptr<Array> GetArrayContent(int array_id);
		void InsertArrayContent(shared_ptr<Array> array);
		vector<shared_ptr<Array>>& GetALLArrayContent();
		void DeleteArrayContent(int array_id);
		int GetNumOfCircuits();
	private:
		bool m_Skip;									// �Ƿ���Ը�Block
		int m_block_id;									//Block��Ӧ��BlockID

		OFFSET m_originoffset;							//Block��Ӧ��ԭ��ƫ��

		// ==== ���� ==== //
		int m_BadNum;						// ��������
		bool m_BadMarkUse;					// �Ƿ�ʹ�û���
		BoardMarkType m_BadMarkType;		// ����������

		// ==== �ɽ��ܱ�� ===// 
		bool m_AcceptMarkUse;               // �Ƿ�ʹ�ÿɽ��ܵ�

		// Block ��С��ƴ�������
		struct
		{
			int X;							// X ����ƴ�����
			int Y;							// Y ����ƴ�����
			DirectionType Direction;
		} m_bkContentSize;

		//ƫ�ƣ�ƴ��֮���ƫ����Ϣ��
		struct
		{
			double X;						// X ����ƫ��
			double Y;						// Y ����ƫ��
		}m_DirectionOffset;

		vector<shared_ptr<Array>> m_board_array;		//Array�����ݹ���
	};

	class AS_EXPORTS BaseBoard
	{
	public:
		BaseBoard();
		BaseBoard& operator=(BaseBoard& ref);
		//BaseBoard& operator=(sm::BaseBoard& ref);

		//template <class Archive>
		//friend void boost::serialization::serialize(Archive& ar, BaseBoard& val, const unsigned int version);

		void SetBaseBoardOriginX(double X);
		void SetBaseBoardOriginY(double Y);
		inline Point GetBaseBoardOrigin();
		inline void SetBaseBoardOrigin(Point pos);

		void SetBaseBoardScanX1(double X);

		void SetBaseBoardScanY1(double Y);

		void SetBaseBoardScanX2(double X);

		void SetBaseBoardScanY2(double Y);

		Point GetBaseBoardScanPoint1();

		void SetBaseBoardScanPoint1(Point point);

		Point GetBaseBoardScanPoint2();

		void SetBaseBoardScanPoint2(Point point);

		inline void SetCoordinateType(CoordinateType coor_type);
		inline CoordinateType GetCoordinateType();

		inline DefectMode GetDefectModeData();
		inline void SetDefectModeData(DefectMode val);

		double GetBaseBoardInitinalTheta();
		bool CheckBaseBoardInitinalTheta();			// ��ǰ��·���Ƿ񱻱궨��
		void SetBaseBoardInitinalTheta(double theta);

		void SetBaseBoardSize(double x, double y);
		void SetBaseBoardSizeX(double x);
		void SetBaseBoardSizeY(double y);
		double GetBaseBoardSizeX();
		double GetBaseBoardSizeY();

		bool GetUse();
		void SetUse(bool u);
		
		BlockType GetBlockType();
		void SetBlockType(BlockType bt);

		void SetXY(int X, int Y, double deltaX, double deltaY, BlockType preblocktype, BlockType currblocktype);
		double GetBlockXNum();
		void SetBlockXNum(int num);
		double GetBlockYNum();
		void SetBlockYNum(int num);
		double GetXDelta();
		double GetYDelta();

		shared_ptr<Block> GetBlockContent(int block_id);
		void InsertBlockContent(shared_ptr<Block>);
		vector<shared_ptr<Block>>& GetALLBlockContent();
		void DeleteBlockContent(int block_id);
		shared_ptr<Array> GetCircuitContent(int block_id, int circuit_id);
		
		int GetNumOfBlocks();
		int GetAllBlockArrayNum();
		void UpdateMarkCalFlag();
	private:
		Point m_origin;								//ԭ������
		CoordinateType m_coordinate;				//��������
		DefectMode m_DefectMode;                    //���ģʽ
		double m_InitialTheta;						//��ʼ���Ƕ�			

		// ===ɨ�跶Χ=== //
		Point m_scanPoint1;                         //ɨ���1
		Point m_scanPoint2;							//ɨ���2
		struct BoardSize
		{
			double X;								//���ӵ�X�ߴ�
			double Y;								//���ӵ�Y�ߴ�
		}m_size;

		//====block===//
		bool m_bUse;								// �Ƿ�ʹ�÷ֿ鹦��
		BlockType m_Type;							// �������
		int m_NumX;									// X ����Ŀ���
		int m_NumY;									// Y ����Ŀ���
		double m_DeltaX;							// X ��������ƫ��
		double m_DeltaY;							// Y ��������ƫ��
		vector<shared_ptr<Block>> m_BlockContents;	// Block �����ݹ���
	};
}
#endif
