#pragma once

#include "Location.h"
#include "Player.h"
#include "AbstractController.h"

class Model {
public:
    Model();
    Player* getPLayer();
    void setController(AbstractController* controller);
    void setLocation(Location* loc);
private:
    //Location *location;
    Player* player;
    QPixmap background;
    AbstractController* controller;
    std::vector<Enemy*> enemies;
    std::vector<QGraphicsItem*> obstacles;
};
