/**

* ������FileManager

* ���ߣ�

* ���ڣ�

* ���� : �������ɽ��������ļ�,�ռ��㹻�ļ�,�����Լ�����������ʱ��Ѫ,Ѫ���۹�,��Ϸʧ��.

**/ 
#ifndef __FILEMANAGER_H_
#define __FILEMANAGER_H_
#include "cocos2d.h"
USING_NS_CC;
class FileManager:public Node{
public:
	CREATE_FUNC(FileManager);
	virtual bool init();
	//��Ҫ�����ļ�����
	CC_SYNTHESIZE(int,fileneed,FileNeed);
	//��ǰ�յ����ļ�����
	CC_SYNTHESIZE(int,filereceived,FileReceived);
protected:
	//���̶�ʱ��(�������Ź��ﲨ��)�����ļ�
	void createFile(float dt);
	Vec2 monsterCreatePosition();
};
#endif