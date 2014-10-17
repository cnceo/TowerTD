#ifndef  _SHAPEFUNC_H
#define  _SHAPEFUNC_H
#include "ShapeBullet.h"
class shapeFunc : public ShapeBullet {
	Vec2 vfromPostion;
public:
	struct Increment
	{
		float incrementX;
		float incrementY;
		Increment(float incrementX, float incrementY)
		{
			this->incrementX = incrementX;
			this->incrementY = incrementY;
		}
	};
	std::vector<Increment>own;//�洢ÿ��������߶γ���

	//void sprite_create(float speed, Vec2 fromPosition, Vec2 toPosition, int number);
	virtual void update(float t);
	//����ÿ������������λ��
	void halfcicle_bullet(float speed, Vec2 fromPosition, Vec2 toPosition, int number);
	virtual bool init(float speed, Vec2 fromPosition, float attack, std::string fileName, Vec2 toPosition, int number);
	//����������������������Ҫ�����������ӵ������һ��������ÿ���ӵ��ľ���Ƕ�
	static shapeFunc *create(float speed, Vec2 fromPosition, float attack, std::string fileName, Vec2 toPosition, int number);

	virtual void onEnter();
};
#endif