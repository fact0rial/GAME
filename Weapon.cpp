//
// Created by Pavel on 31.05.2023.
//

#include "Weapon.h"

Weapon::Weapon(Entity *parentPtr) {
    setSprites(":/sources/pixil-frame-", 31);
    parent = parentPtr;
    setPixmap(*sprites[0]);
    setVisible(false);
}

void Weapon::advance() {
    if (isVisible()) {
        setOffset(parent->offset() + QPointF(50,10));
        if (counter != 30) {
            counter++;
            setPixmap(*sprites[counter]);
        } else {
            counter = 0;
            setPixmap(*sprites[0]);
            setVisible(false);
        }
    }
}