#include "BaseRole.h"


BaseRole *BaseRole::create(std::string fileName){
	BaseRole *baserole = new BaseRole();
	if (baserole && baserole->initWithSpriteFrameName(fileName))
	{
		baserole->autorelease();
		return baserole;
	}

	CC_SAFE_DELETE(baserole);
	return NULL;
}

bool BaseRole::initWithSpriteFrameName(std::string fileName){
	if (!Sprite::initWithSpriteFrameName(fileName))
	{
		return false;
	}
	
	m_hp = 0;					//Ѫ��
	
	m_speed = 0;				//�ٶ�
	
	
	m_attack = 0;					//�����ˣ����ǵĹ�����Ϊ0��

	m_state = false;			//����״̬

	return true;
}

void BaseRole::move(){					//�ƶ�   �麯��

}

void BaseRole::jump(){						//��  �麯��

}

void BaseRole::hurt(){					// �麯��

}

void BaseRole::die(){					  //����  �麯��

}

void BaseRole::bornAnimate(){				// ��������  �麯��

}

//��������   ͨ�����ഫ����������Ƭ������������
void BaseRole::dieRunAnimation(const char *fileNames,...){	

	Animation *ani = Animation::create();			//��������
	
	this->stopAllActions();		//ֹͣ��ǰ��������еĶ���

	//������������

	va_list args;			//�����Ƭ�ļ��ϵĶ���

	va_start(args,fileNames);				//������������Ƭ���ڼ��� args ��

	if (!fileNames)			//���ͼƬΪ��
	{
		return;
	}

	SpriteFrame *frame;
	const char *fileStr;
	fileStr = va_arg(args,const char *);		//fileName���׵�ַ������һ��Ԫ�أ�

	frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(fileStr);		
	ani->addSpriteFrame(frame);

	while (!fileStr){
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(fileStr);
		ani->addSpriteFrame(frame);
		fileStr = va_arg(args,const char *);

	}

	va_end(args);

	//���ж���

	ani->setDelayPerUnit(0.1);
	ani->setLoops(1);
	auto fun = CCCallFunc::create(std::bind(&BaseRole::remove,this));

	this->runAction(Sequence::create(Animate::create(ani),fun,NULL));		//���ж���

}

//�Ƴ�����
void BaseRole::remove(){
	this->removeFromParentAndCleanup(true);
}
