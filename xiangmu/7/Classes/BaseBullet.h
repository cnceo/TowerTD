/************************************************************************/
/* 
��Ҫʵ�ֵĹ��ܣ�
		���ԣ�
				1.m_attack  ������
				2.m_range   ���
				3.die()     ����
				4.move()    �ƶ�
				5.m_state  ״̬��״̬��ͬ���䲻ͬ���ӵ���

*/
/************************************************************************/
#ifndef __BASEBULLET_H_
#define __BASEBULLET_H_

#include "cocos2d.h"

using namespace cocos2d;

class BaseBullet:public Sprite{

protected:
	CC_SYNTHESIZE(int,m_range,M_range);		//   ���
	Size m_vsize;		//��������С
public:
	
	virtual bool init(std::string fileName);
	static BaseBullet * create(std::string fileName);
	virtual void die();			// ����
	void move();		//   �ƶ�	
	CC_SYNTHESIZE_PASS_BY_REF(bool,m_state,State);

};

#endif