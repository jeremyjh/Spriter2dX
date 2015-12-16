#ifndef CCPOINTINSTANCEINFO_H
#define CCPOINTINSTANCEINFO_H

#include "../SpriterPlusPlus/spriterengine/objectinfo/pointinstanceinfo.h"

namespace cocos2d {
	class Node;
}

namespace Spriter2dX
{

	class CCPointInstanceInfo : public SpriterEngine::PointInstanceInfo
	{
	public:
		CCPointInstanceInfo(cocos2d::Node* parent);

		void render() override;

	private:
        cocos2d::Node* parent;

	};

}

#endif // CCPOINTINSTANCEINFO_H
