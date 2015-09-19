#include "BlankLayer.h"


BlankLayer::BlankLayer(void)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCLabelTTF* pLabel = CCLabelTTF::create("对不起，下一个场景还在制作", "Arial", 24);
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel->getContentSize().height));

	this->addChild(pLabel);
}


BlankLayer::~BlankLayer(void)
{
}
