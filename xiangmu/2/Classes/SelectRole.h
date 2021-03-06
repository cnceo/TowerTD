#ifndef __SELECTROLE_H
#define __SELECTROLE_H
#include "cocos2d.h"
#include "Person.h"

using namespace cocos2d;
class SelectRole
{
private:
	static SelectRole *instence;
	SelectRole(){}
	SelectRole(const SelectRole &s){}
	SelectRole operator=(const SelectRole &s){
		return s;
	}
	Vector<Person *>roleArmatures;
	Vector<Person *>EnemyArmatures;
public:
	CC_SYNTHESIZE(Vector<Layer *>, hpLayer, HpLayer);
	void addHplayer(Layer * layer);
	void hpLayerclear();
	static SelectRole *getInstence();
	Vector<Person *> getRoleArmatures();
	void addRoleArmature(Person *person);
	void deleteRoleArmature();
	void RoleClearAll();
	Vector<Person *> getEnemyArmatures();
	void addArmature(Person *person);
	void deleteEnemyArmature();
	void EnemyClearaAll();

};
#endif /* defined(__Dota_Legend__SelectRole__) */
