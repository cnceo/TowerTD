#ifndef __UILAYER_H
#define __UILAYER_H
#include "cocos2d.h"
#include "cocoStudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio;
using namespace ui;

class UiLayer : public Layer{
	int curhomehp;//���ѳ�ʼѪ��
	int curmoney;//��ʼ��Ǯ��
	int waves;//�����ܲ���
	int shuts;//�ڼ���
	int totalwaves;//������
	Widget * uilayer;
	TextBMFont * wave;//����and����
	TextBMFont * money;//��Ǯ��
	TextBMFont * homehp;//����Ѫ��
	virtual void setMoney(Ref * sender);
	virtual void setHomehp(Ref * sender);
	virtual void setWave(Ref * sender);
	virtual void updateTower(Ref* sender);
	virtual void removeTower(Ref* sender);
public:
	UiLayer();
	~UiLayer();
	virtual int getcurmoney();
	virtual bool init();
	CREATE_FUNC(UiLayer);
};
#endif
