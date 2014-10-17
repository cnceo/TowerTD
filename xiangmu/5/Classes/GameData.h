#ifndef __GAMEDATA_H_
#define __GAMEDATA_H_

//��ͼ����
#define GAME_MAPS_COUNT 12
//ʱ����������
#define TIME_SCORE 1
//�����Զ��������ʱ��
#define ADD_SCORE_TIME 0.5
//��������
#define ROLE_POSITION_X 100
#define ROLE_POSITION_Y 185
//�����ٶ�
#define BACKGROUND_SPEED 150
//�ϰ��﹥����
#define BLOCK_ATTACK 1500
//����Ѫ��
#define ROLE_ALL_HP 1000
//������״̬��Ѫϵ��
#define BOND_DROP_HP 0.5
//����ÿ���Ѫ��
#define ROLE_SCEOND_HP 2
//�����Զ���Ѫʱ����
#define DORP_HP_TIME 0.02
//Ѫ����Ѫ��
#define BLOOD_ADD_HP 200

//������ǲ�
#define GET_ROLE_LAYER dynamic_cast<RoleLayer *>(dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene())->getRoleLayer())
//��ñ�����
#define GET_BACKGROUND_LAYER dynamic_cast<BackgroundLayer *>(dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene())->getBackgroundLayer())

//������Ч
#define BACK_GUOUND_MUSIC(FILENAME, AUDIOFLAG) \
	if (AUDIOFLAG)\
	{\
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(FILENAME, true);\
	}

#define EFFECT_MUSIC(FILENAME, AUDIOFLAG) \
	if (AUDIOFLAG)\
	{\
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(FILENAME);\
	}

//���ڴ�С
#define VISIBLE_SIZE Director::getInstance()->getVisibleSize()

//logo
#define LOGO_FILENAME "gamelogo.png"

//�˳��Ի���ͼƬ
#define EXIT_BACKGROUND_FILENAME "exitButton.png"
#define EXIT_YESBUTTON_FILENAME "yesButton.png"
#define EXIT_NOBUTTON_FILENAME "noButton.png"

//���ǵ���
#define ROLE_STATE_PROTECT "bubbleattachment-sheet0.png"
#define ROLE_STATE_BUCKET "bucketattachment-sheet0"
#define ROLE_STATE_BAND "plaster-sheet0.png"

//the image name of role runAction
#define ROLE_RUN_FILENAME "chicken-sheet0"
#define ROLE_JUMP_UP_FILENAME "chicken-jumpUp-sheet0"
#define ROLE_JUMP_DOWN_FILENAME "chicken-jumpDown-sheet0"
#define ROLE_HURT_FILENAME "chicken-hurt-sheet0"
#define ROLE_DIE_FILENAME "chicken-die-sheet0"
#define ROLE_ELECTRIC_FILENAME "chicken-electric-sheet0"
//���������ز�
#define ROLE_JUMPING_0_FILENAME "chicken-jumpDown-sheet0.png"
#define ROLE_JUMPING_1_FILENAME "chicken-jumpDown-sheet1.png"

//�������������ز�
#define ROLE_DIEPING_FILENAME "chicken-die-sheet0_01.png"

//��ʼ�����ز�
//��Ч����
#define AUDIOON_FILENAME "audioon-sheet0.png"
#define AUDIOOFF_FILENAME "audiooff-sheet0.png"
//�������ǽ���
#define  ABOUT_FILENAME "about.png"
//��ʼ��ť
#define PLAY_MAIN_1_FILENAME "play_main-sheet0.png"
#define PLAY_MAIN_2_FILENAME "play_main-sheet1.png"
//��ʼ����
#define MAIN_BACK_FILENAME "main_back-sheet0.png"
//������ʾ
#define INSTRUCTIONS_FILENAME "instructions-sheet0.png"
//����
#define RIBBON_FILENAME "ribbon-sheet0.png"
//Game Logo
#define GAME_LOGO_FILENAME "headless_logo-sheet0.png"
//Max score
#define MAX_SCORE_FILENAME "kelchend-sheet0.png"

