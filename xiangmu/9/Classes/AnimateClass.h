#ifndef  __ANIMATECLASS_H
#define  __ANIMATECLASS_H

#include "cocos2d.h"
USING_NS_CC;
class AnimateClass :public Animate
{
public:
	virtual bool init();
	CREATE_FUNC(AnimateClass);
	//������ض���
	ActionInterval *heroRun();
	ActionInterval *heroAttack();
	ActionInterval *heroJumpAttack();
	ActionInterval *heroHurt();
	ActionInterval *heroDie();
	ActionInterval *heroSwordAnger();
	ActionInterval *heroLightningAnger();
	ActionInterval *heroStop();
	//���ܶ���
	ActionInterval *skillSwordAnger();
	ActionInterval *skillLightning();
	ActionInterval *skillBig();
	//������ض���
	ActionInterval * monsterRun(int id);
	ActionInterval * monsterHurt(int id);
	ActionInterval * monsterAttack(int id);
	//�粼�����߶���
	ActionInterval * goblinRun();
	//�粼�����˶���
	ActionInterval * goblinHurt();
	//�粼�ֹ�������
	ActionInterval * goblinAttack();
	//�Ϲ����߶���
	ActionInterval * soldierRun();
	//�Ϲ����˶���
	ActionInterval * soldierHurt();
	//�ϹϹ�������
    ActionInterval * soldierAttick();
	//ţͷboos���߶���
	ActionInterval * boosRun();
	//ţͷ���˶���
	ActionInterval * boosHurt();
	//ţͷboos��������
	ActionInterval * boosAttick();
};

#endif