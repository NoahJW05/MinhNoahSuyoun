#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"

class GameObject
{
    protected:
        int xpos;
        int ypos;

        SDL_Texture* objectTexture;
        SDL_Rect srcRect, destRect;
    
    public:
        GameObject();
        GameObject(const char* texturesheet,int x,int y);
        ~GameObject();

        void Update();
        void Render();

};

#endif