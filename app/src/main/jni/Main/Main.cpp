#include "Main.h"
#include "imgui.h"

// Hàm vẽ giao diện Mod Menu
void DrawMenu() {
    // Đã đổi tên menu thành xkietmods
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
