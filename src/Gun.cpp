#include "Gun.hpp"
#include "Projectile.hpp"
#include <iostream>

Gun::Gun(int cooldown) : reloadTime(cooldown), timeSinceLastShot(0), damage(damage){}
Gun::~Gun(){
        for (auto projectile : projectiles) {
        delete projectile;
    }
    projectiles.clear();
}
void Gun::Shoot(const char* projectileTexture, int x, int y, int IMHeight, int IMWidth, int scale, int damage,int speed, int direction) {
    if (timeSinceLastShot >= reloadTime) {
        Projectile* newProjectile = new Projectile(projectileTexture, x, y, IMHeight, IMWidth, scale, speed, direction);
        projectiles.push_back(newProjectile);
        timeSinceLastShot = 0;  // Reset the timer
    }
}