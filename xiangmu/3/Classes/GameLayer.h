//��,��,�ӵ����ڵĲ�
#ifndef __GAMELAYER_H_
#define __GAMELAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class GameLayer:public Layer{
public:
	CREATE_FUNC(GameLayer);
	virtual bool init();
	void onEnter();
	void onExit();
protected:
	//��֡�ص�����ײ���
	void update(float dt);
};
#endif