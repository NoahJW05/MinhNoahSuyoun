#include "Player.hpp"
#include <string>

Player::Player(const char *texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, int Health, int Damage, int velocity) : GameObject(texturesheet, x, y, IMHeight, IMWidth, scale), health(Health), damage(Damage), velocity(velocity) { }

void Player::MovePlayer(std::string direction)
{
    this->direction = direction;
    if (direction == "up")
    {
        ypos--;
    }
    if (direction == "down")
    {
        ypos++;
    }
    if (direction == "right")
    {
        xpos++;
    }
    if (direction == "left")
    {
        xpos--;
    }
}

void Player::Update()
{
    GameObject::Update();
    // Player::MovePlayer();
}

void Player::Render()
{
    GameObject::Render();
}