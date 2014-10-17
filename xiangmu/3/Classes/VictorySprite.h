#ifndef __VictorSprite_H
#define __VictorSprite_H
#include "cocos2d.h"
USING_NS_CC;
class VirctoSprite :public Sprite{
public:
	virtual bool init(int hp,int needfile,float selfrecoverspeed);
	static VirctoSprite*create(int hp,int needfile,float selfrecoverspeed=0.5);
	CC_SYNTHESIZE(int,fullhp,Fullhp);//��Ѫ��
	CC_SYNTHESIZE(int,curhp,Curhp);//��ǰѪ��
	CC_SYNTHESIZE(int,receivedfile,ReceivedFile);//���ܵ����ļ�����
	CC_SYNTHESIZE(int,needfile,Needfile);//��Ҫ�����ļ����ʤ������
	CC_SYNTHESIZE(float,selfrecoverspeed,SelfRecoverSpeed);
	virtual void onEnter();
	//�����ļ�
	void increaseprogress();
	//�ܵ��˺�
	int hurt(int attackValue);
	void setProgressFunc(std::function<void(float)> gameprogress);
	//��ѪѪ��,��ǰѪ��
	void setHurtEffectFunc(std::function<void(int fullhp,int curhp)> hurteffect);
	//ʧ�ܵ��ú���
	void setLoseFunc(std::function<void()>losefunc);
	//�ɹ����ú���
	void setWinFunc(std::function<void()>winfunc);
	virtual void update(float t);
protected:
	//�Զ���Ѫ
	void selfRecover(float dt);
	std::function<void(float)> gameprogress;//�������������ص�����������������
	std::function<void(int,int)> hurteffect;
	std::function<void()> losefunc;
	std::function<void()>winfunc;
	Animate*normalAni;
	Animate*hurtAni;
	bool getprogressfuncbind;//�����Ƿ�󶨳ɹ�
	
	VirctoSprite(){
		curhp = 0;
		fullhp = 0;
		needfile =0;
		getprogressfuncbind= false;
	}
};



#endif  