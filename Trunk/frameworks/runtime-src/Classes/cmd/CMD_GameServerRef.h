#ifndef __CMD_GAME_SERVER_REF__
#define __CMD_GAME_SERVER_REF__

#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "JT_Macro.h"
#include "CMD_StructRef.h"
#include "CMD_GameServer.h"


//��������
JT_CLASS_CMD(CMD_GR_ConfigServer)
	//��������
	JT_SYNTHESIZE(WORD			,				wTableCount);						//������Ŀ
	JT_SYNTHESIZE(WORD			,				wChairCount);						//������Ŀ

	//��������
	JT_SYNTHESIZE(WORD			,				wServerType);						//��������
	JT_SYNTHESIZE(DWORD			,				dwServerRule);						//�������
};

//�û�״̬
JT_CLASS_CMD(CMD_GR_UserStatus)
void initRef(){
	UserStatus = tagUserStatusRef::createWithNotify();
	UserStatus->cmd = this->cmd.UserStatus;
};
	JT_SYNTHESIZE(DWORD			,dwUserID);							//�û���ʶ
	JT_SYNTHESIZE_REF(tagUserStatusRef*,UserStatus);							//�û�״̬
};

//�û�����
JT_CLASS_CMD(CMD_GR_UserScore)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
void initRef(){
	UserScore = tagUserScoreRef::createWithNotify();
	UserScore->cmd = this->cmd.UserScore;
};
	JT_SYNTHESIZE(DWORD				,			dwUserID);							//�û���ʶ
	JT_SYNTHESIZE_REF(tagUserScoreRef*	,	UserScore);							//������Ϣ
};

//�û�����
JT_CLASS_CMD(CMD_GR_MobileUserScore)
void initRef(){
	UserScore = tagMobileUserScoreRef::createWithNotify();
	UserScore->cmd = this->cmd.UserScore;
}
JT_SYNTHESIZE(DWORD					,		dwUserID);							//�û���ʶ
JT_SYNTHESIZE_REF(tagMobileUserScoreRef*,UserScore);							//������Ϣ
};

//����ʧ��
JT_CLASS_CMD(CMD_GR_RequestFailure)
JT_SYNTHESIZE(LONG,lErrorCode);							//�������
JT_SYNTHESIZE_TCHAR(szDescribeString,256);				//������Ϣ
};


//��������
JT_CLASS_CMD(CMD_GR_C_SendTrumpet)
	JT_SYNTHESIZE(BYTE             ,              cbRequestArea);                        //����Χ 
	JT_SYNTHESIZE(WORD             ,              wPropertyIndex);                      //�������� 
	JT_SYNTHESIZE(DWORD            ,              TrumpetColor);                        //������ɫ
	JT_SYNTHESIZE_TCHAR(szTrumpetContent,TRUMPET_MAX_CHAR);  //��������
};

//��������
JT_CLASS_CMD(CMD_GR_S_SendTrumpet)
	JT_SYNTHESIZE(WORD        ,                   wPropertyIndex);                      //�������� 
	JT_SYNTHESIZE(DWORD       ,                   dwSendUserID);                         //�û� I D
	JT_SYNTHESIZE(DWORD       ,                   TrumpetColor);                        //������ɫ
	JT_SYNTHESIZE_TCHAR(szSendNickName,32);				    //����ǳ� 
	JT_SYNTHESIZE_TCHAR(szTrumpetContent,TRUMPET_MAX_CHAR);  //��������
};

// ���ȵ���
JT_CLASS_CMD(CMD_GR_PropSouna)
    JT_SYNTHESIZE(DWORD			,					playerID);							// �û�ID
    JT_SYNTHESIZE(WORD			,					wGameID);							// ��ϷID
    JT_SYNTHESIZE(WORD			,					wSuonaType);							// ��������
    JT_SYNTHESIZE_TCHAR(szMsg,256);                         // ������Ϣ����
    JT_SYNTHESIZE_TCHAR(szNickName,LEN_NICKNAME);           // �û��ǳ�
} ;


//�û�����
JT_CLASS_CMD(CMD_GR_S_UserChat)
	JT_SYNTHESIZE(WORD			,				wChatLength);						//��Ϣ����
	JT_SYNTHESIZE(DWORD			,				dwChatColor);						//��Ϣ��ɫ
	JT_SYNTHESIZE(DWORD			,				dwSendUserID);						//�����û�
	JT_SYNTHESIZE(DWORD			,				dwTargetUserID);						//Ŀ���û�
	JT_SYNTHESIZE_TCHAR(szChatString,LEN_USER_CHAT);		//������Ϣ
};

//�û����ͱ���
JT_CLASS_CMD(CMD_GF_S_UserExpression)
	JT_SYNTHESIZE(WORD			,				wItemIndex);						//��Ϣ����
	JT_SYNTHESIZE(DWORD			,				dwSendUserID);						//�����û�
	JT_SYNTHESIZE(DWORD			,				dwTargetUserID);						//Ŀ���û�
};

//ת�˼�¼
JT_CLASS_CMD(CMD_GR_S_TransGoldRecordInfo)
	JT_SYNTHESIZE(DWORD         ,  dwSourceGameID);                            //ת��ID
	JT_SYNTHESIZE(DWORD         ,  dwTargetGameID);                            //Ŀ��ID
	JT_SYNTHESIZE(SCORE         ,  lTransScores);                              //ת����Ŀ
	JT_SYNTHESIZE_TCHAR(szNickName,LEN_NICKNAME);                  //�ü��ǳ�
	JT_SYNTHESIZE_TCHAR(szDateTime,MAX_COLUMN);                    //ת������
	JT_SYNTHESIZE_TCHAR(szClientIP,16);                            //�ͻ���IP
	JT_SYNTHESIZE_TCHAR(szDescMsg,64);                    //�����ʾ
};

#endif //__CMD_GAME_SERVER_REF__