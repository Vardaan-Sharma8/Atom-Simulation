#include <iostream>
#include <cmath>
#include "raylib.h"


//---Variables---
const float pi = 3.141;
const float h = 6.62;
const float c = 3;
bool running = true;
const int WIDTH = 1200;
const int HEIGHT = 720;
const char* TITLE = "Bohr\'s Atomic Model";
Vector2 centre = (Vector2){WIDTH / 2, HEIGHT / 2};
float baseRad = 50;


//---Classes---
class Electron{
public:
    float charge = -1.6;
    int n = 1;
    Vector2 pos;
    Vector2 centre_pos;
    float radius;
    Electron(Vector2 pos, int n, float radius) : pos(pos), n(n), radius(radius), centre_pos(centre) {}
    float orbit_radius = centre.x - (centre.x + (baseRad * n));

    void DrawOribit(){
        DrawCircleLinesV(centre_pos, orbit_radius, WHITE);
    }

    void Draw(int i){
        DrawOribit();
        float rad;
        rad = (pi * i) / 180;
        pos.x = centre_pos.x - (cos(rad) * orbit_radius);
        pos.y = centre_pos.y + (sin(rad) * orbit_radius);
        DrawCircleV(pos, radius, RED);
    }
};

class Nucleus{
public:
    Vector2 pos;
    float charge;
    float radius;
    Nucleus(Vector2 pos, float radius) : pos(pos), radius(radius) {}
    Nucleus(Vector2 pos, float charge, float radius) : pos(pos), charge(charge) , radius(radius) {}

    void Draw(){
        DrawCircleV(pos, radius, BLUE);
    }
};

class Photon{
public:
    Vector2 start_pos;
    Vector2 pos;
    float speed;
    Vector2 direction;
    Vector2 velocity;
    float E;

    Photon(Vector2 start_pos, Vector2 direction, float speed, float E) : start_pos(start_pos), direction(direction), 
                                                                        speed(speed), E(E), pos(start_pos){}
};

//---Functions---
Vector2 EStartPos(int n){
    Vector2 res;
    res.x = centre.x - (baseRad * n);
    res.y = centre.y - (baseRad * n);
    return res;
}

//---main---
int main(){
    int i = 0;

    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);

    Nucleus nu(centre, 20);
    Electron e(EStartPos(1), 1, 10);
    Photon ph((Vector2){0, 0}, (Vector2){-1, -1}, 50, 40);

    while(running){
        if(WindowShouldClose()){
            running = false;
            break;
        }
        BeginDrawing();
        ClearBackground(BLACK);

        nu.Draw();
        e.Draw(i);

        EndDrawing();
        i++;
    }

    return 0;
}