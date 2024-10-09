#ifndef GUN_HPP
#define GUN_HPP

#include "Projectile.hpp"
#include <vector>

class Gun {
public:
    Gun(int bulletSpeed, int damage);
    void Fire(int x, int y);  // Fire a projectile from a specific position
    void Update();            // Update all projectiles
    void Render();            // Render all projectiles

private:
    std::vector<Projectile*> projectiles;
    int reloadTime;
    int damage;
};