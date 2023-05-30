#include "Controller.h"

Controller::Controller(Model *mod) : model(mod) {}

void Controller::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case (Qt::Key_D): {
            model->getPLayer()->setVelocity(QVector2D(1, model->getPLayer()->getVelocity().y()));
            break;
        }
        case (Qt::Key_A): {
            model->getPLayer()->setVelocity(QVector2D(-1, model->getPLayer()->getVelocity().y()));
            break;
        }
        case (Qt::Key_W): {
            model->getPLayer()->setVelocity(QVector2D(model->getPLayer()->getVelocity().x(), -5));
            break;
        }
    }
}

void Controller::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case (Qt::Key_D):
        case (Qt::Key_A): {
            model->getPLayer()->setVelocity(QVector2D(0, 0));
            model->getPLayer()->reposition();
            qDebug() << "stop";
            break;
        }
    }
}

void Controller::reposition() {
    model->getPLayer()->reposition();
    manager->checkCollisions(view->scene(), model->getPLayer());
}

void Controller::setLocation(Location* loc) {
    model->setLocation(loc);
    view->setLocation(loc);
    view->scene()->addItem(model->getPLayer()->getSprite());
}

void Controller::setView(View* v) {
    view = v;
}
