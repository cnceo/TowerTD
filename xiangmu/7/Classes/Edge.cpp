#include "Edge.h"

bool Edge::init(){
	if (!Node::init())
	{
		return false;

	}
	//��ȡ��������Ĵ�С
	Size visSize = Director::getInstance()->getVisibleSize();
	//����
	setPhysicsBody(PhysicsBody::createEdgeBox(Size(visSize.width,visSize.height)));
	//���ÿ��Բ�����ײ
	getPhysicsBody()->setContactTestBitmask(1);
	//���ô�С
	setContentSize(visSize);
	//this->getPhysicsBody()->getShape(0)->setRestitution(100);
	this->getPhysicsBody()->setCategoryBitmask(1);
	this->getPhysicsBody()->setCollisionBitmask(1);
	this->getPhysicsBody()->setContactTestBitmask(1);


	return true;


}