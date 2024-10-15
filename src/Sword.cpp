#include "Sword.hpp"

Sword::Sword(const char* texturesheet, int IMHeight, int IMWidth, Player* player,int scale,int damage, int angle)
        : GameObject(texturesheet, IMHeight, IMWidth, player->fxpos, player->fypos, scale),
          player(player), damage(damage), angle(angle){ }

    
void Sword:: Update(){        
        double radians = angle * M_PI / 180.0; 
        // update sword pos based on player pos and angle
        fxpos = player->fxpos +40; 
        fypos = player->fypos +15;
        GameObject::fUpdate();
}

void Sword:: Render(){
        GameObject::Render();
}

