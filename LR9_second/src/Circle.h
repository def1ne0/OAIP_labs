//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_CIRCLE_H
#define LR9_SECOND_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    Q_OBJECT
    Q_PROPERTY(qreal radius READ radius WRITE setRadius)

public:
    Circle(qreal x, qreal y, qreal r, QGraphicsItem* parent = nullptr);

    double area() const override { return M_PI * _radius * _radius; }
    double perimeter() const override { return 2 * M_PI * _radius; }
    QPointF centerOfMass() const override { return QPointF(0, 0); }

    qreal radius() const { return _radius; }
    void setRadius(qreal r);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
               QWidget* widget) override;
    QPainterPath shape() const;

    void updateCenterOfMass() override { _center = QPointF(0, 0); }

protected:
    qreal _radius;
};


#endif //LR9_SECOND_CIRCLE_H