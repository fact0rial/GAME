#include "Enemy.h"

QPixmap& Enemy::getSprite() {
    return sprite;
}

Enemy::Enemy(const QPoint& point, QPixmap map) {
    position = point;
    sprite = map;
}