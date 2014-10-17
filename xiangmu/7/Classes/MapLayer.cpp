#include "MapLayer.h"
#include "GetInfoFromXML.h"
#include "AllVectors.h"

bool MapLayer::init(){
	if (!Layer::init()){
		return false;
	}

	//��������С
	visSize = Director::getInstance()->getVisibleSize();

	this->scheduleOnce(schedule_selector(MapLayer::add),0.4);

	return true;

}

void MapLayer::add(float t){
	auto posVector = GetInfoFromXML::getinstance()->getBordVector();
	auto allWidth = GetInfoFromXML::getinstance()->getAllWidth();
	auto mapName = GetInfoFromXML::getinstance()->getMapName();
	log("%s",mapName.c_str());

	m_map = TMXTiledMap::create(mapName);

	this->addChild(m_map);


	for (int it = 0;it<posVector.size();it++){
		auto pos = posVector[it];
		auto width = allWidth[it];		
		addGround1(pos.x,pos.y, width);
	}

	addGround2(0,320,3,visSize.height);
	addGround2(960,320,3,visSize.height);
}



void MapLayer::addGround1(int posX,int posY,int width){		//��ӵذ�
	//��ӵذ�
	auto ground = Sprite::create();//����һ������
	ground->setTag(2002);
	ground->setPhysicsBody(PhysicsBody::createBox(Size(width,3)));
	ground->getPhysicsBody()->setCollisionBitmask(31);
	ground->getPhysicsBody()->setCategoryBitmask(16);
	ground->getPhysicsBody()->setContactTestBitmask(0);
	ground->setTextureRect(Rect(0,0,width,3));//��������� �� ��
	ground->setPosition(Vec2(posX,posY));//���õذ�� λ�� 
	ground->getPhysicsBody()->setDynamic(false);
	ground->setOpacity(0);
	this->addChild(ground);

	AllVectors::getInstance()->addGround(ground);

}

void MapLayer::addGround2(int posX,int posY,int wid,int length){
	//��ӵذ�
	auto ground = Sprite::create();//����һ������
	ground->setTag(2003);
	ground->setPhysicsBody(PhysicsBody::createBox(Size(wid,length)));
	ground->getPhysicsBody()->setCollisionBitmask(31);
	ground->getPhysicsBody()->setCategoryBitmask(16);
	ground->getPhysicsBody()->setContactTestBitmask(2);
	ground->setTextureRect(Rect(0,0,wid,length));//��������� �� ��
	ground->setPosition(Vec2(posX,posY));//���õذ�� λ�� 
	ground->getPhysicsBody()->setDynamic(false);
	ground->setOpacity(0);
	this->addChild(ground);

	AllVectors::getInstance()->addGround(ground);

}

void MapLayer::finishAmt(){
	auto moveUp = MoveBy::create(2,Vec2(0,640));
	auto cf = CallFunc::create([=](){this->setPosition(0,0);});
	auto seq = Sequence::create(moveUp,cf,NULL);
	this->runAction(seq);
}
