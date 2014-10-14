#ifndef __BACEBULLET_H
#define __BACEBULLET_H
#include "cocos2d.h"
//�ӵ��ƶ��ٶ�
#define BULLETSPEED 1000
using namespace cocos2d;
class BaseBullet:public Sprite
{
public:
	virtual bool initWithSpriteFrameName(std::string name,Vec2 position,int speed);
public:
	//������
	CC_SYNTHESIZE_READONLY(int ,attackValue,AttackValue);
	//�ٶ�
	CC_SYNTHESIZE_READONLY(int ,speed,Speed);
	virtual void remove();
};

#endif