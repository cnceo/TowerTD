#pragma once

#include "AppMacro.h"

class MainPlane;

/*
	������л��࣬�л��͵��ߵĻ���
*/
class BaseAirObject : public Sprite{
public:
	virtual void effectWhileCollision(Ref* obj) = 0;
};
