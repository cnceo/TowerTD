#ifndef __LOGICLAYER_H
#define __LOGICLAYER_H
#include "cocos2d.h"
USING_NS_CC;
class LogicLayer:public Layer
{ 
	void TankTestBound();//˫��̹����ײ
	void BulletTestBound();
	void bulletEvsT(); //�о��ӵ��ͼ����ӵ���ײ
	void bulletvsBarrer();//�ӵ���ǽ
	void bulletVsEnemy();//�����ӵ��͵о�
	void bulletVsTank();//�з��ӵ�������
    void checkisDefeated();
	void boundingBox(Vec2 position);//�ӵ�����ײ������ͼ��ǽ�� ͬʱ�ĸ���
public:	
	virtual bool init();
	CREATE_FUNC(LogicLayer);
	
	void update(float);
};
#endif // !__LOGICLAYER_H
