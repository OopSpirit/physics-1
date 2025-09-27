#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"
#include <cmath>
#include<vector>
const unsigned int TARGET_FPS = 50;

float angle = 45.0f;
float speed = 400.0f;
float dt =1.0f/TARGET_FPS;
float time = 0;
const int OFFSCREEN = 300;

class Object {
    friend class PhysicsSimulation;
public:
    Vector2 position ;
    Vector2 velocity;
    float drag =1 ;
    //float mass; will be used in the future
    float radius = 15;
    Color colour = WHITE;
    Object() {
        position = { 0,0 };
        velocity = { 0,0 };
    }
    void draw() {
        DrawCircle(position.x, position.y,radius, colour);
        DrawLineEx(position, position + velocity, 2, colour);
    }
};
std::vector<Object> objects;  // Andy is a circle
class PhysicsSimulation {
public:
    std::vector<Object> objects;
    Vector2 gravityAcceleration = { 0,9 };
    void update() {
        for (int i = 0;i < objects.size();i++) {
            objects[i].position += objects[i].velocity * dt;
            objects[i].velocity += gravityAcceleration * dt;
        }
    }
    void draw() {
        for (int i = 0;i < objects.size();i++) {
            objects[i].draw();

        }
    }
    
};
PhysicsSimulation ps;
void cleanup() {
    for (auto it = ps.objects.begin();it != ps.objects.end();it++) {
        Object& object = *it;
        if (object.position.y > GetScreenHeight() + OFFSCREEN
            || object.position.y < -OFFSCREEN
            || object.position.x < -OFFSCREEN
            || object.position.x >GetScreenWidth() + OFFSCREEN) {
            ps.objects.erase(it);
            break;
        }

    }
}
void update() {
    dt = 1.0f / TARGET_FPS;
    time += dt;
    cleanup();
    ps.update();
    if (IsKeyPressed(KEY_SPACE)) {
        Object bird;
        bird.position = { 200, (float)GetScreenHeight() - 200 };
        bird.velocity = { (float)cos(angle * DEG2RAD) * speed, (float)-sin(angle * DEG2RAD) * speed };
        bird.radius = (float)((rand() % 15) + 5);
        
        ps.objects.push_back(bird);
        
    }
   
}
void Draw() {

    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Doan Vu Duy Thien 101533849", 10, float(GetScreenHeight() - 50), 30, WHITE);

    GuiSliderBar(Rectangle{ 10,15,1000,20 }, "", TextFormat("%.2f", time), &time, 0, 240);
    DrawText(TextFormat("Time: %6.2f", time), GetScreenWidth() - 180, 10, 30, WHITE);

    GuiSliderBar(Rectangle{ 10,60,200,20 }, "", TextFormat("Speed: %.0f", speed), &speed, 0, 1000);
    GuiSliderBar(Rectangle{ 10,90,200,20 }, "", TextFormat("Angle: %.0f", angle), &angle, 0, 90);
    GuiSliderBar(Rectangle{ 10,120,200,20 }, "", TextFormat("Gravity: %.0f", ps.gravityAcceleration.y), &ps.gravityAcceleration.y, -180, 900);
    DrawText(TextFormat("Objects: %i", ps.objects.size()), 10, 160, 30, WHITE);

    Vector2 startPos = { 200, GetScreenHeight() - 200 };
    Vector2 velocity1 = { cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed };

    DrawLineEx(startPos, startPos + velocity1, 5, RED);
    ps.draw();
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