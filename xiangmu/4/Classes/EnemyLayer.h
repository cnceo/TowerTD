#ifndef __ENEMYLAYER__
#define __ENEMYLAYER__

#include "cocos2d.h"
class BaseEnemy;
//�����ƶ��ٶ�
#define ENEMYSPEED 20
#define SMARTSPEED 50
class FirstBoss;

class EnemyLayer : public cocos2d::Layer
{
private:

	int Level;

	int isSkillsBomb;
	//������ͨ����
	void createCommon(int isSkillsBomb);
	//������Ӣ����
	void createElite(int isSkillsBomb);
	//��boss���ּ�ʱ
	int bossTime;
	FirstBoss *boss;
	static bool haveboss;

	//����ϵͳ����
	void upLevel(Ref *);
protected:
	
	//��������
	void createEnemy();
	//��ʱ֡�ص�����
	void addEnemy(float t);
	int contrlNum;
	cocos2d::Size vSize;
	virtual void onEnter();

	//������ͨ����
	void createCommon_BlueGlost(int r);
	//������Ӣ����
	void createElite_Shadow(int r);
	void restartTime(Ref *);
public:
	~EnemyLayer();
	virtual bool init();

	CREATE_FUNC(EnemyLayer);
};

#endif // __HELLOWORLD_SCENE_H__