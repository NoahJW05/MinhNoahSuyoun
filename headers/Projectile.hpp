#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP


#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"


class Projectile:public GameObject{
    protected:
        int speed;
        int angle;
        int velocity;
        bool active;
        Player* player; //pointer to player 
    public:
    Projectile(const char* texturesheet, Player* player, int IMHeight, int IMWidth, int scale, int speed, int angle);
    ~Projectile();

    float getX() const { return fxpos; }  // Getter for x position
    float getY() const { return fypos; }  // Getter for y position

    void Render();
    void Update();
    void MoveProjectile(int angle);
    bool isActive() const;
};
#endif 