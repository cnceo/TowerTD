#ifndef __SWORDANGER_R_
#define __SWORDANGER_R_

#include "cocos2d.h"
#include "SkillBase.h"
using namespace cocos2d;

class SwordAnger : public SkillBase
{
public:
	virtual bool init(Vec2 skillPoint, int dir);
	static SwordAnger * create(Vec2 skillPoint, int dir);
	//ʵ�ֽ������ܵĶ���
	void skillAntimate(int dir);
	//�Ƴ����ܽ���
	void removeAntimate();
};

#endif