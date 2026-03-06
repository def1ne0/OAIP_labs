//
// Created by define on 05.03.2026.
//

#include "Polygon.h"
#include <QPainter>

Polygon::Polygon(const QVector<QPointF>& vertices, QGraphicsItem *parent)
    : Shape(parent),
      _vertices(vertices)
{
    Polygon::updateCenterOfMass();
}

QPointF Polygon::calculateCenterByTriangulation() const {
    if (_vertices.isEmpty()) return {};

    QPointF sum(0, 0);

    for (const auto &p : _vertices) {
        sum += p;
    }

    return sum / static_cast<qreal>(_vertices.size());
}

double Polygon::area() const {
    double a = 0.0;
    const int n = static_cast<int>(_vertices.size());

    for (int i = 0; i < n; ++i) {
        const int j = (i + 1) % n;
        a += _vertices[i].x() * _vertices[j].y();
        a -= _vertices[j].x() * _vertices[i].y();
    }

    return qAbs(a) / 2.0;
}

double Polygon::perimeter() const {
    double p = 0.0;
    const int n = static_cast<int>(_vertices.size());

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        p += QLineF(_vertices[i], _vertices[j]).length();
    }

    return p;
}

QPointF Polygon::centerOfMass() const {
    return _center;
}

void Polygon::updateCenterOfMass() {
    _center = calculateCenterByTriangulation();
}

void Polygon::setVertices(const QVector<QPointF>& vertices) {
    prepareGeometryChange();
    _vertices = vertices;
    updateCenterOfMass();
    update();
}

QRectF Polygon::boundingRect() const {
    if (_vertices.isEmpty()) return {};

    qreal minX = _vertices[0].x(), maxX = _vertices[0].x();
    qreal minY = _vertices[0].y(), maxY = _vertices[0].y();

    for (const auto& p : _vertices) {
        minX = qMin(minX, p.x());
        maxX = qMax(maxX, p.x());
        minY = qMin(minY, p.y());
        maxY = qMax(maxY, p.y());
    }

    return { minX, minY, maxX - minX, maxY - minY };
}

void Polygon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawPath(shape());
}

QPainterPath Polygon::shape() const {
    QPainterPath path;

    if (!_vertices.isEmpty()) {
        path.moveTo(_vertices[0]);
        for (int i = 1; i < _vertices.size(); ++i) {
            path.lineTo(_vertices[i]);
        }
        path.closeSubpath();
    }

    return path;
}