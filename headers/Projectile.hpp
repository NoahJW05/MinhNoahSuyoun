#ifndef Projectile_hpp
#define Projectile_hpp

#include <string>
#include <SDL2/SDL.h>

class Projectile {
protected:
    float x, y;       
    float speed;      
    int damage;       
    SDL_Texture* texture; 
    SDL_Rect rect;    

public:
    Projectile(float startX, float startY, float spd, int dmg, SDL_Texture* tex);

    virtual void updatePosition(float deltaTime) = 0; 

    virtual void render(SDL_Renderer* renderer);

    virtual ~Projectile();
};

#endif // Projectile_HPP
