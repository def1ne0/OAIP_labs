//
// Created by define on 18.02.2026.
//
#include <memory>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _scene(new QGraphicsScene),
      _view(new QGraphicsView),
      _moving_rect(std::make_unique<MovingRectangle>(100, 100, 200, 100)),
      _moving_wheel(std::make_unique<MovingWheel>(100, 150, 20, Qt::red)) {

    setupScene();
    setupUi();

    _moving_rect->moveRight(1000, 10000);
    _moving_wheel->moveRight(1000, 10000);
}

void MainWindow::setupScene() {
    _scene->setSceneRect(0, 0, 2560, 1600);
    _view->setScene(_scene);

    _scene->addItem(_moving_rect.get());
    _scene->addItem(_moving_wheel.get());

    setCentralWidget(_view);
}

void MainWindow::setupUi() const {
    _view->centerOn(500, 300);
}