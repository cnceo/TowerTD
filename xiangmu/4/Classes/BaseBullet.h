#ifndef __BASEBULLET__
#define __BASEBULLET__

#include "Conf.h"

#define M_PI       3.14159265358979323846
class BaseBullet : public cocos2d::Sprite
{
protected:
	int propert;
public:
	/**
	* ��ʼ��
	* @param  speed = �ٶ� position = λ�� 
	* @return �Ƿ�ɹ�
	*/
	
	virtual bool init(float speed, Vec2 fromPosition, float attack, std::string fileName,int bulletSpecies,int pro);
	//�������
	CC_SYNTHESIZE(bool,_isDie,Die);
	CC_SYNTHESIZE(int,_attack,Attack);
	CC_SYNTHESIZE(float,_speed,Speed);
	//CC_SYNTHESIZE(Vec2, position,Position);
	BaseBullet():_isDie(false){}
	//��������
	virtual void die();

	virtual void onEnter();
	
};

#endif