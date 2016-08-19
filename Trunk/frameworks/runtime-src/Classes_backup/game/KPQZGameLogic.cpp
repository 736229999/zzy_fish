#include "KPQZGameLogic.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	#define RtlCopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
	#define CopyMemory RtlCopyMemory
#endif

//////////////////////////////////////////////////////////////////////////


//扑克数据
BYTE KPQZGameLogic::m_cbCardListData[52]=
{
	//0x1C,0x1D,0x3B,0x3C,0x3D,0x09,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	//0x3A,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,	//梅花 A - K
	//0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	//0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39	//黑桃 A - K
	0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,	//方块 A - K
	0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,	//梅花 A - K
	0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,	//红桃 A - K
	0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D	//黑桃 A - K
};

//////////////////////////////////////////////////////////////////////////

//构造函数
KPQZGameLogic::KPQZGameLogic()
{
}

//析构函数
KPQZGameLogic::~KPQZGameLogic()
{
}

//获取类型
BYTE KPQZGameLogic::GetCardType(BYTE cbCardData[], BYTE cbCardCount)
{
	assert(cbCardCount==MAX_COUNT);

	//五小牛
	bool bIsFXN = true;
	BYTE cbTotalValue = 0;
	for(BYTE i=0;i<cbCardCount;i++)
	{
		if (GetCardValue(cbCardData[i]) >= 5)
		{
			bIsFXN = false;
			break;
		}
		cbTotalValue += GetCardValue(cbCardData[i]);
	}
	if (cbTotalValue > 10)
	{
		bIsFXN = false;
	}
	if (bIsFXN) return OX_FIVEXNIU;
	//////////////////////////////////////////////////////////////////////////

	//炸弹牌型
	BYTE bSameCount = 0;
	SortCardList(cbCardData,cbCardCount);
	BYTE bSecondValue = GetCardValue(cbCardData[MAX_COUNT/2]);
	for(BYTE i=0;i<cbCardCount;i++)
	{
		if(bSecondValue == GetCardValue(cbCardData[i]))
		{
			bSameCount++;
		}
	}
	if(bSameCount==4)return OX_FOUR_SAME;



	BYTE bKingCount=0,bTenCount=0;
	for(BYTE i=0;i<cbCardCount;i++)
	{
		if(GetCardValue(cbCardData[i])>10)
		{
			bKingCount++;
		}
		else if(GetCardValue(cbCardData[i])==10)
		{
			bTenCount++;
		}
	}
	if(bKingCount==MAX_COUNT) return OX_FIVEKING;
	else if(bKingCount==MAX_COUNT-1 && bTenCount==1) return 10;

	////葫芦牌型
	//if(bSameCount==3)
	//{
	//	if((bSecondValue!=GetCardValue(cbCardData[3]) && GetCardValue(cbCardData[3])==GetCardValue(cbCardData[4]))
	//	||(bSecondValue!=GetCardValue(cbCardData[1]) && GetCardValue(cbCardData[1])==GetCardValue(cbCardData[0])))
	//		return OX_THREE_SAME;
	//}

	BYTE bTemp[MAX_COUNT];
	BYTE bSum=0;
	for (BYTE i=0;i<cbCardCount;i++)
	{
		bTemp[i]=GetCardLogicValue(cbCardData[i]);
		bSum+=bTemp[i];
	}

	for (BYTE i=0;i<cbCardCount-1;i++)
	{
		for (BYTE j=i+1;j<cbCardCount;j++)
		{
			if((bSum-bTemp[i]-bTemp[j])%10==0)
			{
				return ((bTemp[i]+bTemp[j])>10)?(bTemp[i]+bTemp[j]-10):(bTemp[i]+bTemp[j]);
			}
		}
	}

	return OX_VALUE0;
}

