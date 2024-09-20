#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

class Game {
 private:
 int cnt=0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

 public:
    Game();
    ~Game();
    void initilize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;};
};

#endif /*Game_hpp*/