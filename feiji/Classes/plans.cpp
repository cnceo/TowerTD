#include "plans.h"
//�ɻ���������
plans * plans::instance =nullptr;
plans * plans::getInstance() 
{
	if(!instance)
	{
		instance =new plans();
	}
	return instance;
}
void plans::addplan(BaseEnemyplan * bt)
{
	plansVector.pushBack(bt);
}
void plans::deleteEnemy(BaseEnemyplan* enemy){
	//������ɾ��
	plansVector.eraseObject(enemy);
	//���õл��ķ���ɾ���Լ�
	//enemy->remove();
}