//获取倍数    
BYTE KPQZGameLogic::GetTimes(BYTE cbCardData[], BYTE cbCardCount)
{
	if(cbCardCount!=MAX_COUNT)return 0;

	BYTE bTimes=GetTimes(GetCardType(cbCardData,MAX_COUNT));
	return bTimes;
}

BYTE KPQZGameLogic::GetTimes(BYTE bTimes)
{
	if(bTimes<=7)return 1;
 	//else if(bTimes==7)return 2;
 	else if(bTimes==8)return 2;
 	else if(bTimes==9)return 2;
	else if(bTimes==10)return 3;			//牛牛
//	else if(bTimes==OX_THREE_SAME)return 5;

	else if(bTimes==OX_FIVEKING)return 4;		//五张10
	else if(bTimes==OX_FOUR_SAME)return 4;		//炸弹
	else if(bTimes==OX_FIVEXNIU)return 4;		//五小牛
	else if(bTimes==OX_FOURKING)return 4;		//四张10
	return 0;
}

BYTE KPQZGameLogic::GetTimes_5(BYTE cbCardData[], BYTE cbCardCount)
{
	if(cbCardCount!=MAX_COUNT)return 0;

	BYTE bTimes=GetCardType(cbCardData,MAX_COUNT);
	if(bTimes<2)return 1;
	else if(bTimes==2)return 1;
	else if(bTimes==3)return 1;
	else if(bTimes==4)return 1;
	else if(bTimes==5)return 1;
	else if(bTimes==6)return 1;
	else if(bTimes==7)return 2;
	else if(bTimes==8)return 3;
	else if(bTimes==9)return 4;
	else if(bTimes==10)return 5;
	else if(bTimes==OX_FOURKING)return 5;
	else if(bTimes==OX_FIVEKING)return 5;

	return 0;
}

//获取牛牛
bool KPQZGameLogic::GetOxCard(BYTE cbCardData[], BYTE cbCardCount)
{
	assert(cbCardCount==MAX_COUNT);

	//设置变量
	BYTE bTemp[MAX_COUNT],bTempData[MAX_COUNT];
	CopyMemory(bTempData,cbCardData,sizeof(bTempData));
	BYTE bSum=0;
	for (BYTE i=0;i<cbCardCount;i++)
	{
		bTemp[i]=GetCardLogicValue(cbCardData[i]);
		bSum+=bTemp[i];
	}

	//查找牛牛
	for (BYTE i=0;i<cbCardCount-1;i++)
	{
		for (BYTE j=i+1;j<cbCardCount;j++)
		{
			if((bSum-bTemp[i]-bTemp[j])%10==0)
			{
				BYTE bCount=0;
				for (BYTE k=0;k<cbCardCount;k++)
				{
					if(k!=i && k!=j)
					{
						cbCardData[bCount++] = bTempData[k];
					}
				}assert(bCount==3);

				cbCardData[bCount++] = bTempData[i];
				cbCardData[bCount++] = bTempData[j];

				return true;
			}
		}
	}

	return false;
}

//获取整数
bool KPQZGameLogic::IsIntValue(BYTE cbCardData[], BYTE cbCardCount)
{
	BYTE sum=0;
	for(BYTE i=0;i<cbCardCount;i++)
	{
		sum+=GetCardLogicValue(cbCardData[i]);
	}
	assert(sum>0);
	return (sum%10==0);
}

//排列扑克
void KPQZGameLogic::SortCardList(BYTE cbCardData[], BYTE cbCardCount)
{
	//转换数值
	BYTE cbLogicValue[MAX_COUNT];
	for(BYTE i=0;i<cbCardCount;i++) 
           cbLogicValue[i]=GetCardValue(cbCardData[i]);	

	//排序操作
	bool bSorted=true;
	BYTE cbTempData,bLast=cbCardCount-1;
	do
	{
		bSorted=true;
		for (BYTE i=0;i<bLast;i++)
		{
			if ((cbLogicValue[i]<cbLogicValue[i+1])||
				((cbLogicValue[i]==cbLogicValue[i+1])&&(cbCardData[i]<cbCardData[i+1])))
			{
				//交换位置
				cbTempData=cbCardData[i];
				cbCardData[i]=cbCardData[i+1];
				cbCardData[i+1]=cbTempData;
				cbTempData=cbLogicValue[i];
				cbLogicValue[i]=cbLogicValue[i+1];
				cbLogicValue[i+1]=cbTempData;
				bSorted=false;
			}	
		}
		bLast--;
	} while(bSorted==false);

	return;
}

