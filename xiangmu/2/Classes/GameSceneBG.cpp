
#include "GameSceneBG.h"
#include "VisibileSize.h"
#include "ChangeAttackScene.h"

bool GameSceneBG::init(){
	if (!Layer::init()) {
		return false;
	}
	longBG_begin_x = 0;
	mediumBG_begin_x = 0;
	closeBG_begin_x = 0;
	menuBG_begin_x = 0;

	touch_begin_x = 0;
	touch_end_x = 0;

	auto closeShotBG = dealWithBG("GameSceneBG_a.png");
	auto mediumShotBG = dealWithBG("GameSceneBG_b.png");
	auto longShotBG = dealWithBG("GameSceneBG_c.png");
	auto menuBG = dealWithBG("GameSceneMenuBG.png");



	addChild(longShotBG);
	addChild(mediumShotBG);
	addChild(closeShotBG);
	addChild(menuBG);

	//������ת��ս�۰�ť
	auto campaignItem = MenuItemImage::create("CampaignMenuItem_a.png", "CampaignMenuItem.png", CC_CALLBACK_1(GameSceneBG::campaignIncident, this));
	campaignItem->runAction(RepeatForever::create(RotateBy::create(3, 360)));
	auto cMenu = Menu::create(campaignItem, NULL);
	menuBG->addChild(cMenu, 1);
	cMenu->setPosition(Vec2(menuBG->getContentSize().width / 2 - campaignItem->getContentSize().width * 2.4, menuBG->getContentSize().height / 2 + campaignItem->getContentSize().height));



	//���봥���¼�
	auto listen = EventListenerTouchOneByOne::create();
	listen->onTouchBegan = [=](Touch *t, Event *e){
		longBG_begin_x = longShotBG->getPositionX();
		mediumBG_begin_x = mediumShotBG->getPositionX();
		closeBG_begin_x = closeShotBG->getPositionX();
		menuBG_begin_x = menuBG->getPositionX();

		touch_begin_x = t->getLocation().x;
		return true;
	};
	listen->onTouchMoved = [=](Touch *t, Event *e){
		touch_end_x = t->getLocation().x;
		float dis = touch_end_x - touch_begin_x;

		//��Ļ�ƶ����ж�����
		bool moveJudgement = (closeBG_begin_x + dis <= closeShotBG->getContentSize().width * zoomOutX / 2 && closeBG_begin_x + dis >= vSize.width / 2 - (closeShotBG->getContentSize().width * zoomOutX / 2 - vSize.width / 2));
		if (moveJudgement){
			menuBG->setPositionX(menuBG_begin_x + dis);
			closeShotBG->setPositionX(closeBG_begin_x + dis);
			mediumShotBG->setPositionX(mediumBG_begin_x + dis / 4);
			longShotBG->setPositionX(longBG_begin_x + dis / 6);
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen, this);


	return true;
}

Sprite * GameSceneBG::dealWithBG(std::string name){
	//����ͼƬ
	auto Image = Sprite::create(name);
	Image->setPosition(vSize / 2);
	//���ŵı���
	zoomOutX = vSize.height / Image->getContentSize().height;
	zoomOutY = vSize.height / Image->getContentSize().height;
	Image->setScale(zoomOutX, zoomOutY);
	return Image;


}


void GameSceneBG::campaignIncident(Ref * sender){

	auto scene = ChangeAttackScene::create();
	Director::getInstance()->pushScene(scene);
}

