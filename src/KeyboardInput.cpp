#include "KeyboardInput.hpp"

KeyboardInput::KeyboardInput()
{
    inMenu=1;
    inHelpMenu=0;
    inSettings=0;
}

void KeyboardInput::KeyInputDetedctor(Player* player)
{
    //Game cotrols for player only works if menu isnt open
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if(inMenu==false){
    if(state[SDL_SCANCODE_W])
    {
        player->MovePlayer("up");
    }
    if(state[SDL_SCANCODE_S])
    {
        player->MovePlayer("down");
    }
    if(state[SDL_SCANCODE_A])
    {
        player->MovePlayer("left");
    }
    if(state[SDL_SCANCODE_D])
    {
        player->MovePlayer("right");
    }
    }

    //menu controls
    
    if(state[SDL_SCANCODE_ESCAPE]){
        inMenu = false;
        }
    if(state[SDL_SCANCODE_GRAVE]){
        inMenu = true;
        }
    }

