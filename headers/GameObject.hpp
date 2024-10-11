#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"

class GameObject
{
    protected:
        int height=0;
        int width=0;
        int scale=0;


        SDL_Texture* objectTexture;
        SDL_Rect srcRect, destRect;
    
    public:
        int xpos;
        int ypos;
        
        GameObject();
        GameObject(const char* texturesheet,int x,int y,int IMGHeight,int IMWidth,int scale);
       ~GameObject();

        void Update();
        void Render();

};

#endif