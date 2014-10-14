#ifndef __UPDATELAYER_H
#define __UPDATELAYER_H
#include "cocos2d.h"
#include "BaseTower.h"
USING_NS_CC;

class UpdateLayer: public Layer
{  
	
public:
	virtual bool init( BaseTower *tower);
    static UpdateLayer*create(BaseTower *tower);
	//�ж��Ƿ���ʾ�˵���
	CC_SYNTHESIZE(bool ,isShowing,IsShowing);
	//����Ƿ���ڲ˵���
	void show();
	void unshow();
	//�õ���
	BaseTower * towers;
	//��������Ҫ��Ǯ
	int upGradeMoney;
	//����������Ǯ
	int eradicantMoney;
	//������ǩ
	Label * updateLabel;

};
#endif