#pragma once
#include "Enemy.h"
class EnemyFlying : public Enemy {
public:
    EnemyFlying(const QPointF& pos, int direction = 1);
    void reposition() override;
    void manageLineCollision(QGraphicsLineItem *line) override;
    int vel;
};

