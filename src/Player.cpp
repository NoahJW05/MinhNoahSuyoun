#include "Player.hpp"
#include <string>

Player::Player(const char* texturesheet, int IMHeight, int IMWidth, float fx, float fy,int scale, int Health, int Damage, int velocity) : GameObject(texturesheet, IMHeight, IMWidth, fx, fy,scale), health(Health), damage(Damage), velocity(velocity) { }

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