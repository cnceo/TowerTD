#include "MonsterManager.h"
#include "Enemy.h"
#include "MonsterAttributeConfType.h"
#include "MonsterAttribute.h"
#include "MainScene.h"
#include "EntityManager.h"
#include "MonsterDieEffect.h"
#include "ForwardLayer.h"
#include "MonsterManagerAttribute.h"
#include "MonsterManagerAttributeConfType.h"
USING_NS_CC;
bool MonsterManager::init(){
	if (!Node::init())
	{
		return false;
	}
	srand(time(0));
	return true;
}
void MonsterManager::onEnter(){
	Node::onEnter();
	this->initLevel();
	auto tmp = Director::getInstance()->getRunningScene()->getChildByName("wode");
}
void MonsterManager::initLevel(){
	auto managerattribute = MonsterManagerAttribute::getInstance();
	//��ʼ����ر���
	//��һ�ֳ��� 
	wavecount=1;
	//��1����
	nowwaves = 0;
	//�����ĳɿ����õ�
	totalwaves = managerattribute->getWavesCount();
	for (int i = 0;i < totalwaves;i++)
	{
		//��ȡÿһ����id,id��1��ʼ
		int tmpmonster =  managerattribute->getIntAttribute(i+1,MonsterManagerAttributeConfigType::MonsterManager_MonsterID,1);
		monsters_id[i] = tmpmonster;
		//10s��һ��
		int tmpdelaytimeperwave = managerattribute->getIntAttribute(i+1,MonsterManagerAttributeConfigType::MonsterManager_Delaytime,10);
		delaytimeperwave[i] = tmpdelaytimeperwave;
		//ÿһ��5����
		int tmpmonsternumperwave = managerattribute->getIntAttribute(i+1,MonsterManagerAttributeConfigType::MonsterManager_Monsternum,5);
		monsternumperwave[i] = tmpmonsternumperwave;
	}
	int tmp_delaytime = delaytimeperwave[nowwaves];
	this->schedule(schedule_selector(MonsterManager::waveMonster),1,1,tmp_delaytime);
	
}
//����һ������
void MonsterManager::waveMonster(float dt){
	//��һ����,wave��1
	nowwaves++;
	log("wave monster:%d",nowwaves);
	//���в������
	//�Ѷȷ���
	if ( !(nowwaves < totalwaves))
	{
		this->unschedule(schedule_selector(MonsterManager::waveMonster));
		//�Ѷȷ���
		if (wavecount<=5)
		{
			wavecount++;
		}
		//���³���һ����
		nowwaves = 1;
	}else{
		this->unschedule(schedule_selector(MonsterManager::waveMonster));
	}
	//���㵱ǰ���γ�������
	int tmp_numperwave = monsternumperwave[nowwaves]*wavecount;
	//ÿ��0.3s��һ����,����numperwave[waves]��
	this->schedule(schedule_selector(MonsterManager::createMonster),0.3,tmp_numperwave,0);
	//��ʼ����һ������
	int tmp_delaytime = delaytimeperwave[nowwaves];
	this->schedule(schedule_selector(MonsterManager::waveMonster) , 1 , 1 , tmp_delaytime);
}
//����һ������
void MonsterManager::createMonster(float dt){
	log("create a monster!");
	log("monster id:%d now wave:%d" , monsters_id[nowwaves-1] , nowwaves);
	//���ֲ���
	int tmp_id = monsters_id[nowwaves-1];
	auto tmp_monster = Enemy::create(tmp_id);
	MainScene *mScene = dynamic_cast<MainScene *>(Director::getInstance()->getRunningScene());
	auto mapLayer = mScene->getMapLayer();
	auto map = mapLayer->getTiledMap();
	tmp_monster->setPosition(monsterCreatePosition());//�ӵ�ͼ���ù������λ��
	mapLayer->addChild(tmp_monster);
	
	//�������ӷֺ���
	if (monsteraddprice)
	{
		tmp_monster->setScoreFunc(monsteraddprice);
	}
	//��������Ч����
	tmp_monster->setDieEffectFunc(CC_CALLBACK_1(MonsterManager::monsterDieEffect,this));
	EntityManager::getInstance()->Monster.pushBack(tmp_monster);
}

void MonsterManager::setEarnScoreFunc(std::function<void(int)> monsteraddprice){
	this->monsteraddprice=monsteraddprice;
}
Vec2 MonsterManager::monsterCreatePosition(){
	
	MainScene *mScene = dynamic_cast<MainScene *>(Director::getInstance()->getRunningScene());
	MapLayer *mapLayer = mScene->getMapLayer();
	std::vector<Vec2> burnpoints = mapLayer->enemyBurnPosition();
	int pointsnum = burnpoints.size();
	int i = CCRANDOM_0_1()*pointsnum;
	Vec2 burnp = burnpoints.at(i);
	return burnp;
}
void MonsterManager::monsterDieEffect(Vec2 diepoint){
	auto scene = Director::getInstance()->getRunningScene();
	auto forwardlayer = dynamic_cast<ForwardLayer*>(scene->getChildByName("progressLayer"));
	auto gamelayer = dynamic_cast<GameLayer*>(scene->getChildByName("wode"));
	auto tmp_effect = MonsterDieEffect::create(diepoint,forwardlayer->getScoreLabelPosition());
	gamelayer->addChild(tmp_effect);
}