#include "EnemyLayer.h"
#include "CollideLayer.h"
#include "Common_BlueGlost.h"
#include "Elite_Shadow.h"
#include "Enemys.h"
#include "FirstBoss.h"
#include "Enemys.h"

static Enemys* es = Enemys::getInstance();
bool EnemyLayer::haveboss = false;

bool EnemyLayer::init() {
	if(!Layer::init()){
		return false;
	}
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Enemy/Enemy.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Tool/Tool.plist");
	this->Level = 1;
	contrlNum = 0;
	vSize = Director::getInstance()->getVisibleSize();
	this->bossTime = 0;
	auto center = __NotificationCenter::getInstance();
	center->addObserver(this,callfuncO_selector(EnemyLayer::restartTime),"BossDie",nullptr);

	auto levelCenter = __NotificationCenter::getInstance();
	levelCenter->addObserver(this, callfuncO_selector(EnemyLayer::upLevel), "upLevel", nullptr);
	return true;
}

void EnemyLayer::onEnter() {
	Layer::onEnter();
	//���˳��ֵ�Ƶ�� ��Ӣ����ͨ
	this->schedule(schedule_selector(EnemyLayer::addEnemy), 1.0/this->Level);
}

void EnemyLayer::addEnemy(float t) {
	createEnemy();
}

void EnemyLayer::createEnemy() {
	bossTime++;
	
	if (bossTime >= 15 && haveboss == false)
	{
		boss = FirstBoss::create(Level);
		Enemys::getInstance()->addEnemy(boss);
		this->addChild(boss);
		haveboss = true;
		return;
	}else if(haveboss == false && bossTime < 60)
	{
		//���������B��P B 3%  P %7
		int r = CCRANDOM_0_1() * 100;

		if (es->getEnemyVector().size() >= 5)
		{
			return;
		}
		if(contrlNum % 4 != 0) {

			//������ͨ��
			createCommon_BlueGlost(r);

		}else{

			//������Ӣ��
			createElite_Shadow(r);

		}
	}
}
void EnemyLayer::restartTime(Ref *sender){
	bossTime = 0;
	haveboss = false;
}

void EnemyLayer::createCommon_BlueGlost(int r){


	if (r <= 7)
	{
		//�����׻��ӵ�����
		isSkillsBomb = (r >= 1.1) ? 100 : 200;

	}
	else{
		//�޵���
		isSkillsBomb = 50;

	}

	createCommon(isSkillsBomb);
	
}

void EnemyLayer::createElite_Shadow(int r){

	if (r <= 7)
	{
		//�����׻��ӵ�����
		isSkillsBomb = (r >= 1.1) ? 100 : 200;

	}
	else{
		//�޵���
		isSkillsBomb = 50;
	
	}

	createElite(isSkillsBomb);
}

//������ͨ��
void EnemyLayer::createCommon(int isSkillsBomb){
	
	auto blue = Common_BlueGlost::create(isSkillsBomb, Level);

	Enemys::getInstance()->addEnemy(blue);

	this->addChild(blue);

	contrlNum++;

}
//������Ӣ��
void EnemyLayer::createElite(int isSkillsBomb){

	auto shadow = Elite_Shadow::create(isSkillsBomb, Level);

	Enemys::getInstance()->addEnemy(shadow);

	this->addChild(shadow);

	contrlNum++;

}

//��������ϵͳ
void EnemyLayer::upLevel(Ref *){
	if (this->Level < 3)
	{
		this->Level++;
	}
}
EnemyLayer::~EnemyLayer(){
	__NotificationCenter::getInstance()->removeAllObservers(this);
}