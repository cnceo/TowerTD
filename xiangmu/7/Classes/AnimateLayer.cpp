#include "AnimateLayer.h"
#include "RoleAnimate.h"
bool AnimateLayer::init(){
	if(!Layer::init()){
		return false;
	}
	//0.9����Ƴ�����
	//this->scheduleOnce(schedule_selector(AnimateLayer::removeSp),0.9);
	//��ӳ�������
	//addBornAnimate();
	return true;
}

void AnimateLayer::addBornAnimate(){
	//������ж����ľ���
	bornAnimate4 = Sprite::create();
	bornAnimate4->setPosition(700,196);
	bornAnimate4->setScaleX(0.2);
	bornAnimate4->setScaleY(0.3);
	this->addChild(bornAnimate4);
	//���ж���
	auto ani = RoleAnimate::getinstance()->getBornAnimate(4,11,0.08,1);
	bornAnimate4->runAction(ani);
}

void AnimateLayer::removeSp(float t){
	//�Ƴ����ж����ľ���
	bornAnimate4->removeFromParentAndCleanup(true);
}