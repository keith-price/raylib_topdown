#include "raylib.h"
#include "raymath.h"


// TODO: create separate script for player (player.cpp and player.h)
// TODO: make player rotate towards mouse cursor
// TODO: replace mouse cursor wirth crosshair and capture mouse
// TODO: lerp and slerp for movement and rotation (currently accel abd decel are instant)

int main(void)
{
    const int windowWidth{1920};
    const int windowHeight{1080};
    
    InitWindow(windowWidth, windowHeight, "Top Down");

    // create player struct
    struct Player
    {
        Texture2D texture;
        Vector2 pos;
        Vector2 movement;
        float speed;
    } Player;
    
    
    // load player textures
    Player.texture = LoadTexture("assets/images/survivor1_machine.png");

    // set initial position for player to be drawn
    Player.pos = {200, 200};
    
    // set movement speed
    Player.speed = 550.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // get delta time
        float dT = GetFrameTime();
        
        BeginDrawing();
        
        ClearBackground(DARKGRAY);
        
        // draw player
        DrawTexture(Player.texture, Player.pos.x, Player.pos.y, WHITE);
        
        // movement vector is here so it can be normalized, cancelling out faster speed on the diagonal
        Player.movement = {0.f, 0.f};
        
        if (IsKeyDown(KEY_D))
        {
            Player.movement.x += Player.speed * dT;
        }
        if (IsKeyDown(KEY_A))
        {
            Player.movement.x -= Player.speed * dT;
        }
        if (IsKeyDown(KEY_W))
        {
            Player.movement.y -= Player.speed * dT;
        }
        if (IsKeyDown(KEY_S))
        {
            Player.movement.y += Player.speed * dT;
        }

        // check if both x and y are being set at same time (diagonal movement) -- if so normalize it
        if (Vector2Length(Player.movement) > 0)
        {
            Player.movement = Vector2Normalize(Player.movement);
        }
        
        // move the player with normalized vector
        Player.pos.x += Player.speed * Player.movement.x * dT;
        Player.pos.y += Player.speed * Player.movement.y * dT;
        
        EndDrawing();
    }
    
    UnloadTexture(Player.texture);
    
    CloseWindow();
    
    return 0;
}

