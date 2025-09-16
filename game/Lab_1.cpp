#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"
#include <cmath>
const unsigned int TARGET_FPS = 50;
float launchAngle = 35.0f;
float launchSpeed = 400.0f;
float launchPositionX = 500.0f;
float launchPositionY = 400.0f;
void Draw() {
    float launchAngleRadian = launchAngle * PI / 180.0f; // because sin cos in C++ use radian to calculate
    float vx = launchSpeed * cos(launchAngleRadian);
    float vy = launchSpeed * -sin(launchAngleRadian);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawLineV({ launchPositionX, launchPositionY }, { launchPositionX + vx, launchPositionY + vy }, RED);
    DrawText(TextFormat("Position: {%.1f, %.1f}", launchPositionX, launchPositionY), 30, 20, 30, WHITE);
    DrawText(TextFormat("Angle: %.1f degree", launchAngle), 30, 50, 30, WHITE);
    DrawText(TextFormat("Speed: %.1f m/s", launchSpeed), 30, 80, 30, WHITE);
    EndDrawing();
}
int main() {
    InitWindow(InitialWidth, InitialHeight, "Rendering Launch Vector");
    SetTargetFPS(TARGET_FPS);
    while (!WindowShouldClose()) {
        Draw();
    }
    CloseWindow();
    return 0;
}