//
// Created by Pavel on 09.05.2023.
//

#include "Entity.h"

Entity::Entity() : position(0,0), sprite(nullptr) {};

Entity::Entity(const QPointF& pos) : position(pos), sprite(nullptr) {
}
int Entity::getHealth() const {
    return health;
}
void Entity::setHealth(int num) {
    health = num;
}

const QPointF& Entity::getPosition() const {
    return position;
}
void Entity::setPosition(const QPointF& point) {
    position = point;
};
const QVector2D& Entity::getVelocity() const {
    return velocity;
}
void Entity::setVelocity(const QVector2D& point) {
    velocity = point;
}

const QVector2D& Entity::getAcceleration() const {
    return acceleration;
}
void Entity::setAcceleration(const QVector2D& point) {
    acceleration = point;
};

void Entity::addToVelocity(const QVector2D& point) {
    velocity = velocity + point;
}

QGraphicsPixmapItem* Entity::getSprite() {
    return sprite;
}

void Entity::reposition() {
    setAcceleration(defaultAcceleration);
    addToVelocity(acceleration);
    sprite->setOffset(sprite->offset() + velocity.toPointF());
}

Entity::~Entity() {
    delete sprite;
}
void Entity::manageLineCollision(QGraphicsLineItem* line) {
    QVector2D vector(line->line().p2()-line->line().p1());
    QVector2D velocityPr = vector * QVector2D::dotProduct(velocity, vector) / vector.lengthSquared();
    QVector2D accelerationPr = vector * QVector2D::dotProduct(acceleration, vector) / vector.lengthSquared();
    sprite->setOffset(sprite->offset() - velocity.toPointF() + velocityPr.toPointF());
    //addToVelocity(-acceleration + accelerationPr);
}

void Entity::backtrack() {
    sprite->setOffset(sprite->offset() - velocity.toPointF());
    //addToVelocity(-acceleration);
}

