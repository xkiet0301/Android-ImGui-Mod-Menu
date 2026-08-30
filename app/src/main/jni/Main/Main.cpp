#include <jni.h>
#include <pthread.h>
#include <unistd.h>
#include "Main.h"

// 1. Hàm vẽ giao diện menu xkietmods
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

// 2. Bắt buộc để NDK biên dịch thành công Main.o
void SetupImgui() {
    DrawMenu();
}

void *hack_thread(void *) {
    sleep(5);
    return NULL;
}

__attribute__((constructor)) void __init() {
    pthread_t pt;
    pthread_create(&pt, NULL, hack_thread, NULL);
}
