
#ifndef __Dota_Legend__AttackLayer__
#define __Dota_Legend__AttackLayer__

#include <stdio.h>
#include "cocos2d.h"


USING_NS_CC;
class AttackLayer : public Layer {
protected:
	float bgX;
	float bgY;
	void addHeroWindow();
	void stopLayer(Ref * sender);
	//ͨ����һ�����İ�ť
	void nextMap(Ref * sender);
	//�˳���ť�ص�
	void EndMenu(Ref * sender);
	//�Զ�ս��
	void automaticAttack(Ref * sender);
	//���ֲ�
	Sprite * shield;
	//���Ӣ�۵Ĵ���
	Sprite * herowindow;
	//
	 MenuItemImage *nextitem;
	Sprite *bg;
public:
	virtual bool init();
	CREATE_FUNC(AttackLayer);
	void setNextMapVisable(bool isVisible);
	void setBg(std::string TexName);
	void menuCallback(Ref * sender);
	void popGameScene(Ref* sender);
};
#endif /* defined(__Dota_Legend__AttackLayer__) */
