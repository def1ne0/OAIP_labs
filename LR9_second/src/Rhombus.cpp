//
// Created by define on 05.03.2026.
//

#include "Rhombus.h"
#include <cmath>

Rhombus::Rhombus(qreal x, qreal y, qreal side, qreal angleDegrees,
                 QGraphicsItem* parent)
    : Polygon({}, parent)
    , _side(side)
    , _angle(angleDegrees)
{
    updateVertices();
    setPos(x, y);
}

void Rhombus::setSide(qreal s) {
    prepareGeometryChange();
    _side = s;
    updateVertices();
    update();
}

void Rhombus::setAcuteAngle(qreal angle) {
    prepareGeometryChange();
    _angle = angle;
    updateVertices();
    update();
}

void Rhombus::updateVertices() {
    qreal rad = _angle * M_PI / 180.0;
    qreal h = _side * sin(rad);
    qreal offset = _side * cos(rad);

    _vertices = {
        QPointF(0, 0),
        QPointF(_side, 0),
        QPointF(_side + offset, h),
        QPointF(offset, h)
    };
    updateCenterOfMass();
}

void Rhombus::updateCenterOfMass() {
    _center = QPointF((_vertices[0].x() + _vertices[2].x()) / 2,
                      (_vertices[0].y() + _vertices[2].y()) / 2);
}