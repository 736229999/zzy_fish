#ifndef CMD_OX_HEAD_FILE
#define CMD_OX_HEAD_FILE

#include "Define.h"

#pragma pack(push)  
#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
//�����궨��

#define KIND_ID							25									//��Ϸ I D
#define GAME_PLAYER						5									//��Ϸ����
#define GAME_NAME						TEXT("�ٱ�ţţ")					//��Ϸ����
#define MAX_COUNT						5									//�����Ŀ
#define MAX_JETTON_AREA					4									//��ע����
#define MAX_TIMES						10									//�������

#define VERSION_SERVER					PROCESS_VERSION(6,0,3)				//����汾
#define VERSION_CLIENT					PROCESS_VERSION(6,0,3)				//����汾

//����ԭ��
#define GER_NO_PLAYER					0x10								//û�����

//��Ϸ״̬
#define GS_TK_FREE						GAME_STATUS_FREE					//�ȴ���ʼ
#define GS_TK_CALL						GAME_STATUS_PLAY					//��ׯ״̬
#define GS_TK_SCORE						GAME_STATUS_PLAY+1					//��ע״̬
#define GS_TK_PLAYING					GAME_STATUS_PLAY+2					//��Ϸ����

#define SERVER_LEN						32 

//////////////////////////////////////////////////////////////////////////
//����������ṹ
#define SUB_MB_C_SHOW_TIP_REQUEST      19                         //������ʾ
#define SUB_MB_S_SHOW_TIP_RESPONSE     20                         //��ʾ����

enum SUB_S
{
	 SUB_S_GAME_START		=	100,								//��Ϸ��ʼ
	 SUB_S_ADD_SCORE		=	101,								//��ע���
	 SUB_S_PLAYER_EXIT		=	102,								//�û�ǿ��
	 SUB_S_SEND_CARD		=	103,								//������Ϣ
	 SUB_S_GAME_END			=	104,								//��Ϸ����
	 SUB_S_OPEN_CARD		=	105,								//�û�̯��
	 SUB_S_CALL_BANKER		=	106,								//֪ͨ��ׯ
	 SUB_S_ALL_CARD			=	107,								//�����˿�
	 SUB_S_AMDIN_COMMAND	=	108,								//ϵͳ����
	 SUB_S_BANKER_OPERATE	=	109,								//��ȡ��
	 SUB_S_BONUS_GAME		=	110,								//�н���Ϸ
	 SUB_S_BONUS_GAME_Result =	111,								//�н����
	 SUB_S_ENABLE_OPEN_CARD  =  112,								//֪ͨ����
	 SUB_S_USER_CALL		 =	113,								//�û���ׯ
};

#ifndef _UNICODE
#define myprintf	_snprintf
#define mystrcpy	strcpy
#define mystrlen	strlen
#define myscanf		_snscanf
#define	myLPSTR		LPCSTR
#define myatoi      atoi
#define myatoi64    _atoi64
#else
#define myprintf	swprintf
#define mystrcpy	wcscpy
#define mystrlen	wcslen
#define myscanf		_snwscanf
#define	myLPSTR		LPWSTR
#define myatoi      _wtoi
#define myatoi64	_wtoi64
#endif

//����״̬
struct CMD_S_StatusFree
{
	LONGLONG							lCellScore;							//��������
	LONGLONG							lTurnScore[GAME_PLAYER];			//������Ϣ
	LONGLONG							lCollectScore[GAME_PLAYER];			//������Ϣ
	TCHAR								szGameRoomName[SERVER_LEN];			//��������
};

//��ׯ״̬
struct CMD_S_StatusCall
{
	WORD                                wCallBanker;                           //��ׯ�û�
	BYTE                                cbDynamicJoin;                         //��̬���� 
	BYTE                                cbPlayStatus[GAME_PLAYER];             //�û�״̬
	LONGLONG							lTurnScore[GAME_PLAYER];			   //������Ϣ
	LONGLONG							lCollectScore[GAME_PLAYER];			   //������Ϣ
	TCHAR								szGameRoomName[SERVER_LEN];			   //��������
	BYTE								cbHandCardData[GAME_PLAYER][MAX_COUNT];//�����˿�
	BYTE								cbCallBankerStatus[GAME_PLAYER];	   //��ׯ״̬(0:����,1:��ׯ,2:δ��)
};

