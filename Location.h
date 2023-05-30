#pragma once

#include <QPixmap>
#include "Enemy.h"
#include <vector>

class Location {
public:
    QRect* getSize();

    QPixmap* getBackground();

    std::vector<Enemy*>& getEnemies();

    std::vector<QGraphicsItem*>& getObstacles();

    QPointF* getStartingPosition();

    ~Location();

protected:
    QRect* size;
    QPixmap* background;
    std::vector<Enemy*> enemies;
    std::vector<QGraphicsItem*> obstacles;
    QPointF* startingPosition;
    void addBorder();
};