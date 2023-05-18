#pragma once

#include "Location.h"
#include "Player.h"

class Model {
public:
    Model();
    Player* getPLayer();
private:
    //Location *location;
    Player player;
    std::vector<Enemy> enemies;
    std::vector<QRect> obstacles;
};
