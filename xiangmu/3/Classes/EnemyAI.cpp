#include "EnemyAI.h"
#include "Enemy.h"
#include "EntityManager.h"
#include "Tower.h"
//enemyҪ���Ƶ�̹�˵�ָ��,dt�೤ʱ����һ��

bool EnemyAI:: init(Enemy* enemy,float dt){
	if (!Node::init())return false;
	this->setEnemy(enemy);
	this->setStepTime(dt);
	//�೤ʱ��enemy��һ��
	this->schedule(schedule_selector(EnemyAI::getDirection),this->getStepTime());
	this->schedule(schedule_selector(EnemyAI::checkfire),this->getStepTime());
	this->setLastDirection(LastDirection::DOWNLAST);
	this->setMoveSuccess(true);
	return true;
}
void EnemyAI::getDirection(float  t){
	//�ϴ��ƶ��ɹ�,����90%���ʼ������ϴη�����
	   if (this->isMoveSuccess())
	   {
		   if (CCRANDOM_0_1()>0.1)
		   {
			   this->nextStepandOldDirection(t);
		   }else
		   {
			  this-> nextStepandNewDirection(t);
		   }
	   }else //�ϴ��ƶ����ɹ�,���һ���µķ���
	   {
		   this->nextStepandNewDirection(t);
	   }

	}

void EnemyAI::nextStepandOldDirection(float dt){


	auto tank = getEnemy();
	dynamic_cast<Enemy*> (tank)->setEnemyDir(this->getLastDirection());
	bool moveans;
	switch (this->getLastDirection())
	{

	case LastDirection::UPLAST :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveUp(dt);
		this->setMoveSuccess(moveans);
		break;
	case LastDirection::LEFTLAST :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveLeft(dt);
		this->setMoveSuccess(moveans);
		break;
	case LastDirection::DOWNLAST :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveDown(dt);
		this->setMoveSuccess(moveans);
		break;
	case LastDirection::RIGHTLAST :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveRight(dt);
		this->setMoveSuccess(moveans);
		break;
	default:
		break;
	}
}
void EnemyAI::nextStepandNewDirection(float dt){
	 int dir = CCRANDOM_0_1()*10+1;
	 bool moveans;
	switch (dir)
	{
	case 1 :
		
		moveans=(dynamic_cast<Enemy*>(this->getEnemy())->moveUp(dt));
		this->setLastDirection(LastDirection::UPLAST);
		this->setMoveSuccess(moveans);
		break;
	case 2 :
	case 3 :
	case 4 :
	case 5 :
	case 6 :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveLeft(dt);
		this->setLastDirection(LastDirection::LEFTLAST);
		this->setMoveSuccess(moveans);
		break;
	
	case 7 :
	case 8 :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveDown(dt);
		this->setLastDirection(LastDirection::DOWNLAST);
		this->setMoveSuccess(moveans);
		break;
	case 9 :
	case 10 :
		moveans=(dynamic_cast<Enemy*>(this->getEnemy()))->moveRight(dt);
		this->setLastDirection(LastDirection::RIGHTLAST);
		this->setMoveSuccess(moveans);
		break;
	default:
		break;
	}
}

void EnemyAI::checkfire(float t){
	auto instance = EntityManager::getInstance();
	auto tow = instance->ChakRamgeManager(enemy);
	if (tow != nullptr){
		dynamic_cast<Enemy*>(this->getEnemy())->fire(tow);
	}
}
//enemyҪ���Ƶ�enemy��ָ��,dt�೤ʱ����һ��
EnemyAI* EnemyAI::create(Enemy* enemy,float dt){
	EnemyAI* ai=new EnemyAI();
	if (ai&&ai->init(enemy,dt))
	{
		ai->autorelease();
		return ai;
	}
	CC_SAFE_DELETE(ai);
	return ai;
}

EnemyAI::EnemyAI(){
	enemy = nullptr;
}
EnemyAI::~EnemyAI(){
	log("AI delete");
}