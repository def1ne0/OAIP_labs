//
// Created by define on 05.03.2026.
//

#include "Circle.h"
#include <QPainter>
#include <QPainterPath>

Circle::Circle(qreal x, qreal y, qreal r, QGraphicsItem* parent)
    : Shape(parent)
    , _radius(r)
{
    setPos(x, y);
}

void Circle::setRadius(qreal r) {
    prepareGeometryChange();
    _radius = r;
    update();
}

QRectF Circle::boundingRect() const {
    return QRectF(-_radius, -_radius, 2 * _radius, 2 * _radius);
}

void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(QBrush(Qt::green));
    painter->drawPath(shape());
}

QPainterPath Circle::shape() const {
    QPainterPath path;
    path.addEllipse(QPointF(0, 0), _radius, _radius);
    return path;
}