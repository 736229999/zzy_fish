#ifndef CMD_OXBATTLE_NEW_HEAD_FILE
#define CMD_OXBATTLE_NEW_HEAD_FILE

#include "Define.h"
#include "CMD_OxBattle.h"

#define SUB_S_RED_PACKAGE			115									//���ͺ��
#define SUB_C_RED_PACKAGE			10									//���ͺ��

#pragma pack(push)
#pragma pack(1)

//��һ�ִӽ��ػ�õ�һ��
struct tagAwardFirst
{
	DWORD                          dwGameID;							//���ID
	TCHAR						   szUserName[LEN_NICKNAME];				//����ǳ�
	LONGLONG                       lWinScore;							//��ҷ���
	LONGLONG					   lExtraScore;							//��Ҷ������
	bool						   bExtraScore;							//��������Ƿ��ж������
};


//��Ϸ״̬(������Ϣ:���н���)
struct CMD_S_HunNewStatusFree
{
	//ȫ����Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��
	bool							bEnableSysBanker;					//ϵͳ��ׯ


	//ׯ����Ϣ
	WORD							wBankerUser;						//��ǰׯ��
	WORD							cbBankerTime;						//ׯ�Ҿ���

	//�����Ϣ
	LONGLONG						lUserMaxScore;						//��ҽ��
	LONGLONG						lBankerWinScore;					//ׯ�ҳɼ�
	LONGLONG						lBankerScore;						//ׯ�ҷ���

	//������Ϣ
	LONGLONG						lApplyBankerCondition;				//��������
	LONGLONG						lAreaLimitScore;					//��������
	LONGLONG						lStorageStart;						//���ؿ��
	LONGLONG						lSitMinSocre;						//���µ���С���
	tagAwardFirst                   awardFirst;						//�����Ӯ��
	//������Ϣ
	TCHAR							szGameRoomName[SERVER_LEN];			//��������

};

//��Ϸ״̬(������Ϣ:��Ϸ������)
struct CMD_S_HunNewStatusPlay
{
	//ȫ����Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��
	BYTE							cbGameStatus;						//��Ϸ״̬
	bool							bEnableSysBanker;					//ϵͳ��ׯ
	//�˿���Ϣ
	BYTE							cbTableCardArray[5][5];				//�����˿�

	//ׯ����Ϣ
	WORD							wBankerUser;						//��ǰׯ��
	WORD							cbBankerTime;						//ׯ�Ҿ���
	//ȫ����ע
	LONGLONG						lAllJettonScore[AREA_COUNT];		//ȫ����ע

	//�����ע
	LONGLONG						lUserJettonScore[AREA_COUNT];		//������ע

	//��һ���
	LONGLONG						lUserMaxScore;						//�����ע							

	//������Ϣ
	LONGLONG						lApplyBankerCondition;				//��������
	LONGLONG						lAreaLimitScore;					//��������


	LONGLONG						lBankerWinScore;					//ׯ��Ӯ��
	LONGLONG						lBankerScore;						//ׯ�ҷ���

	//������Ϣ
	LONGLONG						lEndBankerScore;					//ׯ�ҳɼ�
	LONGLONG						lEndUserScore;						//��ҳɼ�
	LONGLONG						lEndUserReturnScore;				//���ػ���
	LONGLONG						lEndRevenue;						//��Ϸ˰��
    LONGLONG						lStorageStart;						//���ؿ��
	LONGLONG						lSitMinSocre;						//���µ���С���
	tagAwardFirst                   awardFirst;						//�����Ӯ��
	
	//������Ϣ
	TCHAR							szGameRoomName[SERVER_LEN];			//��������

};

//��Ϸ����
typedef struct
{
	//�¾���Ϣ
	BYTE							cbTimeLeave;						//ʣ��ʱ��

	//�˿���Ϣ
	BYTE							cbLeftCardCount;					//�˿���Ŀ

	BYTE							bcFirstCard;
 	BYTE							cbTableCardArray[5][5];				//�����˿�
	int								nBankerTime;						//��ׯ����

	//ׯ����Ϣ
	LONGLONG						lBankerScore;						//ׯ�ҳɼ�
	LONGLONG						lBankerTotallScore;					//ׯ�ҳɼ�

	//��ҳɼ�
	LONGLONG						lUserScore;							//��ҳɼ�
	LONGLONG						lUserReturnScore;					//���ػ���

	//ȫ����Ϣ
	LONGLONG						lRevenue;							//��Ϸ˰��
	tagUserWLInfo                   tagWinInfo[WIN_COUNT];				//Ӯ�����
	tagUserWLInfo					tagLoseInfo;						//������
	LONGLONG						lExtraScore;						//�������
	int 							nRedPackage;						//�Ƿ������ȡ���	
	LONGLONG						lStorageStart;						//�����

	//�����
	tagAwardFirst                   awardFirst;						    //�����Ӯ��
	BYTE							cbRedTimeLeave;						//���ʣ��ʱ��
	
}CMD_S_HunNewGameEnd;

//��Ϸ����
typedef struct
{
	BYTE							cbTimeLeave;						//ʣ��ʱ��	
	//WORD                            wLastBankerID;						//����ׯ��
 //   int 							nRedPackage;						//�����켸�������0����������
} CMD_S_HunNewGameFree;


//��ȡ����ɹ�
struct CMD_S_HunNewRED_PACKAGE
{
	LONGLONG					   lAwardScore;							//��ȡ������;
};

#pragma pack(pop)

#endif //#CMD_OXBATTLE_NEW_HEAD_FILE