#ifndef __GLOBALINFO_H_
#define __GLOBALINFO_H_
//Enemy���
#define  SPEED 200
#define  STEP 64//����ÿ�ƶ�һ���ľ����ǵ�ͼ��ı߳�
#define STEPTIME1 0.5
//HealthData���
#define  DATASTEP 64//�����ļ�ÿ�ƶ�һ���ľ����ǵ�ͼ��ı߳�
#define DATASTEPTIME 0.5//�����ļ�û��һ����Ҫ��ʱ��
//������Ч���
struct attackEffect{
	int lowspeedtime;
	int frozentime;
	int firetime;
};

#endif