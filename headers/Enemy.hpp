#ifndef Enemy_hpp
#define Enemy_hpp

#include "Player.hpp"
#include "GameObject.hpp"
#include <cmath> 
#include <cstdlib> 
#include <ctime>   
#include <math.h>


class Enemy : public GameObject {
private:
    bool isAlive;        // Enemy's alive status
    float speed;        // Speed of the enemy
    float angle;        // Current angle towards the player
    Player* player;     // Pointer to the player object

public:
    Enemy(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy, int scale, Player* player);
    
    void SpawnEnemyRandomly();
    void FollowPlayer(Player* player);
    void Update();
    void Render();
};

#endif // ENEMY_HPP

