//��Ϸ�������,����Ԥ������Դ
#ifndef __GAMELOADINGLAYER_H_
#define __GAMELOADINGLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class GameLoadingLayer:public Layer{
public:
	CREATE_FUNC(GameLoadingLayer);
	static Scene* createScene();
	virtual bool init();
	virtual void onEnter();
protected:
	void loadImages();
	void loadSoundEffect();
	void refreshProcessBar();
protected:
	int process;
};
#endif