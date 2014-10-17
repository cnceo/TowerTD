#ifndef __MONSTERDIEEFFECT_H_
#define __MONSTERDIEEFFECT_H_
#include "cocos2d.h"
USING_NS_CC;
class MonsterDieEffect:public Sprite{
public:
	//����Ч��д�ɹ̶���,�������Ҫ���޸�
	//������������Ч��,һ��0һ��1
	static MonsterDieEffect* create(Vec2 appearpoint,Vec2 disappearpoint,std::string effectfile1 = "monsterdieparticle_0.plist",std::string effectfile2 = "monsterdieparticle_1.plist");
	virtual bool init(Vec2 appearpoint,Vec2 disappearpoint,std::string effectfile1,std::string effectfile2);
	
protected:
	void autoRemoveSelf(float dt);
};
#endif