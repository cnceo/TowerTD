#include "SkillBase.h"
#include "GameMainScene.h"
#include "HeroLayer.h"

bool SkillBase::init(std::string name, Vec2 skillPoint)
{
	if(!Sprite::initWithSpriteFrameName(name)){
	     return false;
	}
	//���ü��ܵ�λ��
	this->setPosition(skillPoint);
	//����������еĳ���
	GameMainScene * gameMainScene = dynamic_cast<GameMainScene *>(Director::getInstance()->getRunningScene());
	//��ó�������ŵĲ�
	HeroLayer * heroLayer = dynamic_cast<HeroLayer *>(gameMainScene->getHeroLayer());
	//������������Ų���
	heroLayer->addChild(this);
	return true;
}
