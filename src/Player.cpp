#include "Player.hpp"
#include <string>

Player::Player(const char *texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, int Health, int Damage, int velocity) : GameObject(texturesheet, x, y, IMHeight, IMWidth, scale), health(Health), damage(Damage), velocity(velocity) { }

void Player::MovePlayer(int angle)
{
    if (angle == 90) {
        ypos -= velocity; 
        
    }
    if (angle == 270) {
        ypos += velocity; 

    }
    if (angle == 0) {
        xpos += velocity; 
        
    }
    if (angle == 180) {
        xpos -= velocity; 
       
    }
}

void Player::Update()
{
    GameObject::Update();
}
 
void Player::Render()
{
    GameObject::Render();
}