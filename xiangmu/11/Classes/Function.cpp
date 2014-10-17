//
//  Functon.cpp
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//
//

#include "Function.h"
#include "Poker.h"
#include "Config.h"
#include "Player.h"

using namespace TexasPoker;

// ������ҽ�����淨����
PokerMethod Function::getPokerMethodForHanderAndRiver(Player * player){

	if (isRoyalFlush(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::RoyalFlush) ;
		return PokerMethod::RoyalFlush;
	}else if(isStraightFlush(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::StraightFlush);
		return PokerMethod::StraightFlush;
	}else if(isFourOfAKind(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::FourOfAKind);
		return PokerMethod::FourOfAKind;
	}else if(isFullhouse(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::Fullhouse);
		return PokerMethod::Fullhouse;
	}else if(isFlush(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::Flush);
		return PokerMethod::Flush;
	}else if(isStraight(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::Straight);
		return PokerMethod::Straight;
	}else if(isThreeOfAKind(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::ThreeOfAKind);
		return PokerMethod::ThreeOfAKind;
	}else if(isTwoPairs(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::TwoPairs);
		return PokerMethod::TwoPairs;
	}else if(isOnePair(player))
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::OnePair);
		return PokerMethod::OnePair;
	}else
	{
		player->getPoker_Array()->setPoker_Method(TexasPoker::PokerMethod::HighCard);
		return PokerMethod::HighCard;
	}
}

std::string Function::getStringForPokerMethod(PokerMethod method){
    auto language = TexasPoker::Config::LANGUAGE::getInstance()->AT("Config").asValueMap();

    switch (method) {
        case PokerMethod::RoyalFlush: return language.at("RoyalFlush").asString(); break;
        case PokerMethod::StraightFlush: return language.at("StraightFlush").asString(); break;
        case PokerMethod::FourOfAKind: return language.at("FourOfAKind").asString(); break;
		case PokerMethod::Fullhouse: return language.at("Fullhouse").asString(); break;
        case PokerMethod::Flush: return language.at("Flush").asString(); break;
        case PokerMethod::Straight: return language.at("Straight").asString(); break;
        case PokerMethod::ThreeOfAKind: return language.at("ThreeOfAKind").asString(); break;
        case PokerMethod::TwoPairs: return language.at("TwoPairs").asString(); break;
        case PokerMethod::OnePair: return language.at("OnePair").asString(); break;
        case PokerMethod::HighCard: return language.at("HighCard").asString(); break;
        default:return language.at("HighCard").asString();break;
    }
    
}

// �ʼ�ͬ��˳
bool Function::isRoyalFlush(Vector<Poker *> _pokerArray){
    return true;
}

// �ʼ�ͬ��˳ ���غ���
bool Function::isRoyalFlush(Player * player){
	//�����ͬ��˳���������һ������A����Ϊ�ʼ�ͬ��˳
	if (isStraightFlush(player) && (player->getPoker_Array()->bestPokerGroup.at(0)->getNo() == 14)  )
	{
		return true;
	}

	return false;
}


