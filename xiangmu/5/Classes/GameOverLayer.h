#ifndef _GAMEOVERLAYER_H_
#define _GAMEOVERLAYER_H_
#include "cocos2d.h"
USING_NS_CC;

class GameOverLayer : public Layer
{
protected:
	//��Ӿ��飬����Ϊ��ͼƬ�ļ�����λ�ã����ű���
	void addSprite(std::string fileName, Vec2 spritePos, float scaleValue);
	//��Ӱ�ť������Ϊ����ʾͼƬ��ѡ��ͼƬ��λ�ã��Ƿ��ǿ��أ��ص�����
	void addMenu(std::string norName, std::string selName, Vec2 itemPos, bool toggleFlag, std::function<void(Ref *)> menuCallback);
	//�ص���ʼ���水ť�ص�����
	void toStartScene(Ref * sender);
	//����һ�ΰ�ť�Ļص�����
	void onceGame(Ref * sender);
	virtual bool init();
protected:
	//�ж���Ч�Ŀ���
	int audioFlag;
public:
	//���ӷ�����ʾ
	void addScoreLabel(int curScore, int maxScore);
	CREATE_FUNC(GameOverLayer);
};

#endif // !_GAMEOVERLAYER_H_
