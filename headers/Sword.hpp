#ifndef SWORD_HPP
#define SWORD_HPP
#include "GameObject.hpp"
#include "Player.hpp"
class Sword:public GameObject{

    private:
    int damage;
    Player* player;
    int angle;

public:
    Sword(const char* texturesheet, int IMHeight, int IMWidth, Player* player,int scale, int damage, int angle);
    
    void Update();

    void Render();


};
#endif