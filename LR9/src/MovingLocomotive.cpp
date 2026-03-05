//
// Created by define on 19.02.2026.
//


#include "MovingWheel.h"
#include "MovingLocomotive.h"

#include <QRandomGenerator64>

#include "MovingRectangle.h"

#include <QTimer>

#include "MainWindow.h"

MovingLocomotive::MovingLocomotive(const qreal &x, const qreal &y, QGraphicsObject *parent)
      : QGraphicsObject(parent),
        _animation_group(new QParallelAnimationGroup(this)) {

    setPos(x, y);
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);

    createBody();
    createWheels();
}

QRectF MovingLocomotive::boundingRect() const {
    return { 0, 0, 200, 100 };
}

void MovingLocomotive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void MovingLocomotive::createBody() {
    const auto front = new MovingRectangle(0, 120, 250, 100, Qt::blue, this);
    const auto back = new MovingRectangle(0, 40, 120, 80, Qt::darkBlue, this);
    const auto top = new MovingRectangle(-10, 20, 140, 40, Qt::darkGreen, this);
    const auto chimney = new MovingRectangle(190, 40, 25, 80, Qt::darkYellow, this);

    _body_parts.append(front);
    _body_parts.append(back);
    _body_parts.append(top);
    _body_parts.append(chimney);
}

void MovingLocomotive::createWheels() {
    for (const auto x : QVector<qreal>{ 40, 200 }) {
        const auto wheel = new MovingWheel(x, 225, 25, Qt::black, this);
        _wheels.append(wheel);
    }
}

void MovingLocomotive::moveRight(const qreal &distance, const int &duration) {
    _animation_group->stop();
    _animation_group->clear();

    auto animation = new QPropertyAnimation(this, "xPos");
    animation->setDuration(duration);
    animation->setStartValue(pos().x());
    animation->setEndValue(pos().x() + distance);
    animation->setEasingCurve(QEasingCurve::Linear);

    _animation_group->addAnimation(animation);

    if (!_smoke_timer) {
        _smoke_timer = new QTimer(this);
        _smoke_timer->setInterval(150);
        connect(_smoke_timer, &QTimer::timeout, this, &MovingLocomotive::emitSmoke);
    }

    _smoke_timer->start();

    _animation_group->start();
}

void MovingLocomotive::stop() {
    _animation_group->stop();
}

QPointF MovingLocomotive::chimneyPos() const {
    return mapToScene(QPointF(185, 35));
}

void MovingLocomotive::emitSmoke() {
    auto particle = new SmokeParticle(chimneyPos(), 6 + QRandomGenerator64::global()->bounded(4));

    connect(particle, &SmokeParticle::animationFinished, this, [this, particle] {
        _active_smoke.removeAll(particle);
    });

    if (scene()) {
        scene()->addItem(particle);
    }

    _active_smoke.append(particle);
    particle->startAnimation(1500 + QRandomGenerator64::global()->bounded(1000));
}

