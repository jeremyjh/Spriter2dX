#include "ccfilefactory.h"

#include "tinyxmlspriterfiledocumentwrapper.h"

#include "ccimagefile.h"
#include "ccsoundfile.h"
#include "2d/CCNode.h"

namespace cc = cocos2d;
namespace se = SpriterEngine;

namespace Spriter2dX
{
	class CCFileFactory::impl
	{
	public:
		impl(cc::Node* parent) : parent(parent)
		{
			parent->retain();
		}

		~impl()
		{
			parent->release();
		}


		se::ImageFile* newImageFile(const std::string&initialFilePath, se::point initialDefaultPivot)
		{
			auto file = new CCImageFile(initialFilePath, initialDefaultPivot, parent);
			images.push_back(file);
			return file;
		}

		void resetSprites()
		{
			for (auto file: images) {
				file->resetSprites();
			}
		}

	private:
		cc::Node* parent;
		std::vector<CCImageFile*> images;
	};

	CCFileFactory::CCFileFactory(cc::Node* parent)
			: self(new CCFileFactory::impl(parent)) {}

	CCFileFactory::~CCFileFactory() { }

	se::ImageFile* CCFileFactory::newImageFile(const std::string&initialFilePath, se::point initialDefaultPivot)
	{
		return self->newImageFile(initialFilePath, initialDefaultPivot);
	}

	se::SoundFile* CCFileFactory::newSoundFile(const std::string& initialFilePath)
	{
		return new CCSoundFile(initialFilePath);
	}

	se::SpriterFileDocumentWrapper* CCFileFactory::newScmlDocumentWrapper()
	{
		return new se::TinyXmlSpriterFileDocumentWrapper();
	}

	void CCFileFactory::resetSprites()
	{
		self->resetSprites();
	}


}
