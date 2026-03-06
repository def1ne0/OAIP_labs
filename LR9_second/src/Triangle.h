//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_TRIANGLE_H
#define LR9_SECOND_TRIANGLE_H


#include "Polygon.h"

class Triangle : public Polygon {
public:
    Triangle(const QPointF& p1, const QPointF& p2, const QPointF& p3,
             QGraphicsItem* parent = nullptr);

    void setPoint1(const QPointF& p);
    void setPoint2(const QPointF& p);
    void setPoint3(const QPointF& p);

    [[nodiscard]] QPointF point1() const { return _vertices[0]; }
    [[nodiscard]] QPointF point2() const { return _vertices[1]; }
    [[nodiscard]]  QPointF point3() const { return _vertices[2]; }
};


#endif //LR9_SECOND_TRIANGLE_H