#ifndef __BASEHEROES__
#define __BASEHEROES__

#include "Conf.h"


class BaseHeroes : public cocos2d::Sprite
{
protected:
	CC_SYNTHESIZE(bool, isProtect, IsProtect);
	CC_SYNTHESIZE(std::string,_fileName,FileName);

	ActionInterval * aniFly;

	virtual void fly() = 0;

	Vec2 position;
	//�����ӵ�
	void addFire(float t);
	//���ûص������ӵ�
	virtual void onEnter();
	//��������
	virtual void die() = 0;
	//���˺�����
	virtual ActionInterval * hurtAnimate() = 0;

	virtual ActionInterval * flyAnimate() = 0;

	virtual void protect();
public:
	//��ʼ������
	virtual bool initWithSpriteFrameName(std::string fileName);
	//�����ӵ��ȼ�
	CC_SYNTHESIZE(float, _bulletLevel,BulletLevel);
	//�����ӵ��Ƿ��������
	CC_SYNTHESIZE(bool,_isAddFire,IsAddFire);
	//���˺�����
	virtual void hurt();

	Rect getBox() const;
};

#endif