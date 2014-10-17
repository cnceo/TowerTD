#include "HealthData.h"
#include "HealthDataAI.h"
#include "EntityManager.h"

//enemyҪ���Ƶ�̹�˵�ָ��,dt�೤ʱ����һ��

bool HealthDataAI:: init(HealthData* healthdata,float dt){
	if (!Node::init())return false;
	this->setHealthData(healthdata);
	this->setStepTime(dt);
	//�೤ʱ��enemy��һ��
	this->schedule(schedule_selector(HealthDataAI::getDirection),this->getStepTime());

	this->setLastDirection(DataLastDirection::DATADOWNLAST);
	this->setMoveSuccess(true);
	return true;
}
void HealthDataAI::getDirection(float  t){
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

void HealthDataAI::nextStepandOldDirection(float dt){


	auto tank = getHealthData();
	dynamic_cast<HealthData*> (tank)->setDataDir(this->getLastDirection());
	bool moveans;
	switch (this->getLastDirection())
	{

	case DataLastDirection::DATAUPLAST :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveUp(dt);
		this->setMoveSuccess(moveans);
		break;
	case DataLastDirection::DATALEFTLAST :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveLeft(dt);
		this->setMoveSuccess(moveans);
		break;
	case DataLastDirection::DATADOWNLAST :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveDown(dt);
		this->setMoveSuccess(moveans);
		break;
	case DataLastDirection::DATARIGHTLAST :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveRight(dt);
		this->setMoveSuccess(moveans);
		break;
	default:
		break;
	}
}
void HealthDataAI::nextStepandNewDirection(float dt){
	int dir = CCRANDOM_0_1()*10+1;
	bool moveans;
	switch (dir)
	{
	case 1 :

		moveans=(dynamic_cast<HealthData*>(this->getHealthData())->moveUp(dt));
		this->setLastDirection(DataLastDirection::DATAUPLAST);
		this->setMoveSuccess(moveans);
		break;
	case 2 :
	case 3 :
	case 4 :
	case 5 :
	case 6 :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveLeft(dt);
		this->setLastDirection(DataLastDirection::DATALEFTLAST);
		this->setMoveSuccess(moveans);
		break;

	case 7 :
	case 8 :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveDown(dt);
		this->setLastDirection(DataLastDirection::DATADOWNLAST);
		this->setMoveSuccess(moveans);
		break;
	case 9 :
	case 10 :
		moveans=(dynamic_cast<HealthData*>(this->getHealthData()))->moveRight(dt);
		this->setLastDirection(DataLastDirection::DATARIGHTLAST);
		this->setMoveSuccess(moveans);
		break;
	default:
		break;
	}
}


//enemyҪ���Ƶ�enemy��ָ��,dt�೤ʱ����һ��
HealthDataAI* HealthDataAI::create(HealthData* healthdata,float dt){
	HealthDataAI* ai=new HealthDataAI();
	if (ai&&ai->init(healthdata,dt))
	{
		ai->autorelease();
		return ai;
	}
	CC_SAFE_DELETE(ai);
	return ai;
}

HealthDataAI::HealthDataAI(){
	healthData = nullptr;
}
HealthDataAI::~HealthDataAI(){
	log("AI delete");
}