#include "GameScene.h"
#include "backgroundlayer.h"
#include "MainplanLayer.h"
#include "Enemylayer.h"
#include "Score.h"
bool GameScene::init()
{
	if(!Scene::init())
	{
		return false;
	}
	//�����ز�,ͨ���ļ�����֡���档��������
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Resources.plist");
	// ��background����뵽������ȥ��
	this->addChild(backgroundlayer::create(),0);
	//2.����л���
	auto EnemyLayer = Enemylayer::create();
	this->addChild(EnemyLayer,1);
	EnemyLayer->setName("Enemylayer");
	//3.���������� ���������������
	//this->addChild(MainplanLayer::create(),3);//zoder ����Ϊ3
	auto Mainplanlayer =MainplanLayer::create();
	this->addChild(Mainplanlayer,3);
	Mainplanlayer->setName("MainPlaneLayer");
	this->addChild(Score::create());
	return true;
}
Layer * GameScene::getPlantLayer(){
	return this->getChildByName<Layer*>("MainPlaneLayer");
}
Layer* GameScene::getEnemyLayer(){
	return this->getChildByName<Layer*>("Enemylayer");
}