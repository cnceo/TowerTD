#ifndef __FORWARDLAYER_H_
#define __FORWARDLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class ForwardLayer:public Layer{
private:
	Label *label;
private:
	LabelTTF * m_pLabelLoading;
	LabelTTF * m_PlabelPerCent;
	//Ҫ���ص�����
	int m_nNumbers;
	//�����˵�����
	int m_NumberLoaded;
	ProgressTimer * loadProgress;
	~ForwardLayer();
public:
	CREATE_FUNC(ForwardLayer);
	virtual bool init();
public:
	//ÿ����һ���ļ� �ص�һ�� ����������
	//percentӦ��λ��(0,1)֮��;
	void loadingCallBack(float percent);
	//���� /�жϷ��Ƿ���Դ����� cutsorce��
	 bool cutScore(int sorce);
	//�ӷ�
	 void plusScore(int sorce);
	 //��ʼ����
	 CC_SYNTHESIZE(int,cursorce,curSorce);
	 void onEnter();
	 //��ȡ�Ʒ�Labelλ��
	 Vec2 getScoreLabelPosition();
protected:
//     int A;
// 	int sumA;
// 	int sumB;
// 	int B;
	int showsorce;
	void stateSelecterA();
	void stateSelecterB();
	void resetScoreA(float t);
	void resetScoreB(float t);
};
#endif