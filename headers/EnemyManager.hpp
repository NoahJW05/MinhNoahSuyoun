#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

#include <vector>
#include "Game.hpp"
#include "Enemy.hpp"  
#include "Player.hpp" 


class EnemyManager {
private:
    Player* player;
    std::vector<Enemy*> enemyArray; 
    int maxEnemies; 
    Uint32 spawnInterval; 
    Uint32 lastSpawnTime; 
public:
    EnemyManager(int maxEnemies, Uint32 spawnInterval,Player* player); 
    ~EnemyManager(); 

    void SpawnEnemy(); 
    void Update(Player* player); 
    void Render(); 
    std::vector<Enemy*> getEnemies(); 
 
};

#endif