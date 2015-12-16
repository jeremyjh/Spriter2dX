#include "ccboxinstanceinfo.h"

#include "../SpriterPlusPlus/spriterengine/global/settings.h"

namespace se = SpriterEngine;

namespace Spriter2dX
{

	CCBoxInstanceInfo::CCBoxInstanceInfo(se::point initialSize) :
		se::BoxInstanceInfo(initialSize)
	{
	}

	void CCBoxInstanceInfo::render()
	{
		if (se::Settings::renderDebugBoxes)
		{
            //TODO: debug draw
//			rectangle.setPosition(getPosition().x, getPosition().y);
//			rectangle.setRotation(toDegrees(getAngle()));
//			rectangle.setScale(getScale().x, getScale().y);
//			rectangle.setOrigin(getPivot().x*getSize().x, getPivot().y*getSize().y);
//			renderWindow->draw(rectangle);
		}
	}

}
