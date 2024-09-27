#include "Gun.h"

Gun::Gun(float fireRate, float bulletSpeed, int rechargeTime): fireRate(fireRate), bulletSpeed(bulletSpeed), rechargeTime(rechargeTime){}


// Update the position of the projectile
void Gun::updatePosition(float deltaTime) {
    x += directionX * speed * deltaTime; 
    y += directionY * speed * deltaTime; 
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
}

// Render the projectile
void Gun::render(SDL_Renderer* renderer) {
    Projectile::render(renderer); // Call the base class render method
}
