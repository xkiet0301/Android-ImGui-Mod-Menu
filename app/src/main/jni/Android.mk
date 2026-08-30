LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := loader

LOCAL_SRC_FILES := \
    main.cpp \
    imgui/imgui.cpp \
    imgui/imgui_draw.cpp \
    imgui/imgui_tables.cpp \
    imgui/imgui_widgets.cpp

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(LOCAL_PATH)/imgui

LOCAL_CPPFLAGS := -std=c++17

LOCAL_LDLIBS := \
    -llog \
    -landroid \
    -lEGL \
    -lGLESv2

include $(BUILD_SHARED_LIBRARY)
