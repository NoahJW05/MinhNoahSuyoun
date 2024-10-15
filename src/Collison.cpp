#include "Collison.hpp"

Collison::Collison()
{
}

//enemy to player collison
bool Collison::beenHit(Enemy* enemy,Player* player,float ARadius,float DRadius)
{
float distance;
float attackDistance;
float deltaX;
float deltaY;

deltaX = player->fxpos-enemy->fxpos;
deltaY = player->fypos-enemy->fypos;

distance = sqrt(deltaX * deltaX + deltaY * deltaY);
attackDistance=ARadius+DRadius;

if(distance<attackDistance)
{
    return true;
}else if(distance>attackDistance){
    return false;
}

}

// weapon to enemy detection for disk
bool Collison::enemyHitByDisk(Enemy* enemy,Disk* disk,float ARadius,float DRadius)
{
  float distance;
  float attackDistance;
  float deltaX;
  float deltaY;

  deltaX = enemy->fxpos - disk->fxpos;
  deltaY = enemy->fypos - disk->fypos;

  distance = sqrt(deltaX * deltaX + deltaY * deltaY);
  attackDistance = ARadius + DRadius;

  if (distance < attackDistance){
    return true;
  } else if (distance > attackDistance) {
    return false;
  }
}

// weapon to enemy detection for sword
bool Collison::enemyHitBySword(Enemy* enemy,Sword* sword,float ARadius,float DRadius)
{
  float distance;
  float attackDistance;
  float deltaX;
  float deltaY;

  deltaX = enemy->fxpos - sword->fxpos;
  deltaY = enemy->fypos - sword->fypos;

  distance = sqrt(deltaX * deltaX + deltaY * deltaY);
  attackDistance = ARadius + DRadius;

  if (distance < attackDistance){
    return true;
  } else if (distance > attackDistance) {
    return false;
  }
}

bool Collison::enemyHitByGun(Enemy* enemy,Gun* gun,float ARadius,float DRadius)
{
      float distance;
    float attackDistance;
    float deltaX;
    float deltaY;

    // Loop through each projectile in the gun
    for (auto projectile : gun->getProjectiles()) { // Ensure you have a method to get the projectiles
        deltaX = enemy->fxpos - projectile->getX();
        deltaY = enemy->fypos - projectile->getY();

        distance = sqrt(deltaX * deltaX + deltaY * deltaY);
        attackDistance = ARadius + DRadius;

        // Check for collision
        if (distance < attackDistance) {
            return true; // Collision detected
        }
    }
    return false; // No collision detected
}