//��Ϸ�����ز�
//��Ϸ������
//Զɽ
#define L1_S1_FILENAME "l1_s1-sheet0.png"
#define L1_S2_FILENAME "l1_s2-sheet0.png"
//Զ������Ұ
#define L2_S1_FILENAME "l2_s1-sheet0.png"
#define L2_S2_FILENAME "l2_s2-sheet0.png"
//��
#define L3_S1_FILENAME "l3_s1-sheet0.png"
#define L3_S2_FILENAME "l3_s2-sheet0.png"
#define L3_S3_FILENAME "l3_s3-sheet0.png"
//��������Ұ
#define L4_S1_FILENAME "l4_s1-sheet0.png"
#define L4_S2_FILENAME "l4_s2-sheet0.png"
#define L4_S3_FILENAME "l4_s3-sheet0.png"
//��ľ�� _BN_ �е�NΪ1��2��3��4
#define L5_BN_FILENAME "l5_b%d-sheet0.png"
//���߸ˡ�·�� _SN_ �е�NΪ1��2��3
#define L5_SN_FILENAME "l5_s%d-sheet0.png"
//�ݴ�
#define L7_S1_FILENAME "l7_s1-sheet0.png"
#define L7_S2_FILENAME "l7_s2-sheet0.png"
//·
#define G_S1_FILENAME "g_s1-sheet0.png"
#define G_S2_FILENAME "g_s2-sheet0.png"
#define G_S3_FILENAME "g_s3-sheet0.png"

//��ʾ��
//ľ��
#define TOPBAR_FILENAME "topbar-sheet0.png"
//��ͣ��ť
#define PAUSE_BUTTON_1_FILENAME "pausebutton-sheet0.png"
#define PAUSE_BUTTON_2_FILENAME "pausebutton-sheet1.png"
#define SCREEN1BACKTUT "screen1backtut-sheet0.png"
#define SCREEN2BACKTUT "screen2backtut-sheet0.png"
#define MOBILEJUMP "mobilejump-sheet0.png"
#define MOBILE_LEFT "mobile_left-sheet0.png"
#define MOBILE_RIGHT "mobile_right-sheet0.png"
//��Ѫ����־
#define LOW_BLOOD_WARNING "attention-sheet0.png"

//��ǰ��
#define TIMER_FILENAME "timer-sheet0.png"
//������
#define CONDITION_NO_FILENAME "a1-sheet0.png"
#define CONDITION_YES_FILENAME "a1-sheet1.png"
//С��ͷ
#define ARROW_FILENAME "arrow-sheet0.png"

//��ͣ��������
//��ɫ����
#define BLACK_BACK_FILENAME "overlay-sheet0.png"
//����
#define ENDBACK_P_FILENAME "endbackp-sheet0.png"
//��ͣLOGO
#define PAUSEGFX_FILENAME "pausegfx-sheet0.png"
//����LOGO
#define CHICKEN_END_FILENAME "chickenend-sheet0.png"
//�¼�¼��ʾ
#define NEW_RECORD_FILENAME "newrecord-sheet0.png"
//���ؿ�ʼ���水ť
#define BACK_P_1_FILENAME "backp-sheet0.png"
#define BACK_P_2_FILENAME "backp-sheet1.png"
//ת���������水ť
#define HOWTOP_1_FILENAME "howtop-sheet0.png"
#define HOWTOP_2_FILENAME "howtop-sheet1.png"
//�ص���Ϸ��ť
#define PLAY_P_1_FILENAME "playp-sheet0.png"
#define PLAY_P_2_FILENAME "playp-sheet1.png"
//�����������¿�ʼ��Ϸ��ť
#define REPLAYER_END_1_FILENAME "replayend-sheet0.png"
#define REPLAYER_END_2_FILENAME "replayend-sheet1.png"
//�հ�ť���ն�ܿ�
#define NEAR_MISS_COLL_FILENAME "near_miss_coll-sheet0.png"

//��������
//����¼�¼
#define CONDITION_1_1_FILENAME "r1-sheet0_04.png"
//��Ϸ����5��
#define CONDITION_1_2_FILENAME "r1-sheet0_28.png"

