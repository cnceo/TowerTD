#include "BigSkill.h"
#include "AnimateClass.h"
#include "Skilles.h"
#include <SimpleAudioEngine.h>
using namespace CocosDenshion;
BigSkill * BigSkill::create(Vec2 skillPoint)
{
	BigSkill * bigSkill = new BigSkill();
	if(bigSkill && bigSkill->init(skillPoint))
	{
		bigSkill->autorelease();
		return bigSkill;
	}
	CC_SAFE_DELETE(bigSkill);
	return NULL;
}

bool BigSkill::init(Vec2 skillPoint)
{
	if(!SkillBase::init("bigSkill0.png",skillPoint))
	{
	   return false;
	}
    this->setOpacity(200);
	//��ȡ������������
	Skilles * skilles = Skilles::getInstance();
	_attack = (* skilles->getSkilles().begin())->getAttickValue();
	//ħ������ֵ
	_consumeMp = (* ((skilles->getSkilles().begin()) + 2))->getConsumeMp();
	//dir�����ͷŵķ���
	skillAntimate();
    return true;
}

void BigSkill::skillAntimate()
{
    SimpleAudioEngine::getInstance()->playEffect("BigSkill.wav");
	AnimateClass * animate = AnimateClass::create();
	this->runAction(Sequence::create(animate->skillBig(),CallFunc::create(CC_CALLBACK_0(BigSkill::removeAntimate,this)),NULL));
}

void BigSkill::removeAntimate()
{
	this->removeFromParent();
	_isDie = true;
}