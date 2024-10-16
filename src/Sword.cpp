#include "Sword.hpp"
#include <cmath>

Sword::Sword(const char* texturesheet, int IMHeight, int IMWidth, Player* player,int scale,int damage, float distance, float angle)
        : GameObject(texturesheet, IMHeight, IMWidth, player->fxpos, player->fypos, scale), // Initialize with player's position
          player(player), damage(damage), distance(distance), angle(angle) { }

    // Updates the sword position based on the player position
void Sword:: Update(){        
        double radians = angle * M_PI / 180.0; 
        // Update the sword's position based on player's position and angle
        fxpos = player->fxpos + distance * cos(radians)+40; //x position
        fypos = player->fypos + distance * sin(radians)+15; //y position
        GameObject::fUpdate();
}

void Sword:: Render(){
        GameObject::Render();
}