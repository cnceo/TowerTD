/************************************************************************/
/* 
��Ҫʵ�ֵĹ��ܣ�
	���ԣ�

		�̳���BaseRole
		�����ഫ��Ƭ 
		m_hp//Ѫ��
		move()�ƶ�   
		m_speed�ٶ�
		m_attack�����ˣ����ǵĹ�����Ϊ0��
		jump()��  
		hurt()    
		die()   ����  
		bornAnimate() ��������  
		dieRunAnimation()��������    ͨ�����ഫ����������Ƭ������������
		m_state ״̬

		fire�������Ƿ����ӵ�

*/
/************************************************************************/
#ifndef __HERO_H_
#define __HERO_H_

#include "cocos2d.h"
#include "BaseRole.h"
#include "HeroBullet.h"



class BaseRole;
using namespace cocos2d;
enum HeroState
{
	alive = 0,
	died,
	addBulletAttack,
	addBulletRange
};
enum HeroDirection
{
	RIGHT = 1,
	LEFT
};
class Hero:public BaseRole
{
protected:
	HeroBullet * herobullet;
	Vec2 m_position;
	CC_SYNTHESIZE(bool,m_isRangeUp,M_isRangeUp);
	CC_SYNTHESIZE(bool,m_isFireUp,M_isFireUp);
public:
	CC_SYNTHESIZE(int, m_speed ,M_speed);
	CC_SYNTHESIZE(int, m_state ,M_state);
	CC_SYNTHESIZE(int, m_attack ,M_attack);
	CC_SYNTHESIZE(int, m_hp ,M_hp);
	CC_SYNTHESIZE(bool,m_isHurt,M_isHurt);
	CC_SYNTHESIZE(int,m_RollDirection,M_RollDirection);

/*	CC_SYNTHESIZE(int ,m_range,M_range);*/
	bool isTaking;
	Animate * m_moveLeftAnimate;
	Animate * m_moveRightAnimate;
	Animate * getRightAnimate();
	Animate * getLeftAnimate();
	CC_SYNTHESIZE(bool,isJump,IsJump);  //�Ƿ���
	//�������Ƿ���
	CC_SYNTHESIZE(HeroDirection,direction,Direction);
	CC_SYNTHESIZE(bool,isFire,IsFire);
	virtual bool init(Vec2 position);


	void addBullet(int direction);//��ʼ���ӵ�

	//���ǵ�create���� ���ļ�����λ�ô�������
	static Hero * create(Vec2 position);

	//���ǵĿ��𷽷�
	virtual void addFire(Ref * sender);
	//���ǵ����˷���
	virtual void hurt();

	//���ǵĳ�������
	//virtual void bornAnimate();

	//���ǵ����߷���
	virtual void heroMoveRight(Ref * sender);
	virtual void heroMoveLeft(Ref * sender);
	//���ǵ���Ծ����
	virtual void heroJump(Ref * sender);

	//���ǵ���������
	virtual void die();
	void dieAnimate();
	//�ظ�ԭ��վ������
	void Recover(Ref * sender);
	//վ������
	void standAnimate(int direction);
	//���ǵ���������
	//virtual void dieRunAnimation();

	//����x������ļӼ�
	void addX(float t);

	void subStractX(float t);
	//ֹͣ�ƶ�
	void stopMove(Ref * sender);


	void call(float t);
	int count;

	void createAnimate(std::string fileName);

	//void AddSpeed();
	float time;
	void harmLess(float t);

private:
	~Hero(){
		__NotificationCenter::getInstance()->removeAllObservers(this);
	}
};

#endif
