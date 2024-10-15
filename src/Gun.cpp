#include "Gun.hpp"
#include "SDL2/SDL.h"

Gun::Gun(Player* player, const char* projectileTexture, int projIMHeight, int projIMWidth, int projScale, int projSpeed, int reloadTime)
    : player(player), projectileTexture(projectileTexture), projIMHeight(projIMHeight), projIMWidth(projIMWidth),
      projScale(projScale), projSpeed(projSpeed), reloadTime(reloadTime) {
        lastShotTime =- reloadTime;
      }
//deconstructor
Gun::~Gun() {
    for (auto projectile : projectiles) {
        delete projectile;
    }
}

void Gun::Shoot(int angle) {
    // Check if enough time has passed since the last shot
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastShotTime >= reloadTime) {
        Projectile* newProjectile = new Projectile(projectileTexture, player, projIMHeight, projIMWidth, projScale, projSpeed, angle);
        //storing projectile object in vector
        projectiles.push_back(newProjectile);
        lastShotTime = currentTime;
    }
}

void Gun::Update() {
    for (auto it = projectiles.begin(); it != projectiles.end(); ) {
        (*it)->Update();
        if (!(*it)->isActive()) {
            delete *it;
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

void Gun::Render() {
    // Render all active projectiles
    for (auto projectile : projectiles) {
        projectile->Render();
    }
}