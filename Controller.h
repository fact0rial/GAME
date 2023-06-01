#pragma once
#include "Model.h"
#include <QTimer>
#include <QKeyEvent>
#include "AbstractController.h"
#include "View.h"
#include "Location.h"
#include "CollisionManager.h"
#include "Weapon.h"
#include "EnemyJumping.h"
#include "EnemyFlying.h"
#include "EnemyWalk.h"
class Controller : public AbstractController {
public:
    Controller(Model* mod);
    void keyPressEvent (QKeyEvent* event) override;
    void keyReleaseEvent (QKeyEvent* event) override;
    void setLocation(Location*);
    void setView(View*);
    void spawnJump(const QPointF&);
    void spawnFlying(const QPointF&, int dir);
    void spawnWalk(const QPointF&, int dir);
public slots:
    void remove(Enemy*);
    void reposition() override;
private:
    Q_OBJECT
    Model* model;
    View* view;
    CollisionManager* manager;
};
