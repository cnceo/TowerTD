#include "Mainplan.h"
#include "OneBullet.h"
#include "TwoBullet.h"
bool Mainplan::init()
{
	if(!Sprite::initWithSpriteFrameName("hero_fly_1.png"))
	{
		return false;
	}
	//���طɻ�������
	addAnimation();
	return true;
}

void Mainplan::addAnimation()
{
	//���طɻ�������
	auto anim = Animation::create();
	SpriteFrame *sf;
	//ͨ���建�����ֶ��� �����һ֡
	sf =SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_fly_1.png");
	anim->addSpriteFrame(sf);
	//����ڶ�֡
	sf =SpriteFrameCache::getInstance()->getSpriteFrameByName("hero_fly_2.png");
	anim->addSpriteFrame(sf);
	//����֡ѭ�����Ŵ���  -1��������ѭ��
	anim->setLoops(-1);
	//����֡���ŵļ��
	anim->setDelayPerUnit(0.01f);
	//����anim���д���anim����an 
	auto an =Animate::create(anim);
	//�÷ɻ�����֡����
	this->runAction(an);
}
void Mainplan::onEnter()
{
	//���ʸ����Onenter
	Sprite::onEnter();
	//���ûص������ӵ�
	this->schedule(schedule_selector(Mainplan::addFire),0.15);
}
void Mainplan::addFire(float t)
{
	//�����ӵ��Զ�����
	//this�Ƿɻ�
	OneBullet::create(Vec2(this->getPositionX(),this->getPositionY()+this->getContentSize().height/2));
	TwoBullet::create(Vec2(this->getPositionX(),this->getPositionY()+this->getContentSize().height/2));
	//this->addChild(bullet);
}