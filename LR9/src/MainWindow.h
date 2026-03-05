//
// Created by define on 18.02.2026.
//

#ifndef LR9_MAINWINDOW_H
#define LR9_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <memory>

#include "MovingLocomotive.h"

const QColor SCENE_BACKGROUND_COLOR = Qt::white;
constexpr qreal SCENE_W = 2560;
constexpr qreal SCENE_H = 1600;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupScene();
    void setupUi() const;

    QGraphicsScene                    *_scene = nullptr;
    QGraphicsView                     *_view = nullptr;
    std::unique_ptr<MovingLocomotive> _locomotive;
};


#endif //LR9_MAINWINDOW_H