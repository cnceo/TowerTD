#include "QuadrantBullet.h"
#define  BULLETTIME 10
QuadrantBullet *QuadrantBullet::create(float speed, Vec2 fromPosition, float attack, std::string fileName, Vec2 toPosition, int bulletSpecies){
	QuadrantBullet *pRet = new QuadrantBullet();
	if (pRet && pRet->init(speed, fromPosition, attack, fileName, toPosition,bulletSpecies))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool QuadrantBullet::init(float speed, Vec2 fromPosition, float attack, std::string fileName, Vec2 toPosition, int bulletSpecies){
	if (!BaseBullet::init(speed, fromPosition, attack, fileName,bulletSpecies,0)){
		return false;
	}

	this->toPosition = toPosition;
	return true;
}

void QuadrantBullet::onEnter(){
	Sprite::onEnter();
	exeQuadrantBullet(this->getPosition());
}

void QuadrantBullet::exeQuadrantBullet(Vec2 fromPosition){
	Size viewSize = Director::getInstance()->getVisibleSize();
	//ʹ������������
	float x_cut = abs(toPosition.x - fromPosition.x);
	float y_cut = abs(toPosition.y - fromPosition.y);

	//����˵�Ӣ�۵ľ���
	float enemy_hero = ccpDistance(toPosition, fromPosition);
	float dis_time = this->getSpeed() * enemy_hero;
	//һ�����������������ڣ���X����������Y����������ԭ��9�����  
	bool isInQuadrant1 = (toPosition.x > fromPosition.x) && (toPosition.y > fromPosition.y);
	bool isInQuadrant2 = (toPosition.x < fromPosition.x) && (toPosition.y > fromPosition.y);
	bool isInQuadrant3 = (toPosition.x < fromPosition.x) && (toPosition.y < fromPosition.y);
	bool isInQuadrant4 = (toPosition.x > fromPosition.x) && (toPosition.y < fromPosition.y);
	bool isOnXR = (toPosition.y == fromPosition.y) && (toPosition.x > fromPosition.x);
	bool isOnXL = (toPosition.y == fromPosition.y) && (toPosition.x < fromPosition.x);
	bool isOnYT = (toPosition.x == fromPosition.x) && (toPosition.y > fromPosition.y);
	bool isOnYD = (toPosition.x == fromPosition.x) && (toPosition.y < fromPosition.y);
	bool isZero = (toPosition.x == fromPosition.x) && (toPosition.y == fromPosition.y);
	//


	if (isInQuadrant1)
	{
		//���˵��Ӣ�۵��γɵ�ֱ�ߵ�б��  
		float mMidLineSlope = (fromPosition.y - toPosition.y) / (fromPosition.x - toPosition.x);
		//����ֵ  
		float mMidLineAngleR = atan(mMidLineSlope);
		//�Ƕ�ֵ  
		float mMidLineAngleD = mMidLineAngleR*M_PI / 180;
		if (mMidLineAngleD > 45)
		{
			
			float hero_y = y_cut * toPosition.x / x_cut;
			viewSize = Director::getInstance()->getVisibleSize();
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition,Vec2(960, toPosition.y + hero_y));
			auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(960, toPosition.y + hero_y));
			this->runAction(Sequence::create(to, cf, NULL));

		}
		else{
			float hero_x = x_cut * toPosition.y / y_cut;
			viewSize = Director::getInstance()->getVisibleSize();
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition,Vec2(toPosition.x + hero_x, 640));
			auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(toPosition.x + hero_x, 640));
			this->runAction(Sequence::create(to, cf, NULL));
		}
	}
	else if (isInQuadrant2)
	{
		//���˵��Ӣ�۵��γɵ�ֱ�ߵ�б��  
		float mMidLineSlope = (fromPosition.y - toPosition.y) / (fromPosition.x - toPosition.x);
		//����ֵ  
		float mMidLineAngleR = atan(mMidLineSlope);
		//�Ƕ�ֵ  
		float mMidLineAngleD = mMidLineAngleR*M_PI / 180;
		if (mMidLineAngleD > 45)
		{
			float hero_x = x_cut * toPosition.y / y_cut;
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition,Vec2(toPosition.x - hero_x, 640));
			auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(toPosition.x - hero_x, 640));
			this->runAction(Sequence::create(to, cf, NULL));
		}
		else{
			float hero_y = y_cut * toPosition.x / x_cut;
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition,Vec2(0, toPosition.y + hero_y));
			auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(0, toPosition.y + hero_y));
			this->runAction(Sequence::create(to, cf, NULL));
		}
	}
	else if (isInQuadrant3)
	{
		//���˵��Ӣ�۵��γɵ�ֱ�ߵ�б��  
		float mMidLineSlope = (fromPosition.x - toPosition.x) / (fromPosition.y - toPosition.y);
		//����ֵ  
		float mMidLineAngleR = atan(mMidLineSlope);
		//�Ƕ�ֵ  
		float mMidLineAngleD = mMidLineAngleR*M_PI / 180;
		if (mMidLineAngleD > 45)
		{
			float hero_x = x_cut * toPosition.y / y_cut;
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition,Vec2(toPosition.x - hero_x, 0));
			auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(toPosition.x - hero_x, 0));
			this->runAction(Sequence::create(to, cf, NULL));
		}
		else{
			float hero_y = y_cut * toPosition.x / x_cut;
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition,Vec2(0, toPosition.y - hero_y));
			auto to = MoveTo::create(dist/this->getSpeed()*0.5, Vec2(0, toPosition.y - hero_y));
			this->runAction(Sequence::create(to, cf, NULL));
		}
	}
	else if (isInQuadrant4)
	{
		//���˵��Ӣ�۵��γɵ�ֱ�ߵ�б��  
		float mMidLineSlope = (fromPosition.x - toPosition.x) / (fromPosition.y - toPosition.y);
		//����ֵ  
		float mMidLineAngleR = atan(mMidLineSlope);
		//�Ƕ�ֵ  
		float mMidLineAngleD = mMidLineAngleR*M_PI / 180;
		if (mMidLineAngleD > 45)
		{
			float hero_x = x_cut * toPosition.y / y_cut;
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition, Vec2(fromPosition.x + hero_x, 640));
			auto to = MoveTo::create(dist / getSpeed()*0.5, Vec2(fromPosition.x + hero_x, 640));
			this->runAction(Sequence::create(to, cf, NULL));
		}
		else{
			float hero_y = y_cut * toPosition.x / x_cut;
			auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
			float dist = ccpDistance(fromPosition, Vec2(960, toPosition.y - hero_y));
			auto to = MoveTo::create(dist / getSpeed()*0.5, Vec2(960, toPosition.y - hero_y));
			this->runAction(Sequence::create(to, cf, NULL));
		}
	}else if (isOnXL)
	{
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition,Vec2(0, toPosition.y));
		auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(0, toPosition.y));
		this->runAction(Sequence::create(to, cf, NULL));
	}else if(isOnXR){
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition,Vec2(960, toPosition.y));
		auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(960, toPosition.y));
		this->runAction(Sequence::create(to, cf, NULL));
	}else if (isOnYD)
	{
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition,Vec2(toPosition.x, 640));
		auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(toPosition.x, 640));
		this->runAction(Sequence::create(to, cf, NULL));
	}else if (isOnYD)
	{
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition,Vec2(toPosition.x, 0));
		auto to = MoveTo::create(dist/getSpeed()*0.5, Vec2(toPosition.x, 0));
		this->runAction(Sequence::create(to, cf, NULL));
	}
	else if (isOnXL)
	{
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition, Vec2(0, toPosition.y));
		auto to = MoveTo::create(dist / getSpeed()*0.5, Vec2(0, toPosition.y));
		this->runAction(Sequence::create(to, cf, NULL));
	}
	else if (isOnXR){
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition, Vec2(960, toPosition.y));
		auto to = MoveTo::create(dist / getSpeed()*0.5, Vec2(960, toPosition.y));
		this->runAction(Sequence::create(to, cf, NULL));
	}
	else if (isOnYD)
	{
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition, Vec2(toPosition.x, 640));
		auto to = MoveTo::create(dist / getSpeed()*0.5, Vec2(toPosition.x, 640));
		this->runAction(Sequence::create(to, cf, NULL));
	}
	else if (isOnYD)
	{
		auto cf = CallFunc::create(std::bind(&BaseBullet::die, this));
		float dist = ccpDistance(fromPosition, Vec2(toPosition.x, 0));
		auto to = MoveTo::create(dist / getSpeed()*0.5, Vec2(toPosition.x, 0));
		this->runAction(Sequence::create(to, cf, NULL));
	}
}


