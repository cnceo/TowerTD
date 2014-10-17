#include "DelegetLayer.h"
#include "uiRiskLayer.h"

bool DelegetLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//��ʼUI��
	auto risklayer = uiRiskLayer::create();
	this->addChild(risklayer);
	return true;
}