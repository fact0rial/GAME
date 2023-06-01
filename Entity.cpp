//
// Created by Pavel on 09.05.2023.
//

#include "Entity.h"

Entity::Entity(const QPointF& pos) {
    setOffset(pos);
}
int Entity::getHealth() const {
    return health;
}
void Entity::setHealth(int num) {
    health = num;
}

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

void Entity::reposition() {
    save();
    setAcceleration(defaultAcceleration);
    addToVelocity(acceleration);
    setOffset(offset() + velocity.toPointF());
}


void Entity::manageLineCollision(QGraphicsLineItem *line) {
    restore();
    QVector2D vector(line->line().p2() - line->line().p1());
    QVector2D velocityPr = vector * QVector2D::dotProduct(velocity, vector) / vector.lengthSquared();
    setVelocity(velocityPr);
    setOffset(offset() + velocity.toPointF());
}

void Entity::backtrack() {
    setOffset(offset() - velocity.toPointF());
}

void Entity::save() {
    velocityPre = velocity;
    accelerationPre = acceleration;
    prePosition = offset();
}

void Entity::restore() {
    velocity = velocityPre;
    acceleration = accelerationPre;
    setOffset(prePosition);
}