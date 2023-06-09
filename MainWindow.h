#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "Model.h"
#include "View.h"
#include "Controller.h"
#include "Location1.h"
#include <QLayout>

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow();

    ~MainWindow();

    void createMenu();
public slots:
    void gameLoss();
private:
    Controller *controller;
    Model *model;
    QGraphicsScene *scene;
    View *view;

    QGraphicsView *menuView;
    QGraphicsScene *menuScene;
    QDialog *settingsDialog;

};

