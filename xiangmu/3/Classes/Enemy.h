//create by �Գ�Զ 2014 / 9 /19
//  base enemy 

#ifndef __ENTITY_H_
#define __ENTITY_H_
#include "cocos2d.h"
#include "GlobalInfo.h"
USING_NS_CC;

enum Directionbase{
	DOWNBASE = 0,
	LEFTBASE,
	RIGHTBASE,
	UPBASE,
};
class Bullet;
class Enemy:public Sprite{
public:
	static Enemy* create(int id);
	virtual bool init(int id);
	//������
	void hurtMe(Bullet* bullet);
	void hurtMe(int attvalue);
	//����
	CC_SYNTHESIZE(int,hp,HP);
	//����
	CC_SYNTHESIZE(int,def,Defence);
	//�����ٶ�
	CC_SYNTHESIZE(int,firespeed,FireSpeed);
	//������Χ
	CC_SYNTHESIZE(float,attrange,AttRange);
	//ÿһ���ƶ�����
	CC_SYNTHESIZE(int,speed,Speed);
	//�Ƿ�����
    CC_SYNTHESIZE(bool,isdie,Isdie);
	//���õ����ƶ�����
	CC_SYNTHESIZE(int,direct,EnemyDir);
	CC_SYNTHESIZE(Vec2, target,Target);
	//�ӵ��ƶ��ٶ�
	CC_SYNTHESIZE(int,buspeed,BuSpeed);
	//�ӵ�������
	CC_SYNTHESIZE(int,buattackValue,BuattackValue);
	//�ӵ���
	CC_SYNTHESIZE(std::string,buName,BuName );
	//����۸�
	CC_SYNTHESIZE(int,price,Price);
	//��������Ч
	CC_SYNTHESIZE(attackEffect,attackeffect,AttackEffect);
	//������Ч
	CC_SYNTHESIZE(attackEffect,enemyatteffect,EnemyattEffect);
	virtual void remove();
	//void move(direction dir,float t);
	void fire(Sprite* tow);
	void die();
	//�����ƶ�����
	virtual bool moveUp(float t);
	virtual bool moveDown(float t);
	virtual bool moveLeft(float t);
	virtual bool moveRight(float t);
	bool checkMove(Vec2 newpoint);
	//�������ӷֻص�����
	void setScoreFunc(std::function<void(int)> earnscore);
	//��������Ч����
	void setDieEffectFunc(std::function<void(Vec2 dieposition)> dieeffect);
protected:
	//������Ѫ����
	void intervalHurt(float dt);
	//��˪Ч��(����Ч��)(Ч��ʱ�䲻����)
	void lowspeedEffect(int time);
	//����Ч��(Ч��ʱ�䲻����)
	void frozenEffect(int time);
	//����Ч��(����,������Ѫ)(Ч��ʱ�䲻����)
	void fireEffect(int time);
	void removeLowspeedEffect(float dt);
	void removeFrozenEffect(float dt);
	void removeFireEffect(float dt);
protected:
	bool islowspeed;
	bool isfrozen;
	bool isfire;
	ParticleSystemQuad* snowparticle;
	ParticleSystemQuad* fireparticle;
	//�������߶�����
	Vector<Animate*> m_animates;
	void dieAnimate(std::string fileName);
	//�����ص��ӷֺ���
	std::function<void(int)> earnscore;
	//������Ч����
	std::function<void(Vec2)> dieeffect;
	//�ӷֺ����Ƿ�󶨹�
	bool getmoneyfuncbind;
	//��ʱ����,��¼�ӵ�������,������Ѫʱ��
	int bulletattval;
	Enemy(){
		hp = 0;
		isdie = false;
		getmoneyfuncbind = false;
		speed = STEP;
		def = 0;
		firespeed = 0;
		attrange = 0;
		//��ʼ��״̬
		islowspeed = false;
		isfrozen = false;
		isfire = false;
		attackeffect.firetime = 0;
		attackeffect.frozentime = 0;
		attackeffect.lowspeedtime = 0;
		enemyatteffect.firetime = 0;
		enemyatteffect.frozentime = 0;
		enemyatteffect.lowspeedtime = 0;
		snowparticle = nullptr;
		fireparticle = nullptr;
		bulletattval = 0;
	};
};
#endif