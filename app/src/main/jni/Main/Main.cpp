#include <jni.h>
#include <pthread.h>
#include <unistd.h>
#include "Main.h"

// Giao diện ImGui chuẩn
void DrawMenu() {
    ImGui::Begin("xkietmods", NULL, ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Status: Active");
    ImGui::Separator();

    static bool bOption1 = false;
    ImGui::Checkbox("Option 1", &bOption1);

    static float fValue = 50.0f;
    ImGui::SliderFloat("Slider", &fValue, 0.0f, 100.0f);

    ImGui::End();
}

// Callback bắt buộc cho NDK
void SetupImgui() {
    DrawMenu();
}

// Luồng chạy nền khởi tạo
void *main_thread(void *) {
    sleep(3);
    return NULL;
}

__attribute__((constructor)) void lib_main() {
    pthread_t pt;
    pthread_create(&pt, NULL, main_thread, NULL);
}
