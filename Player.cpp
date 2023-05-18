#include "Player.h"

Player::Player() : position(0,0), sprite(QGraphicsPixmapItem(QPixmap(":/sources/character.png"))) {};

Player::Player(const QPointF& pos) : sprite(QGraphicsPixmapItem(QPixmap(":/sources/character.png"))) {
    position = pos;
}
int Player::getHealth() const {
    return health;
}
void Player::setHealth(int num) {
    health = num;
}
int Player::getDamage() const {
    return damage;
}
void Player::setDamage(int num) {
    damage = num;
}
const QPointF& Player::getPosition() const {
    return position;
}
void Player::setPosition(const QPointF& point) {
    position = point;
};
const QPointF& Player::getVelocity() const {
    return velocity;
}
void Player::setVelocity(const QPointF& point) {
    velocity = point;
}
int Player::getMass() const {
    return mass;
};
void Player::setMass(int num) {
    mass = num;
}
const QPointF& Player::getAcceleration() const {
    return acceleration;
}
void Player::setAcceleration(const QPointF& point) {
    acceleration = point;
};
const QRectF& Player::getHitbox() const {
    return hitbox;
}
void Player::setHitbox(const QRectF& rect) {
    hitbox = rect;
}

void Player::addToVelocity(const QPointF& point) {
    velocity = velocity + point;
}

QGraphicsPixmapItem* Player::getSprite() {
    return &sprite;
}

void Player::reposition() {
    sprite.setOffset(sprite.offset() + velocity);
}