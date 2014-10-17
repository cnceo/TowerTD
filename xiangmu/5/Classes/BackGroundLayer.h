#ifndef __BACKGROUNDLAYER_H_
#define __BACKGROUNDLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class MapLayer;

class BackgroundLayer : public Layer{

public:
	static BackgroundLayer * create();
protected:
	//Զɽ
	Sprite * farMountain_1;
	Sprite * farMountain_2;
	//Զ��Ұ
	Sprite * farField_1;
	Sprite * farField_2;
	//��
	Sprite * dense_1;
	Sprite * dense_2;
	Sprite * dense_3;
	//����Ұ
	Sprite * nearField_1;
	Sprite * nearField_2;
	Sprite * nearField_3;
	//·
	Sprite * road_1;
	Sprite * road_2;
	Sprite * road_3;
	//��
	Sprite * grass_1;
	Sprite * grass_2;
	//��ͼ
	MapLayer * map1;
	MapLayer * map2;
	Vector<Layer *> maps;
protected:
	virtual bool init();
	//����Զɽ����
	void addFarMountain();
	//����Զ��Ұ
	void addFarField();
	//������
	void addDense();
	//���ؽ���Ұ
	void addNearField();
	//����·
	void addRoad();
	//���ع�ľ�����߸˵�����
	void addSundry();
	//���ز�
	void addGrass();
	//Զɽ�ƶ�
	void farMountainMove(float t);
	//��Ұ�ƶ�
	void fieldMove(float t);
	//���ƶ�
	void denseMove(float t);
	//·�ƶ�
	void roadMove(float t);
	//���ƶ�
	void grassMove(float t);
	//���ص�ͼ
	void addMap();
	//��ͼ�ƶ�
	void mapMove(float t);
	//������ͼ
	void changeMap();
};

#endif // !__BACKGROUNDLAYER_H_