//��ע״̬
struct CMD_S_StatusScore
{
	//��ע��Ϣ
	BYTE                                cbPlayStatus[GAME_PLAYER];             //�û�״̬
	BYTE                                cbDynamicJoin;                         //��̬����
	LONGLONG							lTurnMaxScore;						   //�����ע
	LONGLONG							lTableScore[GAME_PLAYER];			   //��ע����
	WORD								wBankerUser;						   //ׯ���û�
	TCHAR								szGameRoomName[SERVER_LEN];			   //��������
	LONGLONG							lTurnScore[GAME_PLAYER];			   //������Ϣ
	LONGLONG							lCollectScore[GAME_PLAYER];			   //������Ϣ
	BYTE								cbHandCardData[GAME_PLAYER][MAX_COUNT];//�����˿�
};

//��Ϸ״̬
struct CMD_S_StatusPlay
{
	BYTE                                cbPlayStatus[GAME_PLAYER];              //�û�״̬
	BYTE                                cbDynamicJoin;                          //��̬����
	LONGLONG							lTurnMaxScore;						    //�����ע
	LONGLONG							lTableScore[GAME_PLAYER];			    //��ע��Ŀ
	WORD								wBankerUser;						    //ׯ���û�

	//�˿���Ϣ
	BYTE								cbHandCardData[GAME_PLAYER][MAX_COUNT]; //�����˿�
	BYTE								bOxCard[GAME_PLAYER];					//ţţ����
	BOOL								bOpenUser[GAME_PLAYER];					//̯���û�

	//��ʷ����
	LONGLONG							lTurnScore[GAME_PLAYER];			    //������Ϣ
	LONGLONG							lCollectScore[GAME_PLAYER];			    //������Ϣ
	TCHAR								szGameRoomName[SERVER_LEN];			    //��������
};

//�û���ׯ
struct CMD_S_CallBanker
{
	WORD								wCallBanker;						//��ׯ�û�
	bool								bFirstTimes;						//�Ƿ��ׯ
	BYTE								cbCallTime;							//��ׯʱ��
};

//��Ϸ��ʼ
struct CMD_S_GameStart
{	
	LONGLONG							lTurnMaxScore;						//�����ע
	WORD								wBankerUser;						//ׯ���û�
	BYTE								cbSelBankerTime;					//ѡׯ��ʱ��
};

//�û���ע
struct CMD_S_AddScore
{
	WORD								wAddScoreUser;						//��ע�û�
	LONGLONG							lAddScoreCount;						//��ע��Ŀ
};

//��Ϸ����
struct CMD_S_GameEnd
{
	LONGLONG							lGameTax[GAME_PLAYER];				//��Ϸ˰��
	LONGLONG							lGameScore[GAME_PLAYER];			//��Ϸ�÷�
	BYTE								cbCardData[GAME_PLAYER];			//�û��˿�
};

//�������ݰ�
struct CMD_S_SendCard
{
	BYTE								cbCardData[GAME_PLAYER][MAX_COUNT];	//�û��˿�
};

//�������ݰ�(����)
struct CMD_S_AllCard
{
	bool								bAICount[GAME_PLAYER];
	BYTE								cbCardData[GAME_PLAYER][MAX_COUNT];	//�û��˿�
};

//�û��˳�
struct CMD_S_PlayerExit
{
	WORD								wPlayerID;							//�˳��û�
};

//�û�̯��
struct CMD_S_Open_Card
{
	WORD								wPlayerID;							//̯���û�
	BYTE								bOpen;								//̯�Ʊ�־
};

//��ʾʣ�����
struct CMD_S_TipResponse
{	
	WORD			wRemainTimes;					//ʣ����ʾ����
	TCHAR			szDesc[64];						//�������
};

