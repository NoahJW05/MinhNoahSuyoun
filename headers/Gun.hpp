#ifndef GUN_HPP
#define GUN_HPP

#include "Projectile.hpp"
#include <vector>

class Gun {
private:
    Player* player;
    const char* projectileTexture;
    int projIMHeight;
    int projIMWidth;
    int projScale;
    int projSpeed;
    int reloadTime;         
    Uint32 lastShotTime;    

    std::vector<Projectile*> projectiles; 
public:
    Gun(Player* player, const char* projectileTexture, int projIMHeight, int projIMWidth, int projScale, int projSpeed, int reloadTime);
    ~Gun();

    void Shoot(int angle); 
    void Update();          
    void Render();          
};

#endif