#pragma once
#include "Animation.h"
#include "Entity.h"

class RightWeapon : public Animation {
public:
    RightWeapon(Entity* parent);
    void advance() override;
private:
    Entity* parent;
};