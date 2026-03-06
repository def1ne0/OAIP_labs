//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_HEXAGON_H
#define LR9_SECOND_HEXAGON_H

#include "Polygon.h"

class Hexagon : public Polygon {
    Q_OBJECT
    Q_PROPERTY(qreal side READ side WRITE setSide)

public:
    Hexagon(qreal x, qreal y, qreal side, QGraphicsItem* parent = nullptr);

    [[nodiscard]] qreal side() const { return _side; }
    void setSide(qreal s);

    void updateVertices();
    void updateCenterOfMass() override { _center = QPointF(0, 0); }

protected:
    qreal _side;
};

#endif //LR9_SECOND_HEXAGON_H