//混乱扑克
void KPQZGameLogic::RandCardList(BYTE cbCardBuffer[], BYTE cbBufferCount)
{
	//CopyMemory(cbCardBuffer,m_cbCardListData,cbBufferCount);
	//混乱准备
	BYTE cbCardData[CountArray(m_cbCardListData)];
	CopyMemory(cbCardData,m_cbCardListData,sizeof(m_cbCardListData));

	//混乱扑克
	BYTE bRandCount=0,bPosition=0;
	do
	{
		bPosition=rand()%(CountArray(m_cbCardListData)-bRandCount);
		cbCardBuffer[bRandCount++]=cbCardData[bPosition];
		cbCardData[bPosition]=cbCardData[CountArray(m_cbCardListData)-bRandCount];
	} while (bRandCount<cbBufferCount);

	return;
}

//逻辑数值
BYTE KPQZGameLogic::GetCardLogicValue(BYTE cbCardData)
{
	//扑克属性
	BYTE bCardColor=GetCardColor(cbCardData);
	BYTE bCardValue=GetCardValue(cbCardData);

	//转换数值
	return (bCardValue>10)?(10):bCardValue;
}

//对比扑克
bool KPQZGameLogic::CompareCard(BYTE cbFirstData[],BYTE cbNextData[],BYTE cbCardCount,int FirstOX,int NextOX)
{
	if(FirstOX!=NextOX)return (FirstOX>NextOX);

	//比较牛大小
	if(FirstOX==TRUE)
	{
		//获取点数
		BYTE cbNextType=GetCardType(cbNextData,cbCardCount);
		BYTE cbFirstType=GetCardType(cbFirstData,cbCardCount);

		//点数判断
		if (cbFirstType!=cbNextType) return (cbFirstType>cbNextType);

		switch(cbNextType)
		{
		case OX_FOUR_SAME:		//炸弹牌型	
		case OX_THREE_SAME:		//葫芦牌型
			{
				//排序大小
				BYTE bFirstTemp[MAX_COUNT],bNextTemp[MAX_COUNT];
				CopyMemory(bFirstTemp,cbFirstData,cbCardCount);
				CopyMemory(bNextTemp,cbNextData,cbCardCount);
				SortCardList(bFirstTemp,cbCardCount);
				SortCardList(bNextTemp,cbCardCount);

				return GetCardValue(bFirstTemp[MAX_COUNT/2])>GetCardValue(bNextTemp[MAX_COUNT/2]);

				break;
			}
		}
	}

	//排序大小
	BYTE bFirstTemp[MAX_COUNT],bNextTemp[MAX_COUNT];
	CopyMemory(bFirstTemp,cbFirstData,cbCardCount);
	CopyMemory(bNextTemp,cbNextData,cbCardCount);
	SortCardList(bFirstTemp,cbCardCount);
	SortCardList(bNextTemp,cbCardCount);

	//比较数值
	BYTE cbNextMaxValue=GetCardValue(bNextTemp[0]);
	BYTE cbFirstMaxValue=GetCardValue(bFirstTemp[0]);
	if(cbNextMaxValue!=cbFirstMaxValue)return cbFirstMaxValue>cbNextMaxValue;

	//比较颜色
	return GetCardColor(bFirstTemp[0]) > GetCardColor(bNextTemp[0]);

	return false;
}

//////////////////////////////////////////////////////////////////////////
