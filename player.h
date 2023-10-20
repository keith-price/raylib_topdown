#include "raylib.h"

struct Player
{
    Texture2D texture;
    Vector2 pos;
    Vector2 movement;
    float speed;
};

void InitPlayer(Player& player);
void UpdatePlayer(Player& player, float dT);
void DrawPlayer(Player& player);
