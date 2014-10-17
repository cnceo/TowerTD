#ifndef __SUSPENDLAYER_H_
#define __SUSPENDLAYER_H_
#include "cocos2d.h"
USING_NS_CC;

class SuspendLayer : public Layer{
public:
	CREATE_FUNC(SuspendLayer);
protected:
	//��Ӿ��飬����Ϊ��ͼƬ�ļ�����λ�ã����ű���
	void addSprite(std::string fileName, Vec2 spritePos, float scaleValue);
	//��Ӱ�ť������Ϊ����ʾͼƬ��ѡ��ͼƬ��λ�ã��Ƿ��ǿ��أ��ص�����
	void addMenu(std::string norName, std::string selName, Vec2 itemPos, bool toggleFlag, std::function<void (Ref *)> menuCallback);
	//�ص���ʼ���水ť�ص�����
	void toStartScene(Ref * sender);
	//ת���������水ť�ص�����
	void toHelpLayer(Ref * sender);
	//������Ϸ��ť�ص�����
	void backToGame(Ref * sender);
	virtual bool init();
	//���touch�¼���������touch�¼�
	void addTouch();

protected:
	int audioFlag;
};

#endif // !__SUSPENDLAYER_H_
