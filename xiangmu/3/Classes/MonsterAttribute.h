/*
��XML�ļ��ж�ȡ�������Ե���,���ڳ�ʼ������.
�����������MonsterAttributeConfType.h�в���
*/

#ifndef __MONSTERATTRIBUTE_H_
#define __MONSTERATTRIBUTE_H_
#include "cocos2d.h"
#include "BasicAttribute.h"
#include "tinyxml2/tinyxml2.h"
#include "MonsterAttributeConfType.h"
#include "ModelAttribute.h"
USING_NS_CC;
class MonsterAttribute:public BasicAttribute{
public:
	//ȡ��Monster������ĵ���
	//monsterid�ǹ���id
	static MonsterAttribute* getInstance(int monsterid);
	//ɾ������
	static MonsterAttribute* destoryInstance();
	//��ȡ��Ӧ������ֵ
	//type:������ȡ�ĸ�����ֵ,defaultvalue:���������û�����ֵ,�򷵻�defaultvalue
	int getIntAttribute(MonsterAttributeConfType type,int defaultvalue);
	//��ModelAttribute��getStringAttribute�ķ�װ,Ҫ���Ӳ�ѯ��type,��Ҫ���޸�ModelAttribute�еĺ���
	//type:������ȡ�ĸ�����ֵ,defaultvalue:���������û�����ֵ,�򷵻�defaultvalue
	std::string getStringAttribute(MonsterAttributeConfType type,std::string defaultvalue);
protected:
	//��id_map�в��ҹ������Ե�map
	virtual bool init(int monsterid);
	MonsterAttribute(){
	}
protected:
	int monsterid;
	static MonsterAttribute* monsterattribute;

};
#endif