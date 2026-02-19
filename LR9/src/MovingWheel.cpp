//
// Created by define on 19.02.2026.
//

#include <QBrush>

#include "MovingWheel.h"

#include <QPainter>

MovingWheel::MovingWheel(
    const qreal &x,
    const qreal &y,
    const qreal &radius,
    const QColor &color,
    QGraphicsObject *parent)
        :   QGraphicsObject(parent),
            _circle(x, y, radius * 2, radius * 2, this),
            _circle_radius(radius),
            _circle_color(color),
            _animation_group(new QParallelAnimationGroup(this)){

    setPos(x, y);
    _circle.setBrush(_circle_color);
    _circle.setPen(QPen(color, 2));
}

QRectF MovingWheel::boundingRect() const {
    return _circle.boundingRect();
}

void MovingWheel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    Q_UNUSED(painter);
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
