//
// Created by jeremy on 12/12/15.
//
#include <2d/CCNode.h>

#include "SpriterNode.h"
#include "ccfilefactory.h"
#include "ccobjectfactory.h"

namespace cc = cocos2d;
namespace se = SpriterEngine;

namespace Spriter2dX {
    SpriterNode::SpriterNode(const std::string& scmlFile)
            : files(new CCFileFactory(this))
            , model(scmlFile, files, new CCObjectFactory(this)) {}

    void SpriterNode::update(float dt)
    {
        files->resetSprites();
        for (auto &entity: entities) {
            entity->setTimeElapsed(dt * 1000.0f);
            entity->render();
            entity->playAllTriggers();
        }
    }

    se::EntityInstance* SpriterNode::createEntity(const std::string& name)
    {
        auto entity = model.getNewEntityInstance(name);
        entities.push_back(std::unique_ptr<se::EntityInstance>(entity));
        return entity;
    }

    SpriterNode* SpriterNode::create(const std::string& scmlFile)
    {
        SpriterNode* ret = new (std::nothrow) SpriterNode(scmlFile);
        if (ret && ret->init())
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(ret);
        }
        return ret;
    }

    void SpriterNode::onEnter() {
        cc::Node::onEnter();
        this->scheduleUpdate();
    }

    void SpriterNode::onExit() {
        cc::Node::onExit();
        this->unscheduleUpdate();
    }
}
