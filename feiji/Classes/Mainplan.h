#ifndef __MAINPLAN_H
#define __MAINPLAN_H
#include "cocos2d.h"
using namespace cocos2d;
class Mainplan:public Sprite
{
private:
	virtual void onEnter();
private:
	//����
	void addFire(float t);
	//���ӷ��ж�����
	void addAnimation();
public:
	virtual bool init();
	CREATE_FUNC(Mainplan);
};

#endif