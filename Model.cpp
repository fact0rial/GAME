#include "Model.h"

Player* Model::getPLayer() {
    return player;
}

Model::Model() : player(new Player(QPointF(0,0))) {};

void Model::setController(AbstractController* controllerPtr) {
    controller = controllerPtr;
}

void Model::setLocation(Location* loc) {
    enemies = loc->getEnemies();
    obstacles = loc->getObstacles();
    player = new Player(*loc->getStartingPosition());
}

std::vector<Enemy*>& Model::getEnemies() {
    return enemies;
};

void Model::remove(Enemy* enemy) {
    enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}