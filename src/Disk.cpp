#include "Disk.hpp"
#include <cmath> // for sin, cos

// Constructor
Disk::Disk(const char* texturesheet, int IMHeight, int IMWidth, Player* player, float radius, float initialAngle, int scale, float speed, int damage)
    : GameObject(texturesheet, IMHeight, IMWidth, player->fxpos + radius * cosf(initialAngle), player->fypos + radius * sinf(initialAngle), scale),
      radius(radius), angle(initialAngle), speed(speed), player(player) { }

// Update the position of the disk to move it in a circular path around the player
void Disk::Update(float deltaTime) {
    angle += speed * deltaTime;

    // Keep the angle within the range 0 to 2 * pi
    if (angle > 2 * M_PI) {
        angle -= 2 * M_PI;
    }

    // Calculate the disk's new position based on the player's position and the current angle
    fxpos = player->fxpos + radius * cosf(angle)-64;  // X position relative to the player
    fypos = player->fypos + radius * sinf(angle)-34;  // Y position relative to the player

    GameObject::fUpdate();
}

// Renders the disk on the screen
void Disk::Render() {
    GameObject::Render();
}
