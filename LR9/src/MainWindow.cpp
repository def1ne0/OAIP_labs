//
// Created by define on 18.02.2026.
//

#include <memory>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _scene(new QGraphicsScene),
      _view(new QGraphicsView),
      _locomotive(std::make_unique<MovingLocomotive>(100, 100)) {

    setupScene();
    setupUi();

    _locomotive->moveRight(400, 5000);
}

void MainWindow::setupScene() {
    _scene->setBackgroundBrush(SCENE_BACKGROUND_COLOR);
    _scene->setSceneRect(0, 0, SCENE_W, SCENE_H);
    _view->setScene(_scene);

    _scene->addItem(_locomotive.get());

    setCentralWidget(_view);
}

void MainWindow::setupUi() const {
    _view->centerOn(500, 300);
}