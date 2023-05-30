#pragma once

#include <QPixmap>
#include <QGraphicsPolygonItem>
#include "Entity.h"

class Player : public Entity {
public:
    Player();
    explicit Player(const QPointF& position);
    //int getDamage() const;
    //void setDamage(int num);
private:
    //int damage = 3;
};

