//
// Created by define on 05.03.2026.
//

#include "Rectangle.h"

Rectangle::Rectangle(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent)
    : Polygon({}, parent)
    , _width(w)
    , _height(h)
{
    updateVertices();
    setPos(x, y);
}

void Rectangle::updateVertices() {
    _vertices = {
        QPointF(0, 0),
        QPointF(_width, 0),
        QPointF(_width, _height),
        QPointF(0, _height)
    };
    updateCenterOfMass();
}

void Rectangle::setWidth(qreal w) {
    prepareGeometryChange();
    _width = w;
    updateVertices();
    update();
}

void Rectangle::setHeight(qreal h) {
    prepareGeometryChange();
    _height = h;
    updateVertices();
    update();
}

double Rectangle::area() const {
    return _width * _height;
}

double Rectangle::perimeter() const {
    return 2 * (_width + _height);
}

void Rectangle::updateCenterOfMass() {
    _center = QPointF(_width / 2, _height / 2);
}