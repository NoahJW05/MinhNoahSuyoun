#include "EnemyManager.hpp"

#include <cstdlib>

EnemyManager::EnemyManager(int maxEnemies, Uint32 spawnInterval,Player* player)
    : maxEnemies(maxEnemies), spawnInterval(spawnInterval), lastSpawnTime(0) {this->player=player;
}

EnemyManager::~EnemyManager() {
  for (auto enemy : enemyArray) {
    // Free allocated memory for each enemy
    delete enemy; 
  }
}

void EnemyManager::SpawnEnemy() {
      if (enemyArray.size() < maxEnemies) {
        Enemy* newEnemy = new Enemy("ProjectPNG/Demon.png", 32, 32, 0, 0, 2, player);
        newEnemy->SpawnEnemyRandomly(); 
        enemyArray.push_back(newEnemy); 
    }
}

void EnemyManager::Update(Player* player) {
    //check if player pointer is null
    if (player == nullptr) {
        std::cout << "Player reference is null!" << std::endl;
        return;
    }
    //to get time 
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastSpawnTime >= spawnInterval) {
        SpawnEnemy();
        //spawn time update
        lastSpawnTime = currentTime;  
    }

    for (auto enemy : enemyArray) {
        enemy->Update();  
    }
}

void EnemyManager::Render() {
  for (auto enemy : enemyArray) {
    enemy->Render();  
  }
}

//array contantaining pointers to enemy
std::vector<Enemy*> EnemyManager::getEnemies() {
    //returns array
    return enemyArray; 
}