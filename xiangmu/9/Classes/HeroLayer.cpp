#include "HeroLayer.h"
#include "SwordmanHero.h"

bool HeroLayer::init()
{
	if(!Layer::init())
	{
	     return false;
	}
	//��ÿ�����Ļ�Ĵ�С
	Vec2 vSize = Director::getInstance()->getVisibleSize();
	//����Ӣ��
	SwordmanHero * hero = SwordmanHero::create();
	hero->setTag(100);
	this->addChild(hero);
	return true;
}


