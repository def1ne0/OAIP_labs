//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_POLYGON_H
#define LR9_SECOND_POLYGON_H

#include "Shape.h"
#include <QVector>
#include <QPainterPath>

class Polygon : public Shape {
public:
    explicit Polygon(const QVector<QPointF>& vertices, QGraphicsItem* parent = nullptr);

    double area() const override;
    double perimeter() const override;
    QPointF centerOfMass() const override;

    void setVertices(const QVector<QPointF>& vertices);
    QVector<QPointF> vertices() const { return _vertices; }

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
               QWidget* widget) override;
    QPainterPath shape() const override;

protected:
    QVector<QPointF> _vertices;
    void updateCenterOfMass() override;

private:
    QPointF calculateCenterByTriangulation() const;
};


#endif //LR9_SECOND_POLYGON_H