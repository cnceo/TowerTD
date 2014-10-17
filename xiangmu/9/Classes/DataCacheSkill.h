#ifndef __DATACAHESKILL_R_
#define __DATACAHESKILL_R_

#include "cocos2d.h"
#include "string.h"
using namespace cocos2d;

class DataCacheSkill : public Ref
{
public:
	//������ݿ��еļ��ܵ�����
	//���ܵ�ID
	CC_SYNTHESIZE(int, _id, Id);
	//���ܵ��˺�ֵ
	CC_SYNTHESIZE(int, _attickValue, AttickValue);
	//���ܵĺ�ħ��
	CC_SYNTHESIZE(int, _consumeMp, ConsumeMp);
	//�����Ƿ����
	CC_SYNTHESIZE(int, _isShow, IsShow);
	//���ܵĵȼ�
	CC_SYNTHESIZE(int, _skillGrade, SkillGrade);
	//������һ���ļӳ�
	CC_SYNTHESIZE(double, _skillAddition, SkillAddition);
	//�������ĵ�sp
	CC_SYNTHESIZE(int, _skillUserSp, SkillUserSp);
	virtual bool init();
	CREATE_FUNC(DataCacheSkill);
	DataCacheSkill(){}
	~DataCacheSkill(){}
};

#endif