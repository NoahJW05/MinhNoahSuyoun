#include "Player.hpp"
#include <string>
#include "SDL2/SDL.h"

Player::Player(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale, int Health, int Damage, int velocity,int coolDown) : GameObject(texturesheet, IMHeight, IMWidth, fx, fy,scale), health(Health), damage(Damage), velocity(velocity), coolDown(coolDown) { }

void Player::MovePlayer(int angle)
{
    if (angle == 90) {
        fypos -= velocity; 
        
    }
    if (angle == 270) {
        fypos += velocity; 

    }
    if (angle == 0) {
        fxpos += velocity; 
        
    }
    if (angle == 180) {
        fxpos -= velocity; 
       
    }
}

void Player::Update()
{
    GameObject::fUpdate();
}
 
void Player::Render()
{
    GameObject::Render();
}
void Player::reduceHealth(int damage) {
    Uint32 lastTimeSinceAttack;
    Uint32 currentTime = SDL_GetTicks()/1000;
    if (currentTime-lastTimeSinceAttack>=coolDown){   
    health -= damage;
    if (health < 0) health = 0; 
    lastTimeSinceAttack = currentTime;
    }
}
int Player::getHealth(){    
    return health;
}