//
//  Poker.h
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//
//

#ifndef __TexasPoker__Poker__
#define __TexasPoker__Poker__

#include <iostream>
#include <cocos2d.h>
using namespace cocos2d;

#include "Global.h"

namespace TexasPoker {
    /**��׼��ö��: �����淨������*/
    enum class PokerMethod{
        /**�ʼ�ͬ��˳ ͬ��˳ + ���������AΪ����Ƶ����� A,K,Q,J,10*/
        RoyalFlush,
        
        /**ͬ��˳ ,ͬ�� + ˳��*/
        StraightFlush,
        
        /**���� , 4������һ�� */
        FourOfAKind,
        
        /**��«, ���� + һ��*/
        Fullhouse,
        
        /**ͬ��, 5����ͬɫ*/
        Flush,
        
        /**˳�� , 5��������*/
        Straight,
        
        /**���� , 3��������һ��*/
        ThreeOfAKind,
        
        /**����*/
        TwoPairs,
        
        /**һ��*/
        OnePair,
        
        /**����*/
        HighCard

	
    };
    
    /**��׼����: ÿ���˿��ƵĻ�ɫ*/
    enum class pokerColor{
		/**����*/
		SPADE = 1,
        /**����*/
        HEART = 2 ,
		/**÷��*/
		CLUB = 3,
        /**����*/
        DIAMOND = 4
    };
    
    /**��׼����: ÿ���˿��Ƶ�*/
    class Poker : public Sprite{
    public:
        /**�Ƶ�����
         2 - 14
         11:J
         12:Q
         13:K
         14:A
         */
	
        CC_SYNTHESIZE(int, number, No);

        /**�ƵĻ�ɫ*/
		CC_SYNTHESIZE(pokerColor, color, PokerColor);
	public:
		/**
		 *  C++�Ĺ��캯����Ҫʹ��,ʹ��coocs2d�Ĺ��캯��
         *  ʹ�ù���������autorelease();
		 */
		static Poker * create(pokerColor color, int number);
		bool init(pokerColor color, int number);
    };
    
    /**��׼����: �˿�������,���2��,����5��;���û����Ҫ����ΪNULL*/
    class PokerArray : public Ref{
		protected:
			/**�������:hand1,hand2*/
			Vector<Poker *> handVector;

			/**����:river1 - river5*/
			Vector<Poker *> riverVector;		
            
			void PokerSort();

		public:
        void setRiverVector(Vector<Poker *> river);
			/**PokerArray �� ����*/
			static PokerArray* create();

			/**PokerArray �� init()*/
			bool init();

			/**��һ������:hand1,hand2*/
			void setHandVector(Poker * poker);

			/**�����������:hand1,hand2*/
			Vector<Poker *> getHandVector();

			/**��ҵ�����*/
			CC_SYNTHESIZE(TexasPoker::PokerMethod, poker_Method, Poker_Method);

		public:
			/**��ҵ������*/
			Vector<Poker *>  bestPokerGroup;
			/**���ƼӺ�������*/
			Vector<Poker* > allPokerVector;
    };
}
#endif /* defined(__TexasPoker__Poker__) */
