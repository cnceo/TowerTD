#ifndef __DELEGETLAYER_H__
#define __DELEGETLAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

//���ɿղ�
class DelegetLayer :public Layer
{
protected:
     virtual bool init();
public:
	CREATE_FUNC(DelegetLayer);	
};

#endif