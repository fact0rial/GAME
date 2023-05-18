#pragma once

#include <QPixmap>
#include <QGraphicsPolygonItem>

class Player {
public:
    Player();
    explicit Player(const QPointF& position);
    int getHealth() const;
    void setHealth(int num);
    int getDamage() const;
    void setDamage(int num);
    const QPointF& getPosition() const;
    void setPosition(const QPointF& point);
    const QPointF& getVelocity() const;
    void setVelocity(const QPointF& point);
    int getMass() const;
    void setMass(int num);
    const QPointF& getAcceleration() const;
    void setAcceleration(const QPointF& point);
    const QRectF& getHitbox() const;
    void setHitbox(const QRectF& point);
    void reposition();
    void addToVelocity(const QPointF& point);
    QGraphicsPixmapItem* getSprite();
private:
    int health = 3;
    int damage = 3;
    QRectF hitbox;
    QGraphicsPixmapItem sprite;
    QPointF position;
    QPointF velocity = QPointF(0,0);
    int mass = 10;
    QPointF acceleration = QPointF(0,0);
};

