//
// Created by define on 05.03.2026.
//

#include "MainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <cmath>
#include <QMouseEvent>
#include <QStatusBar>
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Hexagon.h"
#include "Star.h"
#include "Rhombus.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , _view(nullptr)
    , _scene(nullptr)
    , _selectedShape(nullptr)
    , _isCreating(false)
{
    setWindowTitle("Геометрические фигуры");
    resize(1200, 800);

    // Создаём сцену
    _scene = new QGraphicsScene(this);
    _scene->setSceneRect(-500, -500, 2000, 2000);

    // Подключаемся к сигналу изменения выделения
    connect(_scene, &QGraphicsScene::selectionChanged, this, [this]() {
        auto selected = _scene->selectedItems();
        if (!selected.isEmpty()) {
            Shape* shape = qgraphicsitem_cast<Shape*>(selected.first());
            if (shape && shape != _selectedShape) {
                _selectedShape = shape;
                updatePropertiesPanel();
            }
        } else {
            _selectedShape = nullptr;
            updatePropertiesPanel();
        }
    });

    // Создаём view
    _view = new GraphicsView(_scene, this);
    setCentralWidget(_view);

    // Подключаем сигналы
    connect(_view, &GraphicsView::sceneClicked, this, &MainWindow::onSceneClicked);
    connect(_view, &GraphicsView::itemSelected, this, &MainWindow::onFigureSelected);

    // Создаём интерфейс
    createToolBar();
    createPropertiesPanel();

    // Создаём меню
    QMenuBar* menuBar = this->menuBar();
    QMenu* fileMenu = menuBar->addMenu("Файл");
    QAction* clearAction = fileMenu->addAction("Очистить сцену");
    connect(clearAction, &QAction::triggered, [this]() {
        for (auto* shape : _shapes) {
            _scene->removeItem(shape);
            delete shape;
        }
        _shapes.clear();
        _selectedShape = nullptr;
        updatePropertiesPanel();
    });

    QMenu* helpMenu = menuBar->addMenu("Помощь");
    QAction* aboutAction = helpMenu->addAction("О программе");
    connect(aboutAction, &QAction::triggered, [this]() {
        QMessageBox::information(this, "О программе",
            "Редактор геометрических фигур\n"
            "Выберите фигуру, нажмите 'Создать фигуру',\n"
            "кликните на сцене для размещения.\n\n"
            "Кликните по фигуре для выделения и редактирования.\n"
            "Перетаскивайте фигуры мышью.");
    });

    statusBar()->showMessage("Готово. Выберите фигуру и нажмите 'Создать фигуру'");
}

void MainWindow::createToolBar() {
    _toolBar = addToolBar("Инструменты");
    _toolBar->setMovable(false);

    // Выбор фигуры
    _toolBar->addWidget(new QLabel("Фигура: "));
    _shapeSelector = new QComboBox();
    _shapeSelector->addItem("Треугольник", "triangle");
    _shapeSelector->addItem("Прямоугольник", "rectangle");
    _shapeSelector->addItem("Квадрат", "square");
    _shapeSelector->addItem("Ромб", "rhombus");
    _shapeSelector->addItem("Круг", "circle");
    _shapeSelector->addItem("Шестиугольник", "hexagon");
    _shapeSelector->addItem("5-конечная звезда", "star5");
    _shapeSelector->addItem("6-конечная звезда", "star6");
    _shapeSelector->addItem("8-конечная звезда", "star8");
    _toolBar->addWidget(_shapeSelector);

    _toolBar->addSeparator();

    // Параметры создания
    _toolBar->addWidget(new QLabel("Размер 1: "));
    _sizeInput = new QLineEdit("100");
    _sizeInput->setMaximumWidth(60);
    _toolBar->addWidget(_sizeInput);

    _toolBar->addWidget(new QLabel("Размер 2: "));
    _size2Input = new QLineEdit("50");
    _size2Input->setMaximumWidth(60);
    _toolBar->addWidget(_size2Input);

    _toolBar->addWidget(new QLabel("Угол: "));
    _angleInput = new QLineEdit("60");
    _angleInput->setMaximumWidth(60);
    _toolBar->addWidget(_angleInput);

    _toolBar->addSeparator();

    // Кнопка создания
    _createButton = new QPushButton("Создать фигуру");
    _createButton->setStyleSheet("background-color: #4ecdc4; color: white; font-weight: bold; padding: 5px 10px;");
    _toolBar->addWidget(_createButton);
    connect(_createButton, &QPushButton::clicked, this, &MainWindow::onCreateFigure);

    connect(_shapeSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onShapeSelected);

    onShapeSelected();
}

