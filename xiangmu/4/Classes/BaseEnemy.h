#ifndef __BASEENEMY__
#define __BASEENEMY__
#include "Conf.h"
class GameScene;

class BaseEnemy : public cocos2d::Sprite
{

private:
	//��ʼ�����Է���
	void initPro(float coefficient);

	//�Ƿ�Я������
	void isSkillsBomb(int sb);

	

protected:

	//�ӵ��ٶ�ϵ��
	float bulletCoefficient;

	int sb;

	GameScene* scene;

	//��������
	Sprite * sp;
	//��������
	CC_SYNTHESIZE(bool, enemyType, EnemyType);

	//��ͼ��С
	Size vSize;
	
	//���ж���
	virtual void enemyFly() = 0;

	//��������
	virtual ActionInterval * enemyDie() = 0;

	//���˶���
	virtual void  enemyHurt();

	//��������
	virtual void die();
	
	virtual void removeEnemyNode();

	//�����ӵ� ��ʱ֡�ص�
	virtual void addFire(float t);


public:
	//�������
	CC_SYNTHESIZE(bool, isDie, Die);
	
	//��ʼ����Я�����ߣ��ȼ�
	virtual bool initWithSpriteFrameName(std::string fileName, int sb, int level);

	virtual void onEnter();

	virtual void createBullet(std::string fileName);

	virtual void hurt(int attack);

	
	CC_SYNTHESIZE(int, _score, Score);
	CC_SYNTHESIZE(float, _enemySpeed, EnemySpeed);
	CC_SYNTHESIZE(float, _hp, Hp)
};

#endif // __HELLOWORLD_SCENE_H__