#ifndef __MAINSCENE_H_
#define __MAINSCENE_H_
#include "MapLayer.h"
#include "GameLayer.h"
#include "cocos2d.h"
USING_NS_CC;
class MonsterManager;
class ForwardLayer;
class InjuredEffect;
class TouchLayer;
class GameLayer;
class MapLayer;
class BackgroundLayer;
class GameLayer;
class FileManager;
class BasicAttribute;
class MonsterAttribute;
class MonsterManagerAttribute;
class TowerAttribute;
class MainScene:public Scene{
public:
	static Scene* create(std::string filename,int chapternum);
	virtual bool init(std::string filename,int chapternum);
	MapLayer *getMapLayer();
	Layer * getGameLayer();
	//��ʼ����Ϸ,�첽������Դ
	void initGame();
	//�ɹ�����
	void win();
	//ʧ�ܽ���
	void lose();
	CC_SYNTHESIZE(std::string,filename,FileName);
	//��ǰ���йؿ�
	CC_SYNTHESIZE(int,chapternum,Chapternum);
private:
	void changeWinScene();
	void changeLoseScene();
	void initLayers();
	MonsterManager* monstermanager;
	ForwardLayer* forwardlayer;
	InjuredEffect* injuredlayer;
	TouchLayer* touchlayer;
	GameLayer* gamelayer;
	MapLayer* maplayer;
	BackgroundLayer* backgroundlayer;
	GameLayer* gameLayer;
	FileManager* filemanager;
	~MainScene();
};
#endif