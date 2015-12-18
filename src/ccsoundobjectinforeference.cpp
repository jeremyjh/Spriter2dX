#include "ccsoundobjectinforeference.h"
#include <audio/include/SimpleAudioEngine.h>

namespace Spriter2dX
{

	CCSoundObjectInfoReference::CCSoundObjectInfoReference(const char* path)
	: path(path) {}

	void CCSoundObjectInfoReference::playTrigger()
	{
		if (getTriggerCount())
		{
            auto engine = CocosDenshion::SimpleAudioEngine::getInstance();
            engine->playEffect(path,false,1.0f,float(getPanning()),float(getVolume()));
		}
	}


}
