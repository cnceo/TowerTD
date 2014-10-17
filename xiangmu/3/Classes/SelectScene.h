#ifndef __SelectScene_H
#define __SelectScene_H
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
using namespace ui;
class SelectScene:public Scene{
public:
	virtual bool init();
	CREATE_FUNC(SelectScene);
	virtual void onEnter();
	CC_SYNTHESIZE(int,passedchapter,PassedChapter);
protected:
	Vector<Node*> buttons;
	void addTouchEventListener(Ref*sender,Widget::TouchEventType t);//���ѡ�ذ�ť�ص��ĺ���
	int buttonIndex;
	PageView * page1;
	int pageIndex;
	void nextPage(Ref* sender,Widget::TouchEventType t);//pageView����ĺ���
	void returnLastScene(Ref* sender,Widget::TouchEventType t);//���ذ�ť�Ļص�����
	void setButtonTexture(int buttonIndex,std::string fileName,int tagnum);//δ�ܵ�ȫ�汣��
	//��ȡ����״̬���޸İ�ť
	void readUserMessage();
	SelectScene(){
		buttonIndex = 1;
		pageIndex =0;
	}
};
#endif