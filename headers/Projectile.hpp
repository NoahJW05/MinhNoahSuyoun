#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP


#include "Game.hpp"
#include "GameObject.hpp"


class Projectile:public GameObject{
    protected:
        int speed;
        int direction;
        int velocity;
        bool active;
    public:
    Projectile (const char* texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, int speed, int direction);
    ~Projectile();
    void Render();
    void Update();
    void MoveProjectile(int direction);
    bool isActive() const;
};
#endif 