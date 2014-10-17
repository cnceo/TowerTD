#ifndef __DATAGEARES_R_
#define __DATAGEARES_R_

#include "cocos2d.h"
#include "DataCacheGear.h"
using namespace cocos2d;

class DataGeares
{
private:
	static DataGeares * instance;
public:
	static DataGeares * getInstance();
	void addGearRef(DataCacheGear * gear);
	//��ż������ݵ�����
	CC_SYNTHESIZE_PASS_BY_REF(Vector<DataCacheGear *>, _dataGeares,DataGeares);
private:
	DataGeares(){}
	DataGeares(const DataGeares & skilles){}
	DataGeares operator = (const DataGeares & dataGeares)
	{
		return dataGeares;
	}
	//��������е�����Ԫ��
	void clearDataGeares();
};

#endif