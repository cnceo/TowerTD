#ifndef __SWORDMANHER_R_
#define __SWORDMANHER_R_

#include "HeroBase.h"
#include "cocos2d.h"
#include <iostream>
using namespace std;
using namespace cocos2d;


class SwordmanHero : public HeroBase
{
private:
	//��ȡӢ�۵�װ��
	void addHeroAttribute();
public:
	virtual bool init();
	CREATE_FUNC(SwordmanHero);
	SwordmanHero();
	~SwordmanHero();
}; 

#endif