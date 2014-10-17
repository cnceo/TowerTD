#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;
class Role;

class RoleLayer : public Layer{
public:
	CREATE_FUNC(RoleLayer);
	Role * getRole();
protected:
	//��Ч����
	int audioFlag;
	Role * role;
	//��Ѫ����ʾ��ʾ
	Sprite * lowBloodWarning;
	//������
	LoadingBar * m_hpLoading;
	//������Ч����ֵ
	int soundId;
protected:
	//�ı�Ѫ������
	void changeHpLoadingBar(float t);
	//����Ѫ��
	void addHpLoadingBar();
	virtual bool init();
};