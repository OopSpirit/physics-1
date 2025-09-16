
//float time = 0;
//float dt;
//float x = 500;
//float y = 500;
//float frequency = 1.0f;
//float amplitude = 70;
//void Update() {
//    dt = 1.0 / TARGET_FPS;
//    time += dt;
//
//    x = x + (-sin(time * frequency)) * frequency * amplitude * dt;
//    y = y + (cos(time * frequency)) * frequency * amplitude * dt;
//}
//void Draw() {
//    BeginDrawing();
//    ClearBackground(BLACK);
//    DrawText("Joss Moo-Young 123456789", 10, 20, 20, LIGHTGRAY);
//
//
//
//    // GuiSliderBar(Rectangle{ 60, 5, 1000, 10 }, "Time", TextFormat("%.2f", time), &time, 0, 240);
//    DrawText(TextFormat("FPS: %i, TIME: %.2f", TARGET_FPS, time), GetScreenWidth() - 250, 20, 20, LIGHTGRAY);
//    DrawCircle(x, y, 60, RED);
//    DrawCircle(GetScreenWidth() / 2 + cos(time * frequency) * amplitude, GetScreenHeight() / 2 + sin(time * frequency) * amplitude, 60, GREEN);
//    EndDrawing();
//}
//int main()
//{
//    InitWindow(InitialWidth, InitialHeight, "Game Physics: Joss Moo-Young 123456789");
//    SetTargetFPS(TARGET_FPS);
//
//    while (!WindowShouldClose())
//    {
//        Update();
//        Draw();
//    }
//
//    CloseWindow();
//    return 0;
//}

//Lab1
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
    float launchAngleRadian = launchAngle * PI / 180.0f;
    float vx = launchSpeed * cos(launchAngleRadian);
    float vy = launchSpeed * -sin(launchAngleRadian);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawLineV({ launchPositionX, launchPositionY }, { launchPositionX+ vx, launchPositionY+vy }, RED);
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
