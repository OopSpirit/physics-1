//#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//#include "game.h"
//#include <cmath>
//#include<vector>
//#include <string>
//
//const unsigned int TARGET_FPS = 50;
//
//float angle = 45.0f;
//float speed = 400.0f;
//float dt =1.0f/TARGET_FPS;
//float stime = 0;
//const int OFFSCREEN = 300;
//using namespace std;
//class Object {
//    friend class PhysicsSimulation;
//public:
//    Vector2 position ;
//    Vector2 velocity;
//    //float drag =1 ;
//    float mass = 1;
//    string name = "object";
//    //float radius = 15;
//    Color colour = GREEN;
//    Object() {
//        position = { 0,0 };
//        velocity = { 0,0 };
//    }
//    virtual void draw() {
//        DrawCircle(position.x, position.y,12, colour);
//        DrawLineEx(position, position + velocity, 2, colour);
//    }
//};
////std::vector<Object> objects;  
//class ObjectBox : public Object {
//public:
//    Vector2 size;
//
//};
//class ObjectCircle : public Object {
//public:
//    float radius;
//    void draw() override {
//        DrawCircle(position.x, position.y, radius, colour);
//        DrawLineEx(position, position + velocity, 2, colour);
//    }
//
//};
//bool CircleOverlap(ObjectCircle* A, ObjectCircle* B) {
//    Vector2 displacement = B->position - A->position;
//    float distance = Vector2Length(displacement);
//    float sumR = A->radius + B->radius;
//    if (sumR >= distance) return true;
//    else return false;
//}
//class PhysicsSimulation {
//public:
//    std::vector<Object*> objekts;
//    Vector2 gravityAcceleration = { 0,9 };
//    void update() {
//        for (int i = 0;i < objekts.size();i++) {
//            objekts[i]->position += objekts[i]->velocity * dt;
//            objekts[i]->velocity += gravityAcceleration * dt; // v= v+g*dt
//        }
//        checkCollisions();
//    }
//    void add(Object* newObj) {
//        newObj->name = to_string(objekts.size());
//        objekts.push_back(newObj);
//    }
//   
//    void checkCollisions() {
//        for (int i = 0; i < objekts.size();i++) {
//            objekts[i]->colour = GREEN;
//        }
//        for (int i = 0;i < objekts.size();i++) {
//            for (int j = i + 1;j < objekts.size();j++) {
//                Object* PointerA = objekts[i];
//                ObjectCircle* CircleA = (ObjectCircle*)PointerA;
//
//                Object* PointerB = objekts[j];
//                ObjectCircle* CircleB = (ObjectCircle*)PointerB;
//
//                if (CircleOverlap(CircleA, CircleB)) {
//                    PointerA->colour = RED;
//                    PointerB->colour = RED;
//                }
//                
//            }
//        }
//        
//    }
//};
//
//PhysicsSimulation ps;
//void cleanup() {
//    for (int i = 0;i < ps.objekts.size();i++) {
//        Object* objekt = ps.objekts[i];
//        if (objekt->position.y > GetScreenHeight() || objekt->position.y < 0 || objekt->position.x > GetScreenWidth() || objekt->position.x < 0) {
//            vector<Object*>::iterator it = ps.objekts.begin() + i;
//            Object* pointer = *it;
//            delete pointer;
//            ps.objekts.erase(it);
//            i--;
//        }
//    }
//}
//void update() {
//    dt = 1.0f / TARGET_FPS;
//    stime += dt;
//    
//    ps.update();
//    if (IsKeyPressed(KEY_SPACE)) {
//        ObjectCircle* bird = new ObjectCircle;
//        bird->position = { 200, (float)GetScreenHeight() - 200 };
//        bird->velocity = { (float)cos(angle * DEG2RAD) * speed, (float)-sin(angle * DEG2RAD) * speed };
//        bird->radius = (float)((rand() % 25) + 5);
//        
//        ps.add(bird);
//        
//    }
//
//    cleanup();
//}
//void Draw() {
//
//    BeginDrawing();
//    ClearBackground(BLACK);
//    DrawText("Doan Vu Duy Thien 101533849", 10, float(GetScreenHeight() - 50), 30, WHITE);
//
//    GuiSliderBar(Rectangle{ 10,15,1000,20 }, "", TextFormat("%.2f", stime), &stime, 0, 240);
//    DrawText(TextFormat("Time: %6.2f", stime), GetScreenWidth() - 180, 10, 30, WHITE);
//
//    GuiSliderBar(Rectangle{ 10,60,200,20 }, "", TextFormat("Speed: %.0f", speed), &speed, 0, 1000);
//    GuiSliderBar(Rectangle{ 10,90,200,20 }, "", TextFormat("Angle: %.0f", angle), &angle, 0, 90);
//    GuiSliderBar(Rectangle{ 10,120,200,20 }, "", TextFormat("Gravity: %.0f", ps.gravityAcceleration.y), &ps.gravityAcceleration.y, -180, 900);
//    DrawText(TextFormat("Objects: %i", ps.objekts.size()), 10, 160, 30, WHITE);
//
//    Vector2 startPos = { 200, GetScreenHeight() - 200 };
//    Vector2 velocity1 = { cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed };
//
//    DrawLineEx(startPos, startPos + velocity1, 5, RED);
//    for (int i = 0;i < ps.objekts.size();i++) {
//        ps.objekts[i]->draw();
//
//    }
//    EndDrawing();
//}
//int main() {
//    InitWindow(InitialWidth, InitialHeight, "Sphere-Sphere Overlap");
//    GuiLoadStyleDefault();
//
//    SetTargetFPS(TARGET_FPS);
//    
//    while (!WindowShouldClose()) {
//        update();
//        Draw();
//    }
//    CloseWindow();
//    return 0;
//}
