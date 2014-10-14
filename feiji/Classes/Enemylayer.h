#ifndef __ENEMYLAYER_H
#define __ENEMYLAYER_H
#include "cocos2d.h"
#define DAFEIJISPEED 80
#define QUICKSPEED 400
#define BASEPLANSPEED 150
using namespace cocos2d;
class Enemylayer:public Layer{
public:
	virtual bool init();
	CREATE_FUNC(Enemylayer);
protected:
	//ʱ���Ա������ʱ����
	int t;//0
	//���ֿ�ɻ��ĸ���
	int quickf;//5
	//���ִ�ɻ��ĸ���
	int bigf;//0.1
	//ʱ�伶��,20,40,80,160
	unsigned long levelt;
	//������һ����
	void nextlevel();
	//ÿ��ص�һ��
	void addtime(float t);
	//��ص�
	void update(float t);
	//���ɻ�
	void go();
	//���ɻ�ʱ��
	float outplane;
	//���ɻ��ۼ�ʱ�䳬����ʼ���ַɻ�
	float outsum;

};
#endif