// ͬ��˳
bool Function::isStraightFlush(Vector<Poker *> _pokerArray){
    return true;
}
// ͬ��˳  ���غ���
bool Function::isStraightFlush(Player * player){
	player->getPoker_Array()->bestPokerGroup.clear();

	Vector<Poker *> temp ;
	/**����*/
	int spade = 0;
	/**����*/
	int heart = 0;
	/**÷��*/
	int club = 0;
	/**����*/
	int diamond = 0;

	int len = (int)player->getPoker_Array()->allPokerVector.size();

	for (int i = 0; i < len; i++)
	{
		switch (player->getPoker_Array()->allPokerVector.at(i)->getPokerColor())
		{
		case pokerColor::SPADE:
			spade++;
			break;

		case pokerColor::HEART:
			heart++;
			break;

		case pokerColor::CLUB:
			club++;		
			break;

		case pokerColor::DIAMOND:
			diamond++;			
			break;

		default:
			break;
		}
	}
	if (spade >= 5)
	{
		for (int i = 0; i < len; i++)
		{
			if (player->getPoker_Array()->allPokerVector.at(i)->getPokerColor() == pokerColor::SPADE)
			{
				temp.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			}
		}
	}else if (heart >= 5)
	{
		for (int i = 0; i < len; i++)
		{
			if (player->getPoker_Array()->allPokerVector.at(i)->getPokerColor() == pokerColor::HEART)
			{
				temp.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			}
		}
	}else if (club >= 5)
	{
		for (int i = 0; i < len; i++)
		{
			if (player->getPoker_Array()->allPokerVector.at(i)->getPokerColor() == pokerColor::CLUB)
			{
				temp.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			}
		}
	}else if (diamond >= 5)
	{
		for (int i = 0; i < len; i++)
		{
			if (player->getPoker_Array()->allPokerVector.at(i)->getPokerColor() == pokerColor::DIAMOND)
			{
				temp.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			}
		}
	}

	//������ʱ�洢��ͬ�����飬�����Ƿ���5������˳�ӵ����
	int count = 0;
	int len2 = (int)temp.size();

	for (int i = 0; i < len2; i++)
	{
		if (i + 1 < len2)
		{
			if (temp.at(i)->getNo() == temp.at(i + 1)->getNo() + 1)
			{
				count++;
				if (count == 4)
				{
					for (int j = i - 3; j <= i + 1; j++)
					{
						player->getPoker_Array()->bestPokerGroup.pushBack(temp.at(j));
					}
					return true;
				}
			}else
			{
				count = 0;
			}
		}

	}
	return false;
}


// ����
bool Function::isFourOfAKind(Vector<Poker *> _pokerArray){
	return true;
}
// ����  ���غ���
bool Function::isFourOfAKind(Player * player){
    player->getPoker_Array()->bestPokerGroup.clear();

	//������
	int count = 0;

    //������ʱ���������
	Vector<Poker *> vFour;
    
	int len = 0;
	//������鳤��
	len = (int)player->getPoker_Array()->allPokerVector.size();

	for (int i = 0; i < len; i++){
		if ((i+1)< len){
			if (player->getPoker_Array()->allPokerVector.at(i)->getNo() == player->getPoker_Array()->allPokerVector.at(i + 1)->getNo()){
				count++;
				if (count == 3){
					//�õ�����
					for (int j = i - 2; j <= i + 1; j++){
						vFour.pushBack(player->getPoker_Array()->allPokerVector.at(j));
					}
					break;
				}
			}
			else{
				count = 0;
			}
		}
	}
	/**
	*�����������ԭ����
	*�Ȱ������Ž�ȥ
	*�ڰ�ԭ����ŵĵ�һ�ŷŽ�ȥ
	*/
    if(vFour.size() == 0 ){
        return false;
    }
    
	if (vFour.at(0) == player->getPoker_Array()->allPokerVector.at(0)){
		vFour.pushBack(player->getPoker_Array()->allPokerVector.at(4));
	}
	else{
		vFour.pushBack(player->getPoker_Array()->allPokerVector.at(0));
	}
	player->getPoker_Array()->bestPokerGroup = vFour;
	if (count == 3){
		return true;
	}
	return false;

}


