//
//  Player.h
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//
//  ����   ʱ��         �޸�����
//  Ԭ���� 2014��9��18�� �޸��������
//
//	 ���� 2014��9��19�� �޸� bool GameState=0;
//
//
//

#ifndef __TexasPoker__Player__
#define __TexasPoker__Player__

#include <iostream>
#include <cocos2d.h>
using namespace cocos2d;

#include "Poker.h"

namespace TexasPoker {
    class PokerAction;
	class Function;
	class PokerArray;

    /**�����Ϸ״̬*/
    enum class ePlayerGameState{
        /**����*/
        NORMAL = 1 ,
		/**վ��*/
		STANDUP,
        /**����*/
        FOLD
    };
    
    enum class ePlayerType{
        /**��ͨ���*/
        NORMAL,
        /**�������*/
        AI
    };
    
    /**���*/
    class Player : public Node{
	public:
		/**��Ҹ��˹���(����Ϸ��)����*/
		CC_SYNTHESIZE(int, id, ID);	///< ���id

		CC_SYNTHESIZE(std::string, name, Name);		///< �������

		CC_SYNTHESIZE(char, sex, Sex);		///< ����Ա�	

		CC_SYNTHESIZE(int, totalScore, TotalScore);		///< ����ܻ���
        
        /**
         *  ��ҷ�����ڵĳ���
         */
		CC_SYNTHESIZE(int, score, Score);			///< ��ҷ�����ڵĳ���

		CC_SYNTHESIZE(std::string, playerImageFileName, PlayerImageFileName);			///< ���ͷ���ļ���

    public:
		/**��Ҹ�����Ϸ������*/
		CC_SYNTHESIZE(ePlayerType, playerType, PlayerType);	///< �������:��ͨ���,AI����

		CC_SYNTHESIZE(int, playerIndex, PlayerIndex);	///< ��ҵĵ�ǰλ��

		CC_SYNTHESIZE(ePlayerGameState,playerGameState,PlayerGameState);	///< �����Ϸ״̬

		CC_SYNTHESIZE(bool,gameState,GameState);	///< �Ƿ����ڽ�����Ϸ�� true Or false

		CC_SYNTHESIZE(PokerAction *, poker_Action, Poker_Action);	///< ����������


		CC_SYNTHESIZE(PokerArray *, poker_Array, Poker_Array);	///< ��ҵ� ���ƺͺ���

	public:
        /**Player �� init() */
		virtual bool init(ePlayerGameState playerGameState, int _id,
			std::string name, char sex, int totalScore, int score);

		/**������ҵķ�����Я������*/
		void plusRoomScore(int _score);

		
		/**����������*/
		void clearHand();

		/**��� ���ÿ��Ͷע������ĳ���*/
		int getTempScore();
        
		/**���� ���ÿ��Ͷע������ĳ���*/
		void addTempScore(int _tempScore);
        
        /**
         *  ������ҵ�ÿ��Ͷע���������ʱ����,�ֳ�ʱ��Ҫʹ�ô˺���
         *
         *  @param _tempScore Ҫ���ٵĳ���
         */
        void subTempScore(int _tempScore);
    private:
        int tempScore;		///< ���ÿ��Ͷע������ĳ���

        /**��ȥ��ҵķ�����Я������*/
		void subRoomScore(int _score);
    };
}
#endif /* defined(__TexasPoker__Player__) */
