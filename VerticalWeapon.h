#pragma once
#include "Weapon.h"

class VerticalWeapon : public Animation {
public:
    VerticalWeapon(Entity* parent);
    void advance() override;
private:
    Entity* parent;
};
