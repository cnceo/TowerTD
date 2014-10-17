#ifndef  __EnemyAI_H
#define  __EnemyAI_H
#include "cocos2d.h"
class Enemy;
enum LastDirection{        //ö��
	UPLAST = 1,
	DOWNLAST = 2,
	LEFTLAST = 3,
	RIGHTLAST = 4,
};
class Enemy;
using namespace cocos2d;
class EnemyAI :public Node{
public:
	//AI���init����
	virtual bool init(Enemy* enemy,float dt);
	//��дCreate����
	static EnemyAI* create(Enemy* enemy,float dt);
	//�õ�����ĵ��˶���
	CC_SYNTHESIZE(Enemy*,enemy,Enemy);
	//������һ���˶��ķ���
	CC_SYNTHESIZE(int,dir,LastDirection);
	//�ƶ�ʱ��
	CC_SYNTHESIZE(float,steptime,StepTime);
	//��Ա����success�ĸ�ֵ
	void setMoveSuccess(bool success){
		this->success=success;
	}
	//�Ƿ��ƶ��ɹ�
	bool isMoveSuccess(){
		return success;
	}
	//�õ���ǰ�ƶ�������ƶ�����
	virtual void getDirection(float dt);
	//��һ���ƶ�λ�ú���һ���ƶ�����
	void nextStepandOldDirection(float dt);
	//��һ���ƶ�λ�ú��µ��ƶ�����
	void nextStepandNewDirection(float dt);
	//���˵��Զ�����

protected:
	void checkfire(float t);
	bool success;//��Ա���� :���˵��ƶ��Ƿ�ɹ�
	EnemyAI();
	~EnemyAI();
};
#endif
