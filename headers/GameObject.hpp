#ifndef GameObject_hpp
#define GameObject_hpp

#include "Game.hpp"

class GameObject
{
    private:
        int xpos;
        int ypos;
        int height;
        int width;
        int scale=0;


        SDL_Texture* objectTexture;
        SDL_Rect srcRect, destRect;
    
    public:

        GameObject(const char* texturesheet,int x,int y,int IMGHeight,int IMWidth,int scale);
        ~GameObject();

        void Update();
        void Render();

};

#endif