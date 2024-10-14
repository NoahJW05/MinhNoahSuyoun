#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include "GameObject.hpp"
#include <string>

class Player : public GameObject
{
protected:
    int health;
    int damage;
    int velocity;
    int speed;
    
    int angle;

public:
    void reduceHealth(int amount);
    int getHealth() const{return health; }
    bool inAlive() const{return health > 0;}
    Player(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale, int health, int damage, int velocity);
    void MovePlayer(int angle);
    void Update();
    void Render();
    int getX() const { return xpos; }
    int getY() const { return ypos; }
};

#endif