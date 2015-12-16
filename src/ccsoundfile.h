#ifndef CCSOUNDFILE_H
#define CCSOUNDFILE_H

#include "../SpriterPlusPlus/spriterengine/override/soundfile.h"

namespace Spriter2dX
{

	class CCSoundFile : public SpriterEngine::SoundFile
	{
	public:
		CCSoundFile(std::string initialFilePath);

		SpriterEngine::SoundObjectInfoReference* newSoundInfoReference() override;

	private:
		const char* path;
	};

}

#endif // CCSOUNDFILE_H
