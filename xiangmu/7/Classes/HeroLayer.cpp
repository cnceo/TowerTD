#include "HeroLayer.h"
#include "AllVectors.h"
#include "GameScene.h"

bool HeroLayer::init(){
	if(!Layer::init()){
		return false;
	}
	//��������С
	visSize = Director::getInstance()->getVisibleSize();


	//����һ��Ӣ�ۣ����ڲ���
	Size vis = Size(55,85);

	sp = Hero::create(Vec2(100,78));
	sp->setName("hero");
	sp->setTag(2000);
	//����body
	sp->setPhysicsBody(PhysicsBody::createBox(vis));
	//��ײ֮������ת
	sp->getPhysicsBody()->setRotationEnable(false);

	sp->getPhysicsBody()->setCollisionBitmask(17);
	//ʱ��ɴ�Խ
	sp->getPhysicsBody()->setCategoryBitmask(4);
	//�Ƿ����ײ
	sp->getPhysicsBody()->setContactTestBitmask(1);
	sp->getPhysicsBody()->getShape(0)->setRestitution(0);//����û�� ����

	this->addChild(sp);

	this->schedule(schedule_selector(HeroLayer::getFieBall));

	return true;

}

Hero *HeroLayer::getHero(){
	return sp;
}


void HeroLayer::getFieBall(float t){
	auto ev = AllVectors::getInstance()->getEnemiesVector();
	for (auto it = ev.begin(); it != ev.end(); it++){
		if ((*it)->getBoundingBox().intersectsRect(sp->getBoundingBox()) && (*it)->getM_state() >4 && (*it)->getM_state() <= 5 && (*it)->m_isFired == false){
			(*it)->setPosition(sp->getPosition());
            (*it)->m_isTaken = true;
			sp->isTaking = true;
		}
	}
}
