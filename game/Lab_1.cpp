#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"
#include <cmath>
const unsigned int TARGET_FPS = 50;
float dt = 1.0f / TARGET_FPS;
float time = 0;
float angle = 35.0f;
float speed = 400.0f;

void update() {
    dt = 1.0f / TARGET_FPS;
    time += dt;
}
void Draw() {
   
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Doan Vu Duy Thien 101533849", 10, float(GetScreenHeight() - 50), 30, WHITE);

    GuiSliderBar(Rectangle{ 10,15,1000,20 }, "", TextFormat("%.2f", time), &time, 0, 240);
    DrawText(TextFormat("Time: %6.2f", time), GetScreenWidth() - 180, 10, 30, WHITE);

    GuiSliderBar(Rectangle{ 10,100,200,100 }, "", TextFormat("Speed: %.0f", speed), &speed, -100, 1000);
    GuiSliderBar(Rectangle{ 10,200,200,100 }, "", TextFormat("Angle: %.0f", angle), &angle, -180, 180);

    Vector2 startPos = { 200, GetScreenHeight() - 200 };
    Vector2 velocity = { cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed };

    DrawLineEx(startPos, startPos + velocity, 5, RED);
    
    EndDrawing();
}
int main() {
    InitWindow(InitialWidth, InitialHeight, "Rendering Launch Vector");
    SetTargetFPS(TARGET_FPS);
    while (!WindowShouldClose()) {
        update();
        Draw();
    }
    CloseWindow();
    return 0;
}