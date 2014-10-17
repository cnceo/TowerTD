#include "BossFour.h"
#include "RoleAnimate.h"
#include "AllVectors.h"
#include "GetEnemyInfoFromXML.h"
#include "GameScene.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool BossFour::init(){
	if (!Sprite::init()){
		return false;
	}

	m_dir = MOVELEFT;		//����Ĭ�ϵķ���������
	m_bossIsHurt = false;
	hp = 300;
	isDie = false;

	this->setPosition(Vec2(450,165));

	this->schedule(schedule_selector(BossFour::move),2,-1,1);	//ÿ�� 2����� move����
	this->scheduleOnce(schedule_selector(BossFour::bornAnimate),0);
	this->schedule(schedule_selector(BossFour::_update),2,-1,0);
	this->schedule(schedule_selector(BossFour::fireBallPKBoss));
	this->setVisible(false);

	return true;
    
}
void BossFour::_update(float t){
	
	auto allEnemys = AllVectors::getInstance()->getEnemiesVector();
	//log("%d",allEnemys.size());
	if (allEnemys.size() <= 3 && isDie == false){  //���Bossû���� ����ʣ���С�� ����С�� 3 ��
		auto e = AllVectors::getInstance()->getEfmusic();
		if (!e)
		{
			SimpleAudioEngine::getInstance()->playEffect("Boss4callenemy.wav");
		}
		
		auto allEnemyPos = GetEnemyInfoFromXML::getinstance()->getAllEnemyPosition();
		//�ٶ���Ϣ
		auto allEnemySpeed = GetEnemyInfoFromXML::getinstance()->getAllEnemySpeed();
		//������Ϣ
		auto allEnemyType = GetEnemyInfoFromXML::getinstance()->getAllEnemyType();
		//�����С��Ϣ
		auto allEnemyBody = GetEnemyInfoFromXML::getinstance()->getAllEnemyBody();
		//������Ϣ
		auto allEnemyName = GetEnemyInfoFromXML::getinstance()->getAllenemyName();
		//AI��Ϣ
		auto allEnemyAI = GetEnemyInfoFromXML::getinstance()->getAllEnemyAI();

		srand(time(0));

		for (int i = 0;i < 2;i++){
			
			int randNUm =(int)(CCRANDOM_0_1()*4);
			Vec2 m_pos = allEnemyPos[randNUm];
			int m_speed = allEnemySpeed[randNUm];
			int m_type = allEnemyType[randNUm];
			Size m_body = allEnemyBody[randNUm];
			std::string m_name = allEnemyName[randNUm];
			int m_AI = allEnemyAI[randNUm];
			callEnemy(m_pos,m_speed,m_type,m_body,m_name,m_AI);
		}
	}
}
//��ȡ Boss��״̬
bool BossFour::getState(){
	return isDie;
}


void BossFour::callEnemy(Vec2 pos,int speed,int type,Size body,std::string name,int ai){		//��С��

	auto enemy1 = BaseEnemy::create(name,speed,type,pos,body,ai);

	auto scene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto enemylayer = scene->getEnemyLayer();
	enemy1->setTag(1002);
	enemylayer->addChild(enemy1);

	AllVectors::getInstance()->addEnemy(enemy1);

}
void BossFour::move(float t){
	m_dir = CCRANDOM_0_1() > 0.5 ? direction::MOVELEFT : direction::MOVERIGHT;
	if (m_dir == MOVELEFT){
		this->moveLeftAnimate();
	}else{
		this->moveRightAnimate();//�������ҵĶ���
	}
	if (this->getPositionX() >= 640){//�߽���
        moveLeftAnimate();
	}
	if (this->getPositionX()<= 300){
        moveRightAnimate();
	}
}
void BossFour::moveLeftAnimate(){ //�����ƶ�����
	m_dir = MOVELEFT;
	//վ�������ж���
	auto moveAni = RoleAnimate::getinstance()->createAmt("boss1MoveLeft_0%d.png",4,0.5,1);
    moveAni->setTag(1000);
	this->runAction(moveAni);
	//�ƶ����ж���
	auto moveleft = MoveBy::create(2,Vec2(-70,0));
	auto spa = Spawn::create(moveAni,moveleft,NULL);

	this->runAction(spa);

}

void BossFour::moveRightAnimate(){	//�����ƶ�����
	m_dir = MOVERIGHT;
	//վ�������ж���
	auto moveAni = RoleAnimate::getinstance()->createAmt("boss1MoveRight_0%d.png",4,0.5,1);
    moveAni->setTag(2000);
	this->runAction(moveAni);
	//
	auto moveleft = MoveBy::create(2,Vec2(80,0));
	auto spa = Spawn::create(moveAni,moveleft,NULL);

	this->runAction(spa);

}

void BossFour::bornAnimate(float t){		//��������
	
	auto bornAni = RoleAnimate::getinstance()->createAmt("born0%d.png",14,0.1,1);
	this->runAction(bornAni);
	this->setVisible(true);
}

void BossFour::hurtAnimate(){		//���˶���
	Animate *ani;
    //this->stopActionByTag(1000);
    //this->stopActionByTag(2000);
	if (m_dir == MOVELEFT){
		ani = RoleAnimate::getinstance()->createAmt("boss1HurtLeft_0%d.png",4,0.5,1);
	}else{
		ani = RoleAnimate::getinstance()->createAmt("boss1HurtRight_0%d.png",4,0.5,1);
	}
	this->runAction(ani);
}

void BossFour::dieAnimate(){		//��������
	Animate *ani;
	if (m_dir == MOVELEFT){
		ani = RoleAnimate::getinstance()->createAmt("boss1DieLeft_0%d.png",4,0.5,1);
	}else{
		ani = RoleAnimate::getinstance()->createAmt("boss1DieRight_0%d.png",4,0.5,1);
	}
	this->runAction(ani);
}

void BossFour::hurt(){
	m_bossIsHurt = true;
	hurtAnimate();
	this->hp -= 100;
	if (hp <= 0 ){
		isDie = true;
		die();
    }
}

void BossFour::die(){
	dieAnimate();
	auto remo = CCCallFunc::create([=](){
		this->removeFromParentAndCleanup(true);
	});
    this->runAction(Sequence::create(DelayTime::create(2),remo,NULL));

}

void BossFour::fireBallPKBoss(float t){
	//�����˵ĳ���
	auto scene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	//��ȡ ���˲�
	auto enemylayer = scene->getEnemyLayer();

	auto roll = enemylayer->getChildByName("roll");

	if (roll != NULL){
		if ( (roll->getPositionY() < this->getPositionY()-40) &&this->getBoundingBox().containsPoint(roll->getPosition())){
            this->hurt();
			enemylayer->setRollTime(3);
		}
	}

}

	

