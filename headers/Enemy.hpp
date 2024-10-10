#ifndef Enemy_hpp
#define Enemy_hpp

#include "Player.hpp"
#include "GameObject.hpp"
#include <cmath> 
#include <cstdlib> 
#include <ctime>   

class Enemy : public GameObject {
 protected:
    int EHealth;
    int EDamage;
    int Evelocity;

 public:
    Enemy(const char* texturesheet, int health, int damage, int velocity)
        : GameObject(texturesheet, 0, 0, 0, 0, 0), EHealth(health), EDamage(damage), Evelocity(velocity) {
        std::srand(std::time(0)); 
        SpawnEnemyRandomly();
    }

    void SpawnEnemyRandomly() {
        xpos = std::rand() % 800;
        ypos = std::rand() % 600; 

        destRect.x = xpos;
        destRect.y = ypos;
    }

    void FollowPlayer(int playerX, int playerY) {
        int deltaX = playerX - xpos;
        int deltaY = playerY - ypos;

        float distance = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

        if (distance > 0) {
            xpos += (deltaX / distance) * Evelocity;
            ypos += (deltaY / distance) * Evelocity;
        }

        destRect.x = xpos;
        destRect.y = ypos;
    }

    void Update(int playerX, int playerY) {
        FollowPlayer(playerX, playerY); 
    }
    void Render() {
        SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
    }
};


#endif