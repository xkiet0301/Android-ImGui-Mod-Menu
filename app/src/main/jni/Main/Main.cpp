#include "Main.h"
#include <Includes/imgui.h>

void DrawMenu() {
    ImGui::Begin("xkietmods", NULL, ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Status: Activated");
    ImGui::Separator();

    static bool bAimbot = false;
    ImGui::Checkbox("Auto Aimbot", &bAimbot);

    static bool bESP = false;
    ImGui::Checkbox("Player ESP", &bESP);

    static bool bWallhack = false;
    ImGui::Checkbox("Wallhack 3D", &bWallhack);

    ImGui::Separator();

    static float fFOV = 90.0f;
    ImGui::SliderFloat("Aimbot FOV", &fFOV, 10.0f, 360.0f);

    static int iSpeed = 1;
    ImGui::SliderInt("Speed Hack", &iSpeed, 1, 5);

    ImGui::End();
}

void SetupImgui() {
    DrawMenu();
}

// Các hàm bổ trợ hệ thống để tránh lỗi biên dịch Main.o
extern "C" {
    JNIEXPORT void JNICALL
    Java_com_android_support_Preferences_Changes(JNIEnv *env, jclass clazz, jobject feature, jint value) {
        // Callback tùy chọn
    }
}
