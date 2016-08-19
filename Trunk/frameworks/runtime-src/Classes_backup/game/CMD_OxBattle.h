#ifndef CMD_BACCARAT_HEAD_FILE
#define CMD_BACCARAT_HEAD_FILE

#include "Define.h"

//״̬����
#define	GS_PLACE_JETTON				GAME_STATUS_PLAY					//��ע״̬
#define	GS_GAME_END					GAME_STATUS_PLAY+1					//����״̬
#define	GS_MOVECARD_END				GAME_STATUS_PLAY+2					//����״̬

//����
#define MAX_INDEX					3									//�������
#define AREA_COUNT					5									//������Ŀ
#define AREA_CARD_COUNT             5                                   //ӵ������
#define SERVER_LEN					32									//���䳤��
#define HUN_GAME_PLAYER			    100									//��Ϸ����

#pragma pack(1)

//����������ṹ
#define SUB_S_GAME_FREE				99									//��Ϸ����
#define SUB_S_GAME_START			100									//��Ϸ��ʼ
#define SUB_S_PLACE_JETTON			101									//�û���ע
#define SUB_S_HUN_GAME_END		    102									//��Ϸ����
#define SUB_S_APPLY_BANKER			103									//����ׯ��
#define SUB_S_CHANGE_BANKER			104									//�л�ׯ��
#define SUB_S_CHANGE_USER_SCORE		105									//���»���
#define SUB_S_SEND_RECORD			106									//��Ϸ��¼
#define SUB_S_PLACE_JETTON_FAIL		107									//��עʧ��
#define SUB_S_CANCEL_BANKER			108									//ȡ������

//��Ϸ״̬
#define GAME_STATUS_FREE            0                                  //����״̬
#define GAME_STATUS_PLAY            100                                //��Ϸ״̬
#define GAME_STATUS_WAIT            200                                //�ȴ�״̬

//��¼��Ϣ
typedef struct
{
	bool							bWinShunMen;						//˳��ʤ��
	bool							bWinDuiMen;							//����ʤ��
	bool							bWinDaoMen;							//����ʤ��
	bool							bWinHuang;							//����ʤ��
} tagServerGameRecord;


//ʧ�ܽṹ
typedef struct
{
    BYTE							lJettonArea;						//��ע����
	WORD							wPlaceUser;							//��ע���
	LONGLONG						lPlaceScore;						//��ǰ��ע
} CMD_S_HunPlaceJettonFail;

//���»���
typedef struct
{
    BYTE							cbBankerTime;						//ׯ�Ҿ���
	WORD							wChairID;							//���Ӻ���
    WORD							wCurrentBankerChairID;				//��ǰׯ��
    
    //ׯ����Ϣ
	DOUBLE							lScore;								//��һ���
	DOUBLE							lCurrentBankerScore;				//ׯ�ҷ���
} CMD_S_HunChangeUserScore;

//����ׯ��
typedef struct
{
	WORD							wApplyUser;							//�������
} CMD_S_HunApplyBanker;

//ȡ������
typedef struct
{
    WORD                            wChairID;                           //�������
	TCHAR							szCancelUser[32];					//ȡ�����
} CMD_S_HunCancelBanker;

//�л�ׯ��
typedef struct
{
	WORD							wBankerUser;						//��ׯ���
	LONGLONG						lBankerScore;						//ׯ�ҽ��
} CMD_S_HunChangeBanker;

//��Ϸ״̬
typedef struct
{
	//ȫ����Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��
    bool							bEnableSysBanker;					//ϵͳ��ׯ
	WORD							wBankerUser;						//��ǰׯ��
    WORD							cbBankerTime;						//ׯ�Ҿ���
	
    //�����Ϣ
	LONGLONG						lUserMaxScore;						//��ҽ��
	LONGLONG						lBankerWinScore;					//ׯ�ҳɼ�
	LONGLONG						lBankerScore;						//ׯ�ҷ���

	//������Ϣ
	LONGLONG						lApplyBankerCondition;				//��������
	LONGLONG						lAreaLimitScore;					//��������
    LONGLONG						lSitMinSocre;						//���µ���С���

	//������Ϣ
	TCHAR							szGameRoomName[SERVER_LEN];			//��������
} CMD_S_HunStatusFree;

