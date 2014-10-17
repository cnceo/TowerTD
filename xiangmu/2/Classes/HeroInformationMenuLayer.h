
#ifndef __Dota_Legend__HeroInformationMenuLayer__
#define __Dota_Legend__HeroInformationMenuLayer__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class HeroInformationMenuLayer : public Layer {
protected:
	//����,ͼ��,���� ����
	void toggleButton(Ref * sender);

	//ͼ�����ݿ���
	void fieldGuideInformati(Ref *sender);

	//���ز˵�
	void Return(Ref * sender);

	//���Ӳ˵�����
	void addMenu();

	//�˵�����
	Sprite * menuBG;

	//��������
	MenuItemToggle * characterToggle;
	MenuItemToggle * illustratedHhandbookToggle;
	MenuItemToggle * skillToggle;

	//������ļ��뺯��
	void addCharacter();

	void addIllustratedHandbook();

	void addSkill();

	//����������
	//����
	Sprite * character;

	//ͼ��
	Menu * illustratedHhandbook;

	//����
	Sprite * skill;


public:
	virtual bool init();
	CREATE_FUNC(HeroInformationMenuLayer);
};
#endif /* defined(__Dota_Legend__HeroInformationMenuLayer__) */
