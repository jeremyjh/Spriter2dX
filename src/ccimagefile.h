#ifndef SPRITER2DX_IMAGEFILE_H
#define SPRITER2DX_IMAGEFILE_H

#include <vector>
#include <functional>
#include "../SpriterPlusPlus/spriterengine/override/imagefile.h"

namespace cocos2d {
    class Node;
    class Sprite;
}

namespace Spriter2dX
{
    typedef std::vector<cocos2d::Sprite*> SpriteList;
    typedef std::function<cocos2d::Sprite*(const std::string&)> SpriteLoader;

	class CCImageFile : public SpriterEngine::ImageFile
	{
	public:
        CCImageFile(std::string initialFilePath
                   ,SpriterEngine::point initialDefaultPivot
				   ,cocos2d::Node* parent
                   ,SpriteLoader loader);
        ~CCImageFile();

		void renderSprite(SpriterEngine::UniversalObjectInterface *spriteInfo) override;
        void resetSprites();


	private:
        SpriteLoader loader;
        cocos2d::Sprite* nextSprite();

        cocos2d::Node* parent;
        SpriteList avail;
        SpriteList used;
	};

}

#endif // SPRITER2DX_IMAGEFILE_H
