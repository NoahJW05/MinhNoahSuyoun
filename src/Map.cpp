#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[20][30]={
        {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
        {8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 7}
    };

Map::Map()
{
    //all edges
    GrassRE = TextureManager::LoadTexture("ProjectPNG/GrassRE.png");
    GrassLE = TextureManager::LoadTexture("ProjectPNG/GrassLE.png");
    GrassTE = TextureManager::LoadTexture("ProjectPNG/GrassTE.png");
    GrassBE = TextureManager::LoadTexture("ProjectPNG/GrassBE.png");
    //all corners
    GrassTRC = TextureManager::LoadTexture("ProjectPNG/GrassTRC.png");
    GrassTLC = TextureManager::LoadTexture("ProjectPNG/GrassTLC.png");
    GrassBRC = TextureManager::LoadTexture("ProjectPNG/GrassBRC.png");
    GrassBLC = TextureManager::LoadTexture("ProjectPNG/GrassBLC.png");
    //Center
    GrassC = TextureManager::LoadTexture("ProjectPNG/GrassC.png");

    LoadMap(lvl1);
//sets the location for the map to start generating from.
    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;
    dest.x = 0;
    dest.y = 0;

}

void Map::LoadMap(int arr[20][30])
{
    for(int row = 0 ; row < 20 ;row++){
        for(int column = 0 ;column <30;column++){
            map[row][column]=lvl1[row][column];
        }
    }
}

void Map::DrawMap()
{
    int type = 0;
    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 30; column++) {
            type =  0;
            type=map[row][column];
            dest.x = column*32;
            dest.y = row*32;

            switch (type)
            {
            case 0:
                TextureManager::Draw(GrassC,src,dest);
             break;
            case 1:
                TextureManager::Draw(GrassTE, src, dest);
             break;
            case 2:
              TextureManager::Draw(GrassBE, src, dest);
              break;
            case 3:
              TextureManager::Draw(GrassRE, src, dest);
              break;
            case 4:
              TextureManager::Draw(GrassLE, src, dest);
              break;
            case 5:
              TextureManager::Draw(GrassTRC, src, dest);
              break;
            case 6:
              TextureManager::Draw(GrassTLC, src, dest);
              break;
            case 7:
              TextureManager::Draw(GrassBRC, src, dest);
              break;
            case 8:
              TextureManager::Draw(GrassBLC, src, dest);
              break;
            default:
                break;
            }
    }
  }
}