void MainWindow::createPropertiesPanel() {
    _propertiesDock = new QDockWidget("Свойства фигуры", this);
    _propertiesDock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, _propertiesDock);

    _propertiesWidget = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(_propertiesWidget);

    // Информация о фигуре
    QGroupBox* infoGroup = new QGroupBox("Информация");
    QVBoxLayout* infoLayout = new QVBoxLayout(infoGroup);

    QLabel* typeLabel = new QLabel("Тип: -");
    typeLabel->setObjectName("typeLabel");
    infoLayout->addWidget(typeLabel);

    QLabel* areaLabel = new QLabel("Площадь: -");
    areaLabel->setObjectName("areaLabel");
    infoLayout->addWidget(areaLabel);

    QLabel* perimeterLabel = new QLabel("Периметр: -");
    perimeterLabel->setObjectName("perimeterLabel");
    infoLayout->addWidget(perimeterLabel);

    QLabel* centerLabel = new QLabel("Центр масс: -");
    centerLabel->setObjectName("centerLabel");
    infoLayout->addWidget(centerLabel);

    mainLayout->addWidget(infoGroup);

    // Трансформации
    QGroupBox* transformGroup = new QGroupBox("Трансформации");
    QVBoxLayout* transformLayout = new QVBoxLayout(transformGroup);

    // Перемещение
    QHBoxLayout* moveLayout = new QHBoxLayout();
    moveLayout->addWidget(new QLabel("X:"));
    _moveXInput = new QLineEdit("0");
    _moveXInput->setMaximumWidth(60);
    moveLayout->addWidget(_moveXInput);
    moveLayout->addWidget(new QLabel("Y:"));
    _moveYInput = new QLineEdit("0");
    _moveYInput->setMaximumWidth(60);
    moveLayout->addWidget(_moveYInput);
    transformLayout->addLayout(moveLayout);

    _moveButton = new QPushButton("Переместить");
    _moveButton->setEnabled(false);
    transformLayout->addWidget(_moveButton);
    connect(_moveButton, &QPushButton::clicked, this, &MainWindow::onMoveFigure);

    // Вращение
    QHBoxLayout* rotateLayout = new QHBoxLayout();
    rotateLayout->addWidget(new QLabel("Угол:"));
    _rotateAngleInput = new QLineEdit("45");
    _rotateAngleInput->setMaximumWidth(60);
    rotateLayout->addWidget(_rotateAngleInput);
    rotateLayout->addWidget(new QLabel("°"));
    transformLayout->addLayout(rotateLayout);

    _rotateButton = new QPushButton("Повернуть");
    _rotateButton->setEnabled(false);
    transformLayout->addWidget(_rotateButton);
    connect(_rotateButton, &QPushButton::clicked, this, &MainWindow::onRotateFigure);

    // Масштабирование
    QHBoxLayout* scaleLayout = new QHBoxLayout();
    scaleLayout->addWidget(new QLabel("Фактор:"));
    _scaleFactorInput = new QLineEdit("1.5");
    _scaleFactorInput->setMaximumWidth(60);
    scaleLayout->addWidget(_scaleFactorInput);
    transformLayout->addLayout(scaleLayout);

    _scaleButton = new QPushButton("Масштабировать");
    _scaleButton->setEnabled(false);
    transformLayout->addWidget(_scaleButton);
    connect(_scaleButton, &QPushButton::clicked, this, &MainWindow::onScaleFigure);

    // Длительность анимации
    QHBoxLayout* durationLayout = new QHBoxLayout();
    durationLayout->addWidget(new QLabel("Длительность:"));
    _durationInput = new QLineEdit("1000");
    _durationInput->setMaximumWidth(60);
    durationLayout->addWidget(_durationInput);
    durationLayout->addWidget(new QLabel("мс"));
    transformLayout->addLayout(durationLayout);

    mainLayout->addWidget(transformGroup);

    // Удаление
    _deleteButton = new QPushButton("Удалить фигуру");
    _deleteButton->setStyleSheet("background-color: #ff6b6b; color: white; font-weight: bold;");
    _deleteButton->setEnabled(false);
    mainLayout->addWidget(_deleteButton);
    connect(_deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteFigure);

    mainLayout->addStretch();

    _propertiesDock->setWidget(_propertiesWidget);
    updatePropertiesPanel();
}

