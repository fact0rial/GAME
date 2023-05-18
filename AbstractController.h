#pragma once
#include <QObject>
#include <QKeyEvent>
class AbstractController : public QObject {
    Q_OBJECT
public:
    virtual void keyPressEvent (QKeyEvent* event) = 0;
    virtual void keyReleaseEvent (QKeyEvent* event) = 0;
public slots:
    virtual void reposition() = 0;
};
