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
    int angle;

public:
    Player(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale, int health, int damage, int velocity, int coolDown);
    int health;
    int damage;
    int coolDown;
    void MovePlayer(int angle);
    void Update();
    int getHealth();
    void reduceHealth(int damage);
    void Render();
    int getX() const { return xpos; }
    int getY() const { return ypos; }
};

#endif