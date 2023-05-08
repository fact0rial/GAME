
#include "EnemyBlob.h"

EnemyBlob::EnemyBlob(const QPoint& point) {
    sprite = QPixmap(":/sources/enemy.png");
    position = point;
}