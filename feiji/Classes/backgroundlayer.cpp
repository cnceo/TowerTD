#include "backgroundlayer.h"

bool backgroundlayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
	//�õ���Ļ��ʾ���Ĵ�С��
	vSize = Director::getInstance()->getVisibleSize();
	//���ӱ���
	bg1 =Sprite::createWithSpriteFrameName("background_2.png");
	//���ñ�������Ļ������ʾ
	bg1->setPosition(vSize/2);
	//�����ʺ���Ļ��С
	bg1->setScaleY(vSize.height/bg1->getContentSize().height+0.005);
    bgheight = bg1->getBoundingBox().size.height;
	this->addChild(bg1);
	bg2 =Sprite::createWithSpriteFrameName("background_2.png");
	bg2->setScaleY(vSize.height/bg2->getContentSize().height+0.005);
	Vec2 p2 (vSize.width/2,bg1->getPositionY()+bgheight-5);
	//��һ����Ļ�ĸ߶ȡ�
	bg2->setPosition(p2);
	this->addChild(bg2);
	this->scheduleUpdate();
	return true;
}
void backgroundlayer::update(float t)
{
	//ÿ֡ÿ�����������ƶ�
	bg1->setPositionY(bg1->getPositionY()-BGDOWNSPEED*t);
	bg2->setPositionY(bg2->getPositionY()-BGDOWNSPEED*t);
	//�������ñ�����λ�á�
	if(bg1->getPositionY()+bgheight/2<0)
	{
		bg1->setPositionY(bg2->getPositionY()+bgheight-5);
	}
	if(bg2->getPositionY()+bgheight/2<0)
	{
		bg2->setPositionY(bg1->getPositionY()+bgheight-5);
	}
}