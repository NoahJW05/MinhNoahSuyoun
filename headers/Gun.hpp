#ifndef GUN_HPP
#define GUN_HPP

#include "Projectile.hpp"
class Gun:public Projectile {
    private:
        float directionX;
        float directionY;
        float fireRate;
        float bulletSpeed;
        int rechargeTime;// will get shorter as weapon levels up
         
    public:
    Gun(float startX, float startY, float dirX, float dirY, float spd, int dmg, SDL_Texture* tex,float fireRate, float bulletSpeed, int rechargeTime)

    void updatePosition(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    
    //firing the bullet
    bool shoot(float currentTime)
};
#endif