/*
*��������
*/

#ifndef __GAMELAYER__
#define __GAMELAYER__

#include "cocos2d.h"
/************************************************************************/
/* ��Ϸ��                                                                     */
/************************************************************************/
class GameLayer : public cocos2d::Layer
{
private:
	//��ʼ��Ϸ
	void startGame();
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameLayer);
};

#endif // __HELLOWORLD_SCENE_H__
