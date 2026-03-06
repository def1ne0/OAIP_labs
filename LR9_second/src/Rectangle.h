//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_RECTANGLE_H
#define LR9_SECOND_RECTANGLE_H


#include "Polygon.h"

class Rectangle : public Polygon {
    Q_OBJECT
    Q_PROPERTY(qreal width READ width WRITE setWidth)
    Q_PROPERTY(qreal height READ height WRITE setHeight)

public:
    Rectangle(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent = nullptr);

    [[nodiscard]] double area() const override;
    [[nodiscard]] double perimeter() const override;

    [[nodiscard]] qreal width() const { return _width; }
    [[nodiscard]] qreal height() const { return _height; }
    void setWidth(qreal w);
    void setHeight(qreal h);

    void updateCenterOfMass() override;

protected:
    qreal _width, _height;
    void updateVertices();
};

#endif //LR9_SECOND_RECTANGLE_H