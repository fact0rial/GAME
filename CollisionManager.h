#pragma once
#include <vector>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include "Entity.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Player.h"
#include "VerticalWeapon.h"

class CollisionManager : QObject {
    Q_OBJECT
public:
    void checkCollisions(QGraphicsScene*, Player*);
    void checkEnemyCollisions(QGraphicsScene*, Enemy*);
private:
};

