#pragma once

#include "AppMacro.h"
#include "BaseAirObject.h"

// class BaseAirObject; �̳е�ʱ����ʹ�����ַ�ʽ

class Prop :public BaseAirObject{
protected:
	virtual bool init();
public:
	CREATE_FUNC(Prop);

	virtual void effectWhileCollision(Ref *obj);
};