#ifndef __SKILLSHOWLAYER_H
#define __SKILLSHOWLAYER_H

#include "cocos2d.h"
using namespace cocos2d;
class SkillShowLayer:public Layer
{
private:
	Sprite * _skill1;
	Sprite * _skill2;
	Sprite * _skill3;
	int _skillType;
	int _width;
public:	
	static Scene * createScene();
	virtual bool init();
	CREATE_FUNC(SkillShowLayer);
	SkillShowLayer(){}
	~SkillShowLayer();
private:
	//����cd��ʵ��
	void skill1Progress(Sprite * sp,std::string name, float cdTime, int skillId);
	void skill2Progress(Sprite * sp,std::string name, float cdTime, int skillId);
	void skill3Progress();
	void skill3(Ref * obj);
	// �۲��ߺ���
	void skillObserver(Ref * ref);
	//������Ϣ
	void endSkill1Cd();
	//������Ϣ
	void endSkill2Cd();
	//������Ϣ
	void endSkill3Cd();
};

#endif