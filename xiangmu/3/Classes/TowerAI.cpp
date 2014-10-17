#include "TowerAI.h"
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EntityManager.h"
USING_NS_CC;
bool TowerAI::init(Tower* tower){
	if (!Node::init())
	{
		return false;
	}
	this->setTower(tower);
	//�����л�ȡ�����ٶ�
	this->setFireSpeed(tower->getFireSpeed());
	
	return true;
}

void TowerAI::onEnter(){
	Node::onEnter();
	this->schedule(schedule_selector(TowerAI::checkfire),this->getFireSpeed());
}

TowerAI* TowerAI::create(Tower* tower){
	auto towerai = new TowerAI();
	if (towerai&&towerai->init(tower))
	{
		towerai->autorelease();
		return towerai;
	}
	CC_SAFE_DELETE(towerai);
	towerai = nullptr;
	return towerai;
}
void TowerAI::checkfire(float dt){
	//��AI���Ƶ�������
	//����
	auto monster =EntityManager::getInstance()->ChakRangeTower(tower);
	//��ȡ����Ч��monster�ſ���
	if (monster != nullptr)
	{
		this->getTower()->fire(monster);
	}
	
}

