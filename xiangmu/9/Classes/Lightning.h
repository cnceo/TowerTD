#ifndef  __LIGHTNING_R_
#define  __LIGHTNING_R_

#include "cocos2d.h"
#include "SkillBase.h"
using namespace cocos2d;

class Lightning : public SkillBase
{
public:
	virtual bool init(Vec2 skillPoint);
	static Lightning * create(Vec2 skillPoint);
	//ʵ�����缼�ܵĶ���
	void skillAntimate();
	//�Ƴ���������
	void removeAntimate();
};

#endif