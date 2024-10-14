// #include "Gun.hpp"
// #include <algorithm>

// void Gun::CreateProjectile(const char* texturesheet, float x, float y, int IMHeight, int IMWidth, int scale, int speed, int direction) {
//     projectiles.emplace_back(texturesheet, x, y, IMHeight, IMWidth, scale, speed, direction);
// }

// void Gun::UpdateProjectiles() {
//     for (auto& projectile : projectiles) {
//         projectile.Update();
//     }

//     // Remove inactive projectiles
//     projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
//         [](const Projectile& p) { return !p.isActive(); }), projectiles.end());
// }

// void Gun::RenderProjectiles() {
//     for (auto& projectile : projectiles) {
//         projectile.Render();
//     }
// }