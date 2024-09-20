#include "Game.hpp"
#include <SDL2/SDL.h>

Game *game = nullptr;

int main(int argc, char **argv) {
game = new Game();

game->initilize("GameTest",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);

while(game->running())
{
  game->handleEvents();
  game->update();
  game->render();
}
  game->clean();

  return 0;
}