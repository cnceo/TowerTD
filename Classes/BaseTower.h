#ifndef __BASETOWER_H
#define __BASETOWER_H
#include "cocos2d.h"
#include "EnemyBase.h"
#include "GameBasic.h"
USING_NS_CC;

class BaseTower:public Sprite
{
public:
	int maxlevel;
	EnemyBase *soldier;//����
	Vec2 targetpoint;//Ŀ���

	virtual bool init();	

	CC_SYNTHESIZE(float,scope,Scope);//�������߷�Χ
	CC_SYNTHESIZE(int,curlevel,Curlevel);//��ǰ�ȼ�
	CC_SYNTHESIZE(int,curgold,Curgold);//����������Ҫ��Ǯ
	CC_SYNTHESIZE(int,goldvalue,Goldvalue);//����ʱ�Ľ��ֵ	
	//CREATE_FUNC(BaseTower);
	BaseTower();
	~BaseTower();
	virtual void runAnimate(std::string name);//������ִ�ж���
	 
	virtual void checkNearestEnemy();//����������
	virtual void stopAnm() = 0;//���µĶ���
	virtual void Attack(float t)=0;//��������
    virtual void postuplevel();//������������
	virtual void uplevel();//����
    virtual void postDeleteTower();//�����Ƴ�
    virtual void removeTower(); //�Ƴ�����
		//���ķ����ٶ�
	virtual void pauseAllTowers(); //��ͣ�������Ķ���
	//��������������
	//virtual void updateTowersAnimation();
	Animation * animat;
	Animate *ani;
	std::string fileName;


protected:
	void setSpeed(float);
	void update(float dt);
	void changeState();
private:
	bool isAttackTime;
	bool isPreAttackTime;
	bool ischangeState;
	float speed;
};
#endif 