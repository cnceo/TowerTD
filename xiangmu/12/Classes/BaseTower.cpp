#include "BaseTower.h"
#include "GameManager.h"
#include "GameScene.h"
//#include "UpdateLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;
BaseTower::BaseTower()
:curgold(100)
,maxlevel(4)
,curlevel(0)
,speed(0)
,goldvalue(50)
,soldier(NULL)
,isAttackTime(false)
,ischangeState(false)
,isPreAttackTime(false)
,scope(0)
{}
BaseTower::~BaseTower(){}
bool BaseTower::init()
{
	if(!Sprite::init())
	{
		return false;
	}
	Armature* toweramt = Armature::create("Project Animation");
	toweramt->setName("toweramimature");
	this->addChild(toweramt);
	this->scheduleUpdate();
	this->stopAnm();
	GameManager::getInstance()->towerVector.pushBack(this);
	postuplevel();
	return true;
}
void BaseTower::update(float dt)
{
	checkNearestEnemy(); 
	changeState();
}
void BaseTower::changeState()
{
	if (ischangeState)
	{
		ischangeState=false;
		if (isAttackTime)
		{
			this->schedule(schedule_selector(BaseTower::Attack),speed);
		}else
		{
			this->unschedule(schedule_selector(BaseTower::Attack));
			this->stopAnm();
		}		
	}
}
void BaseTower::setSpeed(float dt)
{
	speed = dt; 
}
void BaseTower::checkNearestEnemy()
{	
	//��������Ҫ�õ�GameManager �ĵ�������  ���ݵ��˺�����λ������� ���Լ��趨�ľ������Ƚ�
	//ͬʱ����������뷶Χ�ڵ�enemy Ȼ��ͨ�� rotateAndAttack(float dt) ���в�ͬ�Ķ���
    GameManager * instance = GameManager::getInstance();
	auto enemyvector = instance->enemyVector;
    for(int i =0;i<enemyvector.size();i++)
	{
		auto enemy = enemyvector.at(i);
		auto distance = this->getPosition().getDistance(enemy->getPosition());
		if (distance <=scope)
		{
			if(enemy->getLive()!=DIE){
				soldier=enemy;
				isAttackTime=true;
				if (isAttackTime!=isPreAttackTime)
				{
					isPreAttackTime=isAttackTime;
					ischangeState=true;				
				}
				targetpoint=soldier->getPosition();
				return;
			}
			
		}
	 }
	soldier = nullptr;
	isAttackTime=false;
	if (isAttackTime!=isPreAttackTime)
	{
		isPreAttackTime=isAttackTime;
		ischangeState=true;				
	}

}
//��������
 void BaseTower::postuplevel()
 {	
	if (curlevel >= maxlevel)
	{
		return;
	}
	auto center =__NotificationCenter::getInstance();
	center->postNotification("update",this);
}
 void BaseTower::uplevel(){
	
     curlevel++;
	 curgold*=1.5;
	 goldvalue=curgold/2;
	 speed*=0.75;
	 scope*=1.25;
	 //����������
	  if(curlevel>1)
	  {
		  Sprite *sprite = Sprite::createWithSpriteFrameName("up1.png");
		  sprite->setPosition(Vec2(0,0));
		  this->addChild(sprite);
		  log("{%.2f,%.2f}",sprite->getPosition().x,sprite->getPosition().y);
		  animat = Animation::create();
		  auto cach =  SpriteFrameCache::getInstance();
		  for(int i =1;i<7;i++)
		  {
			  fileName = StringUtils::format("up%d.png",i);
			  animat->addSpriteFrame(cach->getSpriteFrameByName(fileName));

		  }
		  animat->setDelayPerUnit(0.1f);
		  animat->setLoops(1);
		  ani = Animate::create(animat);
		  auto cf = CallFunc::create([=](){
			  sprite->removeFromParentAndCleanup(true);
		  });
		   sprite->runAction(Sequence::create(ani,cf,NULL));
	  }
 }
 //ɾ�����ķ���
void BaseTower::removeTower()
{
	GameManager::getInstance()->towerVector.eraseObject(this);
	this->removeFromParentAndCleanup(true);
}

//����ɾ��
void BaseTower::postDeleteTower()
{  
	auto center =__NotificationCenter::getInstance();
	center->postNotification("remove",this) ; 
}
void BaseTower::runAnimate(std::string name){
	auto toweramt = this->getChildByName<Armature*>("toweramimature");
	 
	toweramt->getAnimation()->play(name);
} 

void BaseTower::pauseAllTowers()
{
	auto toweramt = this->getChildByName<Armature*>("toweramimature");

	toweramt->getAnimation()->pause();
}





