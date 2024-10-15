#include "Sword.hpp"
#include <cmath>

Sword::Sword(const char* texturesheet, int IMHeight, int IMWidth, Player* player,int scale,int damage, int angle)
        : GameObject(texturesheet, IMHeight, IMWidth, player->fxpos, player->fypos, scale), // Initialize with player's position
          player(player), damage(damage), angle(angle){ }

    // Updates the sword position based on the player position
void Sword:: Update(){        
        double radians = angle * M_PI / 180.0; 
        // Update the sword's position based on player's position and angle
        fxpos = player->fxpos * cos(radians)+90; //x position
        fypos = player->fypos  * sin(radians)+20; //y position
        GameObject::fUpdate();
}

void Sword:: Render(){
        GameObject::Render();
}