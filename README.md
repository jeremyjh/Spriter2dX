A Spriter implementation for Cocos2dX, using [SpriterPlusPlus](https://github.com/lucidspriter/SpriterPlusPlus). 
This is based on the reference implementation's SFML example.

This is not quite ready for use, though it does work (at least on Linux).

Current limitations: 
   * only loads sprites from the frame cache (assumes you've loaded your cache with TexturePacker or similar tools.)
   * debug drawings are not in yet.
   * only Cmake project type is setup (Android coming soon).
   * no example yet

If you want to have a go with it, you can try this (assumes you've checked it out as a submodule in deps/Spriter2dX in the root of your
Cocos2dX project):

In CMakeLists.txt:

```cmake
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/Spriter2dX)
target_link_libraries(${APP_NAME} cocos2d spriter2dx)

include_directories ( 
  ${CMAKE_SOURCE_DIR}/deps/Spriter2dX/src
)
```
 
Then in your game layer, you make an animation node like this:

```cpp
#include <SpriterNode.h>

//an update or init method in a Node or Layer 

    //path to your scml in your Resources folder
    auto scml = FileUtils::getInstance()->fullPathForFilename("my_animation.scml");

    //A SpriterNode is a container which can play multiple animations sourced from a single model.
    auto spriter = Spriter2dX::SpriterNode::create(scml);

    //createEntity gives you a SpriterEngine::EntityInstance that you can do whatever you want with
    //(refer to SpriterPlusPlus API)
    auto entity = spriter->createEntity("entity_000");
    entity->setCurrentAnimation(1);

    //adding this node to a displayed layer will automatically activate its update loop
    //no further maintenance is required, use the EntityInstance to stop/start/switch your animations
    //and call createEntity again to setup a new animation in the same layer.
    this->addChild(spriter,5);
    spriter->setPosition(center());
```

