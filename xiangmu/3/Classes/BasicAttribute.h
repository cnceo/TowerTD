/**

* ������BasicAttribute

* ���ߣ��´�

* ���ڣ�

* ���� : ����xml,��xml��¼����Ϊmap,���������д�map�ж�ȡ����
			���Ҫ��xml�ļ�����������ֶ�,��Ҫ��parseXML()�������getXXXAttribute
			��������Ӧ�Ľ�������Ҵ��롣

**/ 
#ifndef __BASICATTRIBUTE_H_
#define __BASICATTRIBUTE_H_
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
USING_NS_CC;
using namespace tinyxml2;
class BasicAttribute{
public:
	//���õ�ǰ�ؿ���Ҫ������xml�ļ�
	static void setXmlFilename(std::string xmlfilename);

	virtual void reset(){
		id_intmap->clear();
		id_stringmap->clear();
	}
protected:
	static bool openXMLFIle(std::string filename);
	//����xml
	virtual void parseXML(std::string elementname);
	
protected:
	static std::string xmlfilename;
	static tinyxml2::XMLDocument *xmldocument;
	//���α������
	std::map<std::string,int> tmp_attribute_intmap;
	//����xml��,һ������id��Ӧһ����ֵ��
	std::map<int,std::map<std::string,int> > *id_intmap;
	//string�������
	std::map<std::string,std::string> tmp_attribute_stringmap;
	std::map<int,std::map<std::string,std::string> > *id_stringmap;

	BasicAttribute(){
		xmldocument=nullptr;
		id_intmap=new std::map<int,std::map<std::string,int> >();
		id_stringmap=new std::map<int,std::map<std::string,std::string> >();
	}
	virtual~BasicAttribute(){
		CC_SAFE_DELETE(id_intmap);
		CC_SAFE_DELETE(id_stringmap);
		CC_SAFE_DELETE(xmldocument);
	}
};
#endif