// ��«
bool Function::isFullhouse(Vector<Poker *> _pokerArray){

    return true;
}
// ��«  ���غ���
bool Function::isFullhouse(Player * player){
    player->getPoker_Array()->bestPokerGroup.clear();

    
	int count_pair = 0;
	int count_three = 0;
	Vector<Poker *> vPair;
	Vector<Poker *> vThree;

	// ���� 3��
	for (int i=0 ; i < player->getPoker_Array()->allPokerVector.size(); i++){
		if ((i+1) >= player->getPoker_Array()->allPokerVector.size()){
			break;
		}
		if ((i+2) >= player->getPoker_Array()->allPokerVector.size()){
			break;
		}
		int poke01 = player->getPoker_Array()->allPokerVector.at(i)->getNo();
		int poke02 = player->getPoker_Array()->allPokerVector.at(i+1)->getNo();
		int poke03 = player->getPoker_Array()->allPokerVector.at(i+2)->getNo();

		if (poke01 == poke02 && poke01 == poke03){
			// ������ �ӽ�ȥ
			vThree.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			vThree.pushBack(player->getPoker_Array()->allPokerVector.at(i+1));
			vThree.pushBack(player->getPoker_Array()->allPokerVector.at(i+2));

			count_three++;
			break;
		}
	}

	// ���� һ��
	for (int i=0 ; i < player->getPoker_Array()->allPokerVector.size(); i++){
		if ((i+1) >= player->getPoker_Array()->allPokerVector.size()){
			break;
		}
		int poke01 = player->getPoker_Array()->allPokerVector.at(i)->getNo();
		int poke02 = player->getPoker_Array()->allPokerVector.at(i+1)->getNo();

		if (vThree.size() == 0){
			break;
		}

		if (poke01 == poke02 && poke01 != vThree.at(0)->getNo()){
			// ������ �ӽ�ȥ
			vPair.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			vPair.pushBack(player->getPoker_Array()->allPokerVector.at(i+1));

			count_pair++;
			break;
		}
	}

	if (count_pair ==1 && count_three == 1){
        
        /***
         *������ǰ��һ���ں�
         *�ȼ�����
         *���һ��
         */
        for (int i = 0; i < 3; i++){
            player->getPoker_Array()->bestPokerGroup.pushBack(vThree.at(i));
        }
        
        for (int i = 0; i < 2; i++){
            player->getPoker_Array()->bestPokerGroup.pushBack(vPair.at(i));
        }
        
        return true;
    }
    
	return false;
}


// ͬ��
bool Function::isFlush(Vector<Poker *> _pokerArray){
	/**����*/
	int spade = 0;
	/**����*/
	int heart = 0;
	/**÷��*/
	int club = 0;
	/**����*/
	int diamond = 0;
	
	for (int i = 0; i < _pokerArray.size(); i++)
	{
		switch (_pokerArray.at(i)->getPokerColor())
		{
		case pokerColor::SPADE:
			spade++;
			//���ͬɫ�Ƴ������ţ���Ѵ�����֮ǰ�ĸ�Ԫ�ر������ҵ�����ɫ���ƵĴ�Сֵ��
			//����player�е�pokerArrayָ�����õ����������顣����ͬ��
			if (spade == 5)
			{					
				return true;
			}
			break;

		case pokerColor::HEART:
			heart++;
			if (heart == 5)
			{			
				return true;
			}
			break;

		case pokerColor::CLUB:
			club++;
			if (club == 5)
			{		
				return true;
			}
			break;

		case pokerColor::DIAMOND:
			diamond++;
			if (diamond == 5)
			{				
				return true;
			}
			break;

		default:
			break;
		}

	}
    return false;
}
// ͬ��  ���غ���
bool Function::isFlush(Player * player){
    player->getPoker_Array()->bestPokerGroup.clear();

	/**����*/
	int spade = 0;
	/**����*/
	int heart = 0;
	/**÷��*/
	int club = 0;
	/**����*/
	int diamond = 0;

	int len = (int)player->getPoker_Array()->allPokerVector.size();

	for (int i = 0; i < len; i++)
	{
		switch (player->getPoker_Array()->allPokerVector.at(i)->getPokerColor())
		{
		case pokerColor::SPADE:
			spade++;
			//���ͬɫ�Ƴ������ţ���Ѵ�����֮ǰ�ĸ�Ԫ�ر������ҵ�����ɫ���ƵĴ�Сֵ��
			//����player�е�pokerArrayָ�����õ����������顣����ͬ��
			if (spade == 5)
			{
				for (int j = 0,index = 0; j <= i; j++)
				{
					if (player->getPoker_Array()->allPokerVector.at(j)->getPokerColor() == pokerColor::SPADE)
					{
						player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(j));
						index++;
					}

				}		
				return true;
			}
			break;

		case pokerColor::HEART:
			heart++;
			if (heart == 5)
			{
				for (int j = 0,index = 0; j <= i; j++)
				{
					if (player->getPoker_Array()->allPokerVector.at(j)->getPokerColor() == pokerColor::HEART)
					{
						player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(j));
						index++;
					}

				}
				return true;
			}
			break;

		case pokerColor::CLUB:
			club++;
			if (club == 5)
			{
				for (int j = 0,index = 0; j <= i; j++)
				{
					if (player->getPoker_Array()->allPokerVector.at(j)->getPokerColor() == pokerColor::CLUB)
					{
						player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(j));
						index++;
					}

				}
				return true;
			}
			break;

		case pokerColor::DIAMOND:
			diamond++;
			if (diamond == 5)
			{
				for (int j = 0,index = 0; j <= i; j++)
				{
					if (player->getPoker_Array()->allPokerVector.at(j)->getPokerColor() == pokerColor::DIAMOND)
					{
						player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(j));
						index++;
					}

				}
				return true;
			}
			break;

		default:
			break;
		}

	}
	return false;
}


