#include "Player.h"

Player::Player(const QPointF& pos) : Entity(pos), weapon(new Weapon(this)), verticalWeapon(new VerticalWeapon(this)), rightWeapon(new RightWeapon(this)) {
    setPixmap(QPixmap(":/sources/character.png"));
}

Player::~Player() {
    delete weapon;
    delete verticalWeapon;
    delete rightWeapon;
}

Weapon* Player::getWeapon() {
    return weapon;
}

//int Player::getDamage() const {
//    return damage;
//}
//void Player::setDamage(int num) {
//    damage = num;
//}

void Player::loseHp() {
    if(!invincibility) {
        health--;
        qDebug() << "ouch";
        if (health == 0) {
            emit playerDeath();
            qDebug() << "game over";
        }
        invincibility = true;
        QTimer::singleShot(10, this, &Player::stopInvincibility);
    }
}

void Player::stopInvincibility() {
    invincibility = false;
}

void Player::manageLineCollision(QGraphicsLineItem *line) {
    restore();
    QVector2D vector(line->line().p2() - line->line().p1());
    QVector2D velocityPr = vector * QVector2D::dotProduct(velocity, vector) / vector.lengthSquared();
    setVelocity(velocityPr);
    setOffset(offset() + velocity.toPointF());
    if (line->line().p1().y() == line->line().p2().y() && offset().y() - 1 <= line->line().p2().y()) {
        setJump(true);
    }
}

void Player::setJump(bool val) {
    canJump = val;
}
bool Player::getJump() {
    return canJump;
}

VerticalWeapon* Player::getVerticalWeapon() {
    return verticalWeapon;
}

RightWeapon* Player::getRightWeapon() {
    return rightWeapon;
}