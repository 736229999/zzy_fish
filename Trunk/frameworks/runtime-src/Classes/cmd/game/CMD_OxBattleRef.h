#ifndef CMD_OX_BACCARAT_REF
#define CMD_OX_BACCARAT_REF

#include "CMD_OxBattle.h"

#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"

//��¼��Ϣ
JT_CLASS_CMD(tagServerGameRecord)
	JT_CREATE_WITH_DATAARRAY(tagServerGameRecord);
	JT_SYNTHESIZE(bool				,			bWinShunMen);						//˳��ʤ��
	JT_SYNTHESIZE(bool				,			bWinDuiMen);							//����ʤ��
	JT_SYNTHESIZE(bool				,			bWinDaoMen);							//����ʤ��
	JT_SYNTHESIZE(bool				,			bWinHuang);							//����ʤ��
};


//ʧ�ܽṹ
JT_CLASS_CMD(CMD_S_HunPlaceJettonFail)
	JT_SYNTHESIZE(WORD				,			wPlaceUser);							//��ע���
	JT_SYNTHESIZE(BYTE				,			lJettonArea);						//��ע����
	JT_SYNTHESIZE(LONGLONG			,			lPlaceScore);						//��ǰ��ע
};

//���»���
JT_CLASS_CMD(CMD_S_HunChangeUserScore)
	JT_SYNTHESIZE(WORD				,			wChairID);							//���Ӻ���
	JT_SYNTHESIZE(DOUBLE			,				lScore);								//��һ���

	//ׯ����Ϣ
	JT_SYNTHESIZE(WORD				,			wCurrentBankerChairID);				//��ǰׯ��
	JT_SYNTHESIZE(BYTE				,			cbBankerTime);						//ׯ�Ҿ���
	JT_SYNTHESIZE(DOUBLE			,				lCurrentBankerScore);				//ׯ�ҷ���
};

//����ׯ��
JT_CLASS_CMD(CMD_S_HunApplyBanker)
	JT_SYNTHESIZE(WORD				,			wApplyUser);							//�������
};

//ȡ������(��wChairID��ֹ�ǳ�����)
JT_CLASS_CMD(CMD_S_HunCancelBanker)
	JT_SYNTHESIZE(WORD              ,              wChairID);                           //�������
	JT_SYNTHESIZE_TCHAR(szCancelUser,						32);					//ȡ�����
};

//�л�ׯ��
JT_CLASS_CMD(CMD_S_HunChangeBanker)
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//��ׯ���
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҽ��
};

//��Ϸ״̬
JT_CLASS_CMD(CMD_S_HunStatusFree)
	//ȫ����Ϣ
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��

	//�����Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//��ҽ��

	//ׯ����Ϣ
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//��ǰׯ��
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//ׯ�Ҿ���
	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//ׯ�ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҷ���
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//ϵͳ��ׯ

	//������Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//��������
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//��������
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//���µ���С���

	//������Ϣ
	JT_SYNTHESIZE_TCHAR(szGameRoomName	,		SERVER_LEN);			//��������
};

//��Ϸ״̬
JT_CLASS_CMD(CMD_S_HunStatusPlay)
	//ȫ����ע
	JT_GET_ARR(LONGLONG				,			lAllJettonScore);		//ȫ����ע

	//�����ע
	JT_GET_ARR(LONGLONG				,			lUserJettonScore);		//������ע

	//��һ���
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//�����ע							

	//������Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lApplyBankerCondition);				//��������
	JT_SYNTHESIZE(LONGLONG			,			lAreaLimitScore);					//��������

	//�˿���Ϣ
	JT_GET_ARR2(BYTE				,			cbTableCardArray);					//�����˿�

	//ׯ����Ϣ
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//��ǰׯ��
	JT_SYNTHESIZE(WORD				,			cbBankerTime);						//ׯ�Ҿ���
	JT_SYNTHESIZE(LONGLONG			,			lBankerWinScore);					//ׯ��Ӯ��
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҷ���
	JT_SYNTHESIZE(bool				,			bEnableSysBanker);					//ϵͳ��ׯ

	//������Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lEndBankerScore);					//ׯ�ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lEndUserScore);						//��ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lEndUserReturnScore);				//���ػ���
	JT_SYNTHESIZE(LONGLONG			,			lEndRevenue);						//��Ϸ˰��

	//ȫ����Ϣ
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��
	JT_SYNTHESIZE(BYTE				,			cbGameStatus);						//��Ϸ״̬
	JT_SYNTHESIZE(LONGLONG			,			lSitMinSocre);						//���µ���С���

	//������Ϣ
	JT_SYNTHESIZE_TCHAR(szGameRoomName	,SERVER_LEN);			//��������
};

