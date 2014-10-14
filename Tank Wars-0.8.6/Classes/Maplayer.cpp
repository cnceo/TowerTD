#include "MapLayer.h"


bool MapLayer::init(){
	if (!Layer::init()){
		return false;
	}
	count =4;
	
	

	//��ͼ������
	map = TMXTiledMap::create("map.tmx");


	//���õĵ�ͼ�еı�����
	bgLayer = map->getLayer("bg");
	bgLayer->setZOrder(-1);
	//bgLayer->setNormalizedPosition(Vec2(0.2, 0));
	bossLayer = map->getLayer("boss");
	bossLayer->setVisible(false);
	//ƫ��
	offX =/*Director::getInstance()->getVisibleSize().width*0.2 -64*/0;
		
	this->addChild(map);

	//������ȡ
	object = map->getObjectGroup("obj");
	//��ʼ�������
	initPointsVector(offX);
// 	log("%d", checkNodeBreak(Vec2(100, 500)));
// 	log("%d", checkNodeBreak(Vec2(100, 100)));
// 	auto sp = Sprite::createWithSpriteFrameName("p1.png");
// 	sp->setPosition(pointsVector.at(0)->getPosition());
// 	this->addChild(sp);
// 	auto sp1 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp1->setPosition(pointsVector.at(1)->getPosition());
// 	this->addChild(sp1);
// 	auto sp2 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp2->setPosition(pointsVector.at(2)->getPosition());
// 	this->addChild(sp2);
// 	auto sp3 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp3->setPosition(pointsVector.at(3)->getPosition());
// 	this->addChild(sp3);
	//
// 	auto sp1 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp1->setPosition(pointsVector.at(1)->getPosition());
// 	this->addChild(sp1);
// 	auto sp2 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp2->setPosition(pointsVector.at(2)->getPosition());
// 	this->addChild(sp2);
// 	auto sp3 = Sprite::createWithSpriteFrameName("p1.png");
// 	sp3->setPosition(pointsVector.at(3)->getPosition());
// 	this->addChild(sp3);
	return true;
}
//��ȡ�����
void MapLayer::initPointsVector(float offX){
	Node* runOfPoint = nullptr;

	//1
	int count = 1;
	ValueMap point;
	
	//2
	while (count<5)
	{
		point = object->getObject(std::to_string(count));
	
		//3
		auto x = point.at("x").asFloat();
		auto y = point.at("y").asFloat();
		//4
		runOfPoint = Node::create();
		runOfPoint->setPosition(Vec2(x + offX , y));
		this->pointsVector.pushBack(runOfPoint);
		//point = object->getObject(std::to_string(count));
		count++;
		
	runOfPoint = nullptr;
	}
}
//���������0~3
Vec2 MapLayer::getState(int i){
	Vec2 point = pointsVector.at(i)->getPosition();
	return point;
}
//�����ת��
//����
Vec2 MapLayer::converTotileCoord(Vec2 position){
	int x = (position.x - offX) / map->getContentSize().width*map->getMapSize().width;
	int y = map->getMapSize().height - position.y / map->getContentSize().height*map->getMapSize().height;
	return Vec2(x, y);
}
// Vec2 MapLayer::converToMatrixCoord(Vec2 position){
// 	int x = (position.x + offX) / map->getContentSize().width*map->getMapSize().width;
// 	int y = position.y / map->getContentSize().height*map->getMapSize().height;
// 	return Vec2(x, y);
// }

//����Ƿ��ж���
bool MapLayer::checkIsNode(Vec2 position){

	Vec2 towerCoord = converTotileCoord(Vec2(position.x,position.y));//��ͼ����
	//Vec2 matrixCoord = converToMatrixCoord(position);//����λ��
	if (towerCoord.x>=40||towerCoord.x<0)
	{
		return false;
	}
	if (towerCoord.y>=40||towerCoord.y<0)
	{
		return false;
	}
	int gid = bgLayer->getTileGIDAt(towerCoord);//�õ�gid
	//�õ��˸�ͼ���GID����ͨ�������ж��Ƿ�������ӵ����
	if (!gid || gid == 5 || gid == 6 || gid == 19 || gid == 20){
		return false;
	}return true;
}


//����Ƿ�����ƻ�
bool MapLayer::checkNodeBreak(Vec2 position){
	Vec2 towerCoord = converTotileCoord(position);//��ͼ����
	//Vec2 matrixCoord = converToMatrixCoord(position);//����λ��
	int gid = bgLayer->getTileGIDAt(towerCoord);//�õ�gid
	//�õ��˸�ͼ���GID����ͨ�������ж��Ƿ�������ӵ����
	
	auto titleTemp =  (map->getPropertiesForGID(gid).asValueMap());

	bool BreakValue;
	
	BreakValue = titleTemp.at("canBreak").asBool();
	return BreakValue;

}
bool MapLayer::checkNodeWrite(Vec2 position)//����Ƿ�Ϊˮ{
{
	Vec2 towerCoord = converTotileCoord(position);//��ͼ����
	//Vec2 matrixCoord = converToMatrixCoord(position);//����λ��
	int gid = bgLayer->getTileGIDAt(towerCoord);//�õ�gid
	if (gid == 7 || gid == 8 || gid == 21 || gid == 22){
		return true;
	}
	return false;
}
// ���õ�ľ����Ƴ�, ��Ϊ�ܵ��ӵ�����
bool MapLayer::breakNode(Vec2 position){
	if (checkIsNode(position)&&checkNodeBreak(position)&&!checkNodeWrite(position)){
	
	Vec2 towerCoord = converTotileCoord(position + Vec2(0,0));//��ͼ����
	 
	auto sptoBreak = bgLayer->tileAt(towerCoord);
	if (bgLayer->getTileGIDAt(towerCoord) == 11 || bgLayer->getTileGIDAt(towerCoord) == 12 || bgLayer->getTileGIDAt(towerCoord) == 25 || bgLayer->getTileGIDAt(towerCoord) == 26){
		count--;
	}
	if (sptoBreak){
		sptoBreak->removeFromParentAndCleanup(true);
		
	}
	 
	}
	return true;
}
//����Ƿ�ʧ��,���ǻ�����û�б���
bool MapLayer::isDefeated(){
	if (count==0){
		return true;
	}
	return false;
}void MapLayer::failed()//ʧ�ܵ��õķ���
{
	bossLayer->setVisible(true);
}