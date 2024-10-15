#include "Enemy.hpp"
#include <cmath> 
#include <math.h>

Enemy::Enemy(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale, Player* player) 
    : GameObject(texturesheet, IMHeight, IMWidth, fx, fy,scale) 
{
    this->player = player;
    isAlive = true;
    speed = 0.5;
    angle=90*(M_PI/180);
}

void Enemy::SpawnEnemyRandomly()
{
    int minX=0;
    int minY=0;
    int maxX=960;
    int maxY;


    fxpos = minX + std::rand() % (maxX - minX + 1);
    fypos = minY + std::rand() % (maxY - minX + 1); 

    destRect.x = fxpos;
    destRect.y = fypos;
}

void Enemy::FollowPlayer(Player* player)
{
float deltaX = player->fxpos - this->fxpos;
float deltaY = player->fypos - this->fypos;

// Get the angle to the player in radians
angle = atan2(deltaY, deltaX);

// Normalize the angle between -π and π
while (angle < -M_PI) {
    angle += 2 * M_PI;
}
while (angle > M_PI) {
    angle -= 2 * M_PI;
}

// Move the enemy towards the player using the normalized angle
this->fxpos += speed * cos(angle);
this->fypos += speed * sin(angle);
}

void Enemy::Update()
{
    FollowPlayer(player);
    GameObject::fUpdate();
}

void Enemy::Render()
{
    GameObject::Render(); 
}