// ˳��
bool Function::isStraight(Vector<Poker *> _pokerArray){
    return true;
}
// ˳��  ���غ���
bool Function::isStraight(Player * player){
	player->getPoker_Array()->bestPokerGroup.clear();
    
	int count = 0;
	int len = (int)player->getPoker_Array()->allPokerVector.size();

	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len)
		{
			if (player->getPoker_Array()->allPokerVector.at(i)->getNo() == player->getPoker_Array()->allPokerVector.at(i + 1)->getNo() + 1)
			{
				count++;
				if (count == 4)
				{
					for (int j = i - 3; j <= i + 1; j++)
					{
						player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(j));
					}
					return true;
				}
			}else
			{
				count = 0;
			}
		}
		
	}
	return false;
}


// ����
bool Function::isThreeOfAKind(Vector<Poker *> _pokerArray){

    return true;
}
// ����  ���غ���
bool Function::isThreeOfAKind(Player * player){
	player->getPoker_Array()->bestPokerGroup.clear();

	int len = 0;
	int count = 0;
	len = (int)player->getPoker_Array()->allPokerVector.size();
	Vector <Poker* > vThree;

	//����
	for (int i = 0; i < len; i++){
		if (i + 1 < len)
		{
			if (player->getPoker_Array()->allPokerVector.at(i)->getNo() == player->getPoker_Array()->allPokerVector.at(i + 1)->getNo()){
				count++;
				if (count == 2){
					for (int j = i - 1; j <= i + 1; j++)
					{
						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(j));
					}
					if (vThree.at(0)->getNo() < player->getPoker_Array()->allPokerVector.at(1)->getNo()){

						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(0));

						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(1));
					}else if(vThree.at(0)->getNo() == player->getPoker_Array()->allPokerVector.at(0)->getNo()){

						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(3));

						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(4));

					}else if (vThree.at(0)->getNo() == player->getPoker_Array()->allPokerVector.at(1)->getNo())
					{
						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(0));
						vThree.pushBack(player->getPoker_Array()->allPokerVector.at(4));
					}
					player->getPoker_Array()->bestPokerGroup = vThree;
					break;
				}
				
			}else
			{
				count = 0;
			}
			
		}
			
	}
	if (count == 2){
		return true;
	}
	return false;
}


