#pragma once

#include "Location.h"
#include "Player.h"
#include "AbstractController.h"

class Model {
public:
    Model();
    Player* getPLayer();
    std::vector<Enemy*>& getEnemies();
    void setController(AbstractController* controller);
    void setLocation(Location* loc);
    void remove(Enemy*);
private:
    //Location *location;
    Player* player;
    QPixmap background;
    AbstractController* controller;
    std::vector<Enemy*> enemies;
    std::vector<QGraphicsItem*> obstacles;
};
