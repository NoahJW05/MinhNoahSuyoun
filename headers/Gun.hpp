#ifndef GUN_HPP
#define GUN_HPP
#include "Projectile.hpp"
#include <vector>
class Gun {
    private:
        int reloadTime;            // Time between shots
         
        int damage;    // Timer to track when the gun can fire again
        std::vector<Projectile*> projectiles;  // List of active projectiles
    public:
        Gun(int cooldown);
        ~Gun();
    
        void Shoot(const char* projectileTexture, int x, int y, int IMHeight, int IMWidth, int scale, int damage ,int speed, int direction);
        void UpdateProjectiles();
};
#endif 