void MainWindow::onShapeSelected() {
    _currentShapeType = _shapeSelector->currentData().toString();

    // Показываем/скрываем поля в зависимости от фигуры
    bool needsSize2 = (_currentShapeType == "rectangle" || _currentShapeType == "rhombus" ||
                       _currentShapeType.startsWith("star"));
    bool needsAngle = (_currentShapeType == "rhombus");

    _size2Input->setVisible(needsSize2);
    _angleInput->setVisible(needsAngle);

    QLabel* size2Label = findChild<QLabel*>();
    for (QObject* obj : _toolBar->children()) {
        QLabel* label = qobject_cast<QLabel*>(obj);
        if (label && label->text() == "Размер 2: ") {
            label->setVisible(needsSize2);
        }
        if (label && label->text() == "Угол: ") {
            label->setVisible(needsAngle);
        }
    }
}

void MainWindow::onCreateFigure() {
    _isCreating = true;
    _view->setCursor(Qt::CrossCursor);
    statusBar()->showMessage("Кликните на сцене для создания фигуры", 3000);
}

void MainWindow::onSceneClicked(const QPointF& pos) {
    if (!_isCreating) return;

    bool ok1, ok2, ok3;
    qreal size1 = _sizeInput->text().toDouble(&ok1);
    qreal size2 = _size2Input->text().toDouble(&ok2);
    qreal angle = _angleInput->text().toDouble(&ok3);

    if (!ok1) size1 = 100;
    if (!ok2) size2 = 50;
    if (!ok3) angle = 60;

    Shape* shape = nullptr;

    if (_currentShapeType == "triangle") {
        qreal h = size1 * sqrt(3) / 2;
        shape = new Triangle(
            QPointF(-size1/2, h/2),
            QPointF(size1/2, h/2),
            QPointF(0, -h/2)
        );
    }
    else if (_currentShapeType == "rectangle") {
        shape = new Rectangle(0, 0, size1, size2);
    }
    else if (_currentShapeType == "square") {
        shape = new Square(0, 0, size1);
    }
    else if (_currentShapeType == "rhombus") {
        shape = new Rhombus(0, 0, size1, angle);
    }
    else if (_currentShapeType == "circle") {
        shape = new Circle(0, 0, size1);
    }
    else if (_currentShapeType == "hexagon") {
        shape = new Hexagon(0, 0, size1);
    }
    else if (_currentShapeType == "star5") {
        shape = new FivePointedStar(0, 0, size1, size2);
    }
    else if (_currentShapeType == "star6") {
        shape = new SixPointedStar(0, 0, size1, size2);
    }
    else if (_currentShapeType == "star8") {
        shape = new EightPointedStar(0, 0, size1, size2);
    }

    if (shape) {
        shape->setPos(pos);
        shape->setFlag(QGraphicsItem::ItemIsSelectable, true);
        shape->setFlag(QGraphicsItem::ItemIsMovable, true);
        shape->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
        shape->setAcceptHoverEvents(true);

        _scene->addItem(shape);
        _shapes.append(shape);

        // Выделяем только что созданную фигуру
        shape->setSelected(true);
        _selectedShape = shape;

        // Подключаем событие анимации
        connect(shape, &Shape::transformationTick, this, [this, shape]() {
            if (shape == _selectedShape) {
                updatePropertiesPanel();
            }
        });

        statusBar()->showMessage("Фигура создана. Кликните для выбора другой.", 2000);
        updatePropertiesPanel();
    }

    _isCreating = false;
    _view->setCursor(Qt::ArrowCursor);
}

