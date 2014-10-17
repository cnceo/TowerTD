#ifndef __BOUNDINGLAYER_H_
#define __BOUNDINGLAYER_H_
#include "cocos2d.h"
#include "BaseBlock.h"
#include "BaseTools.h"
USING_NS_CC;

class BoundingLayer : public Layer{
public:
	CREATE_FUNC(BoundingLayer);
protected:
	//����֪ͨ��keyΪ���߻����ϰ�������
	void notification(BaseSprite * sprite);
	virtual bool init();
private:
	void addPhysicsEvent();
};
#endif // !__BOUNDINGLAYER_H_
