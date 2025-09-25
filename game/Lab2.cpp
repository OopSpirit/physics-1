#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"
#include <cmath>
const unsigned int TARGET_FPS = 50;

float angle = 45.0f;
float speed = 400.0f;


class Object {
    friend class PhysicsSimulation;
public:
    Vector2 position ;
    Vector2 velocity;
    //float drag;
    //float mass; will be used in the future
    Object() {
        position = { 0,0 };
        velocity = { 0,0 };
    }
};
Object Andy;  // Andy is a circle
class PhysicsSimulation {
    friend class Object;
public:
    float dt;
    float time = 0;
    Vector2 gravityAcceleration;
    PhysicsSimulation() {
        dt = 0;
        time = 0;
        gravityAcceleration = { 0,100 };
    }
    void Update(Object& obj) {
        time += dt;
        obj.velocity = obj.velocity + gravityAcceleration * dt;
    }
    
};
PhysicsSimulation ps;
void update() {
    ps.dt = 1.0f / TARGET_FPS;
    //ps.time += ps.dt;
    if (IsKeyPressed(KEY_SPACE)) {
        Andy.position = { 200, (float)GetScreenHeight() - 200 };
        Andy.velocity = { (float)cos(angle * DEG2RAD) * speed, (float) - sin(angle * DEG2RAD) * speed};
    }
    Andy.position = Andy.position + Andy.velocity * ps.dt;
    ps.Update(Andy);
}
void Draw() {

    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Doan Vu Duy Thien 101533849", 10, float(GetScreenHeight() - 50), 30, WHITE);

    GuiSliderBar(Rectangle{ 10,15,1000,20 }, "", TextFormat("%.2f", ps.time), &ps.time, 0, 240);
    DrawText(TextFormat("Time: %6.2f", ps.time), GetScreenWidth() - 180, 10, 30, WHITE);

    GuiSliderBar(Rectangle{ 10,60,200,20 }, "", TextFormat("Speed: %.0f", speed), &speed, 0, 1000);
    GuiSliderBar(Rectangle{ 10,90,200,20 }, "", TextFormat("Angle: %.0f", angle), &angle, 0, 90);
    GuiSliderBar(Rectangle{ 10,120,200,20 }, "", TextFormat("Gravity: %.0f", ps.gravityAcceleration.y), &ps.gravityAcceleration.y, -180, 900);
    DrawCircle(Andy.position.x, Andy.position.y, 15, RED);

    Vector2 startPos = { 200, GetScreenHeight() - 200 };
    Vector2 velocity1 = { cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed };

    DrawLineEx(startPos, startPos + velocity1, 5, RED);

    EndDrawing();
}
int main() {
    InitWindow(InitialWidth, InitialHeight, "Launching Bird Simulation");
    SetTargetFPS(TARGET_FPS);
    
    while (!WindowShouldClose()) {
        update();
        Draw();
    }
    CloseWindow();
    return 0;
}