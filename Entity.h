#pragma once

#include <QPixmap>
#include <QGraphicsPolygonItem>
#include <QVector2D>

class Entity : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
public:

    explicit Entity(const QPointF &position);

    int getHealth() const;

    void setHealth(int num);

    const QVector2D &getVelocity() const;

    void setVelocity(const QVector2D &point);

    const QVector2D &getAcceleration() const;

    void setAcceleration(const QVector2D &point);

    virtual void reposition();

    void addToVelocity(const QVector2D &point);

    void backtrack();

    virtual void manageLineCollision(QGraphicsLineItem *);

    const QVector2D defaultAcceleration = QVector2D(0, 0.05);

    void save();

    void restore();

protected:
    int health = 1;
    QPointF prePosition;
    QVector2D velocity = QVector2D(0, 0);
    QVector2D acceleration = QVector2D(0, 0.1);
    QVector2D velocityPre;
    QVector2D accelerationPre;
};
