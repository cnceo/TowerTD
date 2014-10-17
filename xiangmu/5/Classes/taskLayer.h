#ifndef __TASKLAYER__H
#define __TASKLAYER__H
#include "cocos2d.h"
USING_NS_CC;

class taskLayer : public Layer
{
public:
	CREATE_FUNC(taskLayer);

protected:
	virtual bool init();
	void onEnter();

	//����Label��ʾ,�����ƿ�
	void changeDisplay(std::string name);
	
	//���������Ҫ��������
	void addTool();

	//���������Լ�Label����ͷ
	void addSprite();

	//������յ�֪ͨ
	void testMessage(Ref * message);

	//��ʾ����
	void showTask();

	//����Label��ʾ
	void setLabel();

	virtual ~taskLayer();
	

private:
	int audioFlag;
	//�����
	Sprite * conditionIcon_1;
	Sprite * conditionIcon_2;
	Sprite * conditionIcon_3;

	//������µ�Label
	Label * conditionLabel_1;
	Label * conditionLabel_2;
	Label * conditionLabel_3;

	//������Ҫ�����ĵ���
	Sprite * taskTool;

	int count;

	//�������õ�����������
	ValueMap allCondition; 

	//�����
	Vector<Sprite *> conditionIcons;

	//�������辫��ļ���
	Vector<Sprite *> taskSprites;

	//����ʾ��3��Label
	Vector<Label *> labels;
};

#endif