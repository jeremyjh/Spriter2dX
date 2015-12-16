#ifndef CCBOXINSTANCEINFO_H
#define CCBOXINSTANCEINFO_H

#include "../SpriterPlusPlus/spriterengine/objectinfo/boxinstanceinfo.h"

namespace Spriter2dX
{

	class CCBoxInstanceInfo : public SpriterEngine::BoxInstanceInfo
	{
	public:
		CCBoxInstanceInfo(SpriterEngine::point initialSize);

		void render() override;
	};

}

#endif // SFMLBOXINSTANCEINFO_H
