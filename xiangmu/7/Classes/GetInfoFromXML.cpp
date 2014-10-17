#include "GetInfoFromXML.h"

GetInfoFromXML *GetInfoFromXML::instance = nullptr;

GetInfoFromXML *GetInfoFromXML::getinstance(){
	if(instance ==nullptr){
		instance = new GetInfoFromXML();
	
		instance->loadXML();
	}
	return instance;
}

void GetInfoFromXML::reloadXML(){
	loadXML();
}

void GetInfoFromXML::loadXML(){
	//�������Ĵ�С



	Size visSize = Director::getInstance()->getVisibleSize();

//=======================================��ȡmapconfig.xml�ļ��еĵ�ͼ��Ϣ========================================
	
    int value = UserDefault::getInstance()->getIntegerForKey("ID",1);
	//�ҵ��ļ�
	auto xmlFileName = FileUtils::getInstance()->getStringFromFile("mapconfig.xml");//�õ��ļ���λ��  
	//log("%s",xmlFileName.c_str());//��֤�Ƿ���ȷ

	tinyxml2::XMLDocument doc;						//����������
	doc.Parse(xmlFileName.c_str());					//���ļ��н��������� 
	XMLElement *root = doc.RootElement();				//��ȡ���ڵ�
	XMLElement *stage = root->FirstChildElement();
	while (stage!=nullptr){
		auto id = stage->Attribute("ID");
		int _id = atof(id);
		if (_id == value){
			ID = id;
			Stage = stage;
			break;
		}
		stage = stage->NextSiblingElement();
	}
	XMLElement *name = Stage->FirstChildElement();		//��ȡ���ֽڵ�
	auto content = name->GetText();						//��ȡ���ֽڵ������
	std::string con = StringUtils::format("%s",content);
	
	mapName = con;									//��Ҫ���ص� ��ͼ������

	name = name->NextSiblingElement();

	while (name!=nullptr){
		//��ȡ���Խڵ�(λ��)
		auto gro_posx = name->Attribute("gro_posx");
		auto gro_posy = name->Attribute("gro_posy");
		auto gro_width = name->Attribute("gro_width");
		//ת�� 
		float _one = atof(gro_posx);
		float _two = atof(gro_posy);
		float _three = atof(gro_width);

		bordPos = Vec2(_one,_two);   //��Ҫ���ص� �ذ������
		bordsVector.push_back(bordPos);//��Ž�����
		mapWidth = _three;			//��Ҫ���ص� �ذ�Ŀ��
		allWidth.push_back(mapWidth);
		log("%d",allWidth.size());
		name = name->NextSiblingElement();

	}

}

std::vector<Vec2> GetInfoFromXML::getBordVector(){
	return bordsVector;
}

std::vector<float> GetInfoFromXML::getAllWidth(){
	return allWidth;
}

void GetInfoFromXML::clean(){
	allWidth.clear();
	bordsVector.clear();

}
