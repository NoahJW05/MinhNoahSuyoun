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

//calculate the differences in x and y pos
deltaX = player->fxpos-enemy->fxpos;
deltaY = player->fypos-enemy->fypos;


//distance formula
distance = sqrt(deltaX * deltaX + deltaY * deltaY);

attackDistance=ARadius+DRadius;

//collision occurs only when distance is less than attack distance 
if(distance<attackDistance)
{
    return true;
}else if(distance>attackDistance){ //if distance is greater than attack distance, collision not occur
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