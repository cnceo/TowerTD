/************************************************************************/
/* 
	1. ����ש���    allBricks
	2. �����ӵ���    allBullets
	3. ���� ����     allEnemies
	4. ���еĵ���    allTools

*/
/************************************************************************/
#ifndef _ALLVECTORS_H
#define _ALLVECTORS_H
#include "cocos2d.h"
#include "EnemyBullet.h"
#include "HeroBullet.h"
#include "BaseTool.h"
#include "BaseEnemy.h"

using namespace cocos2d;

class AllVectors
{
private:
	AllVectors(){
		bg_music_isSelect = false;
		ef_music_isSelect = false;
	}		//���캯��
	AllVectors(const AllVectors * obj){}		//��������
	AllVectors operator=(const AllVectors * obj){return obj;}		//����������
protected:
	static AllVectors * instance;		//��������
	Vector<Sprite *> bricksVector;		//ש�鼯��
	Vector<HeroBullet *> heroBulletsVector;		//Ӣ���ӵ�����
	Vector<EnemyBullet *> enemyBulletsVector;		//�����ӵ�����
	Vector<BaseTool *> toolsVector;			//���߼���
	Vector<Sprite *> groundsVector;			//�ذ弯��
	Vector<BaseEnemy *> enemiesVector;		//

public:
	//��õ���
	static AllVectors * getInstance();
	//���ש�鼯��-------
	Vector<Sprite *> getBricksVector();
	//�򼯺���Ӷ���
	void addBrick(Sprite * brick);
	//�Ӽ���ɾ������
	void deleteBrick(Sprite * brick);
	//��ռ���
	void bricksVectorCleanUp();


	//��������ӵ�����-------
	Vector<HeroBullet *> getHeroBulletsVector();
	//�򼯺���Ӷ���
	void addHeroBullet(HeroBullet * bullet);
	//�Ӽ���ɾ������
	void deleteHeroBullet();
	//��ռ���
	void heroBulletsVectorClearUp();


	//��õ����ӵ�����--------
	Vector<EnemyBullet *> getEnemyBulletsVector();
	//�򼯺���Ӷ���
	void addEnemyBullet(EnemyBullet * bullet);
	//�Ӽ���ɾ������
	void deleteEnemyBullet();
	//��ռ���
	void enemyBulletsVectorClearUp();


	//��õ��߼���----------
	Vector<BaseTool *> getToolsVector();
	//�򼯺���Ӷ���
	void addTool(BaseTool * tool);
	//�Ӽ���ɾ������
	void deleteTool(BaseTool * tool);
	//��ռ���
	void toolsVectorCleanUp();


	//��õ��˼���----------
	Vector<BaseEnemy *> getEnemiesVector();
	//�򼯺���Ӷ���
	void addEnemy(BaseEnemy * enemy);
	//�Ӽ���ɾ������
	void deleteEnemy();
	//��ռ���
	void enemiesVectorCleanUp();


	//��õذ弯��----------
	Vector<Sprite *> getGroundVector();
	//�򼯺���Ӷ���
	void addGround(Sprite * ground);
	


	//���� ���ֺ���Ч�� ����

	bool bg_music_isSelect;
	bool ef_music_isSelect;

	bool getBgmusic();
	void setBgmusic(bool bg);
	bool getEfmusic();
	void setEfmusic(bool ef);



};
#endif