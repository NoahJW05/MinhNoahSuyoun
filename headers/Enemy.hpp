#ifndef Enemy_hpp
#define Enemy_hpp

#include "Player.hpp"
#include "GameObject.hpp"
#include <cmath> 
#include <cstdlib> 
#include <ctime>   
#include <math.h>

class Enemy : public GameObject {
 protected:
    int EHealth;
    int EDamage;
    int Evelocity;
    bool isAlive;
    Player* player;
    int speed;
 public:
    Enemy(const char *texturesheet, int x, int y, int IMHeight, int IMWidth, int scale,Player* player);
    void SpawnEnemyRandomly();

    void FollowPlayer(Player* player);

    void Update();
    void Render();
};


#endif