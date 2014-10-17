#ifndef __BACKGROUNDLAYER_H__
#define __BACKGROUNDLAYER_H__

#include "cocos2d.h"
#include "T_BackgroudLayer.h"
USING_NS_CC;

class BackgroundLayer:public Layer
{
private:
	virtual bool init(std::string filename);
	//��ȡ������XML�ļ�
	void testXML(std::string filename);
	//�������ƶ�
	void backgroundMoveRight(Ref * obj);
	void backgroundMoveLeft(Ref * obj);
	void baclgroundMoveLeftUpdate(float t);
	void baclgroundMoveRightUpdate(float t);
	//����ֹͣ�ƶ�
	void stopBackgroundMove(Ref * obj);
public:
	static BackgroundLayer * create(std::string filename);
	BackgroundLayer(){}
	~BackgroundLayer();
private:
	Sprite * _background;
};

#endif