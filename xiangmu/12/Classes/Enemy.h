#ifndef __ENEMY_H
#define __ENEMY_H
#include "cocos2d.h"
#include "EnemyBase.h"
#include "cocoStudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace ui;
using namespace cocostudio;
class Enemy:public EnemyBase{
private:
	Color3B m_orgcolor; 
	int m_pointCounter;
	std::string m_name;
	Sprite* m_hpBgSprite;
	Vec2 p1,p2;
	std::vector<Vec2>m_points;
public:
	Enemy();
	~Enemy();
	CC_SYNTHESIZE(bool,isIce,ISICE);//�Ƿ��ڱ���״̬
	CC_SYNTHESIZE(bool,isFire,ISFIRE);//�Ƿ��ڻ���״̬
	CC_SYNTHESIZE(bool,isWind,ISWIND);//�Ƿ��ڷִ�״̬
	CC_SYNTHESIZE(bool,isWire,ISWIRE);//�Ƿ����׵�״̬
	CC_SYNTHESIZE(ProgressTimer*,m_hpBar,HpBar);//Ѫ��������
	CC_SYNTHESIZE(bool,m_enemySuccessful, EnemySuccessful);//
	static Enemy* create(std::string str,float hp,float speed,float money);
	virtual bool init(std::string str,float hp,float speed,float money);
	virtual void setMoveDirection();//�����ƶ�����
	virtual void runAnimate();//֡����
	virtual void attackAnimate();//��������
	virtual void dieAnimate();//��������
	virtual void createHpBar();//����Ѫ�����Ѫ����
	virtual void setHpBar();//����Ѫ����
	virtual void hurt(float attack,HurtState state);//���˱�����Ѫ����
	virtual void move(float t);//�ƶ�����
	virtual void iceEvent();//������
	virtual void fireEvent();//������
	virtual void windEvent();//������
	virtual void wireEvent();//������
	virtual void iceAnimate();//�����Ա�������
	virtual void fireAnimate();//�����Ա�������
	virtual void wireAnimate();//�����Ա�������
	virtual void moneyLable();//������Ǯ����
	Vec2 currPoint();//��ǰ��
	Vec2 nextPoint();//��һ����
};
#endif