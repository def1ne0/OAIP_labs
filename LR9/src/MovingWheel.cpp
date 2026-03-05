//
// Created by define on 19.02.2026.
//

#include <QBrush>
#include <QPainter>

#include "MovingWheel.h"

MovingWheel::MovingWheel(
    const qreal &x,
    const qreal &y,
    const qreal &radius,
    const QColor &color,
    QGraphicsObject *parent)
        :   QGraphicsObject(parent),
            _circle_radius(radius),
            _circle_color(color),
            _animation_group(new QParallelAnimationGroup(this)) {
    setPos(x, y);
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);

}

QRectF MovingWheel::boundingRect() const {
    return { -_circle_radius - 2, -_circle_radius - 2, _circle_radius * 2 + 2, _circle_radius * 2 + 2 };
}

void MovingWheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(_circle_color);
    painter->setPen(Qt::NoPen);

    painter->drawEllipse(QPointF(0, 0), _circle_radius, _circle_radius);
}

void MovingWheel::moveRight(const qreal &distance, const int &duration) {
    if (_animation_group->state() == QAbstractAnimation::Running) {
        _animation_group->stop();
    }

    _animation_group->clear();

    const auto animation = new QPropertyAnimation(this, "xPos");
    animation->setDuration(duration);
    animation->setStartValue(pos().x());
    animation->setEndValue(pos().x() + distance);
    animation->setEasingCurve(QEasingCurve::Linear);

    _animation_group->addAnimation(animation);
    _animation_group->start();
}

void MovingWheel::stop() {
    _animation_group->stop();
}
