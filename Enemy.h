#pragma once

#include <QPixmap>

class Enemy {
public:
    QPixmap& getSprite() {
    return sprite;
}
protected:
    int health;
    QPixmap sprite;
    QPoint position;
};
