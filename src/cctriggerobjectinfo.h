#ifndef CCTRIGGEROBJECTINFO_H
#define CCTRIGGEROBJECTINFO_H

#include "../SpriterPlusPlus/spriterengine/objectinfo/triggerobjectinfo.h"

namespace Spriter2dX
{

	class CCTriggerObjectInfo : public SpriterEngine::TriggerObjectInfo
	{
	public:
		CCTriggerObjectInfo(const std::string& name);

		void playTrigger() override;

	private:
        const std::string name;
	};

}

#endif // CCTRIGGEROBJECTINFO_H
