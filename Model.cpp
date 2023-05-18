#include "Model.h"

Player* Model::getPLayer() {
    return &player;
}

Model::Model() : player() {};