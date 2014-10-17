/************************************************************************/
/* 
��Ҫʵ�ֵĹ��ܣ�
		1.�̳��� Sprite
		2.���ԣ�
				m_hp//Ѫ��
				move()�ƶ�   �麯��
				m_speed�ٶ�
				m_attack�����ˣ����ǵĹ�����Ϊ0��
				jump()��  �麯��
				hurt()    �麯��
				die()   ����  �麯��
				bornAnimate() ��������  �麯��
				dieRunAnimation()��������    �麯��  ͨ�����ഫ����������Ƭ������������

			
*******************************************************************/

#ifndef __BASEROLE_H_
#define __BASEROLE_H_

#include "cocos2d.h"

using namespace cocos2d;

class BaseRole:public Sprite{

protected:
	int m_hp;					//Ѫ��
	int m_speed;				//�ٶ�
	int m_attack;					//�����ˣ����ǵĹ�����Ϊ0��
	CC_SYNTHESIZE_PASS_BY_REF(bool,m_state,State);				//����״̬


public:
	virtual bool initWithSpriteFrameName(std::string fileName);
	static BaseRole *create(std::string fileName);
		
		void move();					//�ƶ�   �麯��
		
		void jump();						//��  �麯��
		void hurt();					// �麯��
		void die();					  //����  �麯��
		void bornAnimate();				// ��������  �麯��
		void dieRunAnimation(const char *fileNames,...);				//��������    �麯��  ͨ�����ഫ����������Ƭ������������

		void remove();			//����Ļ�Ƴ�
};

#endif
