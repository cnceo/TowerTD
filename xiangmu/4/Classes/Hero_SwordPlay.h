#ifndef __HERO_SWORDPLAY_H_
#define __HERO_SWORDPLAY_H_

#include "BaseHeroes.h"

class Hero_SwordPlay : public BaseHeroes
{
public:
	virtual void die();
	virtual bool init();
	static Hero_SwordPlay * create();
	virtual ActionInterval * hurtAnimate();
	//���ж���
	virtual ActionInterval * flyAnimate();
	
	virtual void onEnter();
	virtual void fly();
	
};

#endif 