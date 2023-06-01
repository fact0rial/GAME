//
// Created by Pavel on 01.06.2023.
//

#include "RightWeapon.h"

RightWeapon::RightWeapon(Entity *parentPtr) {
    parent = parentPtr;
    setSprites(":/sources/vertical attack1/pixil-frame-", 31);
    setPixmap(*sprites[0]);
    setVisible(false);
}

void RightWeapon::advance() {
    if (isVisible()) {
        setOffset(parent->offset() + QPointF(-50,0));
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