// ����
bool Function::isTwoPairs(Vector<Poker *> _pokerArray){
    return true;
}
// ����  ���غ���
bool Function::isTwoPairs(Player * player){
    player->getPoker_Array()->bestPokerGroup.clear();

	// ������
	int count = 0;

	// ������õ�5����
	Vector<Poker *> vTwoPair;
	auto it_1 = player->getPoker_Array()->allPokerVector.begin();
	auto it_2 = player->getPoker_Array()->allPokerVector.begin();
	for ( ; it_1 != player->getPoker_Array()->allPokerVector.end(); it_1++){
		it_2++;

		if (it_2 == player->getPoker_Array()->allPokerVector.end()){
			break;
		}

		if ((*it_1)->getNo() == (*it_2)->getNo() && count <2){
			// ��һ�� �ӽ�ȥ
			vTwoPair.pushBack(*it_1);
			vTwoPair.pushBack(*it_2);
			count++;
		}
	}
	player->getPoker_Array()->bestPokerGroup = vTwoPair;

	if (count == 2){
		for (int i = 0; i < player->getPoker_Array()->allPokerVector.size(); i++){
			if (player->getPoker_Array()->allPokerVector.at(i)->getNo() != vTwoPair.at(0)->getNo() && 
				player->getPoker_Array()->allPokerVector.at(i)->getNo() != vTwoPair.at(2)->getNo()){
				player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(i));
				break;
			}
		}
		return true;
	}
	return false;
}


// һ��
bool Function::isOnePair(Vector<Poker *> _pokerArray){
    return true;
}
//  һ��  ���غ���
bool Function::isOnePair(Player * player){
    player->getPoker_Array()->bestPokerGroup.clear();

	// ������
	int count = 0;

	// ������õ�5����
	//Vector<Poker *> bestPokerGroup;

	auto it_1 = player->getPoker_Array()->allPokerVector.begin();
	auto it_2 = player->getPoker_Array()->allPokerVector.begin();
	for ( ; it_1 != player->getPoker_Array()->allPokerVector.end(); it_1++){
		it_2++;

		if (it_2 == player->getPoker_Array()->allPokerVector.end()){
			break;
		}

		if ((*it_1)->getNo() == (*it_2)->getNo()){
			// ��һ�� �ӽ�ȥ
			player->getPoker_Array()->bestPokerGroup.pushBack(*it_1);
			player->getPoker_Array()->bestPokerGroup.pushBack(*it_2);
			count++;
			break;
		}
	}

	if (count == 1){
		for (int i = 0; i< count; i++){
			it_2--;
		}
		// �ж� һ�� ��_pokerArray�е�λ�ã��Ա�ȡֵ
		for (int i = 0; i < player->getPoker_Array()->allPokerVector.size(); i++){
			// �ж� size = 5
			// �ж� ����һ��
			if (player->getPoker_Array()->allPokerVector.at(i)->getNo() != (*it_2)->getNo() && player->getPoker_Array()->bestPokerGroup.size() < 5){
				player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(i));
			}
		}
		return true;
	}
	return false;
}


// ����
bool Function::isHighCard(Vector<Poker *> _pokerArray){
    return true;
}
// ����  ���غ���
bool Function::isHighCard(Player * player){
    player->getPoker_Array()->bestPokerGroup.clear();

	for (int i = 0; i < player->getPoker_Array()->allPokerVector.size() && i<5; i++)
	{
		player->getPoker_Array()->bestPokerGroup.pushBack(player->getPoker_Array()->allPokerVector.at(i));
	}
	return true;
}
//����
Player * Function::sortPlayerByCardType(Map<int, Player *> ChairsAtProcess){
	for (int i = 1; i <=9; i++)
	{
		Player * player = ChairsAtProcess.at(i);

		if (player == NULL) {
			continue;
		}
		Function fun;
		fun.getPokerMethodForHanderAndRiver(player);
	}

	//������ʱ����������Դ���ԭ������б���
	Map<int,Player *> tempPlayerMap;
	tempPlayerMap = ChairsAtProcess;

	//��ʱ���飬�����ʹӴ�С��˳�������
	for (int i = 1; i <= 9; i++)
	{
		//����һ������������ң���ʼ��Ϊ��ָ�������һ�����
		Player * maxPlayer = nullptr;
		Player * player_1 = tempPlayerMap.at(i);
		maxPlayer = player_1;

		for (int j = i + 1; j <= 9; j++)
		{
			Player * player = tempPlayerMap.at(j);
			if (player->getPoker_Array()->getPoker_Method() > maxPlayer->getPoker_Array()->getPoker_Method())
			{
				maxPlayer = player;
			}
		}

// 		for (int i = 1; i <= 9; i++)
// 		{
// 			if ()
// 			{
// 			}
// 		}
	}
	return nullptr;
}

