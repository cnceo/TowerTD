/************************************************************************/
/* 
	������


*/
/************************************************************************/
#ifndef __HEROLAYER_H
#define __HEROLAYER_H

#include "cocos2d.h"
#include "Hero.h"
#include "AllVectors.h"

using namespace cocos2d;

class HeroLayer:public Layer{

public:

	virtual bool init();
	CREATE_FUNC(HeroLayer);

	
	Size visSize;		//�������Ĵ�С

	Hero *sp;
	void getFieBall(float t);
	Hero *getHero();

};
#endif // !__HEROLAYER_H