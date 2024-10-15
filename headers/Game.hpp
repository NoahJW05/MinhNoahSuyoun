#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

class Game {
 private:
   
   int cnt=0;
   //determents if the game has run and if not stops it
    bool isRunning;
    SDL_Window *window;

   //timer to track elapsed time
    Uint32 timer; 
    Uint32 elapsedTime;
    int level1= 10;
    int level2=20;
    
    int currentWeapon; //disk=1, gun=2, sword=3

 public:
    Game();
    ~Game();
    void initilize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);



    void handleEvents();
    void update();
    void render();
    void clean();
    void selectWeapon(); 
    int getSelectedWeapon();
   
   static SDL_Renderer *renderer;

    bool running(){return isRunning;};

};

#endif /*Game_hpp*/