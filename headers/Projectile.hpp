#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "GameObject.hpp"
class Projectile:public GameObject{
    protected:
        int speed;
        int direction;
        bool isActive;
    private:
    
    void Projectile::Render();
    void Projectile::Update();
};
#endif 