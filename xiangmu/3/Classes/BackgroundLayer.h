//���ñ���(���ڿ��������Ч)
#ifndef __BACKGROUNDLAYER_H_
#define __BACKGROUNDLAYER_H_
#include "cocos2d.h"
using namespace cocos2d;
class BackgroundLayer:public Layer{
public:
	CREATE_FUNC(BackgroundLayer);
	virtual bool init();
	//onEnter���ݵ�ǰ�ؿ�������(������ò���ֱ��)
	virtual void onEnter();
};
#endif