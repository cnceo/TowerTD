#ifndef __DATACACHEGEAR_R_
#define __DATACACHEGEAR_R_

#include "cocos2d.h"
#include "string.h"
using namespace cocos2d;

enum
{
	DONTHAVE,
    HAVE,
	NO,
	YES,
	WEAPON,
	ARMOUR,
	SHOE 
};

class DataCacheGear : public Ref
{
private:
	char * _name;
	char * _picture;
public:
	//������ݿ��е�װ��������
	//װ����ID
	CC_SYNTHESIZE(int, _id, Id);
	//װ�����˺�ֵ
	CC_SYNTHESIZE(int, _attickValue, AttickValue);
	//װ���ķ�����
	CC_SYNTHESIZE(double, _defenseValue, DefenseValue);
	//װ��������
	CC_SYNTHESIZE(double, _aglityValue, AglityValue);
	//װ��������
	CC_SYNTHESIZE(int, _gearType, GearType);
	//װ���ĵȼ�
	CC_SYNTHESIZE(int, _quality, Quality);
	//װ����һ�����Եļӳ�
	CC_SYNTHESIZE(double, _additionValue, AdditionValue);
	//װ�������ĵ�sp
	CC_SYNTHESIZE(int, _gearUserSp, GearUserSp);
	//Ӣ���Ƿ�ӵ��
	CC_SYNTHESIZE(int, _heroHave, HeroHave);
	//Ӣ���Ƿ����
	CC_SYNTHESIZE(int, _heroAdorn, HeroAdorn);
	//Ӣ��ӵ�е�����
	CC_SYNTHESIZE(int, _haveNumber, HaveNumber);
	//��ȡװ��������
	void setName(char * name)
	{
	    _name = new char();
		strcpy(_name,name);
	}
	char * getName()
	{
	   return _name;
	}
	//��ȡװ����ͼƬ����
	void setPictureName(char * name)
	{
		_picture = new char();
		strcpy(_picture,name);
	}
	char * getPictureName()
	{
		return _picture;
	}
	virtual bool init();
	CREATE_FUNC(DataCacheGear);
	DataCacheGear(){}
	~DataCacheGear()
	{
	    delete [] _name;
		delete [] _picture;
	}
};

#endif