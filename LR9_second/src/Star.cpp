//
// Created by define on 05.03.2026.
//

#include "Star.h"
#include <cmath>

Star::Star(int points, qreal outerRadius, qreal innerRadius,
           QGraphicsItem* parent)
    : Polygon({}, parent)
    , _points(points)
    , _outerRadius(outerRadius)
    , _innerRadius(innerRadius)
{
    updateVertices();
}

void Star::updateVertices() {
    _vertices.clear();
    qreal angleStep = M_PI / _points;

    for (int i = 0; i < _points * 2; ++i) {
        qreal radius = (i % 2 == 0) ? _outerRadius : _innerRadius;
        qreal angle = i * angleStep - M_PI / 2;
        qreal x = radius * cos(angle);
        qreal y = radius * sin(angle);
        _vertices.append(QPointF(x, y));
    }

    updateCenterOfMass();
}

FivePointedStar::FivePointedStar(qreal x, qreal y, qreal outerR, qreal innerR,
                                  QGraphicsItem* parent)
    : Star(5, outerR, innerR, parent)
{
    setPos(x, y);
}

SixPointedStar::SixPointedStar(qreal x, qreal y, qreal outerR, qreal innerR,
                                QGraphicsItem* parent)
    : Star(6, outerR, innerR, parent)
{
    setPos(x, y);
}

EightPointedStar::EightPointedStar(qreal x, qreal y, qreal outerR, qreal innerR,
                                    QGraphicsItem* parent)
    : Star(8, outerR, innerR, parent)
{
    setPos(x, y);
}