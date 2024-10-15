#include "Disk.hpp"
#include <cmath>

Disk::Disk(const char* texturesheet, int IMHeight, int IMWidth, Player* player, float radius, float initialAngle, int scale, float speed, int damage)
    : GameObject(texturesheet, IMHeight, IMWidth, player->fxpos , player->fypos, scale),
      radius(radius), angle(initialAngle), speed(speed), player(player) { }

void Disk::Update(float deltaTime) {
    angle += speed * deltaTime;

    // Keep the angle within the range 0 to 2 * pi
    if (angle > 2 * M_PI) {
        angle -= 2 * M_PI;
    }

    // Calculate the disk's new position based on the player's position and the current angle
    fxpos = player->fxpos + radius * cos(angle)-64;  // x position
    fypos = player->fypos + radius * sin(angle)-34;  // y position 

    GameObject::fUpdate();
}

// Renders the disk on the screen
void Disk::Render() {
    GameObject::Render();
}
