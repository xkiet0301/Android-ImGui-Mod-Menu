LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := loader

# Liệt kê tất cả các file nguồn C++ cần biên dịch
LOCAL_SRC_FILES := main.cpp

# Thêm đường dẫn thư mục chứa file header (.h) nếu chúng nằm trong thư mục con
# Ví dụ: Nếu thư mục 'Include' hoặc 'Main' chứa file .h, hãy thêm dòng dưới:
LOCAL_C_INCLUDES := $(LOCAL_PATH)

LOCAL_LDLIBS := -llog -landroid -lGLESv2 -lEGL

include $(BUILD_SHARED_LIBRARY)
