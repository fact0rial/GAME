#pragma once

#include <QPixmap>
#include "Enemy.h"
#include <vector>

class Location {
public:
private:
    QPixmap background;
    std::vector<Enemy *> enemies;
    QPoint startingPosition;
};