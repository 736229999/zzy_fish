#ifndef SPRITEURL_H_
#define SPRITEURL_H_

/**
	��ȡ����ͼƬ
**/

#include "cocos2d.h"
#include "network/HttpClient.h"
#include "URLData.h"

USING_NS_CC;
using namespace network;
using namespace std;

class SpriteURL:public Sprite
{
public:
	SpriteURL(std::string _path,std::string _defaultPath,std::string _userGameID);
	~SpriteURL();
	static SpriteURL*create(std::string _path,std::string _defaultPath,std::string _userGameID);
	void createStorgePath();		//����ͼƬ����·��
	void getHttpPic(cocos2d::Size size_);				//��ȡ����ͼƬ

	void saveURLPic(std::vector<char>*_data);				//����ȡ��ͼƬ��������

	//BUG,���뵽��׿,����д
	//virtual void setDisplayFrameWithAnimationName(const std::string& animationName, ssize_t frameIndex){};
    void getCachePath(Node *sender, Value data);
    
	
private:
	void onURLLoaderCompleted(EventCustom* event);
	void onHttpRequestCompleted(HttpClient *sender,HttpResponse *response);

	std::string m_path;				//����ͼƬ��ַ
	std::string m_defaultPath;		//Ĭ��ͼƬ
	std::string _storagePath;		//�洢·��
	std::string m_picName;			//����ͼƬ������
	std::string m_userGameID;    //���ID   ���ڱ���ͼƬ��
    cocos2d::Size m_size;								//����ͼƬ�滻��Ĵ�С
};

#endif