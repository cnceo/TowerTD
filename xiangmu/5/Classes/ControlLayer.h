#ifndef __CONTROLLAYER_H_
#define __CONTROLLAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class Role;

class ControlLayer : public Layer{
public:
	CREATE_FUNC(ControlLayer);
protected:
	virtual bool init();
	//���Ӵ����¼�
	void addTouch();
	//���������Ӧ
	void addGravity();
private:
	void onEnter();
	Role * role;
	//�ж������Ƿ��������ܵ�״̬
	bool isNormal;

};

#endif // !__CONTROLLAYER_H_
