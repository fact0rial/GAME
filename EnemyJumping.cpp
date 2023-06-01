//
// Created by Pavel on 31.05.2023.
//

#include "EnemyJumping.h"


EnemyJumping::EnemyJumping(const QPointF& pos) : Enemy(pos) {
    setVelocity(QVector2D(1,0));
    setPixmap(QPixmap(":/sources/ghost.png"));
    setOffset(pos);
}

void EnemyJumping::manageLineCollision(QGraphicsLineItem *line) {
    restore();
    if (line->line().angle() == 270 || line->line().angle() == 90 ) {
        velocity.setX(-velocity.x());
    } else {
        velocity.setY(-velocity.y());
    }
}