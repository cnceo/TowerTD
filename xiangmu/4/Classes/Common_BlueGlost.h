#ifndef __COMMON_BLUEGLOST_H_
#define __COMMON_BLUEGLOST_H_
#include "Conf.h"
#include "BaseCommon.h"

#define kCommon_BlueGlostSpeed 100
#define kCommon_BlueGlostHp 100
#define kCommon_BlueGlostFileName "EnemyCommon_one1.png"
class Common_BlueGlost:public BaseCommon
{
protected:
	//���ж���
	virtual void enemyFly();
	//��������
	virtual ActionInterval * enemyDie();
public:
	static Common_BlueGlost *create(int sb, int level);
	virtual bool initWithSpriteFrameName(int sb, int level);
 	virtual void onEnter();
};
#endif