#ifndef __TOWER_H_
#define __TOWER_H_
#include "cocos2d.h"
#include "Tower.h"
#include "TowerAI.h"
#include "GlobalInfo.h"
using namespace cocos2d;
class Tower:public Sprite{
public:
	virtual bool init(int id);
	static Tower*create(int id);
	CC_SYNTHESIZE(int, hp,Hp);//����Ѫ��
	CC_SYNTHESIZE(int, scope, Scope);  // ��������
	CC_SYNTHESIZE(float, attack, Attack);   // ɱ����
	CC_SYNTHESIZE(bool,isdie,Isdie);
	CC_SYNTHESIZE(float,firespeed,FireSpeed);//�����ٶ�
	//�ӵ��ƶ��ٶ�
	CC_SYNTHESIZE(int,buspeed,BuSpeed);
	//�ӵ�������
	CC_SYNTHESIZE(int,buattackValue,BuattackValue);
	//�ӵ���
	CC_SYNTHESIZE(std::string,buName,BuName );
	//���ķ�����
	CC_SYNTHESIZE(int,def ,Def);
	//���۸�
	CC_SYNTHESIZE(int,price,Price);
	//������Ч
	CC_SYNTHESIZE(attackEffect,atteffect,AttEffect);
	virtual void fire(Sprite* monster);//���Ŀ��𷽷�
	void towerhurt(int monsterAttack);
	void remove();
	virtual  void die();
	void onEnter();
	
protected:
	
	TowerAI* ai;
	 Tower(){
		 hp =0;
		 scope = 0;
		 attack =0;		
		 isdie = false;
		 ai=nullptr;
		atteffect.firetime = 0;
		atteffect.frozentime = 0;
		atteffect.lowspeedtime = 0;
	 }
    virtual~Tower(){
	}
};
#endif