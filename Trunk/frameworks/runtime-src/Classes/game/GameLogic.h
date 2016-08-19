#ifndef GAME_LOGIC_HEAD_FILE
#define GAME_LOGIC_HEAD_FILE

#pragma once

#include "Define.h"
#include "SpriteDefine.h"

//////////////////////////////////////////////////////////////////////////
//����
//enum emCardType
//{
//	CT_ERROR			=	0,								//��������
//	CT_POINT			=	1,								//��������
//	CT_SPECIAL_NIU1		=	1,								//ţһ
//	CT_SPECIAL_NIU2		=	2,								//ţ��
//	CT_SPECIAL_NIU3		=	3,								//ţ��
//	CT_SPECIAL_NIU4		=	4,								//ţ��
//	CT_SPECIAL_NIU5		=	5,								//ţ��
//	CT_SPECIAL_NIU6		=	6,								//ţ��
//	CT_SPECIAL_NIU7		=	7,								//ţ��
//	CT_SPECIAL_NIU8		=	8,								//ţ��
//	CT_SPECIAL_NIU9		=	9,								//ţ��
//	CT_SPECIAL_NIUNIUXW	=	10,								//С��ţ
//	CT_SPECIAL_NIUNIUDW	=	10,								//����ţ
//	CT_SPECIAL_NIUNIU	=	10,								//ţţ
//	CT_SPECIAL_NIUYING	=	10,								//��ţ
//	CT_SPECIAL_NIUKING	=	10,								//��ţ
//	CT_SPECIAL_BOMEBOME	=	10								//ը��
//};
enum emCardType
{
	CT_ERROR			=	0,								//��������
	CT_POINT			=	1,								//��ţ
	CT_SPECIAL_NIU1		=	2,								//ţһ
	CT_SPECIAL_NIU2		=	3,								//ţ��
	CT_SPECIAL_NIU3		=	4,								//ţ��
	CT_SPECIAL_NIU4		=	5,								//ţ��
	CT_SPECIAL_NIU5		=	6,								//ţ��
	CT_SPECIAL_NIU6		=	7,								//ţ��
	CT_SPECIAL_NIU7		=	8,								//ţ��
	CT_SPECIAL_NIU8		=	9,								//ţ��
	CT_SPECIAL_NIU9		=	10,								//ţ��	
	CT_SPECIAL_NIUNIU	=	11,								//ţţ	
	CT_SPECIAL_BOMEBOME	=	12,								//ը��
	CT_SPECIAL_NIUYING	=	13,								//��ţ(�廨ţ)
	CT_SPECIAL_NIUKING	=	14,								//��ţ(�廨ţ)	
	CT_SPECIAL_SMALL	=	15								//��С�
};
		
//��ֵ����
#define	LOGIC_MASK_COLOR			0xF0						//��ɫ����
#define	LOGIC_MASK_VALUE			0x0F						//��ֵ����

//��������
#define	ST_VALUE					1							//��ֵ����
#define	ST_NEW					    3							//��ֵ����
#define	ST_LOGIC					2							//�߼�����

//�˿���Ŀ
#define CARD_COUNT					52							//�˿���Ŀ
#define USER_CARD_NUM               5                            //����

//��Ϸ�߼�
class CGameLogic
{
	//��������
public:
	static const BYTE				m_cbCardListData[CARD_COUNT];		//�˿˶���

	//��������
public:
	//���캯��
	CGameLogic();
	//��������
	virtual ~CGameLogic();

	//���ͺ���
public:
	//��ȡ��ֵ
	static BYTE GetCardValue(BYTE cbCardData) 
	{ 
		return cbCardData&LOGIC_MASK_VALUE; 
	}
	//��ȡ��ɫ
	static BYTE GetCardColor(BYTE cbCardData)
	{
		return (cbCardData&LOGIC_MASK_COLOR)>>4;
	}

	//���ƺ���
public:
	//�����˿�
	static void RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount);
	//�����˿�
	static void RandCardListEx(BYTE cbCardBuffer[], BYTE cbBufferCount);
	//�����˿�
	static void SortCardList(BYTE cbCardData[], BYTE cbCardCount, BYTE cbSortType);

	static int RetType(int itype);

	//�߼�����
public:
	//��ȡ�Ƶ�
	static BYTE GetCardListPip(const BYTE cbCardData[], BYTE cbCardCount);
	//��ȡ����
	static BYTE GetCardType(const BYTE cbCardData[], BYTE cbCardCount,BYTE *bcOutCadData = NULL);
	//��С�Ƚ�
	static int CompareCard(const BYTE cbFirstCardData[], BYTE cbFirstCardCount,const BYTE cbNextCardData[], BYTE cbNextCardCount,BYTE &Multiple);
	//�߼���С
	static BYTE GetCardLogicValue(BYTE cbCardData);

	static BYTE GetCardNewValue(BYTE cbCardData);

	//����С��
	static BYTE CheckKingCard(const BYTE cbCardData[], BYTE cbCardCount);
};

//////////////////////////////////////////////////////////////////////////

#endif
