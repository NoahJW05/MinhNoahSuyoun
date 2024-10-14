#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class KeyboardInput
{
    protected:
    const Uint8* state = SDL_GetKeyboardState(NULL);
    int count;
    public:
        KeyboardInput();
        void KeyInputDetedctor(Player* player, Enemy* enemy);
        

        bool inMenu;
        bool inGame;
        bool inSettings;
        bool inHelpMenu;
};



#endif