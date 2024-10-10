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
    std::string direction;

public:
    Player(const char *texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, int health, int damage, int velocity);

    void MovePlayer(std::string direction);
    void Update();
    void Render();

    int getX() const { return xpos; }
    int getY() const { return ypos; }
};

#endif