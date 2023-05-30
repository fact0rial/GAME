#pragma once
#include <vector>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include "Entity.h"

class CollisionManager : QObject {
    Q_OBJECT
public:
    void checkCollisions(QGraphicsScene*, Entity*);
private:
};

