#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
};

