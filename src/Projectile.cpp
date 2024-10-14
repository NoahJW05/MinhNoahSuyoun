#include "Projectile.hpp"
#include <cmath>
Projectile::Projectile(const char* texturesheet, Player* player, int IMHeight, int IMWidth, int scale, int speed, int angle)
    : GameObject(texturesheet, player->getX(), player->getY(), IMHeight, IMWidth, scale), speed(speed), angle(angle) {
    velocity = 1;
    xpos = player->getX();  // Get initial X position directly from player
    ypos = player->getY();  // Get initial Y position directly from player
}
Projectile::~Projectile(){}

void Projectile::Update(){

    GameObject::Update();
    MoveProjectile(angle);
}

void Projectile:: MoveProjectile(int angle){
    double radians = angle * M_PI / 180.0; 
    xpos += speed*std::cos(radians); //moving in x-direction
    ypos+= speed*std::sin(radians); //moving in y-direction
}


bool Projectile:: isActive()const{
    //check if projectile is in bound
    return xpos >= 0 || xpos <= 960 || ypos >= 0 || ypos <= 640; 
}

void Projectile::Render()
{
    GameObject::Render();
}