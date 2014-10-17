/**

* ������MonsterManager

* ���ߣ��´�

* ���ڣ�

* ���� : һ��һ���ĳ��ֹ���,���ڵİ汾���ֹ����������һ����
			���յİ汾Ӧ�����޳���,ֱ����Ϸ����Ϊֹ

**/ 
#ifndef __MONSTERMANAGER_H_
#define __MONSTERMANAGER_H_
#include "cocos2d.h"
USING_NS_CC;
class MonsterManager:public Node{
public:
	CREATE_FUNC(MonsterManager);
	void setEarnScoreFunc(std::function<void(int)> monsteraddprice);
	//����������Ч(�󶨸�����ص�)
	void monsterDieEffect(Vec2 diepoint);
protected:
	virtual bool init();
	//��ʼ���ؿ��Ѷ�
	void initLevel();
	//����һ������
	void waveMonster(float dt);
	//����һ������
	void createMonster(float dt);
	//���һ���������λ��
	Vec2 monsterCreatePosition();
	virtual void onEnter();
protected:
	//�ڼ�����
	int nowwaves;
	//ÿһ��֮��ļ��
	int intervalperwave;
	//���м�����
	int totalwaves;
	//ѭ������(��������Ϊmonsternumperwave*wavecount,wavecount���Ϊ5)
	int wavecount;
	//ÿһ���ֵ�id
	std::map<int,int> monsters_id;
	//ÿһ����֮��ļ��(��Ӧ��С�ڵ���2s)
	std::map<int,int> delaytimeperwave;
	//ÿһ���м�����
	std::map<int,int> monsternumperwave;
	//��������ʱ�ص����function,��������ʱ��������
	std::function<void(int)> monsteraddprice;
	ProgressTimer* pro;
	float progress;
};
#endif