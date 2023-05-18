#pragma once

#include <QGraphicsView>
#include "AbstractController.h"
#include <QTimer>
#include <QKeyEvent>

class View : public QGraphicsView {
public:
    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    View(QWidget *widget = nullptr);

    void setController(AbstractController *);

    void setBackground(const QPixmap &background);

    QTimer timer;

private:
Q_OBJECT
    AbstractController *controller = nullptr;
};

