#pragma once
#include <QGraphicsPixmapItem>
#include <string>

class Animation : public QGraphicsPixmapItem {
public:
    virtual void advance();
    ~Animation();
protected:
    int counter = 0;
    void setSprites(std::string path, int len);
    int length;
    std::vector<QPixmap*> sprites;
};

