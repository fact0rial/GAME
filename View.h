#pragma once

#include <QGraphicsView>
#include "AbstractController.h"
#include <QTimer>
#include <QKeyEvent>
#include "Location.h"

class View : public QGraphicsView {
public:
    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    View(QWidget *widget = nullptr);

    void setController(AbstractController *);

    void setBackground(const QPixmap &background);

    void setLocation(Location*);

    QTimer timer;

private:
Q_OBJECT
    AbstractController *controller = nullptr;
};

