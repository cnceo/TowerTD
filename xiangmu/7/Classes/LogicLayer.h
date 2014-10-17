#pragma once

#include "cocos2d.h"

using namespace cocos2d;

class LogicLayer:public Layer{

public: 
	virtual bool init();
	CREATE_FUNC(LogicLayer);

	//Ӣ�۵��ӵ��� С����ײ
	void heroBulletPKenemy(float t);


	//Ӣ�ۺ͵��ߵ���ײ
	void heroPKtool(float t);

	//ɾ�����е��ӵ�
	void deleteAllObject();

	void onEnter();

	//�����صĵ��������� ������ת����һ��
	void turnToNextScene(float t);

	//���ǵ��ӵ�����˵��ӵ�
	void heroBulletsPKenemysBullets(float t);

	void heroPKenemyBullets(float t);

	void update(float t);


};