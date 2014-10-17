#ifndef __BACKGROUNDLAYER_H_
#define __BACKGROUNDLAYER_H_

#include "cocos2d.h"
using namespace cocos2d;
//�����ƶ��ٶ�
#define BGMOVESPEED 200
//�����ƶ��ٶ�
#define SPRITEMOVESPEED 200
#define TOTALNUM 3
#define FILENAME "bgc.png"
#define SPRITENAME "liruotong.jpg"

class BackgroundLayer:public Layer {
public:
	virtual bool init();
	CREATE_FUNC(BackgroundLayer);
protected:
	int number;
	Size vSize;
	Sprite *bg1;
	Sprite *bg2;
	void addBackground();
	void update(float t);
	void addSprite(float t);
	void createSprite();
};

#endif