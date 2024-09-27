#include "Projectile.hpp"
#include <string>
#include <SDL2/SDL.h>

Projectile::(float startX, float startY, float spd, int dmg, SDL_Texture* tex): x(startX), y(startY), speed(spd), damage(dmg), texture(tex) {
        rect.x = static_cast<int>(startX); //convert float into int
        rect.y = static_cast<int>(startY);
        rect.w = 20;  
        rect.h = 20; 
    }


Projectile:: render(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, texture, nullptr, &rect); 
    }

Projectile:: ~Projectile() {} // Virt

