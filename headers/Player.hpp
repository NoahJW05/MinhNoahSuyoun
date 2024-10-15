#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include "GameObject.hpp"
#include <string>

class Player : public GameObject
{
protected:

    int velocity;
    int speed;
    int coolDown;
    
    int angle;
    Uint32 lastTimeSinceAttack;

public:
    Player(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale, int health, int damage, int velocity, int coolDown);
    int health=100;
    int damage=20;
    void MovePlayer(int angle);
    void Update();
    void Render();
    int getX() const { return xpos; }
    int getY() const { return ypos; }
    void reduceHealth(int damage);
    int getHealth();
};

#endif