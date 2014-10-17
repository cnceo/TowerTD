#ifndef __TOWERATTRIBUTE_H_
#define __TOWERATTRIBUTE_H_
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
#include "TowerAttributeConfType.h"
#include "BasicAttribute.h"
#include "MonsterAttributeConfType.h"
USING_NS_CC;
using namespace tinyxml2;
class TowerAttribute: public BasicAttribute{
public:
	//ȡ��Tower������ĵ���
	//towerid����id
	static TowerAttribute* getInstance(int towerid);
	//ɾ������
	static TowerAttribute* destoryInstance();
	//��id_map�в��������Ե�map
	virtual bool init(int towerid);
	//��ȡ��������
	int getTowersCount();
	//type:������ȡ�ĸ�����ֵ,defaultvalue:���������û�����ֵ,�򷵻�defaultvalue
	int getIntAttribute(TowerAttributeConfType type,int defaultvalue);
	//��ModelAttribute��getStringAttribute�ķ�װ,Ҫ���Ӳ�ѯ��type,��Ҫ���޸�ModelAttribute�еĺ���
	//type:������ȡ�ĸ�����ֵ,defaultvalue:���������û�����ֵ,�򷵻�defaultvalue
	std::string getStringAttribute(TowerAttributeConfType type,std::string defaultvalue);
protected:
	int towerid;
	std::map<std::string,int> tmp_attribute_map;
	static TowerAttribute* towerattribute;
	TowerAttribute(){
	}
};
#endif