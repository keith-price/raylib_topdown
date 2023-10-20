#include "raylib.h"
#include "Player.h"

int main(void)
{
    const int windowWidth{1920};
    const int windowHeight{1080};

    InitWindow(windowWidth, windowHeight, "Top Down");

    // create player instance
    Player player;

    // load crosshair texture and hide mouse cursor
    HideCursor();
    Texture2D crosshair = LoadTexture("assets/images/crosshair085.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // get delta time
        float dT = GetFrameTime();

        BeginDrawing();

        ClearBackground(DARKGRAY);

        player.UpdatePlayer(player, dT);

        // get mouse position to draw crosshair at correct location
        Vector2 mousePos = GetMousePosition();

        // draw player -- rotation not working
        player.DrawPlayer(player, player.RotateToMouse(player, mousePos));

        // draw crossshair
        DrawTextureEx(crosshair, mousePos, 0, 1, WHITE);

        EndDrawing();
    }
    // how to unload the player texture here
    // UnloadTexture(player.texture);
    UnloadTexture(crosshair);

    CloseWindow();
}
