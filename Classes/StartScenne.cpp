#include "StartScenne.h"
#include "BlankLayer.h"
StartScenne::StartScenne(void)
{
	
}


StartScenne::~StartScenne(void)
{
}

void StartScenne::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
	

}

void StartScenne::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	//onExit或析构中需调用（否则内存泄露）
	SceneReader::sharedSceneReader()->purge();
	GUIReader::shareReader()->purge();
	ActionManager::purge();
}

/*
bool StartScenne::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	CCPoint touchLocation = pTouch->getLocation();
	CCPoint localPosition = this->convertToNodeSpaceAR(touchLocation);

	if(mStartButton){
	}

	if(mContinueButton){

	}

	return false;
}
*/

bool StartScenne::init()
{
	if(!CCLayer::init())
		return false;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//加载
	UILayout* widget = dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("start/startscene.ExportJson"));	
	addChild(widget);
	auto button = widget->getChildByName("start_button");

	mStartButton = dynamic_cast<UIButton*>(widget->getChildByName("start_button"));
	mContinueButton = dynamic_cast<UIButton*>(widget->getChildByName("Button_5"));

	if(mStartButton)
	{
		mStartButton->addTouchEventListener(this, toucheventselector(StartScenne::onClickStartButton));

	}
	return true;
}

CCScene* StartScenne::scene()
{
	CCScene* scene = CCScene::create();

	StartScenne* layer = StartScenne::create();

	scene->addChild(layer);
	 
	return scene;
}

void StartScenne::onClickStartButton( CCObject* object,TouchEventType type )
{
	if(object){
		switch (type)
		{
		case TouchEventType::TOUCH_EVENT_BEGAN:
			break;
		case TouchEventType::TOUCH_EVENT_ENDED:
			{
				CCScene* scene = CCScene::create();
				BlankLayer* layer = new BlankLayer();
				scene->addChild(layer);
				layer->autorelease();

				CCDirector::sharedDirector()->replaceScene(scene);

			}

			break;
		default:
			break;
		}
	}
}

void StartScenne::onClickContinueButton( CCObject* object,TouchEventType type )
{
	if(object){
		switch (type)
		{
		case TouchEventType::TOUCH_EVENT_BEGAN:
			break;
		case TouchEventType::TOUCH_EVENT_ENDED:

			break;
		default:
			break;
		}
		}
}
