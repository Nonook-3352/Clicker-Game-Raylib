#include "raylib.h"
#include <stdio.h>

int SCREEN_WIDTH  = 800;
int SCREEN_HEIGHT = 600;

bool ColorEquals(Color a, Color b) {
    return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
}



int main()
{
    //Start

    int frameRemaining = 0;
    int score = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Clicker Game");
    SetTargetFPS(60);


    Color rectanglecolor = {255, 0, 0, 255};

    Rectangle rec = {SCREEN_WIDTH/2-100, SCREEN_HEIGHT/2-100, 200, 200};

    while (!WindowShouldClose())
    {   //Update

        if (CheckCollisionPointRec(GetMousePosition(), rec)) {
            if (IsMouseButtonPressed(0)) {
                    rectanglecolor = (Color){150, 0, 0 ,255};
                    frameRemaining = 5;
                    score++;



            }
        }

        if (frameRemaining > 0) {
            frameRemaining--;
            if (frameRemaining == 0) {
                rectanglecolor = (Color){255, 0,0 ,255};
            }
        }

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);

        DrawText(TextFormat("%d", score), SCREEN_WIDTH/2, 75, 24, BLACK);



        DrawRectangleRec(rec, rectanglecolor);

        DrawText("CLICK", SCREEN_WIDTH/2-MeasureText("CLICK", 32)/2, SCREEN_HEIGHT/2-32/2, 32, BLACK);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}
