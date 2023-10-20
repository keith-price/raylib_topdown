#include "raylib.h"
#include "player.h"

// TODO: make player rotate towards mouse cursor
// TODO: offset player position so that rotation is around center of texture and not at {0, 0} origin
// TODO: lerp and slerp for movement and rotation (currently accel abd decel are instant)

int main(void)
{
    const int windowWidth{1920};
    const int windowHeight{1080};

    InitWindow(windowWidth, windowHeight, "Top Down");

    Player player;
    InitPlayer(player);

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

        UpdatePlayer(player, dT);

        // get mouse position to draw crosshair at correct location
        Vector2 mousePos = GetMousePosition();

        // draw player -- rotation not working
        DrawPlayer(player, RotateToMouse(player, mousePos));

        // draw crossshair
        DrawTextureEx(crosshair, mousePos, 0, 1, WHITE);

        EndDrawing();
    }

    UnloadTexture(player.texture);
    UnloadTexture(crosshair);

    CloseWindow();
}
