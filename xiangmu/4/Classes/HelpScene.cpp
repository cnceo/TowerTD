#include "HelpScene.h"
#include "ShareFunc.h"
#include "iconv.h"
#include "StartGame.h"

bool HelpScene::init() {
	if (!Layer::init())
	{
		return false;
	}
	vSize = Director::getInstance()->getVisibleSize();
	addHero();
	return true;
}

void HelpScene::addHero() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero/hero.plist");
	hero = Sprite::createWithSpriteFrameName("HeroFly1.png");
	hero->setPosition(hero->getContentSize().width,hero->getContentSize().height);
	this->addChild(hero);
	hero->runAction(ShareFunc::getAct("HeroFly1.png",1,4,0.2,-1));
	label = Label::createWithSystemFont(UTEXT("Ӣ��"),"Arial",40);
	label->setPosition(hero->getPositionX(),hero->getPositionY()+hero->getContentSize().height/2+20);
	label->setAnchorPoint(Vec2(0,0));
	this->addChild(label);
}

void HelpScene::onEnter() {
	Layer::onEnter();
	addMonster();
	addBoss();
	addMenu();
}

void HelpScene::addMonster() {
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy/Enemy.plist");
	monster = Sprite::createWithSpriteFrameName("EnemyCommon_one1.png");
	monster->setPosition(vSize.width/2,vSize.height/2);
	this->addChild(monster);
	monster->runAction(ShareFunc::getAct("EnemyCommon_one1.png", 1, 3, 0.2, -1));
	label2 = Label::createWithSystemFont(UTEXT("����"),"Arial",40);
	label2->setPosition(monster->getPositionX()-monster->getContentSize().width/2,monster->getPositionY()+monster->getContentSize().height/2+20);
	label2->setAnchorPoint(Vec2(0,0));
	this->addChild(label2);
}

void HelpScene::addBoss() {
	boss = Sprite::createWithSpriteFrameName("BossEnemy1.png");
	boss->setPosition(vSize.width-boss->getContentSize().width+150,vSize.height-boss->getContentSize().height);
	boss->setScale(0.3);
	this->addChild(boss);
	boss->runAction(ShareFunc::getAct("BossEnemy1.png", 1, 9, 0.2, -1));
	label3 = Label::createWithSystemFont(UTEXT("�����ϴ�-Boss"),"Arial",40);
	label3->setPosition(boss->getPositionX()-boss->getBoundingBox().size.width/2,boss->getPositionY()+boss->getBoundingBox().size.height/2+20);
	label3->setAnchorPoint(Vec2(0,0));
	this->addChild(label3);
}

void HelpScene::addMenu() {
	auto item = MenuItemFont::create(UTEXT("����˽���Ϸ"),[=](Ref *sender){
		MessageBox("1.���Ӣ���ƶ�����ܵ����ӵ������й���;\n2.������Ļһ��ֱ��Ӣ�����ϳ��ֹ⻷�����ֺ���Խ��������Ĺ���;\n3.����Ļ�ϻ���һ����L�������ͷŴ��У�ʹ�ô��еĴ�������Ŷ","��Ϸ���淨˵��");
	});
	item->setPosition(0,100);
	auto item2 = MenuItemFont::create(UTEXT("�˳�"),[=](Ref *sender){
		auto scene = StartGame::createScene();
		Director::getInstance()->replaceScene(scene);
	});
	item->setPosition(0,-100);
	auto menu = Menu::create(item,item2,NULL);
	menu->setPosition(200,500);
	this->addChild(menu);
}

Scene *HelpScene::createScene() {
	auto scene = Scene::create();
	auto layer = HelpScene::create();
	scene->addChild(layer);
	return scene;
}