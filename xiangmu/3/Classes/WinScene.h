#ifndef __WINSCENE_H
#define __WINSCENE_H
#include "cocos2d.h"
using namespace cocos2d;
class WinScene:public Scene{
private:
	//ɱ����
	int Number;
	int reNumber;
	Label *NumberLabel;
	//˫��
	void changeClick(float dt);
	bool doubleclick;
public:
	//ɱ����
	void setNumber(int Number);
	void resetScore(float t);
public:
	virtual bool init();
	CREATE_FUNC(WinScene);
};
#endif // !__WINSCENE_H
