#ifndef CCOBJECTFACTORY_H
#define CCOBJECTFACTORY_H


#include "../SpriterPlusPlus/spriterengine/override/objectfactory.h"

namespace cocos2d {
	class Node;
}

namespace Spriter2dX
{

	class CCObjectFactory : public SpriterEngine::ObjectFactory
	{
	public:
		CCObjectFactory(cocos2d::Node* parent);
		
		SpriterEngine::PointInstanceInfo *newPointInstanceInfo() override;

		SpriterEngine::BoxInstanceInfo *newBoxInstanceInfo(SpriterEngine::point size) override;

		SpriterEngine::BoneInstanceInfo *newBoneInstanceInfo(SpriterEngine::point size) override;

		SpriterEngine::TriggerObjectInfo *newTriggerObjectInfo(std::string triggerName) override;
	private:
		cocos2d::Node* parent;
	};

}

#endif // CCOBJECTFACTORY_H
