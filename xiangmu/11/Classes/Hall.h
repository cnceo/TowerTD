//
//  Hall.h
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-13.
//
//

#ifndef __TexasPoker__Hall__
#define __TexasPoker__Hall__

#include <iostream>
#include <cocos2d.h>
using namespace cocos2d;

#include "Macros.h"
#include "Room.h"

namespace TexasPoker {
    
    /**����*/
    class Hall:public Layer{
    public:
        enum class HallType{
            CHINA
        };
	protected:
		/**����ID*/
		int ID;

		/**�����б�*/
		Map<int, Room *> Rooms;
        
		/**��������====================???????????????????????*/
		/**����Я����߽��*/
		int ScoreLimit;
        
		/**�����ע���*/
		int ScoreMin;

    public:
		
        /**��������*/
		static void createRoom();
        static void createRoom(HallType hType);
        
        /**��������ڵļ��뷿��*/
		virtual  void joinRoom();
        /**���ݷ���ID���뷿��*/
		virtual  void joinRoom(int roomID);
        
        
        CREATE_SCENE(Hall)
        CREATE_FUNC(Hall);
    private:
        virtual bool init();
        
        ~Hall();
    };
}
#endif /* defined(__TexasPoker__Hall__) */
