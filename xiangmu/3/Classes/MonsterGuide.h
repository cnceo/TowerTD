#ifndef __MonsterGuide 
#define __MonsterGuide
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio;
using namespace ui;
class MonsterGuide :public Layer{
public:
	virtual bool init();
	CREATE_FUNC(MonsterGuide);
	static Scene* createScene();
	virtual void onEnter();
	Vector<Node*>buttons;//�õ�UI����Button����
	Widget* layer;
protected:
	Vector<Sprite*> guideSprite;//�õ�����������ϢͼƬ�ľ�������
	void guideTouch(Ref* sender,Widget::TouchEventType t);//button�Ļص�����
	void operateLayerVector(int index);//�Թ�����ϢͼƬ������в���
};
#endif