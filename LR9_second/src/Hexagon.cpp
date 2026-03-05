//
// Created by define on 05.03.2026.
//

#include "Hexagon.h"
#include <cmath>

Hexagon::Hexagon(qreal x, qreal y, qreal side, QGraphicsItem* parent)
    : Polygon({}, parent)
    , _side(side)
{
    updateVertices();
    setPos(x, y);
}

void Hexagon::setSide(qreal s) {
    prepareGeometryChange();
    _side = s;
    updateVertices();
    update();
}

void Hexagon::updateVertices() {
    _vertices.clear();
    for (int i = 0; i < 6; ++i) {
        qreal angle = i * M_PI / 3 - M_PI / 6;
        qreal x = _side * cos(angle);
        qreal y = _side * sin(angle);
        _vertices.append(QPointF(x, y));
    }
    updateCenterOfMass();
}