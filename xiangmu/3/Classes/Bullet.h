#ifndef __BULLET_H_
#define __BULLET_H_
#include "cocos2d.h"
#include "Enemy.h"
#include "GlobalInfo.h"
class Bullet : public Sprite{
	private:
public:
	virtual bool init(std::string fileName,Vec2 target,Vec2 position,int speed,int attackValue,int scope,attackEffect atteffect);//��дinit����
	static Bullet * create(std::string fileName ,Vec2 target,Vec2 position,int speed,int attackValue,int scope,attackEffect atteffect); //��дCreate�����贫Ŀ������
    void move(Vec2 target);
	void die(float t);
	void remove();
	void onEnter();
	CC_SYNTHESIZE(bool,isdie,Isdie);
	CC_SYNTHESIZE(Vec2, target,Target);
	CC_SYNTHESIZE(Vec2,cposition,cPosition);
	CC_SYNTHESIZE(int, scope,Scope);
	CC_SYNTHESIZE(int,speed,Speed);
	CC_SYNTHESIZE(int,attackValue,AttackValue);//�ӵ�������
	CC_SYNTHESIZE(std::string,buName,BuName );//�ӵ���
	CC_SYNTHESIZE(attackEffect,attackeffect,AttackEffect);
protected:
	Bullet(){
		attackeffect.frozentime = 0;
		attackeffect.frozentime = 0;
		attackeffect.lowspeedtime = 0;
	}
};
#endif