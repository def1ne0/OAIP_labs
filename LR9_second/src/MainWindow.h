//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_MAINWINDOW_H
#define LR9_SECOND_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QToolBar>
#include <QDockWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include "Shape.h"
#include "GraphicsView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;

private slots:
    void onShapeSelected();
    void onCreateFigure();
    void onDeleteFigure();
    void onMoveFigure();
    void onRotateFigure();
    void onScaleFigure();
    void onFigureSelected();
    void onSceneClicked(const QPointF& pos);

private:
    void createToolBar();
    void createPropertiesPanel();
    void updatePropertiesPanel();
    Shape* getSelectedShape();

    // Инструменты
    GraphicsView* _view;
    QGraphicsScene* _scene;
    QToolBar* _toolBar;

    // Панель свойств
    QDockWidget* _propertiesDock;
    QWidget* _propertiesWidget;

    // Выбор фигуры
    QComboBox* _shapeSelector;

    // Параметры создания
    QLineEdit* _sizeInput;
    QLineEdit* _size2Input;
    QLineEdit* _angleInput;

    // Параметры трансформации
    QLineEdit* _moveXInput;
    QLineEdit* _moveYInput;
    QLineEdit* _rotateAngleInput;
    QLineEdit* _scaleFactorInput;
    QLineEdit* _durationInput;

    // Кнопки
    QPushButton* _createButton;
    QPushButton* _deleteButton;
    QPushButton* _moveButton;
    QPushButton* _rotateButton;
    QPushButton* _scaleButton;

    // Состояние
    QString _currentShapeType;
    Shape* _selectedShape;
    bool _isCreating;

    // Список всех фигур
    QVector<Shape*> _shapes;
};


#endif //LR9_SECOND_MAINWINDOW_H