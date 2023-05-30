#include "CollisionManager.h"

void CollisionManager::checkCollisions(QGraphicsScene* scene, Entity* entity) {
    const auto& collisions = scene->collidingItems(entity->getSprite());
    for (auto thing : scene->collidingItems(entity->getSprite())) {
        auto linePtr = dynamic_cast<QGraphicsLineItem*>(thing);
        if(linePtr != nullptr) {
            qDebug() << "bonkLine";
            entity->manageLineCollision(linePtr);
        } else {
            auto rectPtr = dynamic_cast<QGraphicsRectItem*>(thing);
            qDebug() << "bonkRect";
            entity->backtrack();
        }
    }
}