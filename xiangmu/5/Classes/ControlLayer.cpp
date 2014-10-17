#include "ControlLayer.h"
#include "Role.h"
#include "GameData.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "RoleLayer.h"

bool ControlLayer::init(){
	if (!Layer::init())
	{
		return false;
	}
	//��ʼ���������ܣ�״̬Ϊtrue
	isNormal = true;

	addTouch();
	addGravity();

	return true;
}

void ControlLayer::onEnter(){
	Layer::onEnter();
	auto layer = GET_ROLE_LAYER;
	role = layer->getRole();
}

void ControlLayer::addGravity(){
	//����������Ӧ
	Device::setAccelerometerEnabled(true);
	//������������
	auto gravityListener = EventListenerAcceleration::create([=](Acceleration * acc, Event * pevent){
		//ʹ������������Ӧ�ƶ�
		Vec2 position = role->getPosition();
		//�ж��ǿ��ܻ�������
		if (acc->x > 0.2 && isNormal == true)
		{
			role->fastRun();
			isNormal = false;
		}
		else if (acc->x < -0.2 && isNormal == true)
		{
			role->slowRun();
			isNormal = false;
		}
		else if (acc->x >= -0.2 && acc->x < 0 && isNormal == false)
		{
			role->stopSlowRun();
			isNormal = true;
		}
		else if (acc->x >= 0 && acc->x <= 0.2 && isNormal == false)
		{
			role->stopFastRun();
			isNormal = true;
		}
		if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		{
			position.x += acc->x * 2;
		}else if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		{
			position.x += acc->x * 5;
		}
		role->setPosition(position);
	});
	//���¼���������ע��
	_eventDispatcher->addEventListenerWithSceneGraphPriority(gravityListener, this);
}

void ControlLayer::addTouch(){

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [=](Touch * pTouch, Event * pEvent){
		if (role->getM_hp() <= 0)
		{
			return false;
		}
		role->jumpUp();
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}