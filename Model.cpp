#include "Model.h"

Player* Model::getPLayer() {
    return player;
}

Model::Model() : player() {};

void Model::setController(AbstractController* controllerPtr) {
    controller = controllerPtr;
}

void Model::setLocation(Location* loc) {
    enemies = loc->getEnemies();
    obstacles = loc->getObstacles();
    player = new Player(*loc->getStartingPosition());
}