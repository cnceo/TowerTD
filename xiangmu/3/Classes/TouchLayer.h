#ifndef __TOUCHLAYER_H_
#define __TOUCHLAYER_H_
#include "cocos2d.h"
#include "Tower.h"
USING_NS_CC;
class TouchLayer:public Layer{
private:
	bool Pstate;//�Ƿ������þ���λ��
	void setPstate();
	void onEnter();
	Sprite *tmpsp;
	
	Vector<Sprite*> towerbutton;
	//��ʼ��������ť
	void initTowerButton();
	void createTower();
	//���÷�����ť�Ĳ�
	Layer* towerbuttonlayer;
	Vec2 beganPosition;
	Vec2 tiledPosition;//���ͼ��λ��
	//��ʽ������button
	Sprite* formatbutton;
	std::function<bool(int)> cutscore;

	//������ʱ�۷ֵĺ���
	bool spendMoney(int money);
	//ֱ���޸ĵ�ͼ�ϵ�GID(��Ƶ�����,�Ժ���˵��)
	void changeGID(Vec2 towerPosition);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
public:
	CREATE_FUNC(TouchLayer);
	virtual bool init();
	void setCutScore(std::function<bool(int)> cutscore);
public:
	 void setTouchStop(bool isStop);
};
#endif