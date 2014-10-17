#pragma once

#pragma  once

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
using namespace cocos2d;
using namespace tinyxml2;




class GetInfoFromXML{
private:
	GetInfoFromXML(const GetInfoFromXML &instance){}
	GetInfoFromXML(){}
	GetInfoFromXML operator=(const GetInfoFromXML &instance){return instance;}
public:

	static GetInfoFromXML *getinstance();
	static GetInfoFromXML *instance;

	void loadXML();
	XMLElement *Stage;
	std::string ID;

	//===================================================��ͼ����Ϣ===============================================
	//��ȡ ��ͼ����
	CC_SYNTHESIZE(std::string,mapName,MapName);
	//ÿ����ȡ�ְ�λ����Ϣ
	//CC_SYNTHESIZE(Vec2,bordPos,BordPosition);
	Vec2  bordPos;
	//��Ÿְ�ļ���,������
	std::vector<Vec2> bordsVector;
	
	std::vector<Vec2> getBordVector();


	//��ȡ�ְ�Ŀ�
	float mapWidth;
	std::vector<float> allWidth;
	std::vector<float> getAllWidth();
	

	void reloadXML();
	//ɾ��
	void clean();

	
};
