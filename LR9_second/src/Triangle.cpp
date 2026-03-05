//
// Created by define on 05.03.2026.
//

#include "Triangle.h"

Triangle::Triangle(const QPointF& p1, const QPointF& p2, const QPointF& p3,
                   QGraphicsItem* parent)
    : Polygon({p1, p2, p3}, parent)
{
}

void Triangle::setPoint1(const QPointF& p) {
    prepareGeometryChange();
    _vertices[0] = p;
    updateCenterOfMass();
    update();
}

void Triangle::setPoint2(const QPointF& p) {
    prepareGeometryChange();
    _vertices[1] = p;
    updateCenterOfMass();
    update();
}

void Triangle::setPoint3(const QPointF& p) {
    prepareGeometryChange();
    _vertices[2] = p;
    updateCenterOfMass();
    update();
}