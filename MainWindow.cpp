#include "MainWindow.h"
#include "Model.h"
MainWindow::MainWindow() {
    scene = new QGraphicsScene();
    view = new QGraphicsView(this);
    view->setScene(scene);
    scene->setSceneRect(0,0,1000,1000);
    view->setGeometry(0,0,1000, 1600);
    QPixmap map(":/sources/background.png");
    scene->setBackgroundBrush(QBrush(map));
    EnemyBlob George(QPoint(0,0));
    scene->addPixmap(George.getSprite());

    view->show();
}