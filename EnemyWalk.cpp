//
// Created by Pavel on 01.06.2023.
//

#include "EnemyWalk.h"
#include "EnemyFlying.h"

EnemyWalk::EnemyWalk(const QPointF& pos, int velocit) : Enemy(pos) {
    setPixmap(QPixmap(":/sources/slime.png").scaled(200,200));
    setVelocity(QVector2D(velocit,0));
}

void EnemyWalk::manageLineCollision(QGraphicsLineItem *line) {
    restore();
    QVector2D vector(line->line().p2() - line->line().p1());
    QVector2D velocityPr = vector * QVector2D::dotProduct(velocity, vector) / vector.lengthSquared();
    if (line->line().angle() == 270 || line->line().angle() == 90 ) {
        velocity.setX(-velocity.x());
    } else  {
        setVelocity(velocityPr);
    }
    setOffset(offset() + velocity.toPointF());
}