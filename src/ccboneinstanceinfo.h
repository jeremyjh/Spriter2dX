#ifndef CCBONEINSTANCEINFO_H
#define CCBONEINSTANCEINFO_H

#include "../SpriterPlusPlus/spriterengine/objectinfo/boneinstanceinfo.h"

namespace cocos2d {
	class Node;
}
namespace Spriter2dX
{

	class CCBoneInstanceInfo : public SpriterEngine::BoneInstanceInfo
	{
	public:
		CCBoneInstanceInfo(SpriterEngine::point initialSize, cocos2d::Node* parent);

		void render() override;
	};

}

#endif // CCBONEINSTANCEINFO_H
