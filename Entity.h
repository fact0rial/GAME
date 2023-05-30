#pragma once

#include <QPixmap>
#include <QGraphicsPolygonItem>
#include <QVector2D>

class Entity : QObject{
    Q_OBJECT
public:
    Entity();
    explicit Entity(const QPointF& position);
    int getHealth() const;
    void setHealth(int num);
    const QPointF& getPosition() const;
    void setPosition(const QPointF& point);
    const QVector2D& getVelocity() const;
    void setVelocity(const QVector2D& point);
    const QVector2D& getAcceleration() const;
    void setAcceleration(const QVector2D& point);
    void virtual reposition();
    void addToVelocity(const QVector2D& point);
    QGraphicsPixmapItem* getSprite();
    ~Entity();
    void backtrack();
    void manageLineCollision(QGraphicsLineItem*);
protected:
    int health = 3;
    QGraphicsPixmapItem* sprite;
    QPointF position;
    QVector2D velocity = QVector2D(0,0);
    QVector2D acceleration = QVector2D(0,0.05);
    const QVector2D defaultAcceleration = QVector2D(0,0.05);
};
