#ifndef CMD_OX_BACCARAT_NEW_REF
#define CMD_OX_BACCARAT_NEW_REF

#include "cocos2d.h"
USING_NS_CC;

#include "CMD_OxBattleNew.h"
#include "CMD_OxBattleRef.h"
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"

//��һ�ִӽ��ػ�õ�һ��
JT_CLASS_CMD(tagAwardFirst)
	JT_SYNTHESIZE(DWORD              ,             dwGameID);							//���ID
	JT_SYNTHESIZE_TCHAR(szUserName  ,			LEN_NICKNAME);				//����ǳ�
	JT_SYNTHESIZE(LONGLONG          ,             lWinScore);							//��ҷ���
	JT_SYNTHESIZE(LONGLONG			,		   lExtraScore);							//��Ҷ������
	JT_SYNTHESIZE(bool				,		   bExtraScore);							//��������Ƿ��ж������
};

//��Ϸ״̬(������Ϣ:���н���)
JT_CLASS_CMD(CMD_S_HunNewStatusFree)

	void initRef()
	{
		TagAwardFirst = tagAwardFirstRef::createWithNotify();
		TagAwardFirst->cmd = this->cmd.awardFirst;
	}

	//ȫ����Ϣ
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//ϵͳ��ׯ


	//ׯ����Ϣ
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//��ǰׯ��
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//ׯ�Ҿ���

	//�����Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//��ҽ��
	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//ׯ�ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҷ���

	//������Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//��������
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//��������
	JT_SYNTHESIZE(LONGLONG			,			lStorageStart);						//���
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//���µ���С���
	JT_SYNTHESIZE_REF(tagAwardFirstRef*    ,           TagAwardFirst);						//�����Ӯ��

	//������Ϣ
	JT_SYNTHESIZE_TCHAR(szGameRoomName,SERVER_LEN);			//��������
};

//��Ϸ״̬(������Ϣ:��Ϸ������)
JT_CLASS_CMD(CMD_S_HunNewStatusPlay)

	void initRef()
	{
		TagAwardFirst = tagAwardFirstRef::createWithNotify();
		TagAwardFirst->cmd = this->cmd.awardFirst;
	}

	//ȫ����Ϣ
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��
	JT_SYNTHESIZE(BYTE				,			cbGameStatus);						//��Ϸ״̬
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//ϵͳ��ׯ
	
	JT_GET_ARR2(BYTE				,			cbTableCardArray);				//�����˿�

	//ׯ����Ϣ
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//��ǰׯ��
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//ׯ�Ҿ���
	//ȫ����ע
	JT_GET_ARR(LONGLONG			,			lAllJettonScore);		//ȫ����ע

	//�����ע
	JT_GET_ARR(LONGLONG			,			lUserJettonScore);		//������ע

	//��һ���
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//�����ע							

	//������Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//��������
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//��������


	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//ׯ��Ӯ��
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҷ���

	//������Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lEndBankerScore);					//ׯ�ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lEndUserScore);						//��ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lEndUserReturnScore);				//���ػ���
	JT_SYNTHESIZE(LONGLONG			,			lEndRevenue);						//��Ϸ˰��
    JT_SYNTHESIZE(LONGLONG			,			lStorageStart);						//���ؿ��
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//���µ���С���
	JT_SYNTHESIZE_REF(tagAwardFirstRef* ,		TagAwardFirst);						//�����Ӯ��
	

	//������Ϣ
	JT_SYNTHESIZE_TCHAR(szGameRoomName,SERVER_LEN);			//��������
};

//��Ϸ����
JT_CLASS_CMD(CMD_S_HunNewGameEnd)
	void initRef()
	{
		tagLoseInfo = tagUserWLInfoRef::createWithNotify();
		tagLoseInfo->cmd = this->cmd.tagLoseInfo;

		for(int i = 0;i < WIN_COUNT;i++)
		{
			tagWinInfo[i] = tagUserWLInfoRef::createWithNotify();
			tagWinInfo[i]->cmd = this->cmd.tagWinInfo[i];
		}
		TagAwardFirst = tagAwardFirstRef::createWithNotify();
		TagAwardFirst->cmd = this->cmd.awardFirst;
	}

	//�¾���Ϣ
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��

	//�˿���Ϣ
	JT_SYNTHESIZE(BYTE				,			cbLeftCardCount);					//�˿���Ŀ

	JT_SYNTHESIZE(BYTE				,			bcFirstCard);
 	JT_GET_ARR2(BYTE				,			cbTableCardArray);				//�����˿�
	JT_SYNTHESIZE(int				,				nBankerTime);						//��ׯ����

	//ׯ����Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lBankerTotallScore);					//ׯ�ҳɼ�

	//��ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lUserScore);							//��ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lUserReturnScore);					//���ػ���

	//ȫ����Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lRevenue);							//��Ϸ˰��
	JT_SYNTHESIZE_REF_ARR(tagUserWLInfoRef*,tagWinInfo,         WIN_COUNT);				//Ӯ�����
	JT_SYNTHESIZE_REF(tagUserWLInfoRef*	,		tagLoseInfo);						//������
	JT_SYNTHESIZE(LONGLONG			,			lExtraScore);						//�������
	JT_SYNTHESIZE(int 				,			nRedPackage);						//�Ƿ������ȡ���	
	JT_SYNTHESIZE(LONGLONG			,			lStorageStart);						//�����
	//�����
	JT_SYNTHESIZE_REF(tagAwardFirstRef*    ,	TagAwardFirst);						    //�����Ӯ��
	JT_SYNTHESIZE(BYTE				,			cbRedTimeLeave);						//���ʣ��ʱ��
};

//��Ϸ����
JT_CLASS_CMD(CMD_S_HunNewGameFree)
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��	
	//JT_SYNTHESIZE(WORD				,			wLastBankerID);						//����ׯ��
 //   JT_SYNTHESIZE(int 				,			nRedPackage);						//�����켸�������0����������
} ;

//��ȡ����ɹ�
JT_CLASS_CMD(CMD_S_HunNewRED_PACKAGE)
	JT_SYNTHESIZE(LONGLONG			,		   lAwardScore);							//��ȡ������;
};


#endif //CMD_OX_BACCARAT_NEW_REF