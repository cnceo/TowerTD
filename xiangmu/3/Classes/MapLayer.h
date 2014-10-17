#ifndef __MAPLAYER_H_
#define __MAPLAYER_H_
#include "cocos2d.h"
#define  TILEDSIZE  64              //ͼ��ߴ�
#define  MAPPOSITION Vec2(0,0)    //��ͼ��λ��
#define  PIECENUM Vec2(10,15)        //ͼ�����
USING_NS_CC;
class MapLayer:public Layer{
public:
	CREATE_FUNC(MapLayer);
	virtual bool init();
	Vec2 convertTilesPositionToVisiblePosition(Vec2 pointoftiles);
	Vec2 setSPPositOfTiled(Vec2 pointofview);
	Vec2 convertVisiblePositionToTilesPosition(Vec2 pointofview);
	//�ܷ�ͨ��
	bool couldPass(Vec2 pointofworld);
	//�Ƿ�����
	bool hasTower(Vec2 pointofworld);
	//�����
	void changeGID(Vec2 towerPosition);
	//ɾ����
	void removeGID(Vec2 towerPosition);
	//�Ƿ��ڵ�ͼ��
	bool isInMap(Vec2 pointofworld);
	Point getPositionofTiles(Point pointofworld);
	Vec2 getMapSizeInPixel();
	Vec2 getMapPosition();
	Vec2 MonstEndPosition();//������λ��->����˺�
	//�������λ��
	std::vector<Vec2> enemyBurnPosition();
	CC_SYNTHESIZE_RETAIN(TMXTiledMap *,map,TiledMap);
	CC_SYNTHESIZE_RETAIN(TMXLayer*,background,Background);
protected:
	Size mapsize;
	Size tilessize;
	Size mapcontentsize;
	Vec2 mapposition;
	MapLayer(){
		map=nullptr;
		background=nullptr;
	}
	virtual~MapLayer(){
		CC_SAFE_RELEASE_NULL(map);
		CC_SAFE_RELEASE_NULL(background);
	}
};
#endif