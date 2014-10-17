#include "AllVectors.h"

AllVectors * AllVectors::instance = nullptr;		//��������

AllVectors * AllVectors::getInstance(){
	if (instance == NULL){
		instance = new AllVectors();
	}
	return instance;
}

Vector<Sprite *> AllVectors::getBricksVector(){
	return bricksVector;
}

void AllVectors::addBrick(Sprite * brick){
	bricksVector.pushBack(brick);
}

void AllVectors::deleteBrick(Sprite * brick){
	bricksVector.eraseObject(brick);
}

void AllVectors::bricksVectorCleanUp(){
	bricksVector.clear();
}

Vector<HeroBullet *> AllVectors::getHeroBulletsVector(){
	return heroBulletsVector;
}

void AllVectors::addHeroBullet(HeroBullet * bullet){
	heroBulletsVector.pushBack(bullet);

}

void AllVectors::deleteHeroBullet(){

	for (auto it = heroBulletsVector.begin();it!=heroBulletsVector.end();){
		if ((*it)->getState()){
			it= heroBulletsVector.erase(it);
		}else{
			it++;
		}
	}

}

void AllVectors::heroBulletsVectorClearUp(){
	heroBulletsVector.clear();
}

Vector<EnemyBullet *> AllVectors::getEnemyBulletsVector(){
	return enemyBulletsVector;
}

void AllVectors::addEnemyBullet(EnemyBullet * bullet){
	enemyBulletsVector.pushBack(bullet);
}

void AllVectors::deleteEnemyBullet(){
	for (auto it = enemyBulletsVector.begin();it!=enemyBulletsVector.end();){
		if ((*it)->getState()){
			it= enemyBulletsVector.erase(it);
		}else{
			it++;
		}
	}

}

void AllVectors::enemyBulletsVectorClearUp(){
	enemyBulletsVector.clear();
}

Vector<BaseTool *> AllVectors::getToolsVector(){
	return toolsVector;
}

void AllVectors::addTool(BaseTool * tool){
	toolsVector.pushBack(tool);
}

void AllVectors::deleteTool(BaseTool * tool){
	toolsVector.eraseObject(tool);
}

void AllVectors::toolsVectorCleanUp(){
	toolsVector.clear();
}

//��õذ弯��----------
Vector<Sprite *> AllVectors::getGroundVector(){
	return groundsVector;
}
//�򼯺���Ӷ���
void AllVectors::addGround(Sprite * ground){
	groundsVector.pushBack(ground);
}

//��õ��˼���----------
Vector<BaseEnemy *> AllVectors::getEnemiesVector(){
	return enemiesVector;
}
//�򼯺���Ӷ���
void AllVectors::addEnemy(BaseEnemy * enemy){
	enemiesVector.pushBack(enemy);
}
//�Ӽ���ɾ������
void AllVectors::deleteEnemy(){
	for (auto it = enemiesVector.begin(); it != enemiesVector.end();) {
		if ((*it)->getIsDie() == true) {
			it = enemiesVector.erase(it);
		}else{
			it++;
		}
	}
}
//��ռ���
void AllVectors::enemiesVectorCleanUp(){

	enemiesVector.clear();
}

bool AllVectors::getBgmusic(){
	return bg_music_isSelect;
}
void AllVectors::setBgmusic(bool bg){
	bg_music_isSelect = bg;
}

bool AllVectors::getEfmusic(){
	return ef_music_isSelect;
}
void AllVectors::setEfmusic(bool ef){
	ef_music_isSelect = ef;
}