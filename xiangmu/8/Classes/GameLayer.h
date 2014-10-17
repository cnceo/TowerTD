#pragma once

#include "AppMacro.h"
#include "BaseLayer.h"

#define BG_MOVE_SPEED 60

class MainPlane;

class GameLayer : public BaseLayer{
protected:
	Sprite *m_bg1;

	Sprite *m_bg2;

	float m_bjHight;

	MainPlane *m_mainPlane;

	virtual bool init();
public:
	CREATE_FUNC(GameLayer);

	//��ʼ��Ϸ
	void start();

	// ��ͣ
	void stop();

	//���ú���
	void reset();
private:
	/* ��ʼ�������� */
	void startProp();

	void startMainPlane();

	void startEnemy();

	void startBg();

	/* ���� */
	void endProp();

	void endMainPlane();

	void endEnemy();

	void endBg();

	void initMainPlane();

	void initBg();

	/* �������� */
	void update(float t);

	/* �������ߵĻص����� */
	void newProp(float t);

	/* �����л��Ļص����� */
	void newEnemy(float t);
};