#include "KeyboardInput.hpp"

KeyboardInput::KeyboardInput()
{
    inGame=0;
    inMenu=1;
    inHelpMenu=0;
    inSettings=0;
    count=0;
}

void KeyboardInput::KeyInputDetedctor(Player* player)
{
    count++;
    
    //Game cotrols for player only works if menu isnt open
    if(inGame==true){
        
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
        if(count % 10 ==0){
        if(state[SDL_SCANCODE_ESCAPE]){
            inGame=0;
            inMenu=1;
        }
        count=0;
        }
    }else if(inGame==false){
        if(count % 10 ==0){
            //control menu
            if(inMenu==true){
                if(state[SDL_SCANCODE_ESCAPE]){
                    inMenu = 0;
                    inGame = 1;
                }
            }
            //checks if in settings menu if not changes to help menu
                if(inSettings==false){
                    if(state[SDL_SCANCODE_Y])
                    {
                        inMenu=0;
                        inHelpMenu=1;
                    }
                }
            //if in help menu uses escape to ge back to main menu
                if(inHelpMenu==true){
                    if(state[SDL_SCANCODE_ESCAPE]){
                        inHelpMenu=0;
                        inMenu=1;
                    }
                }

            //checks if in help menu if not changes to settings menu
                if(inHelpMenu==false){
                    if(state[SDL_SCANCODE_T])
                    {
                        inMenu = 0;
                        inSettings=1;
                    }
                }
            //if in settings menu uses escape to ge back to main menu
                if(inSettings==true){
                    if(state[SDL_SCANCODE_ESCAPE]){
                        inMenu= 1;
                        inSettings=0;
                    }
                }
        count=0;
    }
        
    }
   
    



}
    

