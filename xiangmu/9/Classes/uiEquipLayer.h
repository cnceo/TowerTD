#ifndef  __UIEQUIPLAYER_H
#define  __UIEQUIPLAYER_H

#include "cocos2d.h"
#include "DataGeares.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio;
using namespace ui;

class uiEquipLayer :public Layer
{
private:
	//����������
	void weaponLayer();
	//����sp��ʾ
	void weaponSp();
	void weaponAttackShow(DataCacheGear * dataCacheGear, Text * label_attack1,Text * label_grade1);
	//�·�������
	void armourLayer();
	void armourSp();
	void armourDefenceShow(DataCacheGear * dataCacheGear, Text * label_attack1,Text * label_grade1);
	//Ь�ӹ�����
	void shoeLayer();
	void shoeSp();
	void shoeDefenceShow(DataCacheGear * dataCacheGear, Text * label_attack1,Text * label_grade1);
	//��ʾsp
	void spValueShow();
public:
	virtual bool init();
	CREATE_FUNC(uiEquipLayer);
	uiEquipLayer(){}
	~uiEquipLayer();
private:
	ImageView* image;
	ScrollView * scroll1;
	ScrollView * scroll2;
	ScrollView * scroll3;
	DataGeares * _dataGeares;
};

#endif