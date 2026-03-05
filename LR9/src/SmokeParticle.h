//
// Created by define on 05.03.2026.
//

#ifndef LR9_SMOKEPARTICLE_H
#define LR9_SMOKEPARTICLE_H

#include <QGraphicsObject>
#include <QParallelAnimationGroup>


class SmokeParticle : public QGraphicsObject {
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)

public:
    explicit SmokeParticle(const QPointF &startPos, qreal radius = 8, QGraphicsObject *parent = nullptr);

    [[nodiscard]] QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    [[nodiscard]] qreal opacity() const { return _opacity; }
    [[nodiscard]] qreal scale() const { return _scale; }
    void setOpacity(qreal o) { _opacity = o; update(); }
    void setScale(qreal s) { _scale = s; update(); }

    void startAnimation(int duration = 1000);

    signals:
        void animationFinished();

private:
    qreal                   _radius;
    qreal                   _opacity = 1.0;
    qreal                   _scale = 1.0;
    QColor                  _color;
    QParallelAnimationGroup *_anim_group;
};


#endif //LR9_SMOKEPARTICLE_H