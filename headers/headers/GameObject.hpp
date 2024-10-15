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

        float fxpos;
        float fypos;
        
        GameObject();
        GameObject(const char* texturesheet,int x,int y,int IMGHeight,int IMWidth,int scale);
        GameObject(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale);
       ~GameObject();

        void Update();
        void fUpdate();
        void Render();

};

#endif