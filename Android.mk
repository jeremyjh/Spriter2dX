LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := Spriter2dX

LOCAL_MODULE_FILENAME := libspriter2dx

LOCAL_SRC_FILES := \
src/ccsoundobjectinforeference.cpp \
src/ccimagefile.cpp \
src/ccfilefactory.cpp \
src/AnimationNode.cpp \
src/ccsoundfile.cpp \
src/ccobjectfactory.cpp \
src/tinyxmlspriterfiledocumentwrapper.cpp \
src/ccpointinstanceinfo.cpp \
src/tinyxmlspriterfileelementwrapper.cpp \
src/cctriggerobjectinfo.cpp \
src/tinyxmlspriterfileattributewrapper.cpp \
src/ccboneinstanceinfo.cpp \
src/ccboxinstanceinfo.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../cocos2d/cocos \
                    $(LOCAL_PATH)/../../cocos2d/external/tinyxml2 \

LOCAL_STATIC_LIBRARIES := SpriterPlusPlus

include $(BUILD_STATIC_LIBRARY)

$(call import-add-path,$(LOCAL_PATH))
$(call import-module,SpriterPlusPlus)
