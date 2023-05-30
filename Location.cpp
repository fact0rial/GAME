#include "Location.h"


QRect* Location::getSize() {
    return size;
}
QPixmap* Location::getBackground(){
    return background;
}
std::vector<Enemy*>& Location::getEnemies() {
    return enemies;
}
std::vector<QGraphicsItem*>& Location::getObstacles() {
    return obstacles;
}
QPointF* Location::getStartingPosition() {
    return startingPosition;
}

Location::~Location() {
    for (auto& obstacle : obstacles) {
        delete obstacle;
    }
    for (auto& enemy : enemies) {
        delete enemy;
    }
    delete size;
    delete background;
    delete startingPosition;
}

void Location::addBorder() {
    obstacles.push_back(new QGraphicsLineItem(QLineF(size->topLeft(), size->topRight())));
    obstacles.push_back(new QGraphicsLineItem(QLineF(size->topRight(), size->bottomRight())));
    obstacles.push_back(new QGraphicsLineItem(QLineF(size->bottomRight(), size->bottomLeft())));
    obstacles.push_back(new QGraphicsLineItem(QLineF(size->bottomLeft(), size->topLeft())));
}