#include "ccobjectfactory.h"

#include "ccpointinstanceinfo.h"
#include "ccboxinstanceinfo.h"
#include "ccboneinstanceinfo.h"

#include "cctriggerobjectinfo.h"

namespace cc = cocos2d;
namespace se = SpriterEngine;

namespace Spriter2dX
{

	CCObjectFactory::CCObjectFactory(cc::Node* parent) : parent(parent)
	{
	}

	se::PointInstanceInfo* CCObjectFactory::newPointInstanceInfo()
	{
		return new CCPointInstanceInfo(parent);
	}

	se::BoxInstanceInfo* CCObjectFactory::newBoxInstanceInfo(se::point size)
	{
		return new CCBoxInstanceInfo(size);
	}

	se::BoneInstanceInfo* CCObjectFactory::newBoneInstanceInfo(se::point size)
	{
		return new CCBoneInstanceInfo(size, parent);
	}

    se::TriggerObjectInfo *CCObjectFactory::newTriggerObjectInfo(std::string triggerName) {
        return new CCTriggerObjectInfo(triggerName);
    }
}