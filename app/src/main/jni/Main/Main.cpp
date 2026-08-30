#include <pthread.h>
#include <unistd.h>
#include "imgui.h"

// ============================================================
// STATE
// ============================================================

struct ModFeatures
{
    bool bypass;
    bool fixCrash;
    bool speedTime;
    bool fakeLag;
    bool resetGuest;

    bool espLine;
    bool espBox;
    bool espFov;

    bool aimBot;
    bool aimHead;
    bool aimLegit;
    bool aimSilent;
    bool aimKill;

    int fovValue;

    bool teleEnemy;
    bool footballMode;
    bool unlockSkin;

    bool speedHack;
    float speedValue;
};

static ModFeatures features =
{
    true,       // bypass
    true,       // fixCrash
    false,      // speedTime
    false,      // fakeLag
    false,      // resetGuest

    false,      // espLine
    false,      // espBox
    false,      // espFov

    false,      // aimBot
    false,      // aimHead
    false,      // aimLegit
    false,      // aimSilent
    false,      // aimKill

    180,        // fovValue

    false,      // teleEnemy
    false,      // footballMode
    false,      // unlockSkin

    false,      // speedHack
    1.0f        // speedValue
};

// ============================================================
// SPEED HACK UI / DEMO STATE
// ============================================================

static void DrawSpeedHack()
{
    if (ImGui::Checkbox("Speed Hack", &features.speedHack))
    {
        if (!features.speedHack)
        {
            features.speedValue = 1.0f;
        }
    }

    if (features.speedHack)
    {
        ImGui::SliderFloat("Speed", &features.speedValue, 1.0f, 5.0f, "%.1fx");
        ImGui::Text("Speed Hack: ON");
        ImGui::Text("Current Value: %.1fx", features.speedValue);
    }
    else
    {
        ImGui::Text("Speed Hack: OFF");
    }
}

// ============================================================
// MAIN TAB
// ============================================================

static void DrawMainTab()
{
    if (!ImGui::BeginTabItem("Main"))
        return;

    ImGui::Text("SYSTEM & SETTINGS");
    ImGui::Separator();

    ImGui::Checkbox("Bypass", &features.bypass);
    ImGui::Checkbox("Fix Crash", &features.fixCrash);
    ImGui::Checkbox("Speed Time", &features.speedTime);
    ImGui::Checkbox("Fake Lag", &features.fakeLag);
    ImGui::Checkbox("Reset Guest", &features.resetGuest);

    ImGui::Separator();
    DrawSpeedHack();

    ImGui::EndTabItem();
}

// ============================================================
// ESP TAB
// ============================================================

static void DrawEspTab()
{
    if (!ImGui::BeginTabItem("ESP"))
        return;

    ImGui::Text("ESP VISUALS");
    ImGui::Separator();

    ImGui::Checkbox("ESP Line", &features.espLine);
    ImGui::Checkbox("ESP Box", &features.espBox);
    ImGui::Checkbox("ESP FOV", &features.espFov);

    ImGui::EndTabItem();
}

// ============================================================
// AIM TAB
// ============================================================

static void DrawAimTab()
{
    if (!ImGui::BeginTabItem("Aimbot"))
        return;

    ImGui::Text("AIM SETTINGS");
    ImGui::Separator();

    ImGui::Checkbox("Aim Bot", &features.aimBot);
    ImGui::Checkbox("Aim Head", &features.aimHead);
    ImGui::Checkbox("Aim Legit", &features.aimLegit);
    ImGui::Checkbox("Aim Silent", &features.aimSilent);
    ImGui::Checkbox("Aim Kill", &features.aimKill);

    ImGui::Separator();
    ImGui::SliderInt("FOV", &features.fovValue, 0, 360, "%d");

    ImGui::EndTabItem();
}

// ============================================================
// TELE / FOOTBALL TAB
// ============================================================

static void DrawTeleTab()
{
    if (!ImGui::BeginTabItem("Tele & Folb"))
        return;

    ImGui::Text("TELEPORT & FOOTBALL");
    ImGui::Separator();

    ImGui::Checkbox("Tele to Enemy", &features.teleEnemy);
    ImGui::Checkbox("Football Mode", &features.footballMode);

    ImGui::EndTabItem();
}

// ============================================================
// SKIN TAB
// ============================================================

static void DrawSkinTab()
{
    if (!ImGui::BeginTabItem("Skin"))
        return;

    ImGui::Text("SKIN SETTINGS");
    ImGui::Separator();

    ImGui::Checkbox("Unlock All Skin", &features.unlockSkin);

    ImGui::EndTabItem();
}

// ============================================================
// MAIN MENU
// ============================================================

void DrawMenu()
{
    ImGuiWindowFlags flags = ImGuiWindowFlags_AlwaysAutoResize;

    if (!ImGui::Begin("xkietmods v5.2", nullptr, flags))
    {
        ImGui::End();
        return;
    }

    ImGui::TextColored(ImVec4(0.2f, 0.8f, 1.0f, 1.0f), "XKIETMODS VIP");
    ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "Status: ACTIVE");
    ImGui::Separator();

    if (ImGui::BeginTabBar("ModTabs"))
    {
        DrawMainTab();
        DrawEspTab();
        DrawAimTab();
        DrawTeleTab();
        DrawSkinTab();

        ImGui::EndTabBar();
    }

    ImGui::End();
}

// ============================================================
// IMGUI SETUP
// ============================================================

void SetupImgui()
{
    DrawMenu();
}

// ============================================================
// BACKGROUND THREAD
// ============================================================

static void* main_thread(void*)
{
    sleep(3);

    while (true)
    {
        sleep(1);
    }

    return nullptr;
}

// ============================================================
// LIBRARY CONSTRUCTOR
// ============================================================

__attribute__((constructor))
static void lib_main()
{
    pthread_t thread{};

    if (pthread_create(&thread, nullptr, main_thread, nullptr) == 0)
    {
        pthread_detach(thread);
    }
}
