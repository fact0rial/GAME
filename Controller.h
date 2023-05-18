#pragma once
#include "Model.h"
#include <QTimer>
#include <QKeyEvent>
#include "AbstractController.h"
#include "View.h"
class Controller : public AbstractController {
public:
    Controller(Model* mod);
    void keyPressEvent (QKeyEvent* event) override;
    void keyReleaseEvent (QKeyEvent* event) override;
public slots:
    void reposition() override;
private:
    Q_OBJECT
    Model* model;
    View* view;
};
