#ifndef __CMD_MB_CMD_COMMOM_REF__
#define __CMD_MB_CMD_COMMOM_REF__
#include "cocos2d.h"
USING_NS_CC;
#include "Define.h"
#include "SpriteDefine.h"
#include "CMD_Base.h"
#include "CMD_Commom.h"
#include "JT_Macro.h"

//ϵͳ��Ϣ
JT_CLASS_CMD(CMD_CM_SystemMessage)
	JT_SYNTHESIZE(WORD			,				wType);								//��Ϣ����
	JT_SYNTHESIZE(WORD			,				wLength);							//��Ϣ����
	JT_SYNTHESIZE_TCHAR(szString	,					1024);						//��Ϣ����
};


#endif //__CMD_MB_CMD_COMMOM_REF__