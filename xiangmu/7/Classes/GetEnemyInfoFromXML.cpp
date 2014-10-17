#include "GetEnemyInfoFromXML.h"

GetEnemyInfoFromXML *GetEnemyInfoFromXML::instance = nullptr;

GetEnemyInfoFromXML *GetEnemyInfoFromXML::getinstance(){
	if(instance ==nullptr){
		instance = new GetEnemyInfoFromXML();
		instance->loadXML();
	}
	return instance;
}

void GetEnemyInfoFromXML::loadXML(){
	//�������Ĵ�С
	Size visSize = Director::getInstance()->getVisibleSize();

//=======================================��ȡmapconfig.xml�ļ��еĵ�ͼ��Ϣ========================================
	
	int value = UserDefault::getInstance()->getIntegerForKey("ID",1);
	//�ҵ��ļ�
	auto xmlFileName = FileUtils::getInstance()->getStringFromFile("enemyconfig.xml");//�õ��ļ���λ��  
	//log("%s",xmlFileName.c_str());//��֤�Ƿ���ȷ

	tinyxml2::XMLDocument doc;							//����������
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
	
	name = name->NextSiblingElement();

	while (name!=nullptr){
		
		//��ȡ���Խڵ�(λ��)
		auto _enemyname = name->Attribute("enemyname");
		auto _enemytype = name->Attribute("enemytype");
		auto _enemyspeed = name->Attribute("enemyspeed");
		auto _enemyposition_x = name->Attribute("enemyposition_x");
		auto _enemyposition_y = name->Attribute("enemyposition_y");
		auto _enemybody_x = name->Attribute("enemybody_x");
		auto _enemybody_y = name->Attribute("enemybody_y");
		auto _enemyAI = name->Attribute("enemyAI");

		//============================================��XML�л�ȡ����Ϣ��Ҫת�� ========================================
		auto enemX = atof(_enemyposition_x);
		auto enemY = atof(_enemyposition_y);
		auto posX = atof(_enemybody_x);
		auto posY = atof(_enemybody_y);
		auto enemAI = atof(_enemyAI);
		enemyName = _enemyname;
		enemyType = atof(_enemytype);
		enemySpeed = atof(_enemyspeed);
		//===============================================��Ҫ���ص� ��Ϣ===============================================
		enemyPosition = Vec2(enemX,enemY);  //ÿ��λ����Ϣ  ���� ������
		allEnemyPosition.push_back(enemyPosition);

		enemyBody = Size(posX,posY);		//ÿ���˵�body��С   ���ڼ�����
		allEnemyBody.push_back(enemyBody);

		allEnemyName.push_back(enemyName);		//ÿ���˵�����  ���ڼ�����

		allEnemyType.push_back(enemyType);		//ÿ���˵�����   ���ڼ�����

		allEnemySpeed.push_back(enemySpeed);		//ÿ���˵� �ٶ�  ���ڼ�����

		allEnemyAI.push_back(enemAI);

		name = name->NextSiblingElement();

	}

}


//����С������ֵļ���
std::vector<std::string> GetEnemyInfoFromXML::getAllenemyName(){
	return allEnemyName;
}

//���ػ�ȡ�������͵ļ���
std::vector<int> GetEnemyInfoFromXML::getAllEnemyType(){
	return allEnemyType;
}

//��ȡ�ٶȵļ���
std::vector<int> GetEnemyInfoFromXML::getAllEnemySpeed(){
	return allEnemySpeed;
}

//��ȡλ����Ϣ�ļ���
std::vector<Vec2> GetEnemyInfoFromXML::getAllEnemyPosition(){
	return allEnemyPosition;
}

//С������С�ļ���
std::vector<Size> GetEnemyInfoFromXML::getAllEnemyBody(){
	return allEnemyBody;
}

//С��AI�ļ���
std::vector<int> GetEnemyInfoFromXML::getAllEnemyAI(){
	return allEnemyAI;
}

void GetEnemyInfoFromXML::clean(){
	allEnemyBody.clear();
	allEnemyPosition.clear();
	allEnemySpeed.clear();
	allEnemyType.clear();

}

void GetEnemyInfoFromXML::reloadXML(){
	loadXML();
}