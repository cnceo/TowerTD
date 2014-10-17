#ifndef __BASETOOLS__H
#define __BASETOOLS__H
#include "cocos2d.h"
#include "BaseSprite.h"
USING_NS_CC;

enum State
{
	Tool_protected			= 1,		//������
	Tool_doubleScore		= 1 << 1,	//˫������
	Tool_goldDoubleScore	= 1 << 2,	//����˫������
	Tool_bucket				= 1 << 3,	//ˮͰ
	Tool_band				= 1 << 4,	//������
	Tool_addBlood			= 1 << 5,	//Ѫ����Ѫ
	Tool_addBloodMost		= 1 << 6,	//Ѫ�μ�Ѫ
	Tool_addScore			= 1 << 7,	//����ʮ��
	Tool_addScoreMost		= 1 << 8	//��һ�ٷ�
};

class BaseTools : public BaseSprite
{
public:
	static BaseTools * create(std::string fileNameStr, int state, std::string m_name);
	virtual bool init(std::string fileNameStr, int state, std::string m_name);
	void removeBaseTool();
	void addPhysicsBody();
	CC_SYNTHESIZE_READONLY(int, m_state, M_state);
protected:
	
};

#endif