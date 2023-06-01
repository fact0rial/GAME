#include "EnemyFlying.h"
void EnemyFlying::reposition() {
    save();
    setOffset(offset().x() + vel, offset().y());
}

EnemyFlying::EnemyFlying(const QPointF& pos, int velocity) : Enemy(pos) {
    setPixmap(QPixmap(":/sources/whale.png"));
    vel = velocity;
}

void EnemyFlying::manageLineCollision(QGraphicsLineItem *line) {
    restore();
    vel = -vel;
}