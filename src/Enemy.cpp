#include "Enemy.hpp"
#include <cmath> 
#include <math.h>

Enemy::Enemy(const char *texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, Player* player) 
    : GameObject(texturesheet, x, y, IMHeight, IMWidth, scale) 
{
    this->player = player;
    isAlive = true;
    speed = 1;
}

void Enemy::SpawnEnemyRandomly()
{
    xpos = 960 / 2; 
    ypos = 640 / 2; 

    destRect.x = xpos;
    destRect.y = ypos;
}

void Enemy::FollowPlayer(Player* player)
{

    int deltaX = (player->xpos - this->xpos);
    int deltaY = (player->ypos - this->ypos);

    float angle = (atan(deltaX/deltaY))*M_PI/180;
    xpos =+ speed * cos(angle);
    ypos =+ speed * sin(angle);



}

void Enemy::Update()
{
    FollowPlayer(player);
    GameObject::Update();
}

void Enemy::Render()
{
    GameObject::Render(); 
}
