#ifndef  __MONSTERS_H
#define  __MONSTERS_H
#include "cocos2d.h"
#include "MonsterBase.h"
class Monsters
{
private:
	Monsters():nowNumber(0){}
	~Monsters(){}
	static Monsters *instance;
public:
	static Monsters *getInstance();
	//������
	CC_SYNTHESIZE_PASS_BY_REF(Vector<MonsterBase *>, monsterVector, MonsterVector);
	//��������
	CC_SYNTHESIZE(int, nowNumber, NowNumber);
	//���ӹ���
	void addMonster(MonsterBase *monster);
	//ɾ������
	void clearMonster();
	//������������й���
	void clearAllMonster();
};
#endif