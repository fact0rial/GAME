#pragma once
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>
#include <vector>
#include "Entity.h"
#include "Animation.h"

class Weapon : public Animation {
public:
    Weapon(Entity* parent);
    void advance() override;
protected:
    Entity* parent;
};

