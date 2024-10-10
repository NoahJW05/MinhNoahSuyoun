#include "Projectile.hpp"
#include <cmath>
Projectile::Projectile(const char* texturesheet, int x, int y, int IMHeight, int IMWidth, int scale, int speed, int direction)
    : GameObject(texturesheet, x, y, IMHeight, IMWidth, scale), speed(speed), direction(direction){velocity=1;}

void Projectile::Update(){
    double radians = direction * M_PI / 180.0; 
    xpos += speed*std::cos(radians); //moving in x-direction
    ypos -= speed*std::sin(radians); //moving in y-direction

    GameObject::Update();
}

bool Projectile:: isActive()const{
    //check if projectile is in bound
    return xpos >= 0 || xpos <= 960 || ypos >= 0 || ypos <= 640; 
}

void Projectile::Render()
{
    GameObject::Render();
}
