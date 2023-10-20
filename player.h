#include "raylib.h"

class Player
{
public:
    Player();
    // void InitPlayer(Player &player);
    void UpdatePlayer(Player &player, float dT);
    void DrawPlayer(Player &player, float rotation);

    float RotateToMouse(Player &player, Vector2 mousePos);

    // add to make movement more natural
    void AddFriction(Player &player);
    void Decelerate(Player &player);

private:
    Texture2D texture;
    Vector2 pos;
    Vector2 movement;
    float maxSpeed;
    float friction;
    float acceleration;
};