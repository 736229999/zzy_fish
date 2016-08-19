#ifndef __CMD_STRUCTREF_H__
#define __CMD_STRUCTREF_H__
#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"
#include "Struct.h"

JT_CLASS_CMD(tagGameServer)
	JT_SYNTHESIZE(WORD			,			wKindID);							//��������
	JT_SYNTHESIZE(WORD			,			wNodeID);							//�ڵ�����
	JT_SYNTHESIZE(WORD			,			wSortID);							//��������
	JT_SYNTHESIZE(WORD			,			wServerID);							//��������
	JT_SYNTHESIZE(WORD			,			wServerPort);						//����˿�
	JT_SYNTHESIZE(DWORD			,			dwOnLineCount);						//��������
	JT_SYNTHESIZE(DWORD			,			dwFullCount);						//��Ա����
	JT_SYNTHESIZE(LONG			,			lCellScore);							//��λ����
	JT_SYNTHESIZE(SCORE			,			lMinEnterScore);						//��ͻ���
	JT_SYNTHESIZE(SCORE			,			lMaxEnterScore);						//��߻���
	JT_SYNTHESIZE_TCHAR(szServerAddr,32);					//�������ƣ�Ӧ���Ƿ�������ַ�ɣ�
	JT_SYNTHESIZE_TCHAR(szServerName,LEN_SERVER);			//��������
	JT_CREATE_WITH_DATAARRAY(tagGameServer);
};

//�û���Ϣ
JT_CLASS_CMD(tagMobileUserInfoHead)
	//�û�����
	JT_SYNTHESIZE(DWORD			,			dwGameID);							//��Ϸ I D
	JT_SYNTHESIZE(DWORD			,			dwUserID);							//�û� I D

		//ͷ����Ϣ
	JT_SYNTHESIZE(WORD			,			wFaceID);							//ͷ������
	JT_SYNTHESIZE(DWORD			,			dwCustomID);							//�Զ���ʶ

		//�û�����
	JT_SYNTHESIZE(BYTE			,			cbGender);							//�û��Ա�
	JT_SYNTHESIZE(BYTE			,			cbMemberOrder);						//��Ա�ȼ�

		//�û�״̬
	JT_SYNTHESIZE(WORD			,			wTableID);							//��������
	JT_SYNTHESIZE(WORD			,			wChairID);							//��������
	JT_SYNTHESIZE(BYTE			,			cbUserStatus);						//�û�״̬

		//������Ϣ
	JT_SYNTHESIZE(SCORE			,			lScore);								//�û�����

		//��Ϸ��Ϣ
	JT_SYNTHESIZE(DWORD			,			dwWinCount);							//ʤ������
	JT_SYNTHESIZE(DWORD			,			dwLostCount);						//ʧ������
	JT_SYNTHESIZE(DWORD			,			dwDrawCount);						//�;�����
	JT_SYNTHESIZE(DWORD			,			dwFleeCount);						//��������
	JT_SYNTHESIZE(DWORD			,			dwExperience);						//�û�����

	JT_SYNTHESIZE_TCHAR(szNickName	,		LEN_NICKNAME);						//�û��ǳ�
	JT_SYNTHESIZE_TCHAR(szFaceIDDownURL	,	LEN_USER_NOTE);						//�Զ���ͷ���ַ
};

//�û�״̬
JT_CLASS_CMD(tagUserStatus)
	JT_SYNTHESIZE(WORD			,			wTableID);							//��������
	JT_SYNTHESIZE(WORD			,			wChairID);							//����λ��
	JT_SYNTHESIZE(BYTE			,			cbUserStatus);						//�û�״̬
};

//�û�����
JT_CLASS_CMD(tagUserScore)
	//������Ϣ
	JT_SYNTHESIZE(SCORE			,				lScore);								//�û�����
	JT_SYNTHESIZE(SCORE			,				lGrade);								//�û��ɼ�
	JT_SYNTHESIZE(SCORE			,				lInsure);							//�û�����

	//��Ӯ��Ϣ
	JT_SYNTHESIZE(DWORD			,				dwWinCount);							//ʤ������
	JT_SYNTHESIZE(DWORD			,				dwLostCount);						//ʧ������
	JT_SYNTHESIZE(DWORD			,				dwDrawCount);						//�;�����
	JT_SYNTHESIZE(DWORD			,				dwFleeCount);						//��������

	//ȫ����Ϣ
	JT_SYNTHESIZE(DWORD			,				dwUserMedal);						//�û�����
	JT_SYNTHESIZE(DWORD			,				dwExperience);						//�û�����
	JT_SYNTHESIZE(LONG			,				lLoveLiness);						//�û�����
};

//�û�����
JT_CLASS_CMD(tagMobileUserScore)
	//������Ϣ
	JT_SYNTHESIZE(SCORE			,				lScore);								//�û�����

	//��Ӯ��Ϣ
	JT_SYNTHESIZE(DWORD			,				dwWinCount);							//ʤ������
	JT_SYNTHESIZE(DWORD			,				dwLostCount);						//ʧ������
	JT_SYNTHESIZE(DWORD			,				dwDrawCount);						//�;�����
	JT_SYNTHESIZE(DWORD			,				dwFleeCount);						//��������

	//ȫ����Ϣ
	JT_SYNTHESIZE(DWORD			,				dwExperience);						//�û�����
};

#endif // !__CMD_STRUCTREF_H__



