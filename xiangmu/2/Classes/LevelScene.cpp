

#include "LevelScene.h"
#include "LevelLayer.h"
#include "ChangeAttackBGLayer.h"

bool LevelScene::init(){
	if (!Scene::init()) {
		return false;
	}
	//����
	auto backGround = ChangeAttackBGLayer::create();
	addChild(backGround);

	//����
	//    auto levelLayer = LevelLayer::create();
	//    addChild(levelLayer);


	return true;
}