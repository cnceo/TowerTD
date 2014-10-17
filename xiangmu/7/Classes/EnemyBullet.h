#ifndef _ENEMYBULLET_H
#define _ENEMYBULLET_H
#include "BaseBullet.h"
#define ENEMYBULLETSPEED 250

class EnemyBullet : public BaseBullet
{
protected:
	Size vsize;
	Vec2 m_position;
public:
	virtual bool init(std::string fileName,Vec2 position);		//��дinit����
	static EnemyBullet *create(std::string fileName,Vec2 position);		//��дcreate����
	void move(int direction);
	Animate * getRightBulletAnimate();
	Animate * getLeftBulletAnimate();
	void removeBullet(float t);
};



#endif