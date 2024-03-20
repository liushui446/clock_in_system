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
		double m_x;				// 偏移X
		double m_y;				// 偏移Y
		double m_r;             // 旋转角度R
	};

	//block 类型定义
	enum class BlockType
	{
		BLOCK_AAAA = 0,         // 相同块，各个块内容完全相同
		BLOCK_ABCD,             // 不同块，各个块内容不相同
	};

	enum class AS_EXPORTS BoardMarkType
	{
		FIDUCIAL_NONE = 0,		// 无基准点
		FIDUCIAL_ARRAY,			// 基准点应用于每个电路
		FIDUCIAL_GLOBAL,		// 基准点应用于每个block
	};

	// 计数方向
	enum  class DirectionType
	{
		DIRECTION_X = 0,        // X 方向计数
		DIRECTION_Y             // Y 方向计数
	};

	enum class AS_EXPORTS LogicType
	{
		LOGIC_WHITE = 0,		// 白色
		LOGIC_BLACK				// 黑色    
	};
	/*enum class AOI_EXPORTS Orbit
	{
		TRACK_ONE=0,
		TRACK_TWO,
	};*/

	//基准点
	class AS_EXPORTS FiducialMark
	{
	public:
		FiducialMark();
		FiducialMark& operator=(FiducialMark& ref);
		//FiducialMark& operator=(sm::FiducialMark& ref);

		struct FiducialPos
		{
			double x = 0;					//基准点位置X
			double y = 0;					//基准点位置Y
			double mark_cal_posx = 0;		//基准点标定位置X
			double mark_cal_posy = 0;		//基准点标定位置Y
			MarkPart m_cMarkPart;
			vector<unsigned char> m_vImageData;
			bool Reachable = true;                 // 当前站下，该mark点可否到达			
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
		Point GetFidMechStandardXYPos(int blockid, int arryid, int index, Station station);  //获取坐标转换后的基板Mark点坐标（机械坐标）
		// Mark点标定过程  
		void MarkCompensationCal(Point& tar_point, double& angle_offset, int blockid, int arryid, Station station = Station::StationF2);
		double MarkAngleArctanCal(double x, double y);
		void FiducialMark::MarkInverseCompensationCal(Point& tar_point, int blockid, int arryid, Station station= Station::StationF2);
		Point MarkCircleCenterCal(Point pt1, Point pt2, Point pt3);
		Point GetFidMechStandardXYPos(int blockid, int arryid,Station station);
	private:
		int m_fid_num;						//基准点数量	
		BoardMarkType m_FiducialType;
		APIErrCode m_MarkFlag;			     // 标定故障码 
		vector<FiducialPos> m_vec_fid_pos;	//基准点位置及ID信息（每个block最多设置3个不同的MarkPra点）			
	};

	//  AcceptMark 可接受点
	class AS_EXPORTS AcceptMark
	{
	private:
		LogicType m_AcceptMarkLogic;	// 可接受点的黑白属性
		Point m_AcceptMarkPos;			// 可接受点位置
		APIErrCode m_MarkFlag;			// 可接受点标定故障码
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

	// 坏点与可接受点具有相同的数据结构
	class AS_EXPORTS BadMark
	{
	private:
		LogicType m_BadMarkLogic;	// 坏点的黑白属性
		struct BadMarkOffset
		{
			double X;
			double Y;
		} m_BadMarkOffset;			// 标记偏移
		Point m_BadMarkPos;			// 坏点位置
		APIErrCode m_MarkFlag;		// 坏点扫描标记
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

	//拼板
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
		bool m_bSkip;				// 是否忽略该Circuit
		int m_array_id;				//Array对应的拼版号
		int m_BlockID;				// 该Circuit对应的块号
		OFFSET m_originoffset;		//Array对应的原点偏移
		shared_ptr<FiducialMark> m_FidMark;		// 基准点
		shared_ptr<AcceptMark> m_AcceptMark;	// 可接受点
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
		//Block 大小（拼板个数）
		int GetXNum();
		void SetXNum(int x);
		int GetYNum();
		void SetYNum(int y);
		//偏移（拼板之间的偏移信息）
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
		bool m_Skip;									// 是否忽略该Block
		int m_block_id;									//Block对应的BlockID

		OFFSET m_originoffset;							//Block对应的原点偏移

		// ==== 坏板 ==== //
		int m_BadNum;						// 坏板数量
		bool m_BadMarkUse;					// 是否使用坏点
		BoardMarkType m_BadMarkType;		// 坏板标记类型

		// ==== 可接受标记 ===// 
		bool m_AcceptMarkUse;               // 是否使用可接受点

		// Block 大小（拼板个数）
		struct
		{
			int X;							// X 方向拼板个数
			int Y;							// Y 方向拼板个数
			DirectionType Direction;
		} m_bkContentSize;

		//偏移（拼板之间的偏移信息）
		struct
		{
			double X;						// X 方向偏移
			double Y;						// Y 方向偏移
		}m_DirectionOffset;

		vector<shared_ptr<Array>> m_board_array;		//Array的内容管理
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
		bool CheckBaseBoardInitinalTheta();			// 当前电路板是否被标定过
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
		Point m_origin;								//原点坐标
		CoordinateType m_coordinate;				//坐标类型
		DefectMode m_DefectMode;                    //检测模式
		double m_InitialTheta;						//初始化角度			

		// ===扫描范围=== //
		Point m_scanPoint1;                         //扫描点1
		Point m_scanPoint2;							//扫描点2
		struct BoardSize
		{
			double X;								//板子的X尺寸
			double Y;								//板子的Y尺寸
		}m_size;

		//====block===//
		bool m_bUse;								// 是否使用分块功能
		BlockType m_Type;							// 块的类型
		int m_NumX;									// X 方向的块数
		int m_NumY;									// Y 方向的块数
		double m_DeltaX;							// X 方向各块的偏差
		double m_DeltaY;							// Y 方向各块的偏差
		vector<shared_ptr<Block>> m_BlockContents;	// Block 的内容管理
	};
}
#endif
