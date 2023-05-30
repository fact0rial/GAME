#include "Player.h"

Player::Player() : Entity() {
    sprite = new QGraphicsPixmapItem(QPixmap(":/sources/enemy.png"));
};

Player::Player(const QPointF& pos) : Entity(pos) {
    sprite = new QGraphicsPixmapItem(QPixmap(":/sources/enemy.png"));
}

//int Player::getDamage() const {
//    return damage;
//}
//void Player::setDamage(int num) {
//    damage = num;
//}