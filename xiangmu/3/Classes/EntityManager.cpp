#include "EntityManager.h"
#include "math.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Tower.h"
#include "VictorySprite.h"
#include "HealthData.h"
#include "FormatUtil.h"
EntityManager * EntityManager::Instance = nullptr;
EntityManager* EntityManager::getInstance(){
	if (!Instance)
	{
		Instance = new EntityManager();
	}
	return Instance;
}
void EntityManager::checkBulletHitTower(){
    for (auto bt = MonsterBullet.begin();bt!=MonsterBullet.end();bt++)
    {
		int size = MonsterBullet.size();
		for (auto tr = TowerVector.begin();tr != TowerVector.cend();tr++)
		{    
			int size = TowerVector.size();
			 //ȡ�����еĲ������ӵ�
	         Bullet* bullet = (*bt);
			 //ȡ�����е���
			 Tower* tower = (*tr);
             //��ײ���
			 if (! bullet->getIsdie()&&! tower->getIsdie()&&bullet -> getBoundingBox().intersectsRect(tower -> getBoundingBox()))
			 {
				 //����ײ �������˺�
				 tower->towerhurt(bullet->getAttackValue());
				 //�����ӵ�
				 bullet->setIsdie(true);
				 //��ɾ��,����ɾ��
			 }
		}
    }
}
void EntityManager::checkBulletHitMonster(){
	for (auto bt = TowerBullet.begin();bt!=TowerBullet.end();bt++)
	{
		for (auto mr = Monster.begin();mr!=Monster.cend();mr++)
		{    
			//ȡ�����������ӵ�
			Bullet* bullet = (*bt);
			//ȡ�����еĲ���
			Enemy* monster = (*mr);
			//����ײ���
			if (! bullet->getIsdie()&&! monster->getIsdie()&&bullet->getBoundingBox().intersectsRect(monster->getBoundingBox()))
			{
				//����ײ �ò������˺�
				monster->hurtMe(bullet);
				//�����ӵ�
				bullet->setIsdie(true);
				//��ɾ��,����ɾ��
			}
		}
	}
}

void EntityManager::removeInvalidTowerEnemy(){
	for (auto it = Monster.begin();it<Monster.end();)
	{
		auto tmp_monster = *it;
		if (tmp_monster->getIsdie())
		{
			tmp_monster->remove();
			it = Monster.erase(it);
			//����ɱ������
			monsterkillednum++;
		}else
		{
			it++;
		}
	}
	for (auto it = TowerVector.begin();it<TowerVector.end();)
	{
		auto tmp_tower = *it;
		if (tmp_tower->getIsdie())
		{
			tmp_tower->remove();
			it = TowerVector.erase(it);
		}else
		{
			it++;
		}
	}
	for (auto it = MonsterBullet.begin();it<MonsterBullet.end();)
	{
		auto tmp_monster = *it;
		if (tmp_monster->getIsdie())
		{
			tmp_monster->remove();
			it = MonsterBullet.erase(it);
		}else
		{
			it++;
		}
	}
	for (auto it = TowerBullet.begin();it<TowerBullet.end();)
	{
		auto tmp_tower = *it;
		if (tmp_tower->getIsdie())
		{
			tmp_tower->remove();
			it = TowerBullet.erase(it);
		}else
		{
			it++;
		}
	}
	for (auto it = healthData.begin();it<healthData.end();){
		auto tmp_healthData = *it;
		if (tmp_healthData->getIsdie()){
			tmp_healthData->die();
			it = healthData.erase(it);
		}else{
			it++;
		}
	}
}

Sprite* EntityManager::ChakRangeTower(Tower* tower){
	float d = tower->getScope();
	int mindisnum=-1;
	//ȡ����Ļ�ϵĲ���
	for (int monsternum=0;monsternum!=Monster.size();monsternum++)
	{

		Enemy* monster = Monster.at(monsternum);
		//���������ľ���d
		Vec2 monsterPosition = monster->getPosition();
		float x1 = monsterPosition.x;
		float y1 = monsterPosition.y;
		float x2 = tower->getPosition().x;
		float y2 = tower->getPosition().y;
		float mineD = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

		////////////////����С����///////////////////////////////////

		if (mineD<=tower->getScope()&&mineD<d)
		{	
			d = mineD;
			mindisnum = monsternum;
		}
	}
	//����ҵ���һ�����ͷ��ظ���,���򷵻�null
	if (mindisnum>=0)
	{
		return Monster.at(mindisnum);
	}else
	{
		return nullptr;
	}
}
Sprite* EntityManager::ChakRamgeManager(Enemy* enemy){
	//ȡ�����н������
	float d = enemy->getAttRange();
	int mindisnum=-1;
		//ȡ����Ļ�ϵĲ���
		for (int towernum=0;towernum!=TowerVector.size();towernum++)
		{
		
			Tower* tower = TowerVector.at(towernum);
			//���������ľ���d
			Vec2 towerPosition = tower->getPosition();
			float x1 = towerPosition.x;
			float y1 = towerPosition.y;
			float x2 = enemy->getPosition().x;
			float y2 = enemy->getPosition().y;
			float mineD = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		
			////////////////����С����///////////////////////////////////
			
			if (mineD<=enemy->getAttRange()&&mineD<d)
			{	
				d = mineD;
				mindisnum = towernum;
			}
		}
		//����ҵ���һ�����ͷ��ظ���,���򷵻�null
		if (mindisnum>=0)
		{
			return TowerVector.at(mindisnum);
		}else
		{
			return nullptr;
		}
}


