/************************************************************************/
/* 
	��������
	����λ��
	dieRunAnimation()��������
	runAnimation()���ж���

	��дcreate ����
	init

*/
/************************************************************************/
#ifndef __BASETOOL_H_
#define __BASETOOL_H_

#include "cocos2d.h"
#include "RoleAnimate.h"

using namespace cocos2d;

typedef enum 
{
	ADDSCORE = 1,				//����
	ADDBLOOD,				//Ѫ��
	ADDRANGE,				//���
	ADDATTACK,				//������
	ADDSPEED				//�ٶ�
}ToolsType;

class BaseTool:public Sprite{

protected:
	//��������
	CC_SYNTHESIZE(ToolsType,m_type,M_type);
	CC_SYNTHESIZE(int,m_score,M_score);
public:
	
	virtual bool initWithSpriteFrameName(Vec2 position);
	static BaseTool *create(Vec2 position);
	//void runAnimation(std ::string fileName);			//���ж���
	void remove();				//�Ƴ�����

};


#endif
