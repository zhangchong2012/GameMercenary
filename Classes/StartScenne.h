#ifndef __START_SCENE_H_
#define __START_SCENE_H_
#include "cocos2d.h"
#include "cocos-ext.h"//cocostudioÖÐµÄ¿Õ¼ä
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
class StartScenne : public cocos2d::CCLayer
{
public:
	StartScenne(void);
	~StartScenne(void);
	virtual void onEnter();
    virtual void onExit();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(StartScenne);

	void onClickStartButton(CCObject* object,TouchEventType type);  
	void onClickContinueButton(CCObject* object,TouchEventType type);  

private:
	ui::UIButton* mStartButton;
	UIButton* mContinueButton;
};
#endif

