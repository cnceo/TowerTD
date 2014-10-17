#include "GameOverLayer.h"
#include "GameData.h"
#include "StartScene.h"
#include "GameScene.h"
#include "BackGroundLayer.h"
#include "DataXML.h"

bool GameOverLayer::init(){
	if (!Layer::init())
	{
		return false;
	}
	audioFlag = DataXML::getInstence()->getInitialValue("sound");
	//��Ӻ�ɫ����
	addSprite(BLACK_BACK_FILENAME, Vec2(480, 320), 5);
	//�����Ϸ��������
	addSprite(ENDBACK_P_FILENAME, Vec2(480, 320), 1);
	//�������LOGO
	addSprite(CHICKEN_END_FILENAME, Vec2(480, 420), 0.8);
	//��ӷ��������水ť
	addMenu(BACK_P_1_FILENAME, BACK_P_2_FILENAME, Vec2(320, 300), false, CC_CALLBACK_1(GameOverLayer::toStartScene, this));
	//������¿�ʼ��Ϸ��ť
	addMenu(REPLAYER_END_1_FILENAME, REPLAYER_END_2_FILENAME, Vec2(640, 300), false, CC_CALLBACK_1(GameOverLayer::onceGame, this));
	//��ӿհ�ť����ֹ���������󻹿��԰���ͣ��ť
	addMenu(NEAR_MISS_COLL_FILENAME, NEAR_MISS_COLL_FILENAME, Vec2(45, 580), false, [](Ref * sender){});
	
	this->setScale(0.8);

	return true;
}

//���ӷ�����ʾ
void GameOverLayer::addScoreLabel(int curScore, int maxScore){
	//��߷�
	Sprite * maxScoreIcon = Sprite::createWithSpriteFrameName(MAX_SCORE_FILENAME);
	maxScoreIcon->setPosition(Vec2(430, 260));
	this->addChild(maxScoreIcon);
	Label * maxScoreLabel = Label::createWithSystemFont(StringUtils::format("%d", maxScore), "Arial", 40);
	maxScoreLabel->setPosition(Vec2(450, 260));
	maxScoreLabel->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(maxScoreLabel);
	//��ǰ��
	Sprite * curScoreIcon = Sprite::createWithSpriteFrameName(TIMER_FILENAME);
	curScoreIcon->setPosition(Vec2(430, 200));
	this->addChild(curScoreIcon);
	Label * curScoreLabel = Label::createWithSystemFont(StringUtils::format("%d", curScore), "Arial", 40);
	curScoreLabel->setPosition(Vec2(450, 200));
	curScoreLabel->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(curScoreLabel);
	//����¼�¼��ʾ
	if (curScore > maxScore)
	{
		addSprite(NEW_RECORD_FILENAME, Vec2(600, 400), 1);
	}
}

//��Ӿ��鷽��
void GameOverLayer::addSprite(std::string fileName, Vec2 spritePos, float scaleValue){
	auto sp = Sprite::createWithSpriteFrameName(fileName);
	sp->setPosition(spritePos);
	sp->setScale(scaleValue);
	this->addChild(sp);
}

//��Ӱ�ť
void GameOverLayer::addMenu(std::string norName, std::string selName, Vec2 menuPos, bool toggleFlag, std::function<void(Ref *)> menuCallback){
	auto normal = SpriteFrameCache::getInstance()->getSpriteFrameByName(norName);
	auto select = SpriteFrameCache::getInstance()->getSpriteFrameByName(selName);
	if (toggleFlag)
	{
		auto itemOn = MenuItemImage::create();
		auto itemOff = MenuItemImage::create();
		itemOn->setNormalSpriteFrame(normal);
		itemOn->setSelectedSpriteFrame(normal);
		itemOff->setNormalSpriteFrame(select);
		itemOff->setSelectedSpriteFrame(select);
		auto toggle = MenuItemToggle::createWithCallback(menuCallback, itemOn, itemOff, NULL);
		auto menuAudio = Menu::create(toggle, NULL);
		menuAudio->setPosition(menuPos);
		this->addChild(menuAudio);
	}
	else
	{
		auto itemAll = MenuItemImage::create();
		itemAll->setCallback(menuCallback);
		itemAll->setNormalSpriteFrame(normal);
		itemAll->setSelectedSpriteFrame(select);
		auto menu = Menu::create(itemAll, NULL);
		menu->setPosition(menuPos);
		this->addChild(menu);
	}
}

//ת����ʼ����
void GameOverLayer::toStartScene(Ref * sender){
	EFFECT_MUSIC("click.mp3",audioFlag);
	Director::getInstance()->resume();
	auto scene = StartScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

//����һ����Ϸ��ť�ص�
void GameOverLayer::onceGame(Ref * sender){
	EFFECT_MUSIC("click.mp3",audioFlag);
	auto scene = GameScene::create();
	Director::getInstance()->replaceScene(scene);
	Director::getInstance()->resume();
}