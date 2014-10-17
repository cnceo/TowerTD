#include "BossTwo.h"
#include "RoleAnimate.h"
#include "GameScene.h"
#include "HeroLayer.h"
#include "EnemyLayer.h"
#include "GetEnemyInfoFromXML.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


bool BossTwo::init(){
	if(!BaseRole::initWithSpriteFrameName("SnackMoveRight1.png")){
		return false;
	}
	//��Ļ������
	vsize = Director::getInstance()->getVisibleSize();
	//��ʼ��bosstwo�ķ���
	bossTwoDirection = 1;
	m_Hp = 400;
	isDie = false;
	//�������
	
	//Ϊbosstwo���÷���ͳ�ʼ����
	this->setPosition(Vec2(vsize.width/2,vsize.height * 0.3));
	/*auto bossAni = moveRightAnimate();
	this->runAction(bossAni);*/

	this->schedule(schedule_selector(BossTwo::move),2);
	this->schedule(schedule_selector(BossTwo::addSkill),5);
	this->schedule(schedule_selector(BossTwo::update));
	this->schedule(schedule_selector(BossTwo::RollPkBossTwo));
	this->scheduleOnce(schedule_selector(BossTwo::addvoice),0.4);
	this->schedule(schedule_selector(BossTwo::_addChild),1,-1,0);

	return true;
}

void BossTwo::addvoice(float t){
	auto e = AllVectors::getInstance()->getEfmusic();
	if (!e)
	{
		SimpleAudioEngine::getInstance()->playEffect("Evelynn.mp3");
	}
	
}

void BossTwo::RollPkBossTwo(float t){
	
	auto rsene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto enemylayer = dynamic_cast<EnemyLayer *>(rsene->getEnemyLayer());
	auto roll = enemylayer->getChildByName("roll");
	if(roll == nullptr){
		return;
	}
	
	if (this->getBoundingBox().containsPoint(roll->getPosition())){	
		enemylayer->setRollTime(3);
		this->BossTwoHurt();
	}
}

void BossTwo::BossTwoHurt(){
	if (this->getbossTwoDirection() == 1){
			auto ani = RoleAnimate::getinstance()->createAmt("SnackHurtRight1.png",3,0.1,1);
			m_Hp -= 100;
			auto e = AllVectors::getInstance()->getEfmusic();
			if (!e)
			{
				SimpleAudioEngine::getInstance()->playEffect("boss2hurt.wav");
			}
			this->runAction(ani);
	}else{
		auto ani = RoleAnimate::getinstance()->createAmt("SnackHurtLeft1.png",3,0.1,1);
		m_Hp -= 100;
		auto e = AllVectors::getInstance()->getEfmusic();
		if (!e)
		{
			SimpleAudioEngine::getInstance()->playEffect("boss2hurt.wav");
		}
		this->runAction(ani);
	}
	if(m_Hp <= 0){
		this->BossTwoDie();
	}
}

void BossTwo::BossTwoDie(){
	this->unschedule(schedule_selector(BossTwo::move));
	this->unschedule(schedule_selector(BossTwo::_addChild));
	auto rscene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto enemylayer = rscene->getEnemyLayer();
	if(this->getbossTwoDirection() == 1){
		auto ani = RoleAnimate::getinstance()->createAmt("DieRight1.png",3,0.3,1);
		auto cf = CCCallFunc::create([=](){
			this->removeFromParentAndCleanup(true);
		});
		auto seq = Sequence::create(ani,cf,NULL);
		this->runAction(seq);
		auto enemyvector = AllVectors::getInstance()->getEnemiesVector();
		for (auto i = enemyvector.begin();i != enemyvector.end();i++){
			(*i)->die();
			auto e = AllVectors::getInstance()->getEfmusic();
			if (!e)
			{
				SimpleAudioEngine::getInstance()->playEffect("boss2die.mp3");
			}
		}
			AllVectors::getInstance()->enemiesVectorCleanUp();
	}else{
		auto ani = RoleAnimate::getinstance()->createAmt("DieLeft1.png",3,0.3,1);
		auto cf = CCCallFunc::create([=](){
			this->removeFromParentAndCleanup(true);
		});
		auto seq = Sequence::create(ani,cf,NULL);
		this->runAction(seq);
		auto enemyvector = AllVectors::getInstance()->getEnemiesVector();
		for(auto i = enemyvector.begin();i != enemyvector.end();i++){
			(*i)->die();
			auto e = AllVectors::getInstance()->getEfmusic();
			if (!e)
			{
				SimpleAudioEngine::getInstance()->playEffect("boss2die.mp3");
			}
		}
		AllVectors::getInstance()->enemiesVectorCleanUp();
	}
}

