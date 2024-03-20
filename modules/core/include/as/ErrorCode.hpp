#ifndef	AS_SOFTWAREERRORCODE_HPP
#define AS_SOFTWAREERRORCODE_HPP

namespace as
{
    enum APIErrCode
    {
        // =============== 0x0XXX软件指令错误码 =============== //

        // ==== 0x01XX PCB编辑 ==== //
        ProSuccess = 0x0100,                // 操作成功
        ProParamError = 0x0200,             // 操作参数错误
        ProFail = 0x0103,                     // 操作失败
        ProNotInit = 0x0104,                 // 未初始化的错误
        MarkLightParaErr = 0x010A,			// Mark光源参数没有初始化
        MarkIgnore = 0x010B,				// Mark忽略标定
        BadMarkTag = 0x010C,                 // 坏板标记标志
        AcceptMarkTag = 0x010D,              // 可接受点标记标志
        MarkNotCal = 0x0409,                 // Mark点未标定
        ConveyBeltSetWidthFail = 0x010E,     // 设置板宽失败      
        WaitWarmMachine = 0x0518,            // 暖机执行，机器进入Wait状态
        WaitScan = 0x0522,                   // 基准点扫描,机器进入Wait状态
        WaitMoveMachine,                    // 编辑状态下移动，机器进入Wait状态
        MarkCalFail = 0x0402,				// Mark点标定操作失败
        // ==== 0x02XX 优化 ==== //
        OptSuccess = 0x0200,                // 优化成功
        OptFail = 0x0201,                   // 优化失败

        // ==== 0x03XX 校正 ==== //

        // ==== 0x04XX 生产 ==== //
        ProduceZeroFail = 0x0400,           // [生产]零点标定失败
        ProduceTransFail = 0x0401,          // [生产]电路板传送失败
        ProduceMarkFail = 0x0402,           // [生产]Mark点标定失败
        ProduceBadMarkFail = 0x0403,        // [生产]坏板检测失败
        ProdcueMarkNotCal = 0x0409,		    // [生产]Mark点未标定
        ProdcueProMarkFail = 0x040A,	    // [生产]预先移动至首个基准点失败
        ProduceAttutideFail = 0x0406,       // [生产]检测元件失败

        ProdcuePShutEvent = 0x040F,         // [生产]终止线程
        ProduceReaction = 0x0438,           // [生产]重新进行本周期
        ProdcueNextState=0x040E,		    // [生产]进入下一周期

        // ==== 0x05XX 状态机 ==== //
        CurrentStateBOOT = 0x0500,                   // BOOT
        CurrentStateIDLE = 0x0501,                   // IDLE
        CurrentStateRUNREADY = 0x0502,               // RUN READY
        CurrentStateRUN = 0x0503,                    // RUN
        CurrentStatePAUSE = 0x0504,                  // PAUSE
        CurrentStateFREEZE = 0x0505,                 // FREEZE
        CurrentStateWAIT = 0x0506,                   // WAIT
        CurrentStateEMG = 0x0507,                    // EMG
        CurrentStateADJ = 0x0508,                    // ADJ
        CurrentStateSTEPMOUNT = 0x0509,              // StepMount

        ProAdjMarkCheckFail = 0x050C,                // [生产]Mark点检测失败手动调整，机器进入Adjust状态
        ProAdjInstructionsErr = 0x0510,              // [生产]硬件或图像指令下发失败，机器进入Adjust状态
        ProAdjBeltErr = 0x0513,                      // [生产]中遇到卡板，机器进入Adjust状态

        MoveInErrState = 0x051C,                     // 当前状态Move指令不可用
        GetInErrState = 0x051D,                      // 当前状态Get指令不可用
        WorkInErrState = 0x051E,                     // 当前状态该指令不可用
        PermissionDeny = 0x051F,                     // 您的用户级别不足以进行该操作，请提升权限后再操作

        // ==== 0x06XX MES ==== //

