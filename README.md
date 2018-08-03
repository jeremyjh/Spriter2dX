A Spriter implementation for Cocos2dX, using [SpriterPlusPlus](https://github.com/lucidspriter/SpriterPlusPlus). 

This is based on the reference implementation's SFML example. 

There is an [example repository](https://github.com/jeremyjh/Spriter2dX-example) to demonstrate using this in a Cocos2d-X project.

This is not quite finished, though it does work (only tested on Android and Linux).

Current limitations: 
   * debug drawings are not in yet.
   * only Cmake and Android project types are supported

## Quick Start
In the root of your Cocos2d-X project:
```shell
mkdir external
cd external
git submodule add git@github.com:jeremyjh/Spriter2dX.git
git submodule update --recursive
```


In your project's CMakeLists.txt, add the first entry and update the existing ones as:

```cmake
add_subdirectory(${CMAKE_SOURCE_DIR}/external/Spriter2dX)
target_link_libraries(${APP_NAME} spriter2dx cocos2d)

include_directories ( 
  ${CMAKE_SOURCE_DIR}/external/Spriter2dX/src
)
```
 
Then in your game layer, you make an animation node like this:

```cpp
#include <AnimationNode.h>

//an update or init method in a Node or Layer 

//path to your scml in your Resources folder
auto scml = FileUtils::getInstance()->fullPathForFilename("my_animation.scml");

//AnimationNode is a container which can play multiple animations sourced from a single model.
auto spriter = Spriter2dX::AnimationNode::create(scml);

//If the images used in your animation are in a spritesheet you've 
//loaded into the Cocos2d frame cache, instantiate the AnimationNode like
//this to load images from there instead:
auto spriter = Spriter2dX::AnimationNode::create(scml, Spriter2dX::AnimationNode::cacheLoader());

//createEntity gives you a SpriterEngine::EntityInstance that you can manipulate.
//(refer to SpriterPlusPlus API)
//You can keep an EntityInstance* as long as your AnimationNode instance is
//retained; it will delete them when it is deleted.
auto entity = spriter->createEntity("entity_000");
entity->setCurrentAnimation(1);

/*
  Adding this node to a visible layer will automatically schedule its update loop.
  no further maintenance is required, use the EntityInstance to stop/start/switch 
  your animations and call createEntity again to setup a new animation in the 
  same node. 
*/
this->addChild(spriter,5);
spriter->setPosition(Vec2(origin.x,visibleSize.height));
```

