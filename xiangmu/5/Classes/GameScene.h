#ifndef __GAMESCENE_H_
#define __GAMESCENE_H_
#include "cocos2d.h"
USING_NS_CC;

class GameScene : public Scene{
public:
	CREATE_FUNC(GameScene);
	//�õ�������
	Layer * getBackgroundLayer();
	//�õ����Ʋ�
	Layer * getControlLayer();
	//�õ����ǲ�
	Layer * getRoleLayer();
protected:
	virtual bool init();
	void onEnter();
	int audioFlag;
};

#endif // !__GAMESCENE_H_
