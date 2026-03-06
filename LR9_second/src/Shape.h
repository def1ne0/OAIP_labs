//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_SHAPE_H
#define LR9_SECOND_SHAPE_H

#include <QGraphicsObject>
#include <QPointF>
#include <QTimer>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QPainter>

class Shape : public QGraphicsObject {
    Q_OBJECT
    Q_PROPERTY(qreal rotationAngle READ rotationAngle WRITE setRotationAngle)
    Q_PROPERTY(qreal scaleFactor READ scaleFactor WRITE setScaleFactor)

public:
    explicit Shape(QGraphicsItem* parent = nullptr);
    ~Shape() override = default;

    [[nodiscard]] virtual double area() const = 0;
    [[nodiscard]] virtual double perimeter() const = 0;
    [[nodiscard]] virtual QPointF centerOfMass() const = 0;

    void moveCenterTo(const QPointF& newCenter);
    void moveCenterBy(const QPointF& offset);

    void moveTo(const QPointF& pos, int durationMs = 1000);
    void rotateBy(double angle, const QPointF& center, int durationMs = 1000);
    void scaleBy(double factor, const QPointF& center, int durationMs = 1000);

    [[nodiscard]] qreal rotationAngle() const { return rotation(); }
    void setRotationAngle(const qreal angle) { setRotation(angle); }

    [[nodiscard]] qreal scaleFactor() const { return transform().m11(); }
    void setScaleFactor(qreal factor);

    [[nodiscard]] QRectF boundingRect() const override = 0;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
        QWidget* widget) override = 0;
    signals:
        void transformationTick();

protected:
    QTimer* _animationTimer;
    QParallelAnimationGroup* _animGroup;
    QPointF _center;

    virtual void updateCenterOfMass() = 0;
};

#endif //LR9_SECOND_SHAPE_H