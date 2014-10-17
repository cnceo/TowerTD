#ifndef __SKILLES_R_
#define __SKILLES_R_

#include "cocos2d.h"
#include "DataCacheSkill.h"
using namespace cocos2d;

class Skilles
{
private:
	static Skilles * instance;
public:
	static Skilles * getInstance();
	//��Ӽ���������
	void addSkillRef(DataCacheSkill * skill);
	//��ż������ݵ�����
	CC_SYNTHESIZE_PASS_BY_REF(Vector<DataCacheSkill *>, _skilles,Skilles);
private:
	Skilles(){}
	Skilles(const Skilles & skilles){}
	Skilles operator + (const Skilles & skilles)
	{
		return skilles;
	}
	//��������е�����Ԫ��
	void clearSkilles();
};

#endif