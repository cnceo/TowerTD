#ifndef __SKILLBASE_R_
#define __SKILLBASE_R_

#include "cocos2d.h"
using namespace cocos2d;

enum Driection1
{
	LEFT1,
	RIGHT1,
	JUMP1,
	NEARSKILL1,
	LEFTFARSKILL1,
	RIGHTFARSKILL1,
	BIGSKILL1,
	ATTACK1,
	STOP1
};

class SkillBase : public Sprite
{
public:
	//�ͷż���Ҫ���ĵ�MP
	CC_SYNTHESIZE(int, _consumeMp, ConsumeMp);
	//�����Ƿ����
	CC_SYNTHESIZE(bool,_isDie, IsDie);
	//���ܵ��˺�ֵ
	CC_SYNTHESIZE(int, _attack, Attack);
	virtual bool init(std::string name, Vec2 skillPoint);
    SkillBase() : _isDie(false){}
};

#endif