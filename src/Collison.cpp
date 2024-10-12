#include "Collison.hpp"

Collison::Collison()
{
}


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