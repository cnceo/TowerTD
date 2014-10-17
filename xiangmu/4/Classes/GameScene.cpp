#include "GameScene.h"
#include "HeroesLayer.h"
#include "CollideLayer.h"
#include "ScoreLayer.h"
class CollideLayer;
#include "BackgroundLayer.h"
bool GameScene::init()
{
   if (!Scene::init())
   {
	   return false;
   }
   return true;
}

void GameScene::onEnter(){
	Scene::onEnter();
	//����������
	auto bgLayer = BackgroundLayer::create();
	this->addChild(bgLayer,0);

	//����������
	auto herolayer = HeroesLayer::create("HeroFly1.png");
	herolayer->setName("HeroLayer");
	this->addChild(herolayer);

	//�����л���
	auto enemyLayer = EnemyLayer::create();
	enemyLayer->setName("EnemyLayer");
	this->addChild(enemyLayer);

	//������ײ��
	auto colideLayer = CollideLayer::create();
	colideLayer->setName("ColideLayer");
	this->addChild(colideLayer);

	auto score = ScoreLayer::create();
	score->setName("Score");
	this->addChild(score);
}

//��ȡ������
HeroesLayer * GameScene::getHeroLayer()
{
	auto hr = dynamic_cast<HeroesLayer *>(this->getChildByName("HeroLayer"));
	return hr;
}

//��ȡ�л���
EnemyLayer* GameScene::getEnemyLayer(){
	return (EnemyLayer *)this->getChildByName("EnemyLayer");
}

//��ȡ��ײ��
Layer* GameScene::getColideLayer(){
	return (Layer *)this->getChildByName("ColideLayer");
}

ScoreLayer *GameScene::getScoreLayer(){
	return (ScoreLayer *)this->getChildByName("Score");
}