/************************************************************************/
/* 
		addEnemy����   ��С��
*/
/************************************************************************/

#ifndef _ENEMYLAYER_H
#define _ENEMYLAYER_H
#include "cocos2d.h"
using namespace cocos2d;


class EnemyLayer : public Layer
{
public:
	Sprite * roll;
	virtual bool init();
	CREATE_FUNC(EnemyLayer);
	static Scene *createScene();
	void addEnemy(float t);		//����������ĺ���

	void addRoll(Vec2 position);

	//��Ա����
	Vec2 m_pos;
	int m_speed;
	int m_type;
	int m_AI;
	Size m_body;
	std::string m_name;

	void add(Vec2 pos,int speed,int type,Size body,std::string name, int AI);


	//��ʾ��һ�� ��������

	Label *m_totleGuan;
	Label *m_curGuna;


	Label *time_label;	//��ʾʱ��
	int m_time;			//����ʱ������ʱ
	void addTime(float t);

	void resetLabel(float t);
	void addLabel(float t);

	void reload();
	Label *getLabel();


	virtual void update(float t);
	CC_SYNTHESIZE(float,rolltime,RollTime);
};


#endif