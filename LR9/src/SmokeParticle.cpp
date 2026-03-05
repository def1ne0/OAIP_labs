//
// Created by define on 05.03.2026.
//

#include "SmokeParticle.h"

#include <QPainter>
#include <QPropertyAnimation>
#include <QRandomGenerator64>

SmokeParticle::SmokeParticle(const QPointF &startPos, qreal radius, QGraphicsObject *parent)
    : QGraphicsObject(parent),
      _radius(radius),
      _color(Qt::gray),
      _anim_group(new QParallelAnimationGroup(this))
{
    setPos(startPos);
    setOpacity(0.8);
    setScale(1);
}

QRectF SmokeParticle::boundingRect() const {
    return { -_radius * 2, -_radius * 2, _radius * 4, _radius * 4 };
}

void SmokeParticle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(_color);
    painter->setPen(Qt::NoPen);

    painter->save();
    painter->scale(_scale, _scale);
    painter->drawEllipse(QPointF(0, 0), _radius, _radius);
    painter->restore();
}

void SmokeParticle::startAnimation(int duration) {
    auto moveAnim = new QPropertyAnimation(this, "pos");
    moveAnim->setDuration(duration);
    moveAnim->setStartValue(pos());
    QPointF endPos(0,
                   pos().y() - 60 - QRandomGenerator::global()->bounded(20));
    moveAnim->setEndValue(endPos);
    moveAnim->setEasingCurve(QEasingCurve::OutQuad);
    
    auto opacityAnim = new QPropertyAnimation(this, "opacity");
    opacityAnim->setDuration(duration);
    opacityAnim->setStartValue(0.8);
    opacityAnim->setEndValue(0.0);
    
    auto scaleAnim = new QPropertyAnimation(this, "scale");
    scaleAnim->setDuration(duration);
    scaleAnim->setStartValue(1.0);
    scaleAnim->setEndValue(2.0);
    
    _anim_group->addAnimation(moveAnim);
    _anim_group->addAnimation(opacityAnim);
    _anim_group->addAnimation(scaleAnim);
    
    connect(_anim_group, &QParallelAnimationGroup::finished, this, [this]() {
        emit animationFinished();
        deleteLater(); 
    });
    
    _anim_group->start();
}
