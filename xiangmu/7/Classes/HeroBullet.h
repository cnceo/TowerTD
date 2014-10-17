#ifndef _HEROBULLET_H
#define _HEROBULLET_H
#include "BaseBullet.h"

#define BULLETSPEED 250

class HeroBullet : public BaseBullet
{
public:
	virtual bool init(std::string fileName,Vec2 position);		//��дinit����
	static HeroBullet *create(std::string fileName,Vec2 position);		//��дcreate����
	void move(int direction);
};


#endif