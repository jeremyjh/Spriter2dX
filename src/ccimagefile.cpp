#include "ccimagefile.h"
#include "../SpriterPlusPlus/spriterengine/objectinfo/universalobjectinterface.h"
#include <2d/CCSprite.h>
#include <CCFileUtils.h>
#include <sstream>

namespace se = SpriterEngine;
namespace cc = cocos2d;

namespace Spriter2dX
{

	CCImageFile::CCImageFile(std::string initialFilePath
                            ,se::point initialDefaultPivot
                            ,cc::Node* parent) :
		se::ImageFile(initialFilePath,initialDefaultPivot), parent(parent)
	{
	}

    CCImageFile::~CCImageFile()
    {
        for (auto sprite: avail) {
            sprite->removeFromParentAndCleanup(true);
        }
        for (auto sprite: used) {
            sprite->removeFromParentAndCleanup(true);
        }
    }

	void CCImageFile::renderSprite(se::UniversalObjectInterface* spriteInfo)
	{
        auto sprite = nextSprite();
        sprite->setOpacity((spriteInfo->getAlpha())*255);
        sprite->setPosition(float(spriteInfo->getPosition().x), -float(spriteInfo->getPosition().y));
        sprite->setRotation(float(se::toDegrees(spriteInfo->getAngle())));
        sprite->setScale(float(spriteInfo->getScale().x), float(spriteInfo->getScale().y));
        sprite->setAnchorPoint(cc::Vec2(float(spriteInfo->getPivot().x), float(spriteInfo->getPivot().y)));
        sprite->setVisible(true);
	}

    std::vector<std::string> split(const std::string& s, char delim) {
        std::stringstream ss(s);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    cc::Sprite* CCImageFile::nextSprite()
    {
        cc::Sprite* sprite {nullptr};
        if ( avail.size() > 0 ) {
            sprite = avail.back();
            avail.pop_back();
        } else {
            auto fullpath = split(path(), '/');
            sprite = cc::Sprite::createWithSpriteFrameName(fullpath.back());
            if (sprite)
            {
                parent->addChild(sprite);
            }
            else
            {
                CCLOGERROR("CCImageFile() - cocos sprite unable to load file from path %s",path().c_str());
            }
        }
        used.push_back(sprite);
        return sprite;
    }

    void CCImageFile::resetSprites()
    {
        for (auto sprite: used) {
            sprite->setVisible(false);
            avail.push_back(sprite);
        }
        used.clear();
    }

}
