/************************************************************************/
/* 
��Ҫʵ�ֵĹ��ܣ�
		1.�̳��� BaseRole
		2.���˷���  ��д
		3.m_state  ״̬

		4. ��дcrate(image��hp,speed)���� init��image��hp,speed��
*******************************************************************/
#ifndef __BASEENEMY_H_
#define __BASEENEMY_H_

#include "cocos2d.h"
#include "BaseRole.h"
#include "EnemyBullet.h"

using namespace cocos2d;

class BaseEnemy:public BaseRole{

protected:
	CC_SYNTHESIZE(int,m_AI,M_AI);
	CC_SYNTHESIZE(bool,m_isSkilled,M_isSkilled);
	CC_SYNTHESIZE(int,m_type,M_type);
	CC_SYNTHESIZE(int,m_state,M_state);
	CC_SYNTHESIZE(bool,isDie,IsDie);
	CC_SYNTHESIZE(float,m_speed,M_speed);
	CC_SYNTHESIZE(bool,m_isSkillReady,M_isSkillReady);
	int countToJump;
	float m_subscructStateTime;				//�����������ת��ǰһ״̬��ʱ��
	float bulletHitTime;					//�ӵ��������
	Vec2 m_posi;
	int m_direction;
	bool isJump;
	bool m_isTaken;
	bool m_isFired;
	EnemyBullet * enemybullet;
	Size m_size;
	bool m_isMoving;
public:
	void renewMove(float t);
	void mySkill();
	void mySkill1();
	virtual bool initWithSpriteFrameName(std::string fileName, int speed, int type, Vec2 posi,Size size, int AI);
	void hurt();
	static BaseEnemy *create(std::string fileName, int speed, int type, Vec2 posi,Size size, int AI);
	void moveLeftAnimate(int imageMount);
	void moveRightAnimate(int imageMount);
	void move();
	void jump();
	void call(float t);
	void update(float t);
	void bulletHit();

    void die();
    void mySkill2();
};


#endif