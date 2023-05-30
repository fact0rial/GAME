#include "Location1.h"

Location1::Location1() {
    size = new QRect(0,0,1000,600);
    startingPosition = new QPointF(0,0);
    background = new QPixmap(":/sources/background.png");;
    obstacles.push_back(new QGraphicsRectItem(100,100,100,100));
    addBorder();
}