// circleprojectile.hpp
#ifndef Disk_hpp
#define Disk_hpp

#include "Projectile.hpp"

class CircleProjectile : public Projectile {
private:
    float radius; 

public:
    CircleProjectile(float startX, float startY, float spd, int dmg, float rad, SDL_Texture* tex)
        : Projectile(startX, startY, spd, dmg, tex), radius(rad) {}

    void updatePosition(float deltaTime) override {
        rect.x = static_cast<int>(x);
        rect.y = static_cast<int>(y);
    }

    void render(SDL_Renderer* renderer) override {
        Projectile::render(renderer); 
    }

    float getRadius() const { return radius; } 
};

#endif // DISK_HPP
