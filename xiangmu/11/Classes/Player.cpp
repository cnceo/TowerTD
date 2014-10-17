//
//  Player.cpp
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//
//

#include "Player.h"
#include "Function.h"
#include "Poker.h"

using namespace TexasPoker;


bool Player::init(ePlayerGameState playerGameState, int _id, std::string name, char sex,
				  int totalScore, int score)
{
	this->playerGameState = playerGameState;
	this->id = _id;
	this->name = name;
	this->sex = sex;
	this->totalScore = totalScore;
	this->score = score;
	this->tempScore = 0;
    
	// ʵ���� ���� �� ���� �� PokerArray
	this->poker_Array = PokerArray::create();
    
	return true;
}

// ������ҵķ�����Я������
void Player::plusRoomScore(int _score){
	this->score += _score;
}

// ��ȥ��ҵķ�����Я������
void Player::subRoomScore(int _score){
	this->score -= _score;
    CCASSERT(this->score>=0, " Player Score Must >= 0 ");
}

// ����������
void Player::clearHand(){
}

// ��� ���ÿ��Ͷע������ĳ���
int Player::getTempScore(){
	return tempScore;
}

// ���� ���ÿ��Ͷע������ĳ���
void Player::addTempScore(int _tempScore){
    this->subRoomScore(_tempScore);
	this->tempScore += _tempScore;
}

void Player::subTempScore(int _tempScore){
    this->tempScore -= _tempScore;
}

