//
//  Functon.h
//  TexasPoker������
//
//  ��׼��ö��, ��׼����
//
//  Created by Ԭ���� on 14-9-13.
//
//	 ���� 2014�� 9.19 ����: ��class PokerArray; �ȷ��� namespace TexasPoker��
//                                        ���ļ�������
//
//
//

#ifndef __TexasPoker__Functon__
#define __TexasPoker__Functon__

#include <iostream>
#include <cocos2d.h>
using namespace cocos2d;

namespace TexasPoker {


	class PokerArray;
	class Room;
	class Poker;
	class Hall;
	class Player;
	enum class PokerMethod;
	enum class pokerColor;


    /**����������*/
    class Function{
		public:
        /**
         *  ������ע�������Ѻû����
         *
         *  @param score ��������
         *
         *  @return ����һ���Ѻõ��ַ�������; 12000 ���� 1.2��  100.23��
         */
        static std::string getFormatScore(int score);
        
        /**
         *  �������͵�ö�ٷ��غ���
         *
         *  @param method һ��pokerMethod��ö��
         *
         *  @return ��ʽ����ĺ���
         */
        static std::string getStringForPokerMethod(PokerMethod method);
        
        /**
         *  ���ϴ��
         *
         *  @param pokers ����һ���Ѿ�������ϵ�PokerVector
         */
        static void randomVector(Vector<Poker *> & pokers);
        
        /**
         *  ����poker�����ֺͻ�ɫ����һ��fileName
         *
         *  @return std::string fileName
         */
        static std::string getPokerFileNameByPokerNumberAndColor(int number,int color);
        
        /**
         *  ͨ������Vec2 ���v1,v2�ĽǶ�
         *
         *  @param v1 v1 description
         *  @param v2 v2 description
         *
         *  @return �Ƕ�
         */
        static float getAngleByVec21ANDVec22(Vec2 v1,Vec2 v2);
        
        /**����������ƺͺ��ƻ�ȡ��������,�жϵı�׼�Դ�С�ķ�ʽ���ж�;
        @return PokerMethod ���ؽ�����淨����
        */
        static PokerMethod getPokerMethodForHanderAndRiver(Player * player);

        /**�����˿�������,��С����,��ʼ����
        ��һ������: 2 -10 - J - A
        �ڶ�������: ���� - ÷��
        52����ͳһ���,����������yguy
        */
        static Vector<Poker *> sortPokerArray(Vector<Poker *> &_pokerArray);

        /**�����˿�������,����Ƿ�ʼ�ͬ��˳*/
        static bool isRoyalFlush(Vector<Poker *> _pokerArray);
        static bool isRoyalFlush(Player* player);

        /**�����˿�������,ͬ��˳,ͬ�� + ˳��*/
        static bool isStraightFlush(Vector<Poker *> _pokerArray);
        static bool isStraightFlush(Player* player);
        /**�����˿�������,����, 4������һ�� */
        static bool isFourOfAKind(Vector<Poker *> _pokerArray);
        static bool isFourOfAKind(Player* player);
        /**�����˿�������,��«, ���� + һ��*/
        static bool isFullhouse(Vector<Poker *> _pokerArray);
        static bool isFullhouse(Player* player);

        /**�����˿�������,ͬ��, 5����ͬɫ*/
        static bool isFlush(Vector<Poker *> _pokerArray);
        static bool isFlush(Player* player);

        /**�����˿�������,˳��, 5��������*/
        static bool isStraight(Vector<Poker *> _pokerArray);
        static bool isStraight(Player* player);
        /**�����˿�������,����, 3��������һ��*/
        static bool isThreeOfAKind(Vector<Poker *> _pokerArray);
        static bool isThreeOfAKind(Player* player);
        /**�����˿�������,����*/
        static bool isTwoPairs(Vector<Poker *> _pokerArray);
        static bool isTwoPairs(Player* player);

        /**�����˿�������,һ��*/
        static bool isOnePair(Vector<Poker *> _pokerArray);
        static bool isOnePair(Player* player);

        /**�����˿�������,����*/
        static bool isHighCard(Vector<Poker *> _pokerArray);
        static bool isHighCard(Player* player);

        /**��ȡ�˿��ƻ�ɫ, ����ֻ���� int�͵� 1�ڣ�2�죬 3÷�� 4�� */
        static pokerColor getPokerColor(int color);
        //pokerColor getRandomPokeColor();

        /**��ÿһ�ֵ���ң��Ƚ����ͣ�������Ұ����ʹӴ�С�������飬���������������*/
        Player * sortPlayerByCardType(Map<int, Player *> ChairsAtProcess);

        /**��Ϸ����; ���������ϵ�������ҵ����ƺͺ���, ���жԱ�,�����㽱���ʤ��*/
        static void GameClearing(Room *room);

        /**����Ӯ---����Ӯ��*/
        static Vector<Player *> getWinners(Vector<Player *> vPlayer);
        
		/**Ӯ�ҷ�Ǯ*/
		static void winnersGetScore(int totalScore, Vector<Player *> winners);
    };
    
    class TP {
    public:
        static void log(const char * format, ...);
    };
    
}
#endif /* defined(__TexasPoker__Functon__) */