//��Ϸ״̬
typedef struct
{
	//ȫ����Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��
	BYTE							cbGameStatus;						//��Ϸ״̬
	bool							bEnableSysBanker;					//ϵͳ��ׯ
    
	//�˿���Ϣ
	BYTE							cbTableCardArray[AREA_COUNT][AREA_CARD_COUNT]; //�����˿�
    
	WORD							wBankerUser;						//��ǰׯ��
	WORD							cbBankerTime;						//ׯ�Ҿ���
    
	//ȫ����ע
	LONGLONG						lAllJettonScore[AREA_COUNT];        //ȫ����ע
    
	//�����ע
	LONGLONG						lUserJettonScore[AREA_COUNT];		//������ע
    
	//��һ���
	LONGLONG						lUserMaxScore;						//�����ע
    
	//������Ϣ
	LONGLONG						lApplyBankerCondition;				//��������
	LONGLONG						lAreaLimitScore;					//��������
    
	//ׯ����Ϣ
	LONGLONG						lBankerWinScore;					//ׯ��Ӯ��
	LONGLONG						lBankerScore;						//ׯ�ҷ���
    
	//������Ϣ
	LONGLONG						lEndBankerScore;					//ׯ�ҳɼ�
	LONGLONG						lEndUserScore;						//��ҳɼ�
	LONGLONG						lEndUserReturnScore;				//���ػ���
	LONGLONG						lEndRevenue;						//��Ϸ˰��
    LONGLONG						lSitMinSocre;						//���µ���С���

	//������Ϣ
	TCHAR							szGameRoomName[SERVER_LEN];			//��������
    
} CMD_S_HunStatusPlay;

//��Ϸ����
typedef struct
{
	BYTE							cbTimeLeave;						//ʣ��ʱ��
} CMD_S_HunGameFree;

//��Ϸ��ʼ
typedef struct
{
    BYTE							cbTimeLeave;						//ʣ��ʱ��
    bool							bContiueCard;						//��������
    WORD							wBankerUser;						//ׯ��λ��
    int								nChipRobotCount;					//�������� (��ע������)
    LONGLONG						lBankerScore;						//ׯ�ҽ��
	LONGLONG						lUserMaxScore;						//�ҵĽ��
} CMD_S_HunGameStart;

//�û���ע
typedef struct
{
    bool							bIsAndroid;							//�Ƿ������
    BYTE							cbJettonArea;						//��������
	WORD							wChairID;							//�û�λ��
	LONGLONG						lJettonScore;						//��ע��Ŀ
} CMD_S_HunPlaceJetton;

//��Ϸ����
typedef struct
{
	//�¾���Ϣ
    BYTE							cbTimeLeave;						//ʣ��ʱ��
	BYTE							cbLeftCardCount;					//�˿���Ŀ
	BYTE							bcFirstCard;                        //��һ����
	BYTE							cbTableCardArray[AREA_COUNT][AREA_CARD_COUNT]; //�����˿�
	int								nBankerTime;						//��ׯ����
	//ׯ����Ϣ
	LONGLONG						lBankerScore;						//ׯ�ҳɼ�
	LONGLONG						lBankerTotallScore;					//ׯ���ܳɼ�
	LONGLONG						lUserScore;							//��ҳɼ�
	LONGLONG						lUserReturnScore;					//���ػ���
	LONGLONG						lRevenue;							//��Ϸ˰��
} CMD_S_HunGameEnd;

