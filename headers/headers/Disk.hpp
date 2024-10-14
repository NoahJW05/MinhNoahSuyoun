#ifndef DISK_HPP
#define DISK_HPP

#include "GameObject.hpp"
#include "Player.hpp"

class Disk : public GameObject {
private:
    float radius;   // Distance from the player
    float angle;    // Angle of the disk relative to the player
    float speed;
    int damage;
    Player* player; 

public:
    // Constructor
    Disk(const char* texturesheet, int IMHeight, int IMWidth, Player* player, float radius, float angle, int scale, float speed, int damage);
    // Updates the disk position to move in a circular path around the player
    void Update(float deltaTime);

    void Render();
};

#endif