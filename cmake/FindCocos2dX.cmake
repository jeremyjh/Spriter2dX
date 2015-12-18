# - Try to find the cocos2d headers

FIND_PATH(COCOS2D_INCLUDE_DIR cocos2d.h
        ${CMAKE_SOURCE_DIR}/cocos2d/cocos
        ${PROJECT_SOURCE_DIR}/cocos2d/cocos
        ${PROJECT_SOURCE_DIR}/../cocos2d/cocos
        ${PROJECT_SOURCE_DIR}/../../cocos2d/cocos
)

SET(COCOS2D_FOUND "NO")
IF (COCOS2D_INCLUDE_DIR)
    SET(COCOS2D_FOUND "YES")
ENDIF (COCOS2D_INCLUDE_DIR)

MARK_AS_ADVANCED(COCOS2D_INCLUDE_DIR)