// ����Ӯ---����Ӯ��
Vector<Player *> Function::getWinners(Vector<Player *> vPlayer){
	//���յ� Ӯ�ҵ� Vector
	Vector<Player *> winPlayer;
	//���͵� Ӯ�ҵ� Vector
	Vector<Player *> winPlayer_pokerType;
    
    // �޳����Ƶ����
	for (int i=0; i<vPlayer.size(); i++){
		if (vPlayer.at(i)->getPlayerGameState() == ePlayerGameState::FOLD) {
			vPlayer.eraseObject(vPlayer.at(i),true);
			i--;
		}
	}
	
    
	//������ҵ�����, �ҵ�������ͣ����� while()
	int type = (int)vPlayer.at(0)->getPoker_Array()->getPoker_Method();
	int typeJ;
    //�жϳ��������
	for (int i = 0; i < vPlayer.size(); i++){
		if ((i+1)< vPlayer.size()){
			typeJ = (int)vPlayer.at(i+1)->getPoker_Array()->getPoker_Method();
			if (typeJ < type){
				type = typeJ;
			}
		}
	}
	for (int i = 0; i<vPlayer.size(); i++){
		if ( type== (int)vPlayer.at(i)->getPoker_Array()->getPoker_Method()){
			winPlayer_pokerType.pushBack(vPlayer.at(i));
		}
	}
    log("winPlayer_pokerType.size() %zd",winPlayer_pokerType.size());
	if (winPlayer_pokerType.size() == 1){
		return winPlayer_pokerType;
	}
    
    
	//�����͵Ļ����ϣ��Ƚ���õ�5���ƣ��ж�����Ӯ�ң�����Ӯ�� Vector
	for (int i = 0; i< winPlayer_pokerType.size(); i++){
        log("Function::getWinners i: %d, winPlayer_pokerType.size() %zd",i,winPlayer_pokerType.size());
        
        if (winPlayer_pokerType.size() == 1) {
            return winPlayer_pokerType;
        }
        
		Vector<Poker *> v1 = winPlayer_pokerType.at(i)->getPoker_Array()->bestPokerGroup;
        
		if ((i+1) < winPlayer_pokerType.size()){
			Vector<Poker *> v2 = winPlayer_pokerType.at(i+1)->getPoker_Array()->bestPokerGroup;
			// ��5�������
			for (int j = 0; j < 5; j++){
				if (v1.at(j)->getNo() < v2.at(j)->getNo()){
					int k = 0;
					for (; k <= i; k++){

                        log("Function::getWinners k: %d , del",k);
						winPlayer_pokerType.eraseObject(winPlayer_pokerType.at(0), true);

					}
                    log("Function::getWinners k: %d i: %d", k,i);
					i = -1;
					break;
				}
				if (v1.at(j)->getNo() > v2.at(j)->getNo()){
					winPlayer_pokerType.
                    eraseObject(winPlayer_pokerType.at(i+1), true);
                    log("Function::getWinners j: %d i: %d , del ",j,i);
					i--;
                    break;
				}
			}
		}
	}
	winPlayer = winPlayer_pokerType;
	return winPlayer;
}

/**Ӯ�ҷ�Ǯ*/
void Function::winnersGetScore(int totalScore, Vector<Player *> winners){
	int winners_count = (int)winners.size();
	int score = 0;
	if (winners_count > 0)
	{
		score = totalScore/winners_count;
	}else
	{
		log("winners_count less than zero ");
	}

	for (int i = 0; i< winners.size(); i++){
		winners.at(i)->plusRoomScore(score);
	}
    log("Function::winnersGetScore score: %d, winners_count: %d",score,winners_count);
}


// ��Ϸ����; ���������ϵ�������ҵ����ƺͺ���, ���жԱ�,�����㽱���ʤ��
void Function::GameClearing(Room *room){

    return;
}