//////////////////////////////////////////////////////////////////////////
//�ͻ�������ṹ
enum SUB_C
{
	SUB_C_CALL_BANKER		=		1,									//�û���ׯ
	SUB_C_ADD_SCORE			=		2,									//�û���ע
	SUB_C_OPEN_CARD			=		3,									//�û�̯��
	SUB_C_SPECIAL_CLIENT_REPORT =   4,									//�����ն�
	SUB_C_AMDIN_COMMAND         =   5,									//ϵͳ����
	SUB_C_PLAY_BONUS_GAME       =   6,									//���潱��������Ϸ
    SUB_C_DISCARD_TIP_REQUEST   =   7,									//������ʾ    
};

enum eBONUS_GAME
{
	eGUESS_BIG = 1 ,                         //�´�С
};

//�û���ׯ
struct CMD_C_CallBanker
{
	BYTE  bBanker;                           //��ׯ��־
};

//�ն�����
struct CMD_C_SPECIAL_CLIENT_REPORT
{
	WORD  wUserChairID;                       //�û���λ
};

//�û���ע
struct CMD_C_AddScore
{
	LONGLONG lScore;                          //��ע��Ŀ
};

//�û�̯��
struct CMD_C_OxCard
{
	BYTE bOX;                                 //ţţ��־
};

//������ʾ
struct CMD_C_ShowTip
{
    DWORD dwGameID;                           //���ID
};

//////////////////////////////////////////////////////////////////////////
struct CMD_C_AdminReq
{
	BYTE cbReqType;
#define RQ_SET_WIN_AREA     1
#define RQ_RESET_CONTROL    2
#define RQ_PRINT_SYN        3
	BYTE cbExtendData[20];  //��������
};

//s->c �н�����Ϸ
struct CMD_S_BONUS_GAME //SUB_S_BONUS_GAME
{
	int gametype;       //����game���� 1 �´�С
	int serialnum;      //�������к� ����
	int chip;           //ע��
};

//c->s Ҫ��
struct CMD_C_PLAY_BONUS_GAME_REQ	//SUB_C_PLAY_BONUS_GAME
{
	int gametype;       //����game���� 1 �´�С
	int serialnum;      //�������к� ����
	int param;          //����
};

//s->c �µĽ��
struct CMD_S_BONUS_GAME_Result	// SUB_S_BONUS_GAME_Result
{
	int gametype;       //����game���� 1 �´�С
	int serialnum;      //�������к� ����
	int ctime;          //����Ӯ�Ĵ��� 0-6
	int ret;            //׬�˶��٣� �����Ǹ���.������
	WORD result[5];     //�µý�� 8����λ ����״��
};

//����ظ�
struct CMD_S_CommandResult
{
	BYTE cbAckType;				//�ظ�����
#define ACK_SET_WIN_AREA  1
#define ACK_PRINT_SYN     2
#define ACK_RESET_CONTROL 3
	BYTE cbResult;
#define CR_ACCEPT  2			//����
#define CR_REFUSAL 3			//�ܾ�
	BYTE cbExtendData[20];		//��������
};

#define IDM_ADMIN_COMMDN WM_USER+1000

//����������Ϣ
struct tagControlInfo
{
	INT  nAreaWin;		//��������
};

//���������Ʒ���
#define	 S_CR_FAILURE				0		//ʧ��
#define  S_CR_UPDATE_SUCCES			1		//���³ɹ�
#define	 S_CR_SET_SUCCESS			2		//���óɹ�
#define  S_CR_CANCEL_SUCCESS		3		//ȡ���ɹ�

struct CMD_S_ControlReturns
{
	BYTE cbReturnsType;				//�ظ�����
	BYTE cbControlArea;				//��������
	BYTE cbControlTimes;			//���ƴ���
};


//�ͻ��˿�������
#define  C_CA_UPDATE				1		//����
#define	 C_CA_SET					2		//����
#define  C_CA_CANCELS				3		//ȡ��
struct CMD_C_ControlApplication
{
	BYTE cbControlAppType;			//��������
	BYTE cbControlArea;				//��������
	BYTE cbControlTimes;			//���ƴ���
};

#pragma pack(pop)

#endif
