//
// Created by define on 05.03.2026.
//

#include "Square.h"

Square::Square(qreal x, qreal y, qreal sideLength, QGraphicsItem* parent)
    : Polygon({}, parent)
    , _side(sideLength)
{
    updateVertices();
    setPos(x, y);
}

void Square::setSide(qreal s) {
    prepareGeometryChange();
    _side = s;
    updateVertices();
    update();
}

void Square::updateVertices() {
    _vertices = {
        QPointF(0, 0),
        QPointF(_side, 0),
        QPointF(_side, _side),
        QPointF(0, _side)
    };
    updateCenterOfMass();
}

void Square::updateCenterOfMass() {
    _center = QPointF(_side / 2, _side / 2);
}