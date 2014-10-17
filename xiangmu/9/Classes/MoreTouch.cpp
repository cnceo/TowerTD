#include "MoreTouch.h"

bool MoTouch::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size vSize = Director::getInstance()->getVisibleSize();
	//ע��һ����㴥��
	auto listen = EventListenerTouchAllAtOnce::create();
	listen->onTouchesBegan = ([=](const std::vector<Touch*>& touch, Event* e)
	{		
		for (auto i:touch)
		{
			if(i->getLocation().x < vSize.width / 2 - MOVEPOINT)
			{
		       _isLeftScreen = true;
		    }
			if(i->getLocation().x > vSize.width / 2 - MOVEPOINT){
				_beginPoint = i->getLocation();
			}
		}
	});
	listen->onTouchesMoved = ([=](const std::vector<Touch*>& touch, Event* e)
	{
		for (auto i:touch)
		{
			//�ж�move���ǰ��ĵ��λ��,�Ƿ�����Ļ�����(�����ƶ�)
			if (_isLeftScreen)
			{
				if (i->getLocation().x < i->getPreviousLocation().x - MOVELENGH)
				{
					actionDriection(LEFT);
				}else if(i->getLocation().x > i->getPreviousLocation().x + MOVELENGH)
				{
					actionDriection(RIGHT);
				}
			}
			else// ����Ļ�ұ�  �ͷż���
			{
				if(!_isLeftScreen)
				{
					if(sqrt((i->getLocation().x - _beginPoint.x)*(i->getLocation().x - _beginPoint.x) + (i->getLocation().y - _beginPoint.y) * (i->getLocation().y - _beginPoint.y)) > 100)
					{
						TouchDir * touchDir = TouchDir::create(_beginPoint,i->getLocation());
						actionDriection(touchDir->judgeDriection());
					}				
				}
			}
		}	
	});
	listen->onTouchesEnded = ([=](const std::vector<Touch*>& touch, Event* e){
		for (auto i:touch)
		{
			if(!_isLeftScreen){
				if (i->getLocation().x > vSize.width / 2)
				{
					 actionDriection(ATTACK);//����
				}
			}
		}	
		actionDriection(STOP);
		_isLeftScreen = false;
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listen,this);
	//�����۲���
	auto onHook = __NotificationCenter::getInstance();
	onHook->addObserver(this,callfuncO_selector(MoTouch::gameOnHook), "staicOnHook", nullptr);
	auto endOnHook = __NotificationCenter::getInstance();
	endOnHook->addObserver(this,callfuncO_selector(MoTouch::endOnHook), "endOnHook", nullptr);
	return true;
}

void MoTouch::gameOnHook(Ref * obj)
{
	schedule(schedule_selector(MoTouch::updateOnHook), 0.1);
}

void MoTouch::updateOnHook(float t)
{
	actionDriection(ATTACK);
}

void MoTouch::endOnHook(Ref * obj)
{
	unschedule(schedule_selector(MoTouch::updateOnHook));
}

MoTouch::~MoTouch()
{
	auto onHook = __NotificationCenter::getInstance();
	onHook->removeObserver(this,"staicOnHook");
	auto endOnHook = __NotificationCenter::getInstance();
	endOnHook->removeObserver(this, "endOnHook");
}