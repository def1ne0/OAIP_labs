//
// Created by define on 18.02.2026.
//

#include "MovingRectangle.h"
#include <QPainter>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QDebug>

MovingRectangle::MovingRectangle(const qreal &x, const qreal &y, const qreal &width, const qreal &height, QColor color, QGraphicsObject *parent)
    : QGraphicsObject(parent),
      _width(width),
      _height(height),
      _rectangle_color(color),
      _animation_group(new QParallelAnimationGroup(this)) {

    setPos(x, y);
}

QRectF MovingRectangle::boundingRect() const {
    return { 0, 0, _width, _height };
}

void MovingRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(_rectangle_color);
    painter->setPen(Qt::NoPen);
    painter->drawRect(0, 0, static_cast<int>(_width), static_cast<int>(_height));
}

void MovingRectangle::moveRight(const qreal &distance, const int &duration) {
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

void MovingRectangle::stop() {
    _animation_group->stop();
}
