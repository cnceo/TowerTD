#include "MainScene.h"
#include "MapLayer.h"
#include "TouchLayer.h"
#include "BackgroundLayer.h"
#include "MonsterAttributeConfType.h"
#include "MonsterAttribute.h"
#include "GameLayer.h"
#include "Enemy.h"
#include "TowerAttributeConfType.h"
#include "TowerAttribute.h"
#include "GameLayer.h"
#include "MonsterManager.h"
#include "ForwardLayer.h"
#include "FileManager.h"
#include "InjuredEffent.h"
#include "BasicAttribute.h"
#include "LoseScene.h"
#include "EntityManager.h"
#include "WinScene.h"
#include "MonsterManagerAttribute.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool MainScene::init(std::string filename,int chapternum){
	if (!Scene::create()){
		return false;
	}
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.mp3",true);
	this->filename = filename;
	this->chapternum = chapternum;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size size = Director::getInstance()->getVisibleSize();
	//��ȡ�ؿ��ļ�
	BasicAttribute::setXmlFilename(filename);
	//��ӱ�����
	backgroundlayer = BackgroundLayer::create();
	this->addChild(backgroundlayer);
	//��ӵ�ͼ��
	maplayer = MapLayer::create();
	maplayer->setTag(100);
	this->addChild(maplayer);
	//�����Ϸ��
	gamelayer = GameLayer::create();
	this->addChild(gamelayer,10);
	//���Touch��
	touchlayer = TouchLayer::create();
	touchlayer->setName("touchlayer");
	this->addChild(touchlayer);
	//��Ϸ��
	gameLayer = GameLayer::create();
	gameLayer->setName("wode");
	this->addChild(gameLayer);
	//ǰ����
	forwardlayer = ForwardLayer::create();
	forwardlayer->setName("progressLayer");
	this->addChild(forwardlayer);
	//����Ч����
	injuredlayer = InjuredEffect::create();
	injuredlayer->setName("injuredEffect");
	this->addChild(injuredlayer);




	//�õ�һ�����������
	monstermanager=MonsterManager::create();
	this->addChild(monstermanager);

	//�õ�һ���ļ�������
	filemanager = FileManager::create();

	this->addChild(filemanager);
	this->initLayers();
	return true;
}
void MainScene::initLayers(){
	//���ó�ʼ����
	forwardlayer->setcurSorce(2000);
	//�󶨼��ֺ���
	touchlayer->setCutScore(CC_CALLBACK_1(ForwardLayer::cutScore,forwardlayer));
	//�󶨼ӷֺ���
	monstermanager->setEarnScoreFunc(CC_CALLBACK_1(ForwardLayer::plusScore,forwardlayer));
}
Scene* MainScene::create(std::string filename,int chapternum){
	auto scene = new MainScene();
	if (scene&&scene->init(filename,chapternum))
	{
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return scene;
}

void MainScene::initGame(){

}
void MainScene::win(){
	//��ǰ�ؿ�ͨ��
	int nowchapternum = UserDefault::getInstance()->getIntegerForKey("passedchapter");
	if (chapternum>nowchapternum)
	{
		UserDefault::getInstance()->setIntegerForKey("passedchapter",chapternum);
	}
	this->changeWinScene();
}

void MainScene::lose(){
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size size = Director::getInstance()->getVisibleSize();
	Vector<Node*> layers = this->getChildren();
	for (auto it = layers.begin();it<layers.end();it++)
	{
		(*it)->ignoreAnchorPointForPosition(false);
		(*it)->setAnchorPoint(Vec2(0.5,0.5));
		(*it)->setPosition(origin.x+size.width/2,origin.y+size.height/2);
		auto mscale = ScaleTo::create(0.3,1,0,0);
		(*it)->runAction(mscale);
	}
	auto maction = Sequence::create(DelayTime::create(0.3),CallFunc::create(CC_CALLBACK_0(MainScene::changeLoseScene,this)),NULL);
	this->runAction(maction);
}
void MainScene::changeLoseScene(){
	///ֹͣ��Ч////////////////////////////////////////////////
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(false);
	auto scene = LoseScene::createScene();
	EntityManager::getInstance()->reset();
	Director::getInstance()->replaceScene(scene);
}
void MainScene::changeWinScene(){
	auto scene = WinScene::create();
	int killnum = EntityManager::getInstance()->getMonsterKilledNum();
	scene->setNumber(killnum);
	EntityManager::getInstance()->reset();
	Director::getInstance()->replaceScene(scene);
}
MapLayer *MainScene::getMapLayer(){
	return dynamic_cast<MapLayer *>(this->getChildByTag(100));
}
Layer *MainScene:: getGameLayer(){
	return this->getChildByName<Layer*>("wode");
}
MainScene::~MainScene(){
	MonsterAttribute::destoryInstance();
	MonsterManagerAttribute::destoryInstance();
	TowerAttribute::destoryInstance();
}