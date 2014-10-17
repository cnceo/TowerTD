#ifndef  __HelthDataAI_H
#define  __HelthDataAI_H
#include "cocos2d.h"

enum DataLastDirection{        //ö��
	DATAUPLAST = 1,
	DATADOWNLAST = 2,
	DATALEFTLAST = 3,
	DATARIGHTLAST = 4,
};
class hHalthData;
using namespace cocos2d;
class HealthDataAI :public Node{
public:
	//AI���init����
	virtual bool init(HealthData* healthData,float dt);
	//��дCreate����
	static HealthDataAI* create(HealthData* healthData,float dt);
	//�õ�����ĵ��˶���
	CC_SYNTHESIZE(HealthData*,healthData,HealthData);
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
	bool success;//��Ա���� :���˵��ƶ��Ƿ�ɹ�
	HealthDataAI();
	~HealthDataAI();
};
#endif
