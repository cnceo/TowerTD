#include "Lightning.h"
#include "Skilles.h"
#include "AnimateClass.h"
#include <SimpleAudioEngine.h>
using namespace CocosDenshion;
Lightning * Lightning::create(Vec2 skillPoint)
{
	Lightning * lightning = new Lightning();
	if(lightning && lightning->init(skillPoint))
	{
		lightning->autorelease();
		return lightning;
	}
	CC_SAFE_DELETE(lightning);
	return NULL;
}

bool Lightning::init(Vec2 skillPoint)
{
	if(!SkillBase::init("kill_lightning0.png",skillPoint))
	{
	    return false;
	}
    this->setOpacity(200);
	Size vSize = Director::getInstance()->getVisibleSize();
	this->setScale(2,vSize.height/this->getContentSize().height);
	//��ȡ������������
	Skilles * skilles = Skilles::getInstance();
	_attack = (* ((skilles->getSkilles().begin()) + 1))->getAttickValue();
	//ħ������ֵ
	_consumeMp = (* ((skilles->getSkilles().begin()) + 1))->getConsumeMp();
	//dir�����ͷŵķ���
	skillAntimate();
    return true;
}

void Lightning::skillAntimate()
{
    SimpleAudioEngine::getInstance()->playEffect("Tornado.wav");
	AnimateClass * skillAnimate = AnimateClass::create();
	this->runAction(Sequence::create(skillAnimate->skillLightning(),CallFunc::create(CC_CALLBACK_0(Lightning::removeAntimate,this)),NULL));
}

void Lightning::removeAntimate()
{
	this->removeFromParent();
	_isDie = true;
}