//�ͻ�������ṹ
#define SUB_C_PLACE_JETTON			1									//�û���ע
#define SUB_C_APPLY_BANKER			2									//����ׯ��
#define SUB_C_CANCEL_BANKER			3									//ȡ������
#define SUB_C_CONTINUE_CARD			4									//��������
#define SUB_C_AMDIN_COMMAND			5									//����Ա����
#define SUB_C_GET_ACCOUNT			6									//��ȡ�ǳ�
#define SUB_C_CHEAK_ACCOUNT			7									//��ȡ�ǳ�

//�ͻ�����Ϣ
#define IDM_ADMIN_COMMDN			WM_USER+1000
#define IDM_GET_ACCOUNT				WM_USER+1001
#define IDM_CHEAK_ACCOUNT			WM_USER+1002

typedef struct
{
	LONGLONG						lUserJettonScore[AREA_COUNT];		//������ע
} CMD_S_HunUserJettonScore;

//�û���ע
typedef struct
{
	BYTE							cbJettonArea;						//��������
	LONGLONG						lJettonScore;						//��ע��Ŀ
} CMD_C_HunPlaceJetton;



//14.08.05����------------------------------------------------

//��������
struct CMD_C_ApplySit
{
	WORD                            wSitChairID;							//���µ�����ID
};
//�뿪λ��
struct CMD_C_CancelSit
{
	WORD                            wSitChairID;							//���µ�����ID
};

//�������³ɹ�
struct CMD_S_ApplySit
{
	WORD                            wSitChairID;							//���µ�����ID
	WORD							wApplySitID;						//�����������ID
};

//�뿪λ�óɹ�
struct CMD_S_CancelSit
{
	WORD                            wSitChairID;							//���µ�����ID
	WORD							wCancelID;							//������Ӻ�					
};

#define SUB_S_WLOSE_INFO            114									//��Ӯ��Ϣ
#define WIN_COUNT					3									//ʤ������

//��Ӯ��Ϣ
struct tagUserWLInfo
{
	WORD                           wChairID;							//���ID
	LONGLONG					   lJettonScore;						//��ҳɼ�
};

struct CMD_S_WLInfo
{
	tagUserWLInfo                   tagWinInfo[WIN_COUNT];				//Ӯ�����
	tagUserWLInfo					tagLoseInfo;						//������
};
///




//--------------------------------------------------//


#pragma pack()
//
///// ������
//#define ChipQuota @[@"1000", @"10000", @"100000", @"500000", @"1000000", @"5000000"]
//
///// ϵͳ��ׯ�����Ӻ�
//#define SystemBankerChairID 65535
//#define SystemBankerName @"������ׯ"

/// ��Ϸ״̬
typedef enum {
    GameStatusKnown     = 0,
    GameStatusBet       = 1,
    GameStatusPlay      = 2,
    GameStatusFree      = 3,
} GameStatusType;

/// ������ׯ״̬
typedef enum {
    AskBankerStatusAsk           = 0,  // ������ׯ
    AskBankerStatusRelieved      = 1,  // ������ׯ
    AskBankerStatusCancel        = 2,  // ȡ��������ׯ
} AskBankerStatus;

/// ������ׯ��Ҫ��ͷ���
#define AskBankerMaxScore 1000000

/// ����ʱ��
#define TimeForDistribute      0.3f        // �˿��ƶ�
#define TimeForStretchCardBack 0.4f        // �Ʊ���չ
#define TimeForTurnCard        0.2f        // ����
#define TimeForStretchRealCard 0.5f        // ������չ
#define TimeForShowCardMachine 0.5f        // ��ʾ���ƻ�
#define TimeForShowNiuNiuView  0.5f        // ��ʾţţ
#define TimeForShowStatusView  0.5f        // ��ʾ״̬
#define TimeForChipHaloBreath  0.2f        // �����Ȧ
#define TimeForAreaHalo        0.4f        // ������Ӯ��ȦЧ��
#define TimeForAreaHaloDelay   3.0f        // ��˷�ȴ�ʱ��

#endif