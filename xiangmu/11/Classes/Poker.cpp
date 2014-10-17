//
//  Poker.cpp
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//
//

#include "Poker.h"

using namespace TexasPoker;

//============================ Poker  =============================
Poker * Poker::create(pokerColor color, int number){
	Poker* poker = new Poker();

	if (poker && poker->init(color, number))
	{
		poker->autorelease();
        poker->retain();
        
		return poker;
	}
	CC_SAFE_DELETE(poker);
	return nullptr;
}

bool Poker::init(pokerColor color, int number){
    
    std::string fileName  = TexasPoker::Function::getPokerFileNameByPokerNumberAndColor(number, (int)color);
    
	//if (!Sprite::initWithSpriteFrameName(fileName) ){
	if(!Sprite::initWithFile(fileName)){
        return false;
	}
	this->number = number;
	this->color = color;

	return true;
}

//===========================  PokerArray  ============================

// PokerArray �� ����
PokerArray* PokerArray::create()
{
	PokerArray *pRet = new PokerArray();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
        pRet->retain();
        
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

void PokerArray::setRiverVector(Vector<Poker *> river){
    riverVector = river;
    
    PokerSort();
}

// PokerArray �� init()
bool PokerArray::init(){
	return true;
}

void TexasPoker::PokerArray::PokerSort(){
    if (allPokerVector.size()>0) {
        allPokerVector.clear();
    }
    
	//�Ѻ��ƷŽ�allPokerVector����
	allPokerVector = riverVector;

	//�����ƷŽ�allPokerVector
    for(auto it : handVector){
        allPokerVector.pushBack(it);
    }
    
	//�������������
	int len = (int)allPokerVector.size();
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - i - 1; j++){
			if (allPokerVector.at(j)->getNo() < allPokerVector.at(j + 1)->getNo()){
				allPokerVector.swap(j,j+1);
			}
		}
	}
}

// ���� �������:hand1,hand2
void PokerArray::setHandVector(Poker * poker){
	this->handVector.pushBack(poker);
}

// ���� �������:hand1,hand2
Vector<Poker *> PokerArray::getHandVector(){
	return handVector;
}
