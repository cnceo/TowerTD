#ifndef __DATAXML__H
#define __DATAXML__H
#include "cocos2d.h"
#include <tinyxml2/tinyxml2.h>
USING_NS_CC;

//���ļ� ��xmlԴ�ļ�������дĿ¼-------������Դ�ļ�����Ŀ���ļ���
int fileCopy(const char * srcFileName, const char * desFileName);

class DataXML
{
public:
	static DataXML * getInstence();

	//��ó�ʼ����
	int getInitialValue(std::string name);

	//�õ�����
	ValueMap getTask();

	//�õ�����ͼƬ��
	std::string getPictureName(std::string conditionName);
	
	//�ﵽ��ǰ��Ҫ�����ĵ���
	ValueMap getCurTool();

	//�õ������������������ǰ����
	int getCurNumber(std::string name);

	//��������޸�isfinish,����������
	void finishTask();

	//������Ϸ����
	void saveData(std::string name, int numValue);

private:
	DataXML(){}
	DataXML(const DataXML & dataXML){}
	DataXML operator=(const DataXML & dataXML){return dataXML;}

private:
	static DataXML * instence;
	tinyxml2::XMLElement * root;
	tinyxml2::XMLElement * root1;
	tinyxml2::XMLElement * root2;
	tinyxml2::XMLElement * root3;
};

#endif