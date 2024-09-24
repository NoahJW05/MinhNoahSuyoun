#include "Player.hpp"
#include "GameObject.hpp"

Player::Player(int health, int damage,const char* texturesheet,int x,int y)
{
    player = new GameObject(texturesheet,x,y);
    
}

Player::~Player(){}