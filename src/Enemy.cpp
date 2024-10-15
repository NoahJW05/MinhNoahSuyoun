#include "Enemy.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>

Enemy::Enemy(const char* texturesheet, int IMHeight, int IMWidth, float fx,
             float fy, int scale, Player* player)
    : GameObject(texturesheet, IMHeight, IMWidth, fx, fy, scale) {
  this->player = player;
  isAlive = true;
  speed = 0.5f;              
  angle = 90 * (M_PI / 180); // make into radians
}

void Enemy::SpawnEnemyRandomly() {
  int minX = 0;
  int minY = 0;
  int maxX = 960;
  int maxY = 540;  

  fxpos = minX + std::rand() % (maxX - minX + 1);
  fypos = minY + std::rand() % (maxY - minY + 1);

  destRect.x = static_cast<int>(fxpos);
  destRect.y = static_cast<int>(fypos);
}

void Enemy::FollowPlayer(Player* player) {
    float deltaX = player->fxpos - this->fxpos;
    float deltaY = player->fypos - this->fypos;

    // Get angle to player
    angle = atan2(deltaY, deltaX);  

    // Move enemy towards player
    this->fxpos += speed * cos(angle);  
    this->fypos += speed * sin(angle);
}

void Enemy::Update() {
  if (player) {
    FollowPlayer(player);  
  }
  GameObject::fUpdate();  
}

void Enemy::Render() {
  GameObject::Render(); 
}