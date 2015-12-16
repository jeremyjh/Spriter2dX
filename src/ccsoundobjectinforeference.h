#ifndef CCSOUNDOBJECTINFOREFERENCE_H
#define CCSOUNDOBJECTINFOREFERENCE_H

#include "../SpriterPlusPlus/spriterengine/override/soundobjectinforeference.h"


namespace Spriter2dX
{
	

	class CCSoundObjectInfoReference : public SpriterEngine::SoundObjectInfoReference
	{
	public:
		CCSoundObjectInfoReference(const char* path);

		void playTrigger() override;

	private:

		const char* path;

	};

}

#endif // CCSOUNDOBJECTINFOREFERENCE_H
