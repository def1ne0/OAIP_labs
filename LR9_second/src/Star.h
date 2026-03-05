//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_STAR_H
#define LR9_SECOND_STAR_H

#include "Polygon.h"

class Star : public Polygon {
public:
    Star(int points, qreal outerRadius, qreal innerRadius,
         QGraphicsItem* parent = nullptr);

    int points() const { return _points; }
    qreal outerRadius() const { return _outerRadius; }
    qreal innerRadius() const { return _innerRadius; }

    void updateVertices();

protected:
    int _points;
    qreal _outerRadius, _innerRadius;
    void updateCenterOfMass() override { _center = QPointF(0, 0); }
};

class FivePointedStar : public Star {
public:
    FivePointedStar(qreal x, qreal y, qreal outerR, qreal innerR,
                    QGraphicsItem* parent = nullptr);
};

class SixPointedStar : public Star {
public:
    SixPointedStar(qreal x, qreal y, qreal outerR, qreal innerR,
                   QGraphicsItem* parent = nullptr);
};

class EightPointedStar : public Star {
public:
    EightPointedStar(qreal x, qreal y, qreal outerR, qreal innerR,
                     QGraphicsItem* parent = nullptr);
};

#endif //LR9_SECOND_STAR_H