#ifndef __COLLIDEMANAGE_R_
#define __COLLIDEMANAGE_R_

#include "cocos2d.h"
#include "SkillReleaseContainer.h"
#include "Monsters.h"
#include "HeroBase.h"
#include "BoundingBox.h"
using namespace cocos2d;


class CollideManage : public Layer
{
private:
	SkillReleaseContainer * _skillReleaseContainer;
	Monsters* _monsterVector;
	HeroBase * _hero;
	BoundingBox * _boundingBox;
	int _skillTime;
public:
    CollideManage():_skillTime(0){}
	virtual bool init();
	CREATE_FUNC(CollideManage);
private:
	//������ײ�Ĺ���
	void manageContainer();
    //�����ײ���Ƿ���������еĲ���Ԫ��
	void containerUpdate(float t);
	//ɾ�������ͷ������в��õ�Ԫ��
	void skillReleaseContainerManger();
	//ɾ�����������в��õ�Ԫ��
	void monsterContainerManger();
	void onEnter();
	void heroAttackAndMonsterBounding();// �˴����͹������
	void heroSkillBounding();
};

#endif