#include "ccpointinstanceinfo.h"

#include "../SpriterPlusPlus/spriterengine/global/settings.h"

namespace se = SpriterEngine;

namespace Spriter2dX
{

	CCPointInstanceInfo::CCPointInstanceInfo(cocos2d::Node* parent) : parent(parent)
	{
		//circle(10)
//		circle.setFillColor(sf::Color::Red);
//		circle.setOrigin(5, 5);
	}

	void CCPointInstanceInfo::render()
	{
		if (se::Settings::renderDebugPoints)
		{
//			circle.setPosition(getPosition().x, getPosition().y);
//			circle.setRotation(toDegrees(getAngle()));
//			renderWindow->draw(circle);
		}
	}

}
