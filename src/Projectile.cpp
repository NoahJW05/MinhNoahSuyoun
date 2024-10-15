#include "Projectile.hpp"

#include <cmath>
Projectile::Projectile(const char* texturesheet, Player* player, int IMHeight, int IMWidth, int scale, int speed, int angle)
    : GameObject(texturesheet, IMHeight, IMWidth, player->fxpos, player->fypos, scale)
    ,angle(angle), speed(speed), player(player){}
Projectile::~Projectile(){}

void Projectile::Update(){
 
    GameObject::fUpdate();
    MoveProjectile(angle);
}

void Projectile:: MoveProjectile(int angle){
    double radians = angle * M_PI / 180.0; 
    fxpos += speed*std::cos(radians); //moving in x-direction
    fypos+= speed*std::sin(radians); //moving in y-direction
}


bool Projectile:: isActive()const{
    //check if projectile is in bound
    return xpos >= 0 || xpos <= 960 || ypos >= 0 || ypos <= 640; 
}

void Projectile::Render()
{
    GameObject::Render();
}