#ifndef SWORD_HPP
#define SWORD_HPP
#include "GameObject.hpp"
#include "Player.hpp"
class Sword:public GameObject{

    private:
    int damage;
    Player* player; 
    float distance; // Distance to maintain from the player
    float angle;

public:
    Sword(const char* texturesheet, int IMHeight, int IMWidth, Player* player,int scale, int damage, float distance, float angle);
    
    void Update();

    void Render();

};
#endif