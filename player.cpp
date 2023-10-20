#include "Player.h"
#include "raymath.h"

// add in friction and acceleration for player plus maxSpeed so player movement is more natural

Player::Player()
{
    // load player textures
    texture = LoadTexture("assets/images/survivor1_machine.png");

    // set start position for player to be drawn
    pos = {200.f, 200.f};

    // set movement maxSpeedpeed
    maxSpeed = 550.f;

    friction = 0.01f;

    acceleration = 0.01f;
}

void Player::UpdatePlayer(Player &player, float dT)
{
    // movement vector is here so it can be normalized, cancelling out faster maxSpeedon the diagonal
    player.movement = {0.f, 0.f};

    if (IsKeyDown(KEY_D))
        player.movement.x += 1.f;
    if (IsKeyDown(KEY_A))
        player.movement.x -= 1.f;
    if (IsKeyDown(KEY_W))
        player.movement.y -= 1.f;
    if (IsKeyDown(KEY_S))
        player.movement.y += 1.f;

    // check if both x and y are being set at same time (diagonal movement) -- if so normalize it
    if (Vector2Length(player.movement) > 0)
    {
        player.movement = Vector2Normalize(player.movement);
    }

    // move the player with normalized vector
    player.pos.x += player.maxSpeed * player.movement.x * dT;
    player.pos.y += player.maxSpeed * player.movement.y * dT;
}

void Player::DrawPlayer(Player &player, float rotation)
{
    // load player textures
    player.texture = LoadTexture("assets/images/survivor1_machine.png");

    // Calculate the offset for the player's texture
    Vector2 offset = (Vector2){player.texture.width * 0.5f, player.texture.height * 0.5f};

    // Draw the player with the correct rotation and offset
    DrawTexturePro(player.texture, (Rectangle){0, 0, (float)player.texture.width, (float)player.texture.height},
                   (Rectangle){player.pos.x + offset.x, player.pos.y + offset.y, (float)player.texture.width, (float)player.texture.height},
                   offset, rotation, WHITE);
}

float Player::RotateToMouse(Player &player, Vector2 mousePos)
{
    // deal with player rotation towards mouse
    Vector2 directionToMouse = Vector2Subtract(mousePos, player.pos);

    // atan2 gives angle in radian - need to convert to degrees
    float angleToMouseRadians = atan2(directionToMouse.y, directionToMouse.x);

    // convert radians to degrees
    float angleToMouseDegrees = angleToMouseRadians * RAD2DEG;

    return angleToMouseDegrees;
}


