#pragma once

#include <QPixmap>

class Character {
public:
    Character(const QString& filename);
private:
    QPixmap sprite;
    int health = 5;
    QPoint position = QPoint(0,0);
};
