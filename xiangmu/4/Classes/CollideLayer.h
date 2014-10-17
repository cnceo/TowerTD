#ifndef __COLLIDELAYER_H_
#define __COLLIDELAYER_H_

#include "Conf.h"
class GameScene;
class HeroesBullets;
class Enemys;
class BaseBullet;
class BaseEnemy;
class EnemyBullets;
class BaseHeroes;
class Tools;
class CollideLayer : public cocos2d::Layer
{
private:
	//����_��Ӣ����ײ
	//void hero_strengthen
	//������ͨ����ײ
	void heroesBulletCollideQuick(HeroesBullets* hbs, Enemys* es);
	void bulletType(BaseBullet* bb);
	int level;
protected:
	//���˺����ǵ���ײ
	void heroes_Enemy_Collide(Enemys* es, BaseHeroes* hero);
	//�����ӵ������ǵ���ײ
	void heroes_EnemyBullet_Collide(EnemyBullets* ebs, BaseHeroes* hero);
	//���Ǻ͵��ߵ���ײ
	void heroes_Tool_Collide(Tools* tool, BaseHeroes* hero);
	//ɾ���ӵ�OR����
	void removeAllObj(HeroesBullets* hbs, EnemyBullets* ebs, Enemys* es, Tools* tool);

	virtual void update(float f);
public:


	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CollideLayer);
};

#endif // __HELLOWORLD_SCENE_H__