#ifndef __ENEMYBASE_H
#define __ENEMYBASE_H
#include "cocos2d.h"

using namespace cocos2d;
enum MoveState{
	STOP,//ֹͣ
	UP,//��
	DOWN,//��
	LEFT,//��
	RIGHT//��
};
enum LifeState{
	NORMAL,//����
	DIE//����
};
enum HurtState{
	NIRGUNA,//������  ֻ��ʹѪ������
	FIRE,//������     ʹ����Ѫ�����ٲ���ʹ������
	ICE,//������      ʹ����Ѫ�����ٲ���ʹ�������
	WIND,//������     ʹ����Ѫ�����ٲ���ʹ�������ⷽ��λ��
	WIRE,//������     ʹ����Ѫ�����ٲ���ʹ����ͷ����������  
}; 
class EnemyBase:public Sprite{
public:	
	EnemyBase();
	~EnemyBase();
	virtual void setMoveDirection()=0;//�ƶ�����
	virtual void runAnimate()=0;//�ƶ�ʱ�Ķ���
	virtual void attackAnimate()=0;//����ʱ�Ķ���
	virtual void dieAnimate()=0;//����ʱ�Ķ���
	virtual void remove();//���
	virtual void hurt(float attack,HurtState state)=0;//����
	virtual bool init(float hp,float speed);
	CC_SYNTHESIZE_READONLY(float,m_maxhp,Maxhp);//���Ѫ��
	CC_SYNTHESIZE_READONLY(float,m_origspeed,OrgSpeed);//��ʼ�ٶ�
	CC_SYNTHESIZE(float,m_curhp,Curhp);//��ǰѪ��
	CC_SYNTHESIZE_READONLY(float,m_money,Money);//���ֵ
	CC_SYNTHESIZE(float,m_speed,SPEED);//�ٶ�
    CC_SYNTHESIZE(bool,m_isstop,isStop);//�Ƿ���ֹͣ״̬
	CC_SYNTHESIZE(HurtState,m_hurtproperty,Property)//����״̬
	CC_SYNTHESIZE(MoveState,m_direction,Direction);//�ƶ�״̬
	CC_SYNTHESIZE(LifeState,m_lifestate,Live);//�Ƿ���
};
#endif