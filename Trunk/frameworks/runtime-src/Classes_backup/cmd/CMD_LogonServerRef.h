#ifndef __CMD_MB_LOGON_SEVER_REF__
#define __CMD_MB_LOGON_SEVER_REF__
#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "CMD_LogonServer.h"
#include "JT_Macro.h"

//��ƽ̨��¼
JT_CLASS_CMD(CMD_MB_LogonOtherPlatform)
	JT_SYNTHESIZE(DWORD,dwPlazaVersion);
	JT_SYNTHESIZE_TCHAR(szHotVer,8);						// �ȸ��°汾
	JT_SYNTHESIZE(BYTE,cbDeviceType);

	JT_SYNTHESIZE(BYTE,cbGender);

	JT_SYNTHESIZE_TCHAR(cVerifyString,LEN_DECRYPTO);

	JT_SYNTHESIZE_TCHAR(szNickName,LEN_NICKNAME);

	JT_SYNTHESIZE_TCHAR(szMachineID,LEN_MACHINE_ID);
	JT_SYNTHESIZE_TCHAR(szUUID,LEN_USER_NOTE);
	JT_SYNTHESIZE_TCHAR(szPassword,LEN_MD5);
	JT_SYNTHESIZE_TCHAR(szDefaultFace,LEN_USER_NOTE);
	JT_SYNTHESIZE(BYTE,cbAcccountType);

};

JT_CLASS_CMD(CMD_GP_S_USER_PAWNSHOP)
	JT_GET_ARR(DWORD           ,                ItemType);                    // ����
	JT_GET_ARR(DWORD           ,                ItemCount);                   // ����
	JT_GET_ARR(DWORD           ,                BuyPrice);                    // ��۸�
	JT_GET_ARR(DWORD           ,                SalePrice);                   // ���۸�
	JT_GET_ARR2(TCHAR           ,                ItemName);  // ��Ʒ����
	//JT_GET_ARR2(TCHAR           ,                szPawnShopImageURL);    //�䵱ͼƬURL
};

JT_CLASS_CMD(CMD_MB_LogonSuccess)
	JT_SYNTHESIZE(BYTE   ,					  cbGender);                           //�û��Ա�
	JT_SYNTHESIZE(DWORD  ,                   dwUserID);                           //�û� I D
	JT_SYNTHESIZE(DWORD  ,                   dwGameID);                           //��Ϸ I D


	JT_SYNTHESIZE(BYTE  ,      cbAccountType);                      //��¼����
	JT_SYNTHESIZE(SCORE ,      lUserScore);                         //�û����
	JT_SYNTHESIZE(SCORE ,      lUserDaimond);
	//JT_SYNTHESIZE(WORD  ,      wContinueReward[CONTINUE_LOGIN_NUM]);//��¼����ֵ
	JT_SYNTHESIZE_TCHAR(         szUUID,LEN_USER_NOTE);              //Ψһ��ʶ
	JT_SYNTHESIZE_TCHAR(         szNickName,LEN_NICKNAME);           //�û��ǳ�
	JT_SYNTHESIZE_TCHAR(         szFaceURL,LEN_USER_NOTE);           //ͷ��URL��ַ
};

//��¼ʧ��
JT_CLASS_CMD(CMD_MB_LogonFailure)
	JT_SYNTHESIZE(LONG,lResultCode);						//�������
	JT_SYNTHESIZE_TCHAR(szDescribeString,128);				//������Ϣ
};

//��¼����
JT_CLASS_CMD(tagLoginAward)
	JT_SYNTHESIZE(BYTE	,			cbLoginCount);						//��¼����
	JT_SYNTHESIZE(BYTE	,			cbAwardType);						//��������
	JT_SYNTHESIZE(BYTE	,			cbAwardSubType);						//��������
	JT_SYNTHESIZE(WORD	,			wAwardCount);						//������Ŀ
};

//��½����
JT_CLASS_CMD(CMD_GP_LoginAward)
	JT_SYNTHESIZE(BYTE	,			cbMaxCount);							//�������
	JT_SYNTHESIZE(BYTE	,			cbDayCount);							//��ǰ����
	//tagLoginAward	,	LoginAward[MAX_LOGIN_AWARD];		//������Ϣ
};

//������ʾ
JT_CLASS_CMD(CMD_MB_UpdateNotify)
	JT_SYNTHESIZE(BYTE	,			cbMustUpdate);						//ǿ������
	JT_SYNTHESIZE(BYTE	,			cbAdviceUpdate);						//��������
	JT_SYNTHESIZE(BYTE	,			cbHotUpdate);						//�ȸ���
	JT_SYNTHESIZE(DWORD	,			dwCurrentVersion);					//��ǰ�汾
	JT_SYNTHESIZE_TCHAR(szHotVer,			8);						//������ȸ��°汾
};

//////////////////////////////////////////////////////////////////////////////////

//��������
JT_CLASS_CMD(CMD_GP_UserInsureInfo)
	JT_SYNTHESIZE(WORD				,			wRevenueTake);						//˰�ձ���
	JT_SYNTHESIZE(WORD				,			wRevenueTransfer);					//˰�ձ���
	JT_SYNTHESIZE(WORD				,			wServerID);							//�����ʶ
	JT_SYNTHESIZE(SCORE				,			lUserScore);							//�û����
	JT_SYNTHESIZE(SCORE				,			lUserInsure);						//���н��
	JT_SYNTHESIZE(SCORE				,			lTransferPrerequisite);				//ת������
};

//���гɹ�
JT_CLASS_CMD(CMD_GP_UserInsureSuccess)
    JT_SYNTHESIZE(DWORD				,			dwUserID);							//�û� I D
    JT_SYNTHESIZE(SCORE				,			lUserScore);							//�û����
    JT_SYNTHESIZE(SCORE				,			lUserInsure);						//���н��
    JT_SYNTHESIZE(DWORD				,			dwFromGameID);						//ת��ID
    JT_SYNTHESIZE(DWORD				,			dwReceGameID);						//����ID
    JT_SYNTHESIZE_TCHAR(						szNickName,LEN_NICKNAME);			//ת���û�
    JT_SYNTHESIZE_TCHAR(						szReceName,LEN_NICKNAME);			//�����û�
    JT_SYNTHESIZE(SCORE				,			lInsureTransfer);					//ת�����
    JT_SYNTHESIZE(SCORE				,			lInsureRevenue);						//˰��
    JT_SYNTHESIZE_TCHAR(						szDateTime,20);						//ת������
    JT_SYNTHESIZE_TCHAR(						szDescribeString,128);				//������Ϣ
};

//////////////////////////////////////////////////////////////////////////////////

#endif //__CMD_MB_LOGON_SEVER_REF__