#include "Bacebullet.h"
#include "GameScene.h"
#include "Bullets.h"
bool BaseBullet::initWithSpriteFrameName(std::string name,Vec2 position,int speed)
{
	if(!Sprite::initWithSpriteFrameName(name))
	{
		return false;
	}
	this->setPosition(position);
	//�õ���ʾ���߶�
	float height = Director::getInstance()->getVisibleSize().height;
	//�ƶ�������
	//�ƶ�λ��Ϊ��Ļ�Ϸ�+�ɻ�ͼƬ�ĸ߶ȡ�
	auto to = MoveTo::create((height-position.y)/speed,Vec2(position.x,height+this->getContentSize().height));
	auto cf = CallFunc::create(std::bind(&BaseBullet::remove,this));
	this->runAction(Sequence::create(to,cf,NULL));
	this->runAction(to);
	//�õ���Ϸ������ʵ��
	GameScene * scene =dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	//ͨ����Ϸ�����õ���Ϸ�㲢���ӵ�������Ϸ��
	scene->getPlantLayer()->addChild(this);
	//���뵥��������
	Bullets::getInstance()->addBullet(this);
	return true;
}
 void BaseBullet::remove(){
	Bullets::getInstance()->deleteBullet(this);
 	this->removeFromParentAndCleanup(true);

 }
