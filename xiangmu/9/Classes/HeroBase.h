#ifndef __HEROBASE_H__
#define __HEROBASE_H__

#include "cocos2d.h"
#include "MoreTouch.h"
#include "SkillReleaseContainer.h"
using namespace cocos2d;
USING_NS_CC;

enum HeroAnimate{
	RUNANIMATE,
	JUMPANIMATE,
	ATTACKANIMATE,
	SKILLATTACKANIMATE,
};

class AnimateClass;

class HeroBase:public Sprite
{
protected:
	SkillReleaseContainer * _skillReleaseContainer;
	AnimateClass *_animate;
	MoTouch* _touch;
	Menu * _men;
	int _attackValue;
	int _attackGearValue;
	int _practicalAttackValue;
	bool _isMenu;
	bool _leftRightSkill;
	bool _downSkill;
	bool _isRun;
	bool _isOneAttack;
	bool _isOneJump;
	bool _isOneDownSkill;
	bool _isOneRightSkill;
	bool _isOneLeftSkill;
	bool _isOneJumpSkill;
	bool _isReleaseSkill;
	bool _isAttackKnocking;
	bool _isLeftBoundary;
	bool _isRightBoundary;
	bool _isBigSkill;
public:	
	CC_SYNTHESIZE(int, _id, Id);
	CC_SYNTHESIZE(int, _dir, DIR);
	CC_SYNTHESIZE(int, _attackBaseValue,AttackBaseValue);
	CC_SYNTHESIZE(int, _directionType,Type);
	CC_SYNTHESIZE(int, _directionTypeWrite, DirectionTypeWrite);
	CC_SYNTHESIZE(int, _directionRunTypeWrite, DirectionRunTypeWrite);
	CC_SYNTHESIZE(int, _expValue, ExpValue);
	CC_SYNTHESIZE(int, _needExp, NeedExpValue);
	CC_SYNTHESIZE(int, _nowExpValue, NowExpValue);
	CC_SYNTHESIZE(int, _takeExpValue, TakeExpValue);
	CC_SYNTHESIZE(int, _levelValue, LevelValue);
	CC_SYNTHESIZE(int, _hpValue, HpValue);
	CC_SYNTHESIZE(int, _allHp, AllHp);
	CC_SYNTHESIZE(int, _mpValue, MpValue);
	CC_SYNTHESIZE(int, _allMp, AllMp);
	//CC_SYNTHESIZE(int, _attackValue, AttackValue);
     virtual int getAttackValue(void) 
	 {
		 return _practicalAttackValue;
	 }
     virtual void setAttackValue(int var)
	 {
		 _attackValue = var; 
	 }
	CC_SYNTHESIZE(double, _agilityValue, AgilityValue);
	CC_SYNTHESIZE(double, _agilityGearValue, AgilityGearValue);
	CC_SYNTHESIZE(double, _defenseValue, DefenseValue);
	CC_SYNTHESIZE(double, _defenseGearValue, DefenseGearValue);
	CC_SYNTHESIZE(int, _spValue, SpValue);
	CC_SYNTHESIZE(int, _heroHurt, HeroHurt);
	CC_SYNTHESIZE(bool, _heroDie, HeroDie);
	CC_SYNTHESIZE(bool, _attackState,AttackState);
	CC_SYNTHESIZE(bool, _jumpAttackState, JumpAttackState);
	virtual bool initWithSpriteFrameName(std::string filename);
	void heroHurt(int attack);
	//���캯��
	HeroBase():_isBigSkill(false), _takeExpValue(0), _isMenu(false), _isRightBoundary(false), _isLeftBoundary(false), _isAttackKnocking(false), _jumpAttackState(false), _heroDie(false), _leftRightSkill(false), _downSkill(false), _isRun(false), _isOneAttack(false), _isOneJump(false), _isOneDownSkill(false),_isOneLeftSkill(false),_isOneRightSkill(false),_isOneJumpSkill(false),_isReleaseSkill(false){}
	~HeroBase();
private:
	//�������ܵ�cdʱ����Ϣ
	void endSkill1Cd(Ref * obj);
	void endSkill2Cd(Ref * obj);
	void endBigSkillCd(Ref * obj);
	//���������ƵĶ��㴦
	void endMoveLeft(Ref * obj);
	void endMoveRight(Ref * obj);
	//����
	void attackKnocking(Ref * obj);
	//���㾭��
	void addExp(Ref * obj);
	//����������
	void addHeroAttribute();
	//��������
	void createSwordAnger();
	//��������
	void createLighning();
	//��������
    void createBigSkill();
	//������ʽ
	void judgeActionType(Driection type);
	void heroRun();
	void heroSwordSkillAttack();
	void heroLightningSkillAttick();
	void heroJump();
	void heroCommonAttack();	
	void endAttackAnimation();
	void heroDie();
	void heroStop();
	//����ֻһ�ι���
    void restoreOneAttack();
	//ֻ��һ�λظ�
	void restoreOneJump();
	//����ֻ��һ�μ���
	void restoreOneSkill();
	//������
	void heroAddRun(float t);
	void heroAddHpMp(float t);
};

#endif