//�Ե�Ѫ������
#define CONDITION_2_25_FILENAME "r1-sheet0_17.png"
#define CONDITION_2_50_FILENAME "r1-sheet0_18.png"
#define CONDITION_2_100_FILENAME "r1-sheet0_13.png"
#define CONDITION_2_200_FILENAME "r1-sheet0_01.png"
//�Ե�Ѫ�δ���
#define CONDITION_2_60_FILENAME "r1-sheet0_21.png"
//�Ե�����������
#define CONDITION_2_3_FILENAME "r1-sheet0_06.png"

//50��
#define CONDITION_3_10_FILENAME "r1-sheet0_08.png"
#define CONDITION_3_20_FILENAME "r1-sheet0_19.png"
//100��
#define CONDITION_4_10_FILENAME "r1-sheet0_27.png"
#define CONDITION_4_30_FILENAME "r1-sheet0_29.png"

//���ն��
#define CONDITION_5_10_FILENAME "r1-sheet0_33.png"
#define CONDITION_5_30_FILENAME "r1-sheet0_32.png"
#define CONDITION_5_50_FILENAME "r1-sheet0_34.png"
#define CONDITION_5_100_FILENAME "r1-sheet0_23.png"

//ײ���ϰ�10��
//����
#define CONDITION_6_BEARTRAP_FILENAME "r1-sheet0_02.png"
//����
#define CONDITION_6_CAMPFIRE_FILENAME "r1-sheet0_07.png"
//���
#define CONDITION_6_E_FENCE_FILENAME "r1-sheet0_16.png"
//����
#define CONDITION_6_BLADE_FILENAME "r1-sheet0_25.png"

//˫������
//���5��˫�����ֵ���
#define CONDITION_7_5_FILENAME "r1-sheet0_11.png"
//���N���˫������ʱ��
#define CONDITION_7_15_FILENAME "r1-sheet0_14.png"
#define CONDITION_7_30_FILENAME "r1-sheet0_03.png"
#define CONDITION_7_40_FILENAME "r1-sheet0_05.png"
#define CONDITION_7_50_FILENAME "r1-sheet0_26.png"

//��߷�500,750,1000,1500,2000,3000,3500
#define CONDITION_8_1_FILENAME "r1-sheet0_10.png"
#define CONDITION_8_2_FILENAME "r1-sheet0_09.png"
#define CONDITION_8_3_FILENAME "r1-sheet0_30.png"
#define CONDITION_8_4_FILENAME "r1-sheet0_20.png"
#define CONDITION_8_5_FILENAME "r1-sheet0_31.png"
#define CONDITION_8_6_FILENAME "r1-sheet0_24.png"
#define CONDITION_8_7_FILENAME "r1-sheet0_12.png"

//�������������ĵ���
//50��
#define TOOLS_SCORE_50_FILENAME "unlocks-sheet0_01.png"
//��ʱ��˫���÷�
#define TOOLS_DOUBLE_SCORE_5_FILENAME "unlocks-sheet0_02.png"
//������
#define TOOLS_PLASTER_FILENAME "unlocks-sheet0_03.png"
//��ʼѪ������20%
#define TOOLS_BEGIN_HP_20_FILENAME "unlocks-sheet0_04.png"
//��ʱ��˫���÷�
#define TOOLS_DOUBLESCORE_15_FILENAME "unlocks-sheet0_05.png"
//Ѫ��
#define TOOLS_BLOOD_DROP_FILENAME "unlocks-sheet0_06.png"
//��ʼѪ������40%
#define TOOLS_BEGIN_HP_40_FILENAME "unlocks-sheet0_07.png"
//100��
#define TOOLS_SCORE_100_FILENAME "unlocks-sheet0_08.png"
//������
#define TOOLS_SHIELD_FILENAME "unlocks-sheet0_09.png"
//ˮͰ
#define TOOLS_BUCKET_FILENAME "unlocks-sheet0_10.png"
//��ʮ��
#define TOOLS_BLOOD_USEABLE_FILENAME "unlocks-sheet0_11.png"
//����
#define TOOLS_RIBBON_FILENAME "unlocks-sheet0_12.png"

#endif // !__GAMEDATA_H_
