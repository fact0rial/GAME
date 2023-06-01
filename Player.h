#pragma once

#include <QPixmap>
#include <QGraphicsPolygonItem>
#include "Entity.h"
#include "Weapon.h"
#include <QTimer>
#include "VerticalWeapon.h"
#include "RightWeapon.h"

class Player : public Entity {
    Q_OBJECT
public:
    explicit Player(const QPointF& position);

    ~Player();
    Weapon* getWeapon();
    VerticalWeapon* getVerticalWeapon();
    RightWeapon* getRightWeapon();
    void loseHp();
    void manageLineCollision(QGraphicsLineItem *) override;
    void setJump(bool);
    bool getJump();
private:
    bool invincibility = false;
    bool canJump = false;
    void stopInvincibility();
    Weapon* weapon;
    VerticalWeapon* verticalWeapon;
    RightWeapon* rightWeapon;
signals:
    void playerDeath();
};

