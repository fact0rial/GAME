#include "View.h"
View::View(QWidget *widget) : QGraphicsView(widget) {
    timer.setInterval(10);

}

void View::keyPressEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        controller->keyPressEvent(event);
    }
}

void View::setController(AbstractController *cont) {
    controller = cont;
}

void View::setBackground(const QPixmap &background) {
    QPixmap scaled = background.scaled(4 * rect().x(), 4 * rect().y());
    QBrush back(scaled);
    setBackgroundBrush(back);
}

void View::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        controller->keyReleaseEvent(event);
    }
}

void View::setLocation(Location* loc) {
    QRect* size = loc->getSize();
    qDebug() << int(size->x());
    setGeometry(*size);
    scene()->setSceneRect(*size);
    setStyleSheet("QGraphicsView { border-image: url(:/sources/background.png);}");
    for (auto thing: loc->getObstacles()) {
        scene()->addItem(thing);
    }
    for (auto enemy: loc->getEnemies()) {
        scene()->addItem(enemy);
    }
}

