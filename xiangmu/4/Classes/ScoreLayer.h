#ifndef __SCORELAYER_H
#define __SCORELAYER_H

#include "cocos2d.h"
/************************************************************************/
/* ���ֲ� ���û����Լ���ͣ��ť                                                                     */
/************************************************************************/
class ScoreLayer : public cocos2d::Layer
{
	~ScoreLayer();
protected:
	cocos2d::Label * label ;
	//������ʾ
	void viewScore(Ref *);
	//������ʾ
	void viewprops(Ref *);
	//������ͣ��ť
	void createPause();
	void deleteProps(Ref *);
	std::vector<cocos2d::Sprite *>nowTools;
public:
	CC_SYNTHESIZE(int,_isScore,nowScore);
	void onEnter();
    int getvectornumber();
	virtual bool init();

	CREATE_FUNC(ScoreLayer);
};

#endif // __HELLOWORLD_SCENE_H__