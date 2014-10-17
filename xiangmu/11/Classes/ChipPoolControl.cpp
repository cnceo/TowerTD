//
//  ChipPoolControl.cpp
//  TexasPoker
//
//  Created by Ԭ���� on 14-9-25.
//

#include "ChipPoolControl.h"
#include "Player.h"
#include "ChipPool.h"
#include "Global.h"

using namespace TexasPoker;


bool ChipPoolControl::init(){
    if(!Layer::init()){
        return false;
    }
    
    _menu = Menu::create();
    _menu->setPosition(560, 430);
    //����
    _menu->alignItemsHorizontally();
    this->addChild(_menu);
    
    
    MenuItemNumber = 0;
    
    createChipPool();
    
    
    return  true;
}

void ChipPoolControl::createChipPool(){
    MenuItemNumber++;
    
    auto _chipPool = ChipPool::create();
    _chipPool->setTag(MenuItemNumber);
    chipPool.pushBack(_chipPool);
    
    
    //brian:��Ҫ�����洦��
    auto sp = Sprite::create("UI/chippool_1.png");
    
    auto _menuItem = MenuItemSprite::create(sp, sp);
    _menuItem->setTag(MenuItemNumber);
    
    auto _label = Label::createWithSystemFont("0", "Arial", 20);
    _label->setName("totalScoreLabel");
    
    _label->setPositionX(sp->getContentSize().width+10);
    _label->setPositionY(10);
    _label->setAnchorPoint(Vec2(0, 0.5));
    
    _menuItem->addChild(_label);
    
    
    _menu->addChild(_menuItem);
    _chipPool->setUserObject( _menu->getChildByTag(MenuItemNumber) );
}

void ChipPoolControl::freshChipPoolItemLabel(){
    log("ChipPoolControl::freshChipPoolItemLabel\n");
    
    for (auto it : chipPool ) {
        auto _item = static_cast<MenuItemSprite *>(it->getUserObject());
        auto _chipPool = static_cast<ChipPool *>(it);
        auto _label =  static_cast<Label *>( _item->getChildByName("totalScoreLabel") );
        _label->setString( Function::getFormatScore(_chipPool->totalScore) );
    }
    
}

void ChipPoolControl::pushBegin(){
    if (tempPlayer.size()>0) {
        tempPlayer.clear();
    }
}

void ChipPoolControl::pushScore(Player * player){
    tempPlayer.pushBack(player);
}

void ChipPoolControl::pushEnd(){
    /**
     *  1.��ȡ�ֳص�����
     */
    Vector<Player *> kindPlayerScore;
    
    std::vector<int> tempScoreVector;
    for (auto _player : tempPlayer) {
        if (_player->getScore() == 0 && _player->getTempScore()>0) {
            auto tempScore = _player->getTempScore();
            TP::log("_tempScore = player->getTempScore(); %p, %d",_player,tempScore);
            
            auto it = std::find(tempScoreVector.begin(), tempScoreVector.end(), tempScore);
            if( it == tempScoreVector.end() ){
                tempScoreVector.push_back(tempScore);
            }
        }
    }
    
    /**
     *  2. �Ƿ���Ҫ�ֳ�
     */
    if(tempScoreVector.size() > 0){
        TP::log("kindPlayerScore.size() > 1, ",tempScoreVector.size());
        
        /**
         *  2.1 ��������������
         */
        for (auto it = tempScoreVector.begin(); it != tempScoreVector.end(); it++) {
            for (auto next_it = it; next_it!=tempScoreVector.end(); next_it++ ) {
                if ( *it > *next_it ) {
                    int tempPlayer = *next_it;
                    *next_it = *it;
                    *it = tempPlayer;
                }
            }
        }
        
        /**
         *  ��ʼ�ֳ�
         */
        int splitPool = 0;
        for (auto it = tempScoreVector.begin(); it != tempScoreVector.end(); it++) {
            log(": %d", *it );
            if (*it == 0 ) {
                continue;
            }
            
            /**
             *  ��Ҫ�鵽���ڵĻ���,��Ҫ��ȥ֮ǰ���г����Ѿ�Ͷ��Ļ���
             */
            int poolScore = *it ;
            for (auto it2 = it+1; it2 != tempScoreVector.end(); it2++) {
                *it2 -= poolScore;
            }
            
            if (splitPool > 0) {
                //����һ����,��ӵ�Vector��
                createChipPool();
            }
            
            for (auto _player : tempPlayer) {
                if (_player->getTempScore() >= poolScore) {
                    addPlayerToChipPool(_player, poolScore);
                    _player->subTempScore(poolScore);
                }
            }
            
            splitPool++;
        }
        
    }else{
        TP::log("kindPlayerScore.size() == 0 , %zd",kindPlayerScore.size());
        
        for (auto player : tempPlayer) {
            addPlayerToChipPool(player,player->getTempScore());
        }
        
    }
    
    log("++++++++++++++++++++++++++++++++++++++");
    for (auto it : chipPool) {
        log("ChipPoolControl::pushEnd chipPool it->totalScore  %d, it->players.size() %zd",it->totalScore, it->players.size());
    }
    log("++++++++++++++++++++++++++++++++++++++");

    
    //ˢ���������
    freshChipPoolItemLabel();
}

Player * ChipPoolControl::findPlayerScoreForVector(int score,Vector<Player *> tempPlayer){
    for (auto pl : tempPlayer) {
        if (pl->getTempScore() == score) {
            return pl;
        }
    }
    return nullptr;
}

void ChipPoolControl::addPlayerToChipPool(Player *player,int Score){
    auto lastChipPool = *(chipPool.end()-1);
    lastChipPool->add(player, Score);
    player->subTempScore(Score);
}

// ���ػ��ֳ�  
Vector<ChipPool * > ChipPoolControl::getChipPoolVector(){
    return chipPool;
}






