//
// Created by define on 18.02.2026.
//

#ifndef LR9_MAINWINDOW_H
#define LR9_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <memory>

#include "MovingRectangle.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupScene();
    void setupUi() const;

    QGraphicsScene                   *_scene = nullptr;
    QGraphicsView                    *_view = nullptr;
    std::unique_ptr<MovingRectangle> _moving_rect;
};


#endif //LR9_MAINWINDOW_H