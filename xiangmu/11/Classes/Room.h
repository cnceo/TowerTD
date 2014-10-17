//
//  Room.h
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//  Ԭ���� 2014��9Լ18�� ����
//

#ifndef __TexasPoker__Room__
#define __TexasPoker__Room__


#include <iostream>

#include <cocos2d.h>
using namespace cocos2d;

#include "Player.h"
#include "Poker.h"

#include <cocostudio/CocoStudio.h>
using namespace cocostudio;

#include <ui/CocosGUI.h>
using namespace ui;

namespace TexasPoker {

    class ProcessControl;
    class Hall;
    
    
    /**����*/
    class Room : public Layer{
    public:
        void initUI();
        void intiAudio();
        virtual void onEnter();
        
        /**
         �ɹ�
         */
        void initDila();
        
			/**���� Room ����*/
			static Scene * createScene(int id,int ScoreMax,int ScoreMin);

			/**���� Room*/
			static Room * create(int _id,int ScoreMax,int ScoreMin);

			/**��д Room �� init ����*/
			virtual bool init(int _id,int ScoreMax,int ScoreMin);

			/**onEnterTransitionDidFinish ����*/
			void onEnterTransitionDidFinish();

		public:
			/**��÷���ID*/
			int getID();
        
			/**������̿�����*/
			//ProcessControl * getProcessControl();
        
			/**�������Я����߽��*/
			int getScoreMax();
        
			/**��������ע���*/
			int getScoreMin();
        
			/**�����λ 1-9*/
			//Map<int, Player *> getChairs(); �޸�����
			Map<int, Player *> getChairs_Players();

			//void setChairs(int chairId, Player *player);
        
        
			/**����������*/
			int getPlayerCount();
        
			/**����������
			 1. ����1��������ϴ��� 
			 processControl->Start();
			 */
			bool Site(Player * player);
        
			/**��ý���*/
			int getPot();
        
			/**
			 *  ��ȡׯ�����ӱ��
			 *
			 *  @return ����һ��1-9�ڵ�����
			 */
			int getDealerPlayerChair();
        
			/**
			 *  ����ׯ�ҵ����ӱ��
			 */
			void setDealerPlayerChair();
        
        /**
         *  �úɹ���tip����
         */
        void startDilaTip();
        
        /**
         *  ֹͣ�ɹٶ���
         */
        void stopDilaTip();
        
        
        /**
         *  �������Ӻ�
         *
         *  @param chairNumber ���Ӻ�
         *
         *  @return ��������������ϵ�ITEM
         */
        MenuItemSprite * & getPlayerItemByChairNumber(int chairNumber);
        
        
        Player * getPlayerByChairNumber(int chairNumber);
        
        
		protected:
			/**����ID*/
			int ID;
        
			/**����Я����߽��*/
			int ScoreMax;
        
			/**�����ע���*/
			int ScoreMin;
        
			/**��λ 1-9*/
			Map<int, Player *> Chairs_Players;
        
			/**ׯ�ҵ����ӱ�� (0)*/
			int DealerPlayerChair;
        
			/**�������*/
			int PlayerCount;
        
			/**���̿���*/
			ProcessControl *processControl;
            
			/**����*/
			int Pot;
        
        /**
         *  ����չʾ�����ϵ����
         */
        Menu * playerMenu;
        MenuItemSprite* playerItem1;
        MenuItemSprite* playerItem2;
        MenuItemSprite* playerItem3;
        MenuItemSprite* playerItem4;
        MenuItemSprite* playerItem5;
        MenuItemSprite* playerItem6;
        MenuItemSprite* playerItem7;
        MenuItemSprite* playerItem8;
        MenuItemSprite* playerItem9;
        
        /**
         ��ʼ���˵�
         */
        void initPlayerMenu();

        

        
        Armature * Dila;
        
        /**�ο�����*/
        Vector<Player *> Guests;
    
        /**����;�����5��*/
        Vector<Poker *> riverPokers;
        
    private:
        /**
         *  ������ҵ�item����Ļ�ϵ�����
         *
         *  @param chairNumber ���Ӻ�
         */
        void setPlayerItemPositionByChairNumber(int chairNumber);
        
        /**
         *  Site()�����Ĺ��ߺ���,�������һ��MenuItem
         *
         *  @param player ����һ����Ҫ���µ����
         */
        void setPlayerMenu(Player* player);
    
    private:
        /**
         *  ������ť
         */
        Button * VoiceButton;
        void onTouchVoiceButton(Ref*ref,ui::Widget::TouchEventType type);
    };
}

#endif /* defined(__TexasPoker__Room__) */
