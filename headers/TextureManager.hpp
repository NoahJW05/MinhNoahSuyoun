#ifndef TextureManager_hpp
#define TextureManager_hpp

#include "Game.hpp"

class TextureManager{
    private:

    public:
        static SDL_Texture* LoadTexture(const char* fileName);
        static void Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest);
};

#endif