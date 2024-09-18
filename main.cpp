#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>



int main(int argc, char **argv) {
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;

  SDL_Surface* image;
  image = IMG_Load("ProjectPNG/katanna.png");

 
  

  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  SDL_CreateWindowAndRenderer(800,600,0,&window,&renderer);
  SDL_Texture* katannaTex = SDL_CreateTextureFromSurface(renderer, image);
  //SDL_RenderSetScale(renderer,2,2);

  SDL_SetRenderDrawColor(renderer,0,0,0,255);
  SDL_RenderClear(renderer);

  

  SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
  SDL_RenderDrawPoint(renderer,800/2,600/2);

 SDL_RenderCopy(renderer,katannaTex,NULL,NULL);

  SDL_RenderPresent(renderer);
  SDL_Delay(10000);


SDL_FreeSurface(image);
SDL_DestroyTexture(katannaTex);
  return 0;
}