#pragma once

#include "Entity.h"
#include <QPoint>
#include <QPixmap>
class Enemy{
public:
    QPixmap& getSprite();
    Enemy(const QPoint& point, QPixmap map);
protected:
    int health;
    QPixmap sprite;
    QPoint position;
};
