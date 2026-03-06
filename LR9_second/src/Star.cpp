//
// Created by define on 05.03.2026.
//

#include "Star.h"
#include <cmath>

Star::Star(const int points, const qreal outerRadius, const qreal innerRadius,
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
    const qreal angleStep = M_PI / _points;

    for (int i = 0; i < _points * 2; ++i) {
        const qreal radius = (i % 2 == 0) ? _outerRadius : _innerRadius;
        const qreal angle = i * angleStep - M_PI / 2;
        const qreal x = radius * cos(angle);
        const qreal y = radius * sin(angle);
        _vertices.append(QPointF(x, y));
    }

    updateCenterOfMass();
}

FivePointedStar::FivePointedStar(const qreal x, const qreal y, const qreal outerR, const qreal innerR,
                                  QGraphicsItem* parent)
    : Star(5, outerR, innerR, parent)
{
    setPos(x, y);
}

SixPointedStar::SixPointedStar(const qreal x, const qreal y, const qreal outerR, const qreal innerR,
                                  QGraphicsItem* parent)
    : Star(6, outerR, innerR, parent)
{
    setPos(x, y);
}

EightPointedStar::EightPointedStar(const qreal x, const qreal y, const qreal outerR, const qreal innerR,
                                  QGraphicsItem* parent)
    : Star(8, outerR, innerR, parent)
{
    setPos(x, y);
}