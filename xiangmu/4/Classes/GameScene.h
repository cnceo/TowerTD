#pragma once
#include "Conf.h"
#include "HeroesLayer.h"
#include "EnemyLayer.h"
#include "ScoreLayer.h"
class GameScene :public Scene
{
protected:
	virtual void onEnter();
public:
	virtual bool init();
	CREATE_FUNC(GameScene);

	//��ȡ������
	HeroesLayer* getHeroLayer();
	//��ȡ�л���
	EnemyLayer* getEnemyLayer();
	//��ȡ��ײ��
	Layer* getColideLayer();
	//��ȡ������
	ScoreLayer *getScoreLayer();

};