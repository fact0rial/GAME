#include <QPushButton>
#include <QDialog>
#include <QSlider>
#include <QPropertyAnimation>
#include <QComboBox>
#include "MainWindow.h"
#include <QApplication>
#include <QFontDatabase>

MainWindow::MainWindow() : menuView(new QGraphicsView()), menuScene(new QGraphicsScene()) {
    setWindowState(Qt::WindowFullScreen);
    createMenu();
}

MainWindow::~MainWindow() {
    delete model;
    delete controller;
}

void MainWindow::createMenu() {
    menuView->setWindowState(Qt::WindowFullScreen);
    menuView->setScene(menuScene);
    menuScene->setSceneRect(0, 0, menuView->rect().x(), menuView->rect().y());

    menuView->setStyleSheet("QGraphicsView { border-image: url(:/sources/menuBackground.png);}");

    //QPixmap *backgroundImage = new QPixmap(":sources/menuBackground.png");

    //QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(*backgroundImage);
    //menuScene->addItem(backgroundItem);

    menuView->setWindowTitle("Меню");
    menuView->setRenderHint(QPainter::Antialiasing);

    menuView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    menuView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QString buttonStyle = "QPushButton {"
                          "    background-color: rgba(255, 255, 255, 100);"
                          "    color: white;"
                          "    border-radius: 5px;"
                          "    border: none;"
                          "    padding: 10px;"
                          "}"
                          "QPushButton:hover {"
                          "    background-color: rgba(255, 255, 255, 150);"
                          "}"
                          "QPushButton:pressed {"
                          "    background-color: rgba(255, 255, 255, 200);"
                          "}";

    QFont buttonFont("Arial", 16, QFont::Bold);

    QPushButton *exitButton = new QPushButton("Выход");
    exitButton->setStyleSheet(buttonStyle);
    exitButton->setFont(buttonFont);
    exitButton->setFixedSize(200, 50);
    exitButton->move(400, 340);
    menuScene->addWidget(exitButton);

    QPushButton *settingsButton = new QPushButton("Настройки");
    settingsButton->setStyleSheet(buttonStyle);
    settingsButton->setFont(buttonFont);
    settingsButton->setFixedSize(200, 50);
    settingsButton->move(400, 270);
    menuScene->addWidget(settingsButton);

    QPushButton *startButton = new QPushButton("Начать игру");
    startButton->setStyleSheet(buttonStyle);
    startButton->setFont(buttonFont);
    startButton->setFixedSize(200, 50);
    startButton->move(400, 200);
    menuScene->addWidget(startButton);

    QObject::connect(exitButton, &QPushButton::clicked, [&]() {
        QApplication::quit();
    });

    settingsDialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout(settingsDialog);
    settingsDialog->setWindowTitle("Настройки");

    QComboBox* languageComboBox = new QComboBox();
    languageComboBox->addItem("Русский");
    languageComboBox->addItem("English");
    layout->addWidget(languageComboBox);

    QSlider *volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    layout->addWidget(volumeSlider);

    QObject::connect(settingsButton, &QPushButton::clicked, [&]() {
        settingsDialog->exec();
    });

    QObject::connect(startButton, &QPushButton::clicked, [&]() {
        setStyleSheet("background-color: black;");
        scene = new QGraphicsScene();
        view = new View(this);
        view->setScene(scene);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        view->setGeometry(500, 400, 1600, 900);
        model = new Model();
        controller = new Controller(model);
        view->setController(controller);
        controller->setView(view);
        view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        connect(&view->timer, &QTimer::timeout, controller, QOverload<>::of(&Controller::reposition));
        view->timer.start();
        auto loc = new Location1();
        controller->setLocation(loc);
        view->show();
        //view->setAlignment(Qt::AlignCenter);
        menuView->setVisible(false);
        //setCentralWidget(view);
    });

    QGraphicsTextItem *copyright = new QGraphicsTextItem();
    QFont copyrightFont("Arial", 16, QFont::Bold);
    copyright->setFont(copyrightFont);
    copyright->setPlainText("Copyright by Pavel Bernyak");
    int textWidth = copyright->boundingRect().width();
    int textHeight = copyright->boundingRect().height();
    int textX = menuScene->width() - textWidth - 10;
    int textY = menuScene->height() - textHeight - 10;
    copyright->setPos(textX, textY);
    menuScene->addItem(copyright);

    QGraphicsTextItem *gameTitle = new QGraphicsTextItem("ARENA");
    QFont titleFont("Arial", 32, QFont::Bold);
    gameTitle->setFont(titleFont);
    gameTitle->setDefaultTextColor(Qt::white);
    int titleX = (menuScene->width() - gameTitle->boundingRect().width()) / 2;
    int titleY = 50;
    gameTitle->setPos(titleX, titleY);
    menuScene->addItem(gameTitle);

//    QPropertyAnimation *titleAnimation = new QPropertyAnimation(gameTitle, "scale");
//    titleAnimation->setStartValue(1.0);
//    titleAnimation->setEndValue(1.2);
//    titleAnimation->setDuration(1000);
//    titleAnimation->setLoopCount(-1);
//    titleAnimation->setDirection(QAbstractAnimation::Forward);
//    titleAnimation->start();

    setCentralWidget(menuView);
}

void MainWindow::gameLoss() {
    QApplication::quit();
}