void BossTwo::_callEnemy(Vec2 pos,int speed,int type,Size body,std::string name,int ai){
	auto scene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto enemylayer = scene->getEnemyLayer();
	enemylayer->add(pos,speed,type,body,name,ai);
}
void BossTwo::_addChild(float t){
	auto allEnemys = AllVectors::getInstance()->getEnemiesVector();
	if (allEnemys.size() < 2 && isDie == false){  //���Bossû���� ����ʣ���С�� ����С�� 3 ��
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
			_callEnemy(m_pos,m_speed,m_type,m_body,m_name,m_AI);
		}
	}
}


void BossTwo::update(float t){
	auto rscene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto herolayer = dynamic_cast<HeroLayer *>(rscene->getHeroLayer());
	hero = herolayer->getHero();

	m_position = hero->getPosition();
}

void BossTwo::addSkill(float t){
	auto i = CCRANDOM_0_1() > 0.4 ? 1 : 2;
	if(i == 1){
		skillTwo();
	}else{
		skillOne();
	}
}



void BossTwo::move(float t){
	auto direction = CCRANDOM_0_1() > 0.5 ? 1 : 2;
	if(this->getPositionX() < 300){
		direction = 1;
	}
	if(this->getPositionX() > 660){
		direction = 2;
	}
	if(direction == 1){
		this->stopAllActions();
		bossTwoDirection = 1;
		auto moveby = MoveBy::create(3,Vec2(300,0));
		moveby->setTag(4001);
		auto moverightani = RoleAnimate::getinstance()->moveRightAnimate();
		this->runAction(Spawn::create(moveby,moverightani,NULL));
	}else{
		this->stopAllActions();
		bossTwoDirection = 2;
		auto moveby = MoveBy::create(3,Vec2(-300,0));
		moveby->setTag(4002);
		auto moveleftani = RoleAnimate::getinstance()->moveLeftAnimate();
		this->runAction(Spawn::create(moveby,moveleftani,NULL));
	}
}

void BossTwo::skillOne(){
	auto rscene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto skilllayer = rscene->getSkillLayer();
	this->stopAllActions();
	this->setScale(1);
	if(bossTwoDirection == 1){
 	    auto attack = RoleAnimate::getinstance()->attrackRightAnimate();
		auto cf = CCCallFunc::create([=](){
			skilllayer->addSkillOne();
		});
		this->runAction(Sequence::create(attack,cf,NULL));
	}else{
		auto attack = RoleAnimate::getinstance()->attrackLeftAnimate();
		auto cf = CCCallFunc::create([=](){
			skilllayer->addSkillOne();
		});
		this->runAction(Sequence::create(attack,cf,NULL));
	}
}

void BossTwo::skillTwo(){
	this->stopAllActions();
	auto rscene = dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());
	auto herolayer = dynamic_cast<HeroLayer *>(rscene->getHeroLayer());
	auto skilllayer = rscene->getSkillLayer();
	hero = herolayer->getHero();

	this->stopAllActions();
	this->setScale(0.5);
		auto hiding = RoleAnimate::getinstance()->HIdingAnimate();
		auto cf = CCCallFunc::create([=](){
			if(hero->getPositionX() < 100){
				this->setPosition(Vec2(m_position.x + 300,m_position.y));
				this->setbossTwoDirection(2);
			}
			if(hero->getPositionX() > 860){
				this->setPosition(Vec2(m_position.x - 300,m_position.y));
				this->setbossTwoDirection(1);
			}
			if(hero->getPositionX() > 100 && hero->getPositionX() < 860){
				int a = CCRANDOM_0_1() > 0.5 ? 1 : 2;
				if(a == 1){
					this->setPosition(Vec2(m_position.x - 300,m_position.y));
					this->setbossTwoDirection(1);
				}else{
					this->setPosition(Vec2(m_position.x + 300,m_position.y));
					this->setbossTwoDirection(2);
				}
			}
			skilllayer->addSkillTwo();
		});
		this->runAction(Sequence::create(hiding,cf,NULL));
}

