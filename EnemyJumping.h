#pragma once
#include "Enemy.h"

class EnemyJumping : public Enemy {
public:
    EnemyJumping(const QPointF& pos);
    void manageLineCollision(QGraphicsLineItem *line) override;
};

