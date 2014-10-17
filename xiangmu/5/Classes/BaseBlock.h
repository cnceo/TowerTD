#ifndef _BASEBLOCK_H_
#define _BASEBLOCK_H_
#include "cocos2d.h"
#include "BaseSprite.h"
USING_NS_CC;

//class of base block �ϰ������
class BaseBlock : public BaseSprite
{
protected:
	virtual bool init(std::string fileNameStr, float attack, std::string name, Vec2 blockPos);
	//��Ӹ���
	virtual void addPhysicsBody();
	//����ǵ�����Ӷ���
	virtual void addKnifeAction();
	//��������������ж���
	virtual void addChainhookAction(Vec2 blockPos);
public:
	CC_SYNTHESIZE_READONLY(int, m_attack, M_attack);
	static BaseBlock * create(std::string fileNameStr, float attack, std::string name, Vec2 blockPos);
};

#endif // !_BASEBLOCK_H_
