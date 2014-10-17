#ifndef __MODELATTRIBUTE_H_
#define __MODELATTRIBUTE_H_
#include "cocos2d.h"
#include "BasicAttribute.h"
#include "tinyxml2/tinyxml2.h"
USING_NS_CC;
using namespace tinyxml2;
enum ModelAttributeConfType
{
	Model_Sprite,
	Model_Runanimate,
	Model_Dieanimate
};
class ModelAttribute{
public:
	static ModelAttribute* getInstance(int modeid);
	
	std::string getStringAttribute(int type,std::string defaultvalue);

protected:
	virtual bool init(int modelid);
	virtual bool openXMLFIle(std::string filename);
	//����xml
	virtual void parseXML();
protected:
	static ModelAttribute* modelattribute;
	//ģ��id
	int modelid;
	//�������
	std::map<std::string,std::string> tmp_attribute_map;
	tinyxml2::XMLDocument *xmldocument;
	
	//����xml��,һ������id��Ӧһ����ֵ��
	std::map<int,std::map<std::string,std::string> > *id_map;
	ModelAttribute(){
		xmldocument=nullptr;
		id_map=new std::map<int,std::map<std::string,std::string> >();
	}
	virtual ~ModelAttribute(){

	}
	ModelAttribute(const ModelAttribute* modelattribute){

	}
	ModelAttribute* operator=(const ModelAttribute* modelattribute){

	}
};
#endif