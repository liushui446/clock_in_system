#ifndef	AS_SOFTWAREERRORCODE_HPP
#define AS_SOFTWAREERRORCODE_HPP

namespace as
{
    enum APIErrCode
    {
        // =============== 0x0XXX���ָ������� =============== //

        // ==== 0x01XX PCB�༭ ==== //
        ProSuccess = 0x0100,                // �����ɹ�
        ProParamError = 0x0200,             // ������������
        ProFail = 0x0103,                     // ����ʧ��
        ProNotInit = 0x0104,                 // δ��ʼ���Ĵ���
        MarkLightParaErr = 0x010A,			// Mark��Դ����û�г�ʼ��
        MarkIgnore = 0x010B,				// Mark���Ա궨
        BadMarkTag = 0x010C,                 // �����Ǳ�־
        AcceptMarkTag = 0x010D,              // �ɽ��ܵ��Ǳ�־
        MarkNotCal = 0x0409,                 // Mark��δ�궨
        ConveyBeltSetWidthFail = 0x010E,     // ���ð��ʧ��      
        WaitWarmMachine = 0x0518,            // ů��ִ�У���������Wait״̬
        WaitScan = 0x0522,                   // ��׼��ɨ��,��������Wait״̬
        WaitMoveMachine,                    // �༭״̬���ƶ�����������Wait״̬
        MarkCalFail = 0x0402,				// Mark��궨����ʧ��
        // ==== 0x02XX �Ż� ==== //
        OptSuccess = 0x0200,                // �Ż��ɹ�
        OptFail = 0x0201,                   // �Ż�ʧ��

        // ==== 0x03XX У�� ==== //

        // ==== 0x04XX ���� ==== //
        ProduceZeroFail = 0x0400,           // [����]���궨ʧ��
        ProduceTransFail = 0x0401,          // [����]��·�崫��ʧ��
        ProduceMarkFail = 0x0402,           // [����]Mark��궨ʧ��
        ProduceBadMarkFail = 0x0403,        // [����]������ʧ��
        ProdcueMarkNotCal = 0x0409,		    // [����]Mark��δ�궨
        ProdcueProMarkFail = 0x040A,	    // [����]Ԥ���ƶ����׸���׼��ʧ��
        ProduceAttutideFail = 0x0406,       // [����]���Ԫ��ʧ��

        ProdcuePShutEvent = 0x040F,         // [����]��ֹ�߳�
        ProduceReaction = 0x0438,           // [����]���½��б�����
        ProdcueNextState=0x040E,		    // [����]������һ����

        // ==== 0x05XX ״̬�� ==== //
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

        ProAdjMarkCheckFail = 0x050C,                // [����]Mark����ʧ���ֶ���������������Adjust״̬
        ProAdjInstructionsErr = 0x0510,              // [����]Ӳ����ͼ��ָ���·�ʧ�ܣ���������Adjust״̬
        ProAdjBeltErr = 0x0513,                      // [����]���������壬��������Adjust״̬

        MoveInErrState = 0x051C,                     // ��ǰ״̬Moveָ�����
        GetInErrState = 0x051D,                      // ��ǰ״̬Getָ�����
        WorkInErrState = 0x051E,                     // ��ǰ״̬��ָ�����
        PermissionDeny = 0x051F,                     // �����û��������Խ��иò�����������Ȩ�޺��ٲ���

        // ==== 0x06XX MES ==== //

        // =============== 0xBAxxx 0xFXXX 0xEXXX Ӳ��ָ������� =============== //
        SendParaError = 0xBA00,                     // Ӳ��ָ��ִ�д���: ָ���·���������           ��ͣ
        UnknowError = 0xBA01,		                // Ӳ��ָ��ִ�д���: δ֪����                  ��ͣ
        PCIInitFailed = 0xBA02,	                    // Ӳ��ָ��ִ�д���: PCI��ʼ��ʧ��             ��ͣ
        PCIReleaseInvalid = 0xBA03,                  // Ӳ��ָ��ִ�д���: PCI�ͷ�ʧ��               ��ͣ
        MotionUnreturnOriginal = 0xBA04,             // Ӳ��ָ��ִ�д���: ϵͳδ��ԭ��              ��ͣ
        Para7043Invalid = 0xBA05,		            // Ӳ��ָ��ִ�д���: 7043��������              ��ͣ
        MotionUnserved = 0xBA06,	                // Ӳ��ָ��ִ�д���: ��δ���ŷ�                ��ͣ
        MoveXParaError = 0xBA09,				    // Ӳ��ָ��ִ�д���: �ƶ�X��ָ���·���������     ��ͣ
        MoveYParaError = 0xBA0A, 				    // Ӳ��ָ��ִ�д���: �ƶ�Y��ָ���·���������     ��ͣ

