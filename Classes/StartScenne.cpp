#include "StartScenne.h"

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
	GUIReader::shareReader()->purge();
}

bool StartScenne::ccTouchBegan( CCTouch *pTouch, CCEvent *pEvent )
{
	return false;
}

void StartScenne::ccTouchMoved( CCTouch *pTouch, CCEvent *pEvent )
{

}

void StartScenne::ccTouchEnded( CCTouch *pTouch, CCEvent *pEvent )
{

}

void StartScenne::ccTouchCancelled( CCTouch *pTouch, CCEvent *pEvent )
{

}

bool StartScenne::init()
{
	if(!CCLayer::init())
		return false;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//加载
	UILayout* widget = dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("start/startscene.ExportJson"));	
	addChild(widget);

	return true;
}

CCScene* StartScenne::scene()
{
	CCScene* scene = CCScene::create();

	StartScenne* layer = StartScenne::create();

	scene->addChild(layer);
	 
	return scene;
}
