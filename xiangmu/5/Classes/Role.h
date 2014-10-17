#ifndef __ROLE__H
#define __ROLE__H
#include "cocos2d.h"
#include "BaseSprite.h"
USING_NS_CC;

enum RoleState
{
 	Role_protected			= 1,		//������
 	Role_doubleScore		= 1 << 1,	//˫������
 	Role_goldDoubleScore	= 1 << 2,	//����˫������
 	Role_bucket				= 1 << 3,	//ˮͰ
 	Role_band				= 1 << 4,	//������
 	Role_addBlood			= 1 << 5,	//Ѫ����Ѫ
 	Role_addBloodMost		= 1 << 6,	//Ѫ�μ�Ѫ
 	Role_addScore			= 1 << 7,	//����ʮ��
 	Role_addScoreMost		= 1 << 8	//��һ�ٷ�
};

class Role : public BaseSprite
{
public:
	CREATE_FUNC(Role);
	void changeState(int);

	//���ǵĸ����˶�����ֹͣ
	void normalRun();
	void slowRun();
	void fastRun();
	void jumpUp();
	void stopFastRun();
	void stopSlowRun();

	//���������½�����Ϊ
	void moveY(float t);

	void hurt(int attack, bool isEfence);
	void die();
	
	CC_SYNTHESIZE_READONLY(int, m_hp, M_hp);
protected:
	virtual ~Role();
	virtual bool init();
	void update(float t);
	void addPhysicsBody();
	void dropHpByTime(float t);
	void boundaryDetection(float t);
	void addSprite();
	void addParticle();
private:
	bool bostZoneFlag;
	//��Ч����
	int audioFlag;
	//�����ѪЧ��
	ParticleSystemQuad * quickBlood;
	ParticleSystemQuad * slowBlood;
	//�ж������Ƿ����½�
	bool isJumpingDown;

	//����ǰ������˵��ٶ�
	int moveSpeed;

	//���ǵ��˶�״̬
	bool isFastRun;
	bool isSlowRnu;
	bool isNormalRun; 
	bool isRunning;

	//���ǵ�����
	int m_state;
	
	//����
	Sprite * protect;
	Sprite * band;
	Sprite * bucket;

	//���ǵĸ��ֶ���
	Animate * normalRunAction;
	Animate * slowRunAction;
	Animate * fastRunAction;
	Animate * jumpUpAction;
	Animate * hurtAction;
	Animate * electricAction;
};

#endif