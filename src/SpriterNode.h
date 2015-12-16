//
// Created by jeremy on 12/12/15.
//

#ifndef SPRITER2DX_SPRITERNODE_H
#define SPRITER2DX_SPRITERNODE_H

#include <memory>

#include "../SpriterPlusPlus/spriterengine/spriterengine.h"
#include "ccfilefactory.h"

#include <2d/CCNode.h>

namespace Spriter2dX {
    class SpriterNode : public cocos2d::Node {
    public:
        SpriterNode(const std::string& scmlFile);
        void update (float dt) override;
        SpriterEngine::EntityInstance* createEntity(const std::string& name);
        static SpriterNode* create(const std::string& scmlFile);
        virtual void onEnter() override;
        virtual void onExit() override;
    private:
        CCFileFactory* files;
        std::vector<std::unique_ptr<SpriterEngine::EntityInstance>> entities;
        SpriterEngine::SpriterModel model;

    };
}



#endif //SPRITERNODE_H
