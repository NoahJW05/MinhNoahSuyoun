#include "Player.hpp"
#include <string>


Player::Player(const char* texturesheet, int x, int y, int IMHeight, int IMWidth,int scale,int Health,int Damage,int Speed):GameObject(texturesheet,x,y,IMHeight,IMWidth,scale),health(Health),damage(Damage),speed(Speed){velocity=1;}


void Player::MovePlayer(std::string direction)
{
    this->direction=direction;
    if(direction=="up"){
        ypos=ypos-speed;
    }
        if(direction=="down"){
        ypos=ypos+speed;
    }
        if(direction=="right"){
        xpos = xpos+speed;
    }
        if(direction=="left"){
        xpos = xpos-speed;
    } 
}


void Player::Update()
{
    GameObject::Update();
    //Player::MovePlayer();
}

void Player::Render()
{
    GameObject::Render();
}