pokerColor Function::getPokerColor(int color){
	switch (color)
	{
	case 1: return pokerColor::SPADE; break;
	case 2: return pokerColor::HEART; break;
	case 3: return pokerColor::CLUB; break;
	case 4: return pokerColor::DIAMOND; break;
	default:
		return pokerColor::SPADE;
		break;
	}
    return pokerColor::SPADE;
}

/**
 *  ��ȡ����Vec2֮��ĽǶ�
 *
 *  @param v1 �Ƕ�1(Բ�ĵ�)
 *  @param v2 �Ƕ�2(Ŀ���)
 *
 *  @return ����һ������
 */
float Function::getAngleByVec21ANDVec22(Vec2 v1,Vec2 v2){
    float angle = v1.getAngle(v2);
    float jiaodu = angle * 180/3.1415926 ;
    if (v2.x>v1.x && v2.y>v1.y) {
        ;
    }else if (v2.x<v1.x && v2.y>v1.y){
        jiaodu = -jiaodu;
        jiaodu = 180 - jiaodu;
    }else if(v2.x<v1.x && v2.y<v1.y){
        jiaodu = 180 + jiaodu;
    }else if (v2.x>v1.x && v2.y<v1.y){
        jiaodu = -jiaodu;
        jiaodu = 360 - jiaodu;
    }
    return jiaodu;
}

void Function::randomVector(Vector<Poker *> & pokers){
    random_shuffle(pokers.begin(), pokers.end(),
                 [](int i)->int{
                     srand((int)clock());
//                                     srand(time(0));
                     return rand()%i;
                 }
    );
}

std::string Function::getPokerFileNameByPokerNumberAndColor(int number,int color){
    std::string fileName = StringUtils::format("POKER/%d%d.png",number,color);
    
    return fileName;
}

std::string Function::getFormatScore(int score){

	auto language = Config::LANGUAGE::getInstance()->AT("Unit").asValueMap();
	std::string unit = language.at("wan").asString();
	
	if (score >= 1000000)
	{
		float s = ((float)score)/10000.0f;
		return StringUtils::format("%.2f%s",s,unit.c_str());
	} 
	else if (score >= 10000)
	{		
		if (score%10000 == 0)
		{
			int s = score/10000;
			return StringUtils::format("%d%s",s,unit.c_str());
		}else if(score%1000 == 0)
		{
			float s = ((float)score)/10000.0f;
			return StringUtils::format("%.1f%s",s,unit.c_str());
		}else if(score%100 == 0)
		{
			float s = ((float)score)/10000.0f;
			return StringUtils::format("%.2f%s",s,unit.c_str());
		}else if(score%10 == 0)
		{
			float s = ((float)score)/10000.0f;
			return StringUtils::format("%.3f%s",s,unit.c_str());
		}else
		{
			float s = ((float)score)/10000.0f;
			 return StringUtils::format("%.4f%s",s,unit.c_str());
		}			
	}
    return StringUtils::format("%d",score);
}


static void _log(const char *format, va_list args)
{
    char buf[MAX_LOG_LENGTH];
    
    vsnprintf(buf, MAX_LOG_LENGTH-3, format, args);
    strcat(buf, "\n");
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info",  "%s", buf);
    
#elif CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT || CC_TARGET_PLATFORM == CC_PLATFORM_WP8
    WCHAR wszBuf[MAX_LOG_LENGTH] = {0};
    MultiByteToWideChar(CP_UTF8, 0, buf, -1, wszBuf, sizeof(wszBuf));
    OutputDebugStringW(wszBuf);
    WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, buf, sizeof(buf), nullptr, FALSE);
    printf("%s", buf);
    fflush(stdout);
#else
    // Linux, Mac, iOS, etc
    fprintf(stdout, "cocos2d: %s", buf);
    fflush(stdout);
#endif
    
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    Director::getInstance()->getConsole()->log(buf);
#endif
    
}

void TP::log(const char * format, ...){
    if(Config::DEBUG){
        va_list args;
        va_start(args, format);
        _log(format, args);
        va_end(args);
    }
}