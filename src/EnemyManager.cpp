#include "EnemyManager.hpp"

#include <cstdlib>

EnemyManager::EnemyManager(int maxEnemies, Uint32 spawnInterval,Player* player)
    : maxEnemies(maxEnemies), spawnInterval(spawnInterval), lastSpawnTime(0) {this->player=player;
  // No need to allocate memory here, we will do it during spawning
}

EnemyManager::~EnemyManager() {
  for (auto enemy : enemyArray) {
    delete enemy;  // Free allocated memory for each enemy
  }
}

void EnemyManager::SpawnEnemy() {
      if (enemyArray.size() < maxEnemies) {
        Enemy* newEnemy = new Enemy("ProjectPNG/Demon.png", 32, 32, 0, 0, 2, player);
        newEnemy->SpawnEnemyRandomly(); // Call this to set position
        enemyArray.push_back(newEnemy);  // Add to the vector
    }
}

void EnemyManager::Update(Player* player) {
   if (player == nullptr) {
        std::cerr << "Player reference is null!" << std::endl;
        return;
    }

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastSpawnTime >= spawnInterval) {
        SpawnEnemy();
        lastSpawnTime = currentTime;  // Update the last spawn time
    }

    for (auto enemy : enemyArray) {
        enemy->Update();  // Update each enemy
    }
}

void EnemyManager::Render() {
  for (auto enemy : enemyArray) {
    enemy->Render();  // Render each enemy
  }
}


std::vector<Enemy*> EnemyManager::getEnemies() {
  return enemyArray;  // Return the vector containing enemy pointers
}