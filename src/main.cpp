#include "Game.hpp"
#include <SDL2/SDL.h>

Game *game = nullptr;

int main(int argc, char **argv) {

//inilized varibles used to control the max frame rate 
const int FPS = 120;
const int frameDelay = 1000/FPS;
Uint32 frameStart;
int frameTime;




//create game window and determined size
game = new Game();
//960,640
game->initilize("GameTest",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,640,0);

while(game->running())
{
//determinds current time
  frameStart = SDL_GetTicks();

//main game loop logic
  game->handleEvents();
  game->update();
  game->render();

//determinds time after running through the loop
  frameTime = SDL_GetTicks()-frameStart;

//determinds if the frames need to be delayed.
  if(frameDelay > frameTime)
  {
  SDL_Delay(frameDelay-frameTime);
  }
}
  game->clean();

  return 0;
}