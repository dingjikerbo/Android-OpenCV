LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

OPENCV_LIB_TYPE := STATIC
include $(LOCAL_PATH)/opencv/jni/OpenCV.mk

LOCAL_MODULE := test_opencv

LOCAL_SRC_FILES := $(LOCAL_PATH)/main.cpp \
$(LOCAL_PATH)/utils.cpp

LOCAL_CFLAGS += -mfpu=neon -std=c++11 -fexceptions -frtti
LOCAL_CFLAGS += -ffast-math -Os -funroll-loops

LOCAL_LDLIBS += -llog

LOCAL_ARM_NEON := true
LOCAL_ARM_MODE := arm

include $(BUILD_SHARED_LIBRARY)