void EntityManager::towerDie(){
}
void EntityManager::BindingChak(){
	checkBulletHitTower();
	checkBulletHitMonster();
}

void EntityManager::reset(){
	TowerVector.clear();
	Monster.clear();
	TowerBullet.clear();
	MonsterBullet.clear();
	healthData.clear();
	monsterkillednum = 0;
}

bool EntityManager::CheckInsterData(VirctoSprite*vsp){
	for (auto it = healthData.begin();it<healthData.end();it++)
	{
		HealthData* tmp_healthData = *it;
		if(vsp->getBoundingBox().intersectsRect(tmp_healthData->getBoundingBox())){
			tmp_healthData->setIsdie(true);

			return true;
		};
	}
	return false;
}
void EntityManager::CheckEnemyInsterVsp(VirctoSprite*vsp){
	for (auto it = Monster.begin();it<Monster.end();it++)
	{
		Enemy* tmp_monster = *it;
		if(vsp->getBoundingBox().intersectsRect(tmp_monster->getBoundingBox())){
			tmp_monster->setIsdie(true);
			vsp->hurt(tmp_monster->getBuattackValue());	
		};
	}
}

bool EntityManager::checkhasEntity(Tower* tower){
	bool hasmonster = false;
	for (auto it = Monster.begin();it<Monster.end();it++)
	{
		Enemy* tmp_monster = *it;
		if(tower->getBoundingBox().intersectsRect(tmp_monster->getBoundingBox())){
			hasmonster = true;
		};
	}
	for (auto it = healthData.begin();it<healthData.end();it++)
	{
		HealthData* tmp_monster = *it;
		if(tower->getBoundingBox().intersectsRect(tmp_monster->getBoundingBox())){
			hasmonster = true;
		};
	}
	return hasmonster;
}

void EntityManager::formatData(FormatUtil* formatutil){
	Vec2 tmp_formatutilposition = formatutil->getPosition();
	//ɾ����
	for (auto it = TowerVector.begin();it<TowerVector.end();it++)
	{
		Tower* tmp_tower = *it;
		Vec2 tmp_towerposition = tmp_tower->getPosition();
		float tmpdis = sqrt(pow(tmp_formatutilposition.x-tmp_towerposition.x,2)+pow(tmp_formatutilposition.y-tmp_towerposition.y,2));
		if (tmpdis<formatutil->getAttRange())
		{
			//��ɱ��
			tmp_tower->towerhurt(tmp_tower->getHp());
		}
	}
	//ɾ����
	for (auto it = Monster.begin();it<Monster.end();it++)
	{
		Enemy* tmp_enemy = *it;
		Vec2 tmp_enemyposition = tmp_enemy->getPosition();
		float tmpdis = sqrt(pow(tmp_formatutilposition.x-tmp_enemyposition.x,2)+pow(tmp_formatutilposition.y-tmp_enemyposition.y,2));
		if (tmpdis<formatutil->getAttRange())
		{
			//��ɱ��
			tmp_enemy->hurtMe(tmp_enemy->getHP());
		}
	}
	//ɾ���ļ�
	for (auto it = healthData.begin();it<healthData.end();it++)
	{
		HealthData* tmp_healthdata = *it;
		Vec2 tmp_healthdataposition = tmp_healthdata->getPosition();
		float tmpdis = sqrt(pow(tmp_formatutilposition.x-tmp_healthdataposition.x,2)+pow(tmp_formatutilposition.y-tmp_healthdataposition.y,2));
		if (tmpdis<formatutil->getAttRange())
		{
			//��ɱ��
			tmp_healthdata->die();
		}
	}
}
EntityManager::EntityManager(){
	monsterkillednum = 0;
}
EntityManager::~EntityManager(){

}