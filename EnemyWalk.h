#pragma once
#include "Enemy.h"
class EnemyWalk: public Enemy {
public:
    EnemyWalk(const QPointF& pos, int direction = 1);
    void manageLineCollision(QGraphicsLineItem *line) override;
};