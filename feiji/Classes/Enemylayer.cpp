#include "Enemylayer.h"
#include "OneEnemyplan.h"
#include "TwoEnemyplan.h"
#include "ThreeEnemylayer.h"
bool Enemylayer::init(){
	if(!Layer::init()){
		return false;;
	}
	//��ʼ��
	t=0;
	quickf=5;
	bigf=0;
	levelt=20;
	outplane=0.8;
	outsum=0;
	//����ʱ��	
	//һ��ص�һ��
	this->schedule(schedule_selector(Enemylayer::addtime),1);
	this->schedule(schedule_selector(Enemylayer::update));
	return true;
}
void Enemylayer::addtime(float t){
	this->t++;
	if(this->t>levelt){
		nextlevel();
	}
}
void Enemylayer::nextlevel(){
	//����
	levelt*+2;
	//��ɻ�����
	if(quickf<50){
	quickf+=5;
	}
	//��ɻ�����
	if(bigf<10){
		bigf++;
	}
}
void Enemylayer::go(){
	int r = CCRANDOM_0_1() * 100;
	if(r < bigf) {
		//���ִ�ɻ�
		ThreeEnemyplan::create(DAFEIJISPEED);
	} else {
		int k = CCRANDOM_0_1() * 100;
		//�ٶ�
		int spe = k < quickf ? QUICKSPEED : BASEPLANSPEED;
		//�����зɻ�
		r = CCRANDOM_0_1() * 100;
		if(r < 20) {
			TwoEnemyplan::create(spe);
		} else {
			OneEnemyplan::create(spe);
		}
	}
}

void Enemylayer::update(float t){
	outsum+=t;
	if(outsum>outplane){
		//����ɻ�
		go();
		outsum=0;
	}
}
