#include "Enemy.h"
Enemy::Enemy(const QPointF& pos) : Entity(pos){
};

void Enemy::loseHp() {
    health--;
    if (health == 0) {
        emit enemyDeath(this);
    }
}