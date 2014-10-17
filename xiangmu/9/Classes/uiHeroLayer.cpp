#include "uiHeroLayer.h"
#include "DataCacheHero.h"
#include "DataGeares.h"
#include <SimpleAudioEngine.h>
using namespace CocosDenshion;

bool uiHeroLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//���UI����
	_uiherolayer = GUIReader::getInstance()->widgetFromJsonFile("hero_1.json");
	_uiherolayer->setPosition(Vec2(0,0));
	this->addChild(_uiherolayer);	
	gearShow();
    attributeValue();
	return true;
}

void uiHeroLayer::attributeValue()
{
	//�����ŵ���
	DataCacheHero * hero = DataCacheHero::getInstance();
    //��ÿ���ͼ��Ļ��С
	Size vSize = Director::getInstance()->getVisibleSize();
	//ȡ��hp��ֵ��������ı�
	auto image = _uiherolayer->getChildByName("Image_9");
	auto hpValue = (Text *)image->getChildByName("_hp");
	auto hpString = StringUtils::format("%d",hero->getHpValue());
	hpValue->setText(hpString);
	//���mp��ֵ��������ı�
	auto mpValue = (Text *)image->getChildByName("_mp");
	auto mpString = StringUtils::format("%d",hero->getMpValue());
	mpValue->setText(mpString);
	//���attack��ֵ��������ı�
	auto attackValue = (Text *)image->getChildByName("_attack");
	auto attackString = StringUtils::format("%d",hero->getAttackValue() + _addAttack);
	attackValue->setText(attackString);
	//���defense��ֵ��������ı�
	auto defenseValue = (Text *)image->getChildByName("_hujia");
	auto defenseString = StringUtils::format("%.2f",hero->getDefenseValue() + _addDefence);
	defenseValue->setText(defenseString);
	//���duck��ֵ��������ı�
	auto agilityValue = (Text *)image->getChildByName("_duck");
	auto agilityString = StringUtils::format("%0.2f",hero->getAgilityValue() + _addAgility);
	agilityValue->setText(agilityString);
	////���crit��ֵ��������ı�
	//auto critValue = (Text *)image->getChildByName("_crit");
	//auto critString = StringUtils::format("%.2f",12);
	//critValue->setText(critString);
	//���exp��ֵ��������ı�
	auto expValue = (Text *)image->getChildByName("_exp");
	auto expString = StringUtils::format("%d",hero->getNowExpValue());
	expValue->setText(expString);
	//���level��ֵ��������ı�
	auto levelValue = (Text *)image->getChildByName("_lerve");
	auto levelString = StringUtils::format("%d",hero->getLevelValue());
	levelValue->setText(levelString);
	//�����ŵ�Name��ֵ��������ı�
	auto heroName = (Text *)image->getChildByName("_hero");
	heroName->setText(hero->getName());
	auto introduceValue = (Text *)image->getChildByName("_neirong");
	introduceValue->setText(hero->getIntroduce());
}

void uiHeroLayer::gearShow()
{
	auto image = _uiherolayer->getChildByName("Image_9");
	//���������ͼƬ��
	auto weaponImage = (ImageView *)image->getChildByName("hero_wepaon");
	//��ȡ���׵�ͼƬ��
	auto armourImage = (ImageView *)image->getChildByName("hero_armour");
	//��ȡЬ�ӵ�ͼƬ��
	auto shoeImage = (ImageView *)image->getChildByName("hero_shoe");
	//���װ����������
	DataGeares * gear = DataGeares::getInstance();
	for(auto x = gear->getDataGeares().begin(); x != gear->getDataGeares().end(); x++)
	{
		if((*x)->getHeroAdorn() == YES)
		{
			if((*x)->getGearType() == WEAPON)
			{
				_addAttack = (*x)->getAttickValue();
				weaponImage->loadTexture((*x)->getPictureName());
			}
			if((*x)->getGearType() == ARMOUR)
			{
				_addDefence = (*x)->getDefenseValue();
				armourImage->loadTexture((*x)->getPictureName());
				log("%f",(*x)->getDefenseValue());
			}
			if((*x)->getGearType() == SHOE)
			{
				_addAgility = (*x)->getAglityValue();
				shoeImage->loadTexture((*x)->getPictureName());
			}
		}
	}
}