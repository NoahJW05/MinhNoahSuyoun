#include "Enemy.hpp"
#include <cmath> 
#include <math.h>
#include <iostream>


Enemy::Enemy(const char* texturesheet, int IMHeight, int IMWidth, float fx,
             float fy, int scale, Player* player)
    : GameObject(texturesheet, IMHeight, IMWidth, fx, fy, scale) {
  this->player = player;
  isAlive = true;
  speed = 0.5f;  
  angle = 90 * (M_PI / 180); 
}

void Enemy::SpawnEnemyRandomly()
{
    int minX=0;
    int minY=0;
    int maxX=960;
    int maxY = 540;  // Adjust as necessary


    fxpos = minX + std::rand() % (maxX - minX + 1);
    fypos = minY + std::rand() % (maxY - minX + 1); 

  destRect.x = static_cast<int>(fxpos);
  destRect.y = static_cast<int>(fypos);
}

void Enemy::FollowPlayer(Player* player) {
  float deltaX = player->fxpos - this->fxpos;
  float deltaY = player->fypos - this->fypos;

  angle = atan2(deltaY, deltaX);  // Get angle to player

  this->fxpos += speed * cos(angle);  // Move enemy towards player
  this->fypos += speed * sin(angle);
}

void Enemy::Update() {
  if (player) {
    FollowPlayer(player);  // Follow player if player pointer is valid
  }
  GameObject::fUpdate();  // Update base class state
}

void Enemy::Render() {
  GameObject::Render();  // Render the enemy
}