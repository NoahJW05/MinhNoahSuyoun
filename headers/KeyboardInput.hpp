#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include "Game.hpp"
#include "Player.hpp"

class KeyboardInput
{
    protected:

    public:

        KeyboardInput();
        void KeyInputDetedctor(Player* player);

                   //determinds which menu games is in
        bool inMenu;
        bool inSettings;
        bool inHelpMenu;
};



#endif