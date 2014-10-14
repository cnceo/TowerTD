#include "BaseEnemyplan.h"
#include "GameScene.h"
#include "plans.h"
bool BaseEnemyplan::initWithSpriteFrameName(std::string filename,int Speed,int Hp){
	if(!Sprite::initWithSpriteFrameName(filename)){
		return false;
	}
	//��Ļ��size
	Size vSize = Director::getInstance()->getVisibleSize();
	//�л�size
	Size eSize = this->getContentSize();
	this->Speed=Speed;
	this->Hp=Hp;
	//���λ��
	this->setPosition(CCRANDOM_0_1()*(vSize.width-eSize.width)+eSize.width/2 ,vSize.height+eSize.height/2);
	//��������
	void die(std::vector<std::string> fileNames);
	//����
	float dis = vSize.height+eSize.height;
	auto move = MoveBy::create(dis/Speed,Vec2(0,-dis));
	//�ƶ����ɾ��
	auto cf = CallFunc::create(std::bind(&BaseEnemyplan::remove,this));
	this->runAction(Sequence::create(move,cf,NULL));
	this->runAction(move);
	//���뵽�л���
	auto scene = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	auto elayer = scene->getEnemyLayer();
	elayer->addChild(this);
	//���ɻ�����ɻ�����
	plans::getInstance()->addplan(this);
	return true;
}
void BaseEnemyplan::die(std::vector<std::string>fileNames){
	auto ani = Animation::create();
	for(auto it:fileNames ){
		auto fram =SpriteFrameCache::getInstance()->getSpriteFrameByName(it);
		ani->addSpriteFrame(fram);
		ani->setDelayPerUnit(0.1);
		ani->setLoops(1);
		//��Ϸ�������ʱ��ص��󶨵ĺ���
		auto cf = CallFunc::create(std::bind(&BaseEnemyplan::remove,this));

		this->runAction(Sequence::create(Animate::create(ani),cf,NULL));

	}
}
void BaseEnemyplan::remove(){
	this->removeFromParentAndCleanup(true);
}