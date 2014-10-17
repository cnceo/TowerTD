#ifndef __SHOWLAYER_H_
#define __SHOWLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class SuspendLayer;
class GameOverLayer;
class Role;

class ShowLayer : public Layer{
public:
	CREATE_FUNC(ShowLayer);
	//��ͣ��
	CC_SYNTHESIZE(SuspendLayer *, suLayer, M_suLayer);
	//������
	CC_SYNTHESIZE_READONLY(GameOverLayer *, gameOverLayer, M_gameOverLayer);
protected:
	//����Ա����suLayer��Ϊ��
	void setLayerNull(Ref * sender);
	//�����Ҳ�˫��������ʾ
	void addBostZone();
	//����˫�����ֱ�ʾ
	void addDoubleScoreIcon();
	//���Ӱ�����
	void addHelpLayerByOneGame();
	//���������
	void addTastLayer();
	//������ͣ��ť
	void addPauseIcon();
	//���Ӷ���ͼ��
	void addTopIcon();
	//��ӷ���ֵ������ֵ
	void addScoreLabel();
	//����ľ��
	void addTopbar();
	//���ӵ�ǰ����
	void increaseCurScore(float t);
	virtual bool init();
	//ע��֪ͨ������֪ͨ
	void addNotification();
	//���ӵ�ǰ����50
	void addCurScore(Ref * sender);
	//100��
	void addMoreCurScore(Ref * sender);
	//����˫������ʱ��
	void doubleScore(Ref * sender);
	//����˫������ʱ��
	void glodDoubleScore(Ref * sender);
	//������˫������
	void bostZoneDoubleScore(Ref * sender);
	//ȡ��������˫������
	void deleteBostZoneDoubleScore(Ref * sender);
	//����������
	void createGameOverLayer(Ref * sender);
	//˫������ʱ���ʱ
	void doubleScoreUpdate(float t);
	void onEnter();
	~ShowLayer();

protected:
	//˫�����ֱ�ʾ
	Sprite * douScore;
	//��Ч����
	int audioFlag;
	//��ǰ��������߷�Label
	Label * curScoreLabel;
	Label * maxScoreLabel;
	//��ǰ��������߷���
	int curScore;
	int maxScore;
	//��ǰ��������
	int timeScore;
	int fiftyScore;
	//˫�����ּ�ʱ
	int doubleScoreCount;
	Role *role;
	bool flag;
};

#endif // !__SHOWLAYER_H_
