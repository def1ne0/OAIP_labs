//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_MAINWINDOW_H
#define LR9_SECOND_MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QButtonGroup>
#include "Shape.h"
#include "GraphicsView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void onShapeSelected();
    void onCreateFigure();
    void onDeleteFigure();
    void onMoveFigure();
    void onRotateFigure();
    void onScaleFigure();
    void onSceneClicked(const QPointF& pos);

private:
    void createToolBar();
    void createPropertiesPanel();
    void updatePropertiesPanel();
    Shape* getSelectedShape();

    GraphicsView *_view;
    QGraphicsScene *_scene;
    QToolBar *_toolBar{};

    QDockWidget *_propertiesDock{};
    QWidget *_propertiesWidget{};

    QComboBox *_shapeSelector{};

    QLineEdit *_sizeInput{};
    QLineEdit *_size2Input{};
    QLineEdit *_angleInput{};

    QLineEdit *_moveXInput{};
    QLineEdit *_moveYInput{};
    QLineEdit *_rotateAngleInput{};
    QLineEdit *_scaleFactorInput{};
    QLineEdit *_durationInput{};

    QPushButton *_createButton{};
    QPushButton *_deleteButton{};
    QPushButton *_moveButton{};
    QPushButton *_rotateButton{};
    QPushButton *_scaleButton{};

    QString _currentShapeType;
    Shape *_selectedShape;
    bool _isCreating;

    QVector<Shape*> _shapes;
};


#endif //LR9_SECOND_MAINWINDOW_H