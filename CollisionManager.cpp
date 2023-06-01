#include "CollisionManager.h"

void CollisionManager::checkCollisions(QGraphicsScene* scene, Player* player) {
    const auto& collisions = scene->collidingItems(player);
    for (auto thing : scene->collidingItems(player)) {
        auto linePtr = dynamic_cast<QGraphicsLineItem*>(thing);
        if (linePtr != nullptr) {
            player->manageLineCollision(linePtr);
        } else if (dynamic_cast<Enemy*>(thing) != nullptr) {
            player->loseHp();
        }
     }
}

void CollisionManager::checkEnemyCollisions(QGraphicsScene* scene, Enemy* enemy) {
    const auto& collisions = scene->collidingItems(enemy);
    for (auto thing : scene->collidingItems(enemy)) {
        auto linePtr = dynamic_cast<QGraphicsLineItem*>(thing);
        if (linePtr != nullptr) {
            enemy->manageLineCollision(linePtr);
        } else if (dynamic_cast<Weapon*>(thing) != nullptr || dynamic_cast<VerticalWeapon*>(thing) != nullptr || dynamic_cast<RightWeapon*>(thing) != nullptr) {
            enemy->loseHp();
        }
    }
}