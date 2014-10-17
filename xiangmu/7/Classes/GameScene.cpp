#include "GameScene.h"
#include "ControlLayer.h"
#include "Edge.h"
#include "LogicLayer.h"
#include "EnemyAILayer.h"
#include "AnimateLayer.h"
#include "BossTwo.h"
#include "ScoreLayer.h"
#include "ui/CocosGUI.h"
#include "StartScene.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace ui;
using namespace cocostudio;


void GameScene::onEnter(){
	Scene::onEnter();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("DragonNest.mp3",true);
}
bool GameScene::init(){
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	
	SimpleAudioEngine::getInstance()->rewindBackgroundMusic();
	

	//Ӣ�۲�
	HeroLayer *herolayer = HeroLayer::create();
	herolayer->setName("herolayer");
	this->addChild(herolayer,3);

	//��ʾ�߿�,ע���˾Ͳ���ʾ��
	//this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//����Ϊ������µļ��ٶ�
	this->getPhysicsWorld()->setGravity(Vec2(0,-1100));



	//���������С
	Size visSize = Director::getInstance()->getVisibleSize();

	//����ͼƬ
	Sprite *bg = Sprite::create("bg19a.jpg");
	bg->setScale(2);
	bg->setPosition(Vec2(visSize.width/2,visSize.height/2));
	this->addChild(bg);



	//����Edge
	Edge *edge = Edge::create();
	//���ñ߽�Ϊ������������
	edge->setPosition(visSize.width/2,visSize.height/2);
	//���ÿ��Բ�����ײ
	//edge->getPhysicsBody()->setContactTestBitmask(1);
	//��ӵ� ������
	this->addChild(edge);

	//���Ʋ�
	ControlLayer *controller = ControlLayer::create();
	controller->setName("controller");
	this->addChild(controller,9);

	//��� ���˲�
	auto enemyLayer = EnemyLayer::create();
	enemyLayer->setName("enemylayer");
	this->addChild(enemyLayer,3);

	//��ͼ
	MapLayer *maplayer = MapLayer::create();
	maplayer->setName("maplayer");
	this->addChild(maplayer,0);


	//�߼���
	LogicLayer *logic = LogicLayer::create();
	this->addChild(logic);

	//��Ӷ�����
	AnimateLayer * animatelayer = AnimateLayer::create();
	this->addChild(animatelayer);

	//����AI��
	auto enemyAILayer = EnemyAILayer::create();
	this->addChild(enemyAILayer);


	//����һ������
	auto background = Sprite::create();//����һ������
	background->setTag(2001);
	background->setPhysicsBody(PhysicsBody::createBox(Size(visSize.width,74)));
	background->setTextureRect(Rect(0,0,visSize.width,74));//��������� �� ��
	background->getPhysicsBody()->setCategoryBitmask(16);
	background->getPhysicsBody()->setCollisionBitmask(31);
	background->getPhysicsBody()->setContactTestBitmask(0);
	background->setPosition(visSize.width/2,5);//���õذ�� λ�� 
	background->getPhysicsBody()->setDynamic(false);
	background->setOpacity(0);//����͸����Ϊ0
	this->addChild(background);


	//�������ֲ�
	ScoreLayer *scoreLayer = ScoreLayer::create();
	scoreLayer->setName("scoreLayer");
	this->addChild(scoreLayer,9);

	SkillLayer *skill = SkillLayer::create();
	skill->setName("skilllayer");
	this->addChild(skill,9);

	return true;
}
HeroLayer * GameScene::getHeroLayer(){
	return this->getChildByName<HeroLayer *>("herolayer");
}

EnemyLayer * GameScene::getEnemyLayer(){
	return this->getChildByName<EnemyLayer *>("enemylayer");
}

MapLayer * GameScene::getMapLayer(){
	return this->getChildByName<MapLayer *>("maplayer");
}

ScoreLayer *GameScene::getScoreLayer(){
	return (ScoreLayer *)this->getChildByName("scoreLayer");
}

SkillLayer *GameScene::getSkillLayer(){
	return (SkillLayer *)this->getChildByName("skilllayer");
}
ControlLayer *GameScene::getControlLayer(){
	return this->getChildByName<ControlLayer *>("controller");
}

