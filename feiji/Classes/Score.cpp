#include "Score.h"
#include "plans.h"
#include "Bullets.h"
bool Score::init(){
	if(!Layer::init()){
		return false;
	}
	//��ǰ�ɼ�
	curScore=0;
	//��߳ɼ�
	maxScore=0;
	this->schedule(schedule_selector(Score::boundingTest));
	return true;
}
void Score::boundingTest(float t){
	auto bullets = Bullets::getInstance()->bulletsVector;
	auto enemys = plans::getInstance()->plansVector;
	for(int i=0;i<enemys.size();i++){
		BaseEnemyplan* enemy =enemys.at(i);
		for(int j=0;j<bullets.size();j++){
			BaseBullet* nbullet =bullets.at(j);
			if(enemy->getBoundingBox().intersectsRect(nbullet->getBoundingBox())){
			//�ӵ���ʧ

				nbullet->remove();
				Bullets::getInstance()->deleteBullet(nbullet);
				//�л���ʧ
// 				enemy->remove();
// 				plans::getInstance()->deleteEnemy(enemy);
				break;
				
		     }
	    }
    }
 }