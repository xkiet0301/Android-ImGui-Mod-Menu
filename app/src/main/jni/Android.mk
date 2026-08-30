LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := loader

# Tự động tìm tất cả các file .cpp trong thư mục jni và các thư mục con
LOCAL_SRC_FILES := main.cpp

# Nếu có thêm các file nguồn ở thư mục khác, hãy liệt kê vào đây, ví dụ:
# ../Loader/loader.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/Include \
                    $(LOCAL_PATH)/Loader \
                    $(LOCAL_PATH)/Main

LOCAL_LDLIBS := -llog -landroid -lGLESv2 -lEGL

include $(BUILD_SHARED_LIBRARY)
