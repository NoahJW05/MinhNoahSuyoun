#ifndef DISK_HPP
#define DISK_HPP

#include "GameObject.hpp"
#include "Game.hpp"
#include "Projectile.hpp"
#include <vector>

class Disk{
    private:
        int damage;

        std::vector<Projectile*> projectiles;  // List of active projectiles
    public:
};
#endif