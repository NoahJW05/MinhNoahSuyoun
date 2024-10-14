#ifndef COLLISON_HPP
#define COLLISON_HPP

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Disk.hpp"
#include "Sword.hpp"


class Collison
{
private:

public:

Collison();
//how the function works
//beenHit(what is attacking,what is been hit,attacker hit box radius,enemy/victim hitbox radius);

bool beenHit(Enemy* enemy,Player* player,float ARadius,float DRadius);
bool enemyHitByDisk(Enemy* enemy,Disk* disk,float ARadius,float DRadius);
void handlePlayerCollision(Enemy* enemy, Player* player, float ARadius);
};

#endif //COLLISON_HPP