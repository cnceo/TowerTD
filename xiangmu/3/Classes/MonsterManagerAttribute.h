#ifndef __MONSTERMANAGERATTRIBUTE_H_
#define __MONSTERMANAGERATTRIBUTE_H_
#include "cocos2d.h"
#include "BasicAttribute.h"
#include "MonsterManagerAttributeConfType.h"
USING_NS_CC;
class MonsterManagerAttribute:public BasicAttribute{
public:
	static MonsterManagerAttribute* getInstance();
	//ɾ������
	static MonsterManagerAttribute* destoryInstance();
	virtual bool init(int wavesnum);
	int getWavesCount();
	//type:������ȡ�ĸ�����ֵ,defaultvalue:���������û�����ֵ,�򷵻�defaultvalue
	int getIntAttribute(int wavesnum,MonsterManagerAttributeConfigType type,int defaultvalue);
	//��ModelAttribute��getStringAttribute�ķ�װ,Ҫ���Ӳ�ѯ��type,��Ҫ���޸�ModelAttribute�еĺ���
	//type:������ȡ�ĸ�����ֵ,defaultvalue:���������û�����ֵ,�򷵻�defaultvalue
	std::string getStringAttribute(int wavesnum,MonsterManagerAttributeConfigType type,std::string defaultvalue);
protected:
	static MonsterManagerAttribute* monstermanagerattribute;
	int wavesnum;
};
#endif