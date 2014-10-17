#ifndef _SHAPEBULLET_H_
#define _SHAPEBULLET_H_

#include "BaseBullet.h"
#define M_PI       3.14159265358979323846
#define ANGLE 15
class ShapeBullet : public BaseBullet{
protected:
	int number;
	Vec2 toPosition;
	int spritenumber;
public:
	virtual bool init(float speed, Vec2 fromPosition, float attack, std::string fileName, Vec2 toPosition, int number);
	//����������������������Ҫ�����������ӵ������һ��������ÿ���ӵ��ľ���Ƕ�
	static ShapeBullet *create(float speed, Vec2 fromPosition, float attack, std::string fileName, Vec2 toPosition, int number);

};
#endif