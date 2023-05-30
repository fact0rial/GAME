#include "MainWindow.h"
MainWindow::MainWindow() {
    scene = new QGraphicsScene();
    view = new View(this);
    view->setScene(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    view->setGeometry(0,0,1200, 800);
    setGeometry(0,0,1200,800);
    model = new Model();
    controller = new Controller(model);
    view->setController(controller);
    controller->setView(view);
    //scene->addItem(model->getPLayer()->getSprite());
    //view->ensureVisible(model->getPLayer()->getSprite());
    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(&view->timer, &QTimer::timeout, controller, QOverload<>::of(&Controller::reposition));
    view->timer.start();
    auto loc = new Location1();
    controller->setLocation(loc);
    view->show();
}

MainWindow::~MainWindow() {
    delete model;
    delete controller;
}