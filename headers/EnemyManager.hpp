#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

#include <vector>
#include "Game.hpp"
#include "Enemy.hpp"  // Include your Enemy class header
#include "Player.hpp" // Include your Player class header

class EnemyManager {
public:
    EnemyManager(int maxEnemies, Uint32 spawnInterval,Player* player); // Constructor
    ~EnemyManager(); // Destructor

    void SpawnEnemy(); // Spawn a new enemy
    void Update(Player* player); // Update all enemies, passing the player
    void Render(); // Render all enemies
    std::vector<Enemy*> getEnemies(); // Retrieve current enemies
 // Retrieve current enemies

private:
    Player* player;
    std::vector<Enemy*> enemyArray; // Vector to hold pointers to enemies
    int maxEnemies; // Maximum number of enemies
    Uint32 spawnInterval; // Time interval for spawning enemies
    Uint32 lastSpawnTime; // Time of the last enemy spawn
};

#endif // ENEMYMANAGER_HPP
