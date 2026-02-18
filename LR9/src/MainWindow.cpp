//
// Created by define on 18.02.2026.
//
#include <memory>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _scene(new QGraphicsScene),
      _view(new QGraphicsView),
      _moving_rect(std::make_unique<MovingRectangle>(0, 0, 200, 100)) {

    setupScene();
    setupUi();

    _moving_rect->moveRight(800, 10000);
}

void MainWindow::setupScene() {
    _scene->setSceneRect(0, 0, 2000, 600);
    _view->setScene(_scene);

    _scene->addItem(_moving_rect.get());
    _view->centerOn(_moving_rect.get());

    setCentralWidget(_view);
}

void MainWindow::setupUi() const {
    _view->centerOn(500, 300);
}