void MainWindow::onFigureSelected() {
    // Основная логика в selectionChanged
}

void MainWindow::updatePropertiesPanel() {
    QLabel* typeLabel = _propertiesWidget->findChild<QLabel*>("typeLabel");
    QLabel* areaLabel = _propertiesWidget->findChild<QLabel*>("areaLabel");
    QLabel* perimeterLabel = _propertiesWidget->findChild<QLabel*>("perimeterLabel");
    QLabel* centerLabel = _propertiesWidget->findChild<QLabel*>("centerLabel");

    if (_selectedShape) {
        typeLabel->setText("Тип: " + QString(_selectedShape->metaObject()->className()));
        areaLabel->setText(QString("Площадь: %1").arg(_selectedShape->area(), 0, 'f', 2));
        perimeterLabel->setText(QString("Периметр: %1").arg(_selectedShape->perimeter(), 0, 'f', 2));
        QPointF center = _selectedShape->mapToScene(_selectedShape->centerOfMass());
        centerLabel->setText(QString("Центр масс: (%1, %2)")
            .arg(center.x(), 0, 'f', 1)
            .arg(center.y(), 0, 'f', 1));

        _deleteButton->setEnabled(true);
        _moveButton->setEnabled(true);
        _rotateButton->setEnabled(true);
        _scaleButton->setEnabled(true);
    } else {
        typeLabel->setText("Тип: -");
        areaLabel->setText("Площадь: -");
        perimeterLabel->setText("Периметр: -");
        centerLabel->setText("Центр масс: -");

        _deleteButton->setEnabled(false);
        _moveButton->setEnabled(false);
        _rotateButton->setEnabled(false);
        _scaleButton->setEnabled(false);
    }
}

Shape* MainWindow::getSelectedShape() {
    if (!_selectedShape) {
        QMessageBox::warning(this, "Ошибка", "Выберите фигуру!");
        return nullptr;
    }
    return _selectedShape;
}

void MainWindow::onDeleteFigure() {
    Shape* shape = getSelectedShape();
    if (!shape) return;

    _shapes.removeAll(shape);
    _scene->removeItem(shape);
    delete shape;
    _selectedShape = nullptr;
    updatePropertiesPanel();
    statusBar()->showMessage("Фигура удалена", 2000);
}

void MainWindow::onMoveFigure() {
    Shape* shape = getSelectedShape();
    if (!shape) return;

    bool okX, okY, okDur;
    qreal dx = _moveXInput->text().toDouble(&okX);
    qreal dy = _moveYInput->text().toDouble(&okY);
    int duration = _durationInput->text().toInt(&okDur);

    if (!okX || !okY || !okDur) {
        QMessageBox::warning(this, "Ошибка", "Некорректные значения!");
        return;
    }

    QPointF newPos = shape->pos() + QPointF(dx, dy);
    shape->moveTo(newPos, duration);
    statusBar()->showMessage("Перемещение...", duration);
}

void MainWindow::onRotateFigure() {
    Shape* shape = getSelectedShape();
    if (!shape) return;

    bool okAngle, okDur;
    qreal angle = _rotateAngleInput->text().toDouble(&okAngle);
    int duration = _durationInput->text().toInt(&okDur);

    if (!okAngle || !okDur) {
        QMessageBox::warning(this, "Ошибка", "Некорректные значения!");
        return;
    }

    QPointF center = shape->mapToScene(shape->centerOfMass());
    shape->rotateBy(angle, center, duration);
    statusBar()->showMessage("Вращение...", duration);
}

void MainWindow::onScaleFigure() {
    Shape* shape = getSelectedShape();
    if (!shape) return;

    bool okFactor, okDur;
    qreal factor = _scaleFactorInput->text().toDouble(&okFactor);
    int duration = _durationInput->text().toInt(&okDur);

    if (!okFactor || !okDur || factor <= 0) {
        QMessageBox::warning(this, "Ошибка", "Некорректные значения!");
        return;
    }

    QPointF center = shape->mapToScene(shape->centerOfMass());
    shape->scaleBy(factor, center, duration);
    statusBar()->showMessage("Масштабирование...", duration);
}

#include "MainWindow.moc"