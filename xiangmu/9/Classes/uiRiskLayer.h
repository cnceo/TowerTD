#ifndef __UIRISKLAYER_H__
#define __UIRISKLAYER_H__

#include "cocos2d.h"
#include "T_uiRiskLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;

class uiRiskLayer :public Layer
{
protected:
	virtual bool init();
    //ת������Ӧ�Ĺؿ�
	virtual void replaceScene(Ref * sender);
public:
	CREATE_FUNC(uiRiskLayer);
	static Scene *createScene();
};
#endif