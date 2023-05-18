#pragma once

#include <QPixmap>
#include "Enemy.h"
#include <vector>

class Location {
public:
    Location(const QRect &rect, const QPixmap pixmap, const std::vector<Enemy> &vec1,
             const std::vector<QRect> &vec2, QPoint point) : size(rect), background(pixmap), enemies(vec1),
                                                             obstacles(vec2), startingPosition(point) {};
    QRect getSize() {
        return size;
    }
    QPixmap getBackground(){
        return background;
    }
    std::vector<Enemy> getEnemies() {
        return enemies;
    }
    const std::vector<QRect>& getObstacles() {
        return obstacles;
    }
    const QPoint& getStartingPosition() {
        return startingPosition;
    }
private:
    QRect size;
    QPixmap background;
    std::vector<Enemy> enemies;
    std::vector<QRect> obstacles;
    QPoint startingPosition;
};