//��Ϸ����
JT_CLASS_CMD(CMD_S_HunGameFree)
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��
};



//��Ϸ��ʼ
JT_CLASS_CMD(CMD_S_HunGameStart)
	JT_SYNTHESIZE(WORD				,			wBankerUser);						//ׯ��λ��
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҽ��
	JT_SYNTHESIZE(LONGLONG			,			lUserMaxScore);						//�ҵĽ��
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��	
	JT_SYNTHESIZE(bool				,			bContiueCard);						//��������
	JT_SYNTHESIZE(int				,			nChipRobotCount);					//�������� (��ע������)
};

//�û���ע
JT_CLASS_CMD(CMD_S_HunPlaceJetton)
	JT_SYNTHESIZE(WORD				,			wChairID);							//�û�λ��
	JT_SYNTHESIZE(BYTE				,			cbJettonArea);						//��������
	JT_SYNTHESIZE(LONGLONG			,			lJettonScore);						//��ע��Ŀ
	JT_SYNTHESIZE(bool				,			bIsAndroid);							//�Ƿ������
};

//��Ϸ����
JT_CLASS_CMD(CMD_S_HunGameEnd)
	//�¾���Ϣ
	JT_SYNTHESIZE(BYTE				,			cbTimeLeave);						//ʣ��ʱ��

	//�˿���Ϣ
	JT_GET_ARR2(BYTE				,			cbTableCardArray);				//�����˿�
	JT_SYNTHESIZE(BYTE				,			cbLeftCardCount);					//�˿���Ŀ

	JT_SYNTHESIZE(BYTE				,			bcFirstCard);
 
	//ׯ����Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lBankerScore);						//ׯ�ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lBankerTotallScore);					//ׯ�ҳɼ�
	JT_SYNTHESIZE(INT				,				nBankerTime);						//��ׯ����

	//��ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lUserScore);							//��ҳɼ�
	JT_SYNTHESIZE(LONGLONG			,			lUserReturnScore);					//���ػ���

	//ȫ����Ϣ
	JT_SYNTHESIZE(LONGLONG			,			lRevenue);							//��Ϸ˰��
};

//�û���ע
JT_CLASS_CMD(CMD_C_HunPlaceJetton)
	JT_SYNTHESIZE(BYTE				,			cbJettonArea);						//��������
	JT_SYNTHESIZE(LONGLONG			,			lJettonScore);						//��ע��Ŀ
};

//14.08.05����------------------------------------------------

//��������
JT_CLASS_CMD(CMD_C_ApplySit)
	JT_SYNTHESIZE(WORD				,			wSitChairID);						//�����������ID
};

//�뿪λ��
JT_CLASS_CMD(CMD_C_CancelSit)
	JT_SYNTHESIZE(WORD				,			wSitChairID);							//������Ӻ�	
};

//�������³ɹ�
JT_CLASS_CMD(CMD_S_ApplySit)
	JT_SYNTHESIZE(WORD              ,           wSitChairID);							//���µ�����ID
	JT_SYNTHESIZE(WORD				,			wApplySitID);						//�����������ID
};

//�뿪λ�óɹ�
JT_CLASS_CMD(CMD_S_CancelSit)
	JT_SYNTHESIZE(WORD              ,           wSitChairID);							//���µ�����ID
	JT_SYNTHESIZE(WORD				,			wCancelID);							//������Ӻ�					
};

//��Ӯ��Ϣ
JT_CLASS_CMD(tagUserWLInfo)
	JT_SYNTHESIZE(WORD              ,             wChairID);							//���ID
	JT_SYNTHESIZE(LONGLONG			,		   lJettonScore);						//��ҳɼ�
};

JT_CLASS_CMD(CMD_S_WLInfo)
public:

	void initRef()
	{
		tagLoseInfo = tagUserWLInfoRef::createWithNotify();
		tagLoseInfo->cmd = this->cmd.tagLoseInfo;

		for(int i = 0;i < WIN_COUNT;i++)
		{
			tagWinInfo[i] = tagUserWLInfoRef::createWithNotify();
			tagWinInfo[i]->cmd = this->cmd.tagWinInfo[i];
		}
	};

	JT_SYNTHESIZE_REF_ARR(tagUserWLInfoRef*,	tagWinInfo,WIN_COUNT);								//Ӯ�����
	JT_SYNTHESIZE_REF(tagUserWLInfoRef*,		tagLoseInfo);						//������
};

//--------------------------------------------------//



#endif //CMD_OX_BACCARAT_REF