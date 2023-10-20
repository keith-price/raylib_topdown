#include "player.h"

#include "raymath.h"

void InitPlayer(Player &player)
{
    // load player textures
    player.texture = LoadTexture("assets/images/survivor1_machine.png");

    // set start position for player to be drawn
    player.pos = {200.f, 200.f};

    // set movement speed
    player.speed = 550.f;
}

void UpdatePlayer(Player &player, float dT)
{
    // movement vector is here so it can be normalized, cancelling out faster speed on the diagonal
    player.movement = {0.f, 0.f};

    if (IsKeyDown(KEY_D))
    {
        player.movement.x += player.speed * dT;
    }
    if (IsKeyDown(KEY_A))
    {
        player.movement.x -= player.speed * dT;
    }
    if (IsKeyDown(KEY_W))
    {
        player.movement.y -= player.speed * dT;
    }
    if (IsKeyDown(KEY_S))
    {
        player.movement.y += player.speed * dT;
    }

    // check if both x and y are being set at same time (diagonal movement) -- if so normalize it
    if (Vector2Length(player.movement) > 0)
    {
        player.movement = Vector2Normalize(player.movement);
    }

    // move the player with normalized vector
    player.pos.x += player.speed * player.movement.x * dT;
    player.pos.y += player.speed * player.movement.y * dT;
}
void DrawPlayer(Player &player)
{
    // load player textures
    player.texture = LoadTexture("assets/images/survivor1_machine.png");

    // draw player
    DrawTextureEx(player.texture, player.pos, 0, 1.5, WHITE);
}