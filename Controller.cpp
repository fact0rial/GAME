#include "Controller.h"

Controller::Controller(Model *mod) : model(mod) {}

void Controller::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case (Qt::Key_D): {
            model->getPLayer()->setVelocity(QPointF(1, 0));
            break;
        }
        case (Qt::Key_A): {
            model->getPLayer()->setVelocity(QPointF(-1, 0));
            break;
        }
    }
}

void Controller::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case (Qt::Key_D):
        case (Qt::Key_A): {
            model->getPLayer()->setVelocity(QPointF(0, 0));
            model->getPLayer()->reposition();
            qDebug() << "stop";
            break;
        }
    }
}

void Controller::reposition() {
    model->getPLayer()->reposition();
}