#ifndef __STARTSCENE_H_
#define __STARTSCENE_H_
#include <cocos2d.h>
using namespace cocos2d;

class StartScene : public Layer
{
private:
	Sprite *backGround;	 //����ͼ
	Sprite *gameLogo;	 //��ϷLogo
	Sprite *prompt;		 //��ʾ
	Sprite *kelchend;	 //����
	Sprite *ribbon;		 //����
	MenuItemImage *startItem;	//��ʼ��ť
	MenuItemImage *audioItem;	//������ť
	MenuItemImage *aboutItem;	//���ڰ�ť
	int audioFlag;		//��������
	void addAboutItem();
	void addSprite(Sprite *sp, std::string fileName, Vec2 p);
	void addMenu(MenuItemImage *item,std::string normalName, std::string selName, Vec2 p, bool toggleFlag);
	void onEnter();

public:
	static Scene *createScene();
	virtual bool init();
	CREATE_FUNC(StartScene);
};
#endif