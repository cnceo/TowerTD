#ifndef __BIGSKILL_R_
#define __BIGSKILL_R_

#include "cocos2d.h"
#include "SkillBase.h"
using namespace cocos2d;

class BigSkill : public SkillBase
{
public:
	virtual bool init(Vec2 skillPoint);
	static BigSkill * create(Vec2 skillPoint);
	//ʵ�ִ��м��ܵĶ���
	void skillAntimate();
	//�Ƴ����м���
	void removeAntimate();
};

#endif