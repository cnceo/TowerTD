#ifndef __HEROESLAYER__
#define __HEROESLAYER__

#include "cocos2d.h"
#include "PetWolf.h"
class BaseHeroes;
class BasePet;

USING_NS_CC;

class HeroesLayer : public cocos2d::Layer
{
private:
	CC_SYNTHESIZE(bool, may, May);
	CC_SYNTHESIZE(std::string,_heroFileName,HeroFileName);
	PetWolf* pet;
	BaseHeroes * hero;
	//��������
	void createHeroes(std::string fileName);
	void createPet();
	//������
	Vec2 Vbegan_1;
	Vec2 Vbegan_2;
	Vec2 Vmin;
	Vec2 Vend;
	int flag;
	float xy_cut;
	void startTime(float t);
	virtual void onEnter();
public:

    int touchTime;
	
    virtual bool init(std::string fileName);          //init()����ҲҪ�Ӳ���

	static HeroesLayer * create(std::string fileName); //��дcreat����

//	~HeroesLayer();

	void setHeroDie();
	void setTouchesStop(bool);

};

#endif // __HELLOWORLD_SCENE_H__
