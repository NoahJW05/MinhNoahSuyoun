#ifndef Map_hpp
#define Map_hpp

#include "Game.hpp"

class Map {
 private:
 SDL_Rect src,dest;
 //all Grass textures
    //all edge textures
        SDL_Texture* GrassRE;
        SDL_Texture* GrassLE;
        SDL_Texture* GrassBE;
        SDL_Texture* GrassTE;
    //all Corner Texters 
        SDL_Texture* GrassTRC;
        SDL_Texture* GrassTLC;
        SDL_Texture* GrassBRC;
        SDL_Texture* GrassBLC;
    //Center texture
        SDL_Texture* GrassC;

int map[30][20];

public:
 Map();
 ~Map();

 void LoadMap(int arr[20][30]);
 void DrawMap();
};

#endif