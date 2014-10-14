#ifndef __SUPERSKILLLAYER_H
#define __SUPERSKILLLAYER_H
#include "cocos2d.h"
#include "GameBasic.h"
class SuperSkillLayer:public Layer
{   
	Sprite * sprite;
	int type;
	EventListenerTouchOneByOne *listener;
	~SuperSkillLayer();
public:
	virtual bool init();
	static SuperSkillLayer *create();
	ProgressTimer* icecoolingBar;//��������ȴ��
	ProgressTimer* firecoolingBar;//������ȴ��
	ProgressTimer* wirecoolingBar;//�缼����ȴ��
	ProgressTimer* windcoolingBar;//�缼����ȴ��
	virtual void updateSkills(float t);
};
#endif // !__SUPERSKILLLAYER_H
