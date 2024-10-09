#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "GameObject.hpp"
class Projectile:public GameObject{
    private:
        int speed;
        int direction;
        bool active;
    private:
    Projectile (const char* texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, int Speed, int Direction);

    void Render();
    void Update();
    bool isActive() const;
};
#endif 