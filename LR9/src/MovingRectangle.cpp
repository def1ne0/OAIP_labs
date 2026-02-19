//
// Created by define on 18.02.2026.
//

#include "MovingRectangle.h"
#include <QPainter>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QDebug>

/*
MovingRectangle::MovingRectangle(QGraphicsObject *parent)
    : QGraphicsObject(parent),
      _rectangle(0, 0, 100, 100),
      _rectangle_color(Qt::black),
      _animation_group(new QParallelAnimationGroup(this)) {

    setPos(0, 0);
}
*/

MovingRectangle::MovingRectangle(const qreal &x, const qreal &y, const qreal &width, const qreal &heigth,QColor color, QGraphicsObject *parent)
    : QGraphicsObject(parent),
      _rectangle(x, y, width, heigth),
      _rectangle_color(color),
      _animation_group(new QParallelAnimationGroup(this)) {

    setPos(x, y);
}

QRectF MovingRectangle::boundingRect() const {
    return _rectangle;
}

void MovingRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setBrush(_rectangle_color);
    painter->setPen(QPen(Qt::black, 2));
    painter->drawRect(_rectangle);
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
