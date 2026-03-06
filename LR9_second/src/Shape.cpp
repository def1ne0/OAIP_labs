//
// Created by define on 05.03.2026.
//

#include "Shape.h"
#include <QTransform>
#include <QPainter>

Shape::Shape(QGraphicsItem* parent)
    : QGraphicsObject(parent)
    , _animationTimer(new QTimer(this))
    , _animGroup(new QParallelAnimationGroup(this))
{
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);
    _animationTimer->setInterval(16);

    connect(_animationTimer, &QTimer::timeout, this, &Shape::transformationTick);
}

void Shape::moveCenterTo(const QPointF& newCenter) {
    const QPointF current = centerOfMass();
    moveBy(newCenter.x() - current.x(), newCenter.y() - current.y());
}

void Shape::moveCenterBy(const QPointF& offset) {
    moveBy(offset.x(), offset.y());
}

void Shape::moveTo(const QPointF& pos, int durationMs) {
    _animGroup->stop();
    _animGroup->clear();

    const auto anim = new QPropertyAnimation(this, "pos");
    anim->setDuration(durationMs);
    anim->setStartValue(QPointF(pos.x(), pos.y()));
    anim->setEndValue(pos);
    anim->setEasingCurve(QEasingCurve::InOutQuad);

    _animGroup->addAnimation(anim);
    _animGroup->start();
    _animationTimer->start();

    connect(_animGroup, &QParallelAnimationGroup::finished,
            _animationTimer, &QTimer::stop, Qt::UniqueConnection);
}

void Shape::rotateBy(double angle, const QPointF& center, int durationMs) {
    _animGroup->stop();
    _animGroup->clear();

    setTransformOriginPoint(center);
    auto anim = new QPropertyAnimation(this, "rotation");
    anim->setDuration(durationMs);
    anim->setStartValue(rotation());
    anim->setEndValue(rotation() + angle);
    anim->setEasingCurve(QEasingCurve::InOutQuad);

    _animGroup->addAnimation(anim);
    _animGroup->start();
    _animationTimer->start();

    connect(_animGroup, &QParallelAnimationGroup::finished,
            _animationTimer, &QTimer::stop, Qt::UniqueConnection);
}

void Shape::scaleBy(double factor, const QPointF& center, int durationMs) {
    _animGroup->stop();
    _animGroup->clear();

    setTransformOriginPoint(center);
    auto anim = new QPropertyAnimation(this, "scaleFactor");
    anim->setDuration(durationMs);
    anim->setStartValue(scaleFactor());
    anim->setEndValue(factor);
    anim->setEasingCurve(QEasingCurve::InOutQuad);

    _animGroup->addAnimation(anim);
    _animGroup->start();
    _animationTimer->start();

    connect(_animGroup, &QParallelAnimationGroup::finished,
            _animationTimer, &QTimer::stop, Qt::UniqueConnection);
}

void Shape::setScaleFactor(qreal factor) {
    QTransform t = transform();
    auto currentScale = transform().m11();
    if (transform().m11() > 0) {
        t.scale(factor / currentScale, factor / currentScale);
        setTransform(t);
    }
}