        // =============== 0xBAxxx 0xFXXX 0xEXXX 硬件指令错误码 =============== //
        SendParaError = 0xBA00,                     // 硬件指令执行错误: 指令下发参数错误           急停
        UnknowError = 0xBA01,		                // 硬件指令执行错误: 未知错误                  急停
        PCIInitFailed = 0xBA02,	                    // 硬件指令执行错误: PCI初始化失败             急停
        PCIReleaseInvalid = 0xBA03,                  // 硬件指令执行错误: PCI释放失败               急停
        MotionUnreturnOriginal = 0xBA04,             // 硬件指令执行错误: 系统未回原点              急停
        Para7043Invalid = 0xBA05,		            // 硬件指令执行错误: 7043参数超限              急停
        MotionUnserved = 0xBA06,	                // 硬件指令执行错误: 轴未上伺服                急停
        MoveXParaError = 0xBA09,				    // 硬件指令执行错误: 移动X轴指令下发参数超限     急停
        MoveYParaError = 0xBA0A, 				    // 硬件指令执行错误: 移动Y轴指令下发参数超限     急停

        PStateFalse = 0xBA80,                       // 硬件指令执行错误: 当前状态前不允许执行硬件指令 提示
        SystemRunNotWRRam = 0xBA81,	                // 硬件指令执行错误: 硬件系统在Run调用写RAM接口  提示
        SystemPause = 0xBA82,		                // 硬件指令执行错误: 系统处于暂停状态            提示
        SystemNotManual = 0xBA83,	                // 硬件指令执行错误: 系统不在手动状态            提示
        SystemNotRun = 0xBA84,		                // 硬件指令执行错误: 系统不在运行状态            提示
        CheckDoorStateFail = 0xBA85,                 // 硬件指令执行错误: 查询门指令超时              提示        
        WriteIniFFail = 0xBA86,                      // 硬件指令执行错误: 写配置文件失败              提示
        DoorOpenPCISetFailed = 0xBA87,               // 硬件指令执行错误: 开门切换RUN失败             提示

        // =============== 0xAXXX 图像CVinsionInterFace指令错误码 =============== //
        // [High Byte: Error Level | Low Byte: Error Message]
        // [0x8000xxxx Serious Error -> may freeze or adjust]
        // [0x1000xxxx General Error -> works fine]
        VisionInterfaceProcSuccess = 0xA000,

        VisionInterfaceRegisterFAIL = 0xA001,
        VisionInterfaceTestFAIL = 0xA002,

        //图像采集相关错误[0x8000A100 - 0x8000A1FF]


        //线程管理&生产处理超时 [0x8000A200 - 0x8000A2FF]
        CREATE_THREAD_FAILED = 0x8000A1A0,
        THREAD_HAS_BEEN_CREATED = 0x1000A1A1,
        INPUT_NULL_POINTER = 0x1000A1A2,

        WAIT_PROCESS_EXIT_TIMEOUT = 0x1000A510,  //图像处理结果等待超时
        INPUT_PARAM_ERROR = 0x8000A511,          //输入参数错误
        IMAGE_INTERFACE_MODE_ERROR = 0x1000A1B1, //图像接口状态错误
        IMAGE_INTERFACE_MODE_INIT_FAILED = 0x8000A1B2, //图像接口初始化失败

        MANUFACTURE_PART_TEST_TIMEOUT = 0x8000A1C1, //生产时测试芯片超时

        //图像算法接口
        TOCJudgeInitColorParam = 0x1000A380,         //toc算法注册时区域不满足初始参数
        ImgInputChannelTypeError = 0x1000A381,       // 输入图像通道不正确
        TOCBGRVectorSizeUnEqual = 0x1000A382,        // 三通道图像过滤后生成Vector尺寸不相等
        ROI_SIZE_OVERRUN       = 0x1000A383,         //截图ROI尺寸或位置超限

        ActiveMarkMove = 0x1000A81D,                 //AOI止挡梢下降，激活Mark点扫描
        NotActiveMarkMove = 0x1000A81E,              //AOI止挡梢下降，没有激活Mark点扫描
    };
}

#endif
