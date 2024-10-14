#ifndef GUN_HPP
#define GUN_HPP

#include <vector>
#include "Projectile.hpp"

class Gun {
public:
    void CreateProjectile(const char* texturesheet, float x, float y, int IMHeight, int IMWidth, int scale, int speed, int direction);
    void UpdateProjectiles();
    void RenderProjectiles();

private:
    std::vector<Projectile> projectiles;  // Store all active projectiles
};

#endif