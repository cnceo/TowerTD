#ifndef __SKILLRELEASECONTAINER_R_
#define __SKILLRELEASECONTAINER_R_

#include "cocos2d.h"
#include "SkillBase.h"
using namespace cocos2d;

class SkillReleaseContainer
{
private:
	SkillReleaseContainer(){}
	SkillReleaseContainer(const SkillReleaseContainer & skillReleaseContainer){}
	SkillReleaseContainer operator + (const SkillReleaseContainer & skillReleaseContainer)
	{
	    return skillReleaseContainer;
	}
	static SkillReleaseContainer * instance;
public:
	static SkillReleaseContainer * getInstance();
	//����������Ӽ���
	void addSkillRelease(SkillBase * skill);
	//��������м��ܱ��Ϊtrue�ļ���
	void removeSkill();
	//������������м���
	void clearContainer();
	CC_SYNTHESIZE_PASS_BY_REF(Vector<SkillBase *>, _skillCreate, SkillCreate);
};

#endif