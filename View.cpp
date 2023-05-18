#include "View.h"

View::View(QWidget *widget) : QGraphicsView(widget) {
    timer.setInterval(20);

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
    QPixmap scaled = background.scaled(1200, 800);
    QBrush back(scaled);
    setBackgroundBrush(back);
}

void View::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        controller->keyReleaseEvent(event);
    }
}

