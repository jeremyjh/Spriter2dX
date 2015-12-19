//
// Created by jeremy on 12/12/15.
//
#include <2d/CCSprite.h>
#include <sstream>

#include "AnimationNode.h"
#include "ccobjectfactory.h"

namespace cc = cocos2d;
namespace se = SpriterEngine;

namespace Spriter2dX {
    AnimationNode::AnimationNode(const std::string& scmlFile, SpriteLoader loader)
            : files(new CCFileFactory(this,loader))
            , model(scmlFile, files, new CCObjectFactory(this)) {}

    void AnimationNode::update(float dt)
    {
        files->resetSprites();
        for (auto &entity: entities) {
            entity->setTimeElapsed(dt * 1000.0f);
            entity->render();
            entity->playAllTriggers();
        }
    }

    se::EntityInstance* AnimationNode::createEntity(const std::string& name)
    {
        auto entity = model.getNewEntityInstance(name);
        entities.push_back(std::unique_ptr<se::EntityInstance>(entity));
        return entity;
    }

    AnimationNode* AnimationNode::create(const std::string& scmlFile, SpriteLoader loader)
    {
        AnimationNode * ret = new (std::nothrow) AnimationNode(scmlFile, loader);
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

    SpriteLoader AnimationNode::fileLoader()
    {
        return [](const std::string& name) { return cc::Sprite::create(name);};
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

    SpriteLoader AnimationNode::cacheLoader()
    {
        return [](const std::string& name) {
            auto fullpath = split(name, '/');
            return cc::Sprite::createWithSpriteFrameName(fullpath.back());
        };
    }

    void AnimationNode::onEnter() {
        cc::Node::onEnter();
        this->scheduleUpdate();
    }

    void AnimationNode::onExit() {
        cc::Node::onExit();
        this->unscheduleUpdate();
    }
}
