#include "GameScene.h"
#include "ControlLayer.h"
#include "BackgroundLayer.h"
#include "ShowLayer.h"
#include "taskLayer.h"
#include "DataXML.h"
#include "BoundingLayer.h"
#include "GameData.h"
#include "RoleLayer.h"

bool GameScene::init(){
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	this->setName("game_scene");

	//��ӱ����㣺����Զ��/�ϰ�
	auto backgroundLayer = BackgroundLayer::create();
	backgroundLayer->setName("BackLayer");
	this->addChild(backgroundLayer);

	//������ǲ�
	auto roleLayer = RoleLayer::create();
	roleLayer->setName("RoleLayer");
	this->addChild(roleLayer);

	//��ӿ��Ʋ㣺����
	auto controlLayer = ControlLayer::create();
	controlLayer->setName("ControlLayer");
	this->addChild(controlLayer);

	//�����ʾ�㣺��ʾ�򣬷�����Ѫ����������
	auto showLayer = ShowLayer::create();
	this->addChild(showLayer);

	//�����ײ��
	auto boundingLayer = BoundingLayer::create();
	this->addChild(boundingLayer);
	

	return true;
}

void GameScene::onEnter() {

	Scene::onEnter();
	audioFlag = DataXML::getInstence()->getInitialValue("sound");
	BACK_GUOUND_MUSIC("chickendance.mp3",audioFlag);
}

Layer * GameScene::getRoleLayer(){
	return dynamic_cast<Layer *>(this->getChildByName("RoleLayer"));
}

Layer * GameScene::getControlLayer(){
	return dynamic_cast<Layer *>(this->getChildByName("ControlLayer"));
}

Layer * GameScene::getBackgroundLayer(){
	return dynamic_cast<Layer *>(this->getChildByName("BackLayer"));
}