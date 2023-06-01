#include "Controller.h"
#include <QRandomGenerator>

Controller::Controller(Model *mod) : model(mod) {
}

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
            if (model->getPLayer()->getJump()) {
                model->getPLayer()->setVelocity(QVector2D(model->getPLayer()->getVelocity().x(), -5));
                model->getPLayer()->setJump(false);
            }
            break;
        }
        case (Qt::Key_Right): {
            model->getPLayer()->getWeapon()->setVisible(true);
            break;
        }
        case (Qt::Key_Up): {
            model->getPLayer()->getVerticalWeapon()->setVisible(true);
            break;
        }
        case (Qt::Key_Left): {
            model->getPLayer()->getRightWeapon()->setVisible(true);
            break;
        }
        case (Qt::Key_Z): {
            spawnWalk(QPointF(100, 100), 1);
            break;
        }
        case (Qt::Key_X): {
            spawnJump(QPointF(100, 100));
            break;
        }
        case (Qt::Key_C): {
            spawnFlying(QPointF(500, 100), 1);
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
    model->getPLayer()->getWeapon()->advance();
    model->getPLayer()->getVerticalWeapon()->advance();
    model->getPLayer()->getRightWeapon()->advance();
    model->getPLayer()->reposition();
    manager->checkCollisions(view->scene(), model->getPLayer());
    //model->getPLayer()->reposition();
    for (auto &enemy: model->getEnemies()) {
        enemy->reposition();
        manager->checkEnemyCollisions(view->scene(), enemy);
    }
}

void Controller::setLocation(Location *loc) {
    model->setLocation(loc);
    view->setLocation(loc);
    view->scene()->addItem(model->getPLayer());
    view->scene()->addItem(model->getPLayer()->getWeapon());
    view->scene()->addItem(model->getPLayer()->getVerticalWeapon());
    view->scene()->addItem(model->getPLayer()->getRightWeapon());
}

void Controller::setView(View *v) {
    view = v;
    connect(model->getPLayer(), SIGNAL(playerDeath()), v->parent(), SLOT(gameLoss()));
}

void Controller::remove(Enemy *enemy) {
    view->scene()->removeItem(enemy);
    model->remove(enemy);
    //delete enemy;
}

void Controller::spawnJump(const QPointF &point) {
    EnemyJumping *jumpy = new EnemyJumping(point);
    view->scene()->addItem(jumpy);
    model->getEnemies().push_back(jumpy);
    connect(jumpy, SIGNAL(enemyDeath(Enemy * )), this, SLOT(remove(Enemy * )));
}

void Controller::spawnFlying(const QPointF &point, int dir) {
    EnemyFlying *jumpy = new EnemyFlying(point, dir);
    view->scene()->addItem(jumpy);
    model->getEnemies().push_back(jumpy);
    connect(jumpy, SIGNAL(enemyDeath(Enemy * )), this, SLOT(remove(Enemy * )));
}

void Controller::spawnWalk(const QPointF &point, int dir) {
    EnemyWalk *jumpy = new EnemyWalk(point, dir);
    view->scene()->addItem(jumpy);
    model->getEnemies().push_back(jumpy);
    connect(jumpy, SIGNAL(enemyDeath(Enemy * )), this, SLOT(remove(Enemy * )));
}