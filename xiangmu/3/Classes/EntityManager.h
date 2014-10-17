#ifndef __ENTITYMANAGER_H_
#define __ENTITYMANAGER_H_
#include "cocos2d.h"
USING_NS_CC;
class Bullet;
class Enemy;
class Tower;
class HealthData;
class VirctoSprite;
class FormatUtil;
class EntityManager{
private:
    static EntityManager * Instance;
public:
	static EntityManager* getInstance();
	Vector<Tower*> TowerVector;
	Vector<Enemy*> Monster;
	Vector<Bullet*> TowerBullet;
	Vector<Bullet*> MonsterBullet;
	Vector<HealthData*>healthData;
	//�����ӵ�������
	void checkBulletHitTower();
	//���ӵ�������
	void checkBulletHitMonster();
	//����������,���ܴ�����
	//bool couldPass(Entity* monster);
	void BindingChak();
	void removeInvalidTowerEnemy();
	//��������
	Sprite* ChakRangeTower(Tower* tower);
	//�ֹ�����
	Sprite* ChakRamgeManager(Enemy* enemy);
	//ɾ������
	void reset();
	//ɾ����
	//�����ļ���ʤ���������ײ���
	bool CheckInsterData(VirctoSprite*vsp);
	//���˺�ʤ���������ײ���
	void CheckEnemyInsterVsp(VirctoSprite*vsp);
	//����ʱ�ж���û�й�
	//�йַ���true û�з���false
	bool checkhasEntity(Tower* tower);
	//��ʽ��(ը������)
	void formatData(FormatUtil* formatutil);
	void towerDie();
	CC_SYNTHESIZE(int,monsterkillednum,MonsterKilledNum);
protected:
	EntityManager();
	virtual~EntityManager();
	EntityManager(const EntityManager& manager);
	EntityManager* operator=(const EntityManager& manager);
};
#endif