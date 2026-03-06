//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_SQUARE_H
#define LR9_SECOND_SQUARE_H

#include "Polygon.h"

class Square : public Polygon {
    Q_OBJECT
    Q_PROPERTY(qreal side READ side WRITE setSide)

public:
    Square(qreal x, qreal y, qreal sideLength, QGraphicsItem* parent = nullptr);

    [[nodiscard]] qreal side() const { return _side; }
    void setSide(qreal s);

protected:
    qreal _side;
    void updateVertices();
    void updateCenterOfMass() override;
};

#endif //LR9_SECOND_SQUARE_H