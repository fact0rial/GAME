#pragma once

#include "Entity.h"
#include <QPoint>
#include <QPixmap>
class Enemy : public Entity {
    Q_OBJECT
public:
    void loseHp();
    Enemy(const QPointF& pos);
    signals:
    void enemyDeath(Enemy*);
};
