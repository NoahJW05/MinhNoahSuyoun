#ifndef GUN_HPP
#define GUN_HPP

#include "Projectile.hpp"
#include <vector>

class Gun {
public:
    Gun(Player* player, const char* projectileTexture, int projIMHeight, int projIMWidth, int projScale, int projSpeed, int reloadTime);
    ~Gun();

    void Shoot(int angle);  // Shoots a projectile at the given angle
    void Update();          // Updates all projectiles
    void Render();          // Renders all projectiles

private:
    Player* player;
    const char* projectileTexture;
    int projIMHeight;
    int projIMWidth;
    int projScale;
    int projSpeed;
    int reloadTime;         // Time between shots in milliseconds
    Uint32 lastShotTime;    // Time when the last shot was fired

    std::vector<Projectile*> projectiles; // List of active projectiles
};

#endif