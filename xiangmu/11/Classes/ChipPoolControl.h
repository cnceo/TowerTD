//
//  ChipPoolControl.h
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-25.
//

#ifndef __TexasPoker__ChipPoolControl__
#define __TexasPoker__ChipPoolControl__

#include <iostream>
#include <cocos2d.h>
using namespace cocos2d;


#include "Player.h"
#include "ChipPool.h"

namespace TexasPoker{
    class ChipPoolControl: public Layer{
        public:
        virtual bool init();
        CREATE_FUNC(ChipPoolControl);
            
        void pushBegin();
        void pushScore(Player * player);
        void pushEnd();
        
        /**���ػ��ֳ�*/
        Vector<ChipPool * > getChipPoolVector();
        
        private:
        
        /**
         *  ���ֳ�
         */
        Vector<ChipPool * > chipPool;
        
        /**
         *  ��ʱ����
         */
        Vector<Player *> tempPlayer;
        
        /**
         *  �����һ��ChipPool��������
         *
         *  @param player ���ָ��
         *  @param Score  ��ӵĻ���
         */
            void addPlayerToChipPool(Player * player,int Score);
        
        /**
         *  ��һ�������ڲ���һ�������Ƿ�����ڴ����
         *
         *  @param score      һ�� int ����
         *  @param tempPlayer �������
         *
         *  @return ����һ�����ڴ˻��ֵ����ָ��
         */
            Player * findPlayerScoreForVector(int score,Vector<Player *> tempPlayer);
        
        Menu * _menu;
        
        int MenuItemNumber;
        
        void createChipPool();
        void freshChipPoolItemLabel();
    };
    
};
#endif /* defined(__TexasPoker__ChipPoolControl__) */
