#ifndef __HEROESLAYER__
#define __HEROESLAYER__

#include "cocos2d.h"
/************************************************************************/
/* ���ֲ� ���û����Լ���ͣ��ť                                                                     */
/************************************************************************/
class HeroesLayer : public cocos2d::Layer
{
protected:
	//�õ�����
	void getScore();
	//������ʾ
	void viewScore();
	//������ͣ��ť
	void createPause();
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(HeroesLayer);
};

#endif // __HELLOWORLD_SCENE_H__