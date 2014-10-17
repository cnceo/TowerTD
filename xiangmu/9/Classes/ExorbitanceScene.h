#ifndef __EXORBSCENE_R_
#define __EXORBSCENE_R_


#include "cocos2d.h"
#include <sqlite3.h>
using namespace cocos2d;

//�洢���ݿ��ļ�
int fileCopy(const char *sreFileName,const char * path);

class ExorbitanceScene : Layer
{
private:
	//���ݿ�
	sqlite3 * _pdb;
public:
	virtual bool init();
	static Scene * createScene();
	CREATE_FUNC(ExorbitanceScene);
private:
	//�����ݿ�
	void opendb();
	//��ѯ���ݿⲢ�����������ȡ
	void queryHeroDb();
	//��ѯ���ݿⲢ�����ܵ�������ȡ
	void querySkillDb();
	//��ѯ���ݿ���װ����������ȡ
	void queryGearDb();
	//������Ч
	void onEnter();
};

#endif