        PStateFalse = 0xBA80,                       // Ӳ��ָ��ִ�д���: ��ǰ״̬ǰ������ִ��Ӳ��ָ�� ��ʾ
        SystemRunNotWRRam = 0xBA81,	                // Ӳ��ָ��ִ�д���: Ӳ��ϵͳ��Run����дRAM�ӿ�  ��ʾ
        SystemPause = 0xBA82,		                // Ӳ��ָ��ִ�д���: ϵͳ������ͣ״̬            ��ʾ
        SystemNotManual = 0xBA83,	                // Ӳ��ָ��ִ�д���: ϵͳ�����ֶ�״̬            ��ʾ
        SystemNotRun = 0xBA84,		                // Ӳ��ָ��ִ�д���: ϵͳ��������״̬            ��ʾ
        CheckDoorStateFail = 0xBA85,                 // Ӳ��ָ��ִ�д���: ��ѯ��ָ�ʱ              ��ʾ        
        WriteIniFFail = 0xBA86,                      // Ӳ��ָ��ִ�д���: д�����ļ�ʧ��              ��ʾ
        DoorOpenPCISetFailed = 0xBA87,               // Ӳ��ָ��ִ�д���: �����л�RUNʧ��             ��ʾ

        // =============== 0xAXXX ͼ��CVinsionInterFaceָ������� =============== //
        // [High Byte: Error Level | Low Byte: Error Message]
        // [0x8000xxxx Serious Error -> may freeze or adjust]
        // [0x1000xxxx General Error -> works fine]
        VisionInterfaceProcSuccess = 0xA000,

        VisionInterfaceRegisterFAIL = 0xA001,
        VisionInterfaceTestFAIL = 0xA002,

        //ͼ��ɼ���ش���[0x8000A100 - 0x8000A1FF]


        //�̹߳���&��������ʱ [0x8000A200 - 0x8000A2FF]
        CREATE_THREAD_FAILED = 0x8000A1A0,
        THREAD_HAS_BEEN_CREATED = 0x1000A1A1,
        INPUT_NULL_POINTER = 0x1000A1A2,

        WAIT_PROCESS_EXIT_TIMEOUT = 0x1000A510,  //ͼ�������ȴ���ʱ
        INPUT_PARAM_ERROR = 0x8000A511,          //�����������
        IMAGE_INTERFACE_MODE_ERROR = 0x1000A1B1, //ͼ��ӿ�״̬����
        IMAGE_INTERFACE_MODE_INIT_FAILED = 0x8000A1B2, //ͼ��ӿڳ�ʼ��ʧ��

        MANUFACTURE_PART_TEST_TIMEOUT = 0x8000A1C1, //����ʱ����оƬ��ʱ

        //ͼ���㷨�ӿ�
        TOCJudgeInitColorParam = 0x1000A380,         //toc�㷨ע��ʱ���������ʼ����
        ImgInputChannelTypeError = 0x1000A381,       // ����ͼ��ͨ������ȷ
        TOCBGRVectorSizeUnEqual = 0x1000A382,        // ��ͨ��ͼ����˺�����Vector�ߴ粻���
        ROI_SIZE_OVERRUN       = 0x1000A383,         //��ͼROI�ߴ��λ�ó���

        ActiveMarkMove = 0x1000A81D,                 //AOIֹ�����½�������Mark��ɨ��
        NotActiveMarkMove = 0x1000A81E,              //AOIֹ�����½���û�м���Mark��ɨ��
    };
}

#endif
