//
// Created by define on 19.02.2026.
//

#ifndef LR9_MOVINGLOCOMOTIVE_H
#define LR9_MOVINGLOCOMOTIVE_H

#include "MovingRectangle.h"
#include "SmokeParticle.h"

class MovingLocomotive : public QGraphicsObject {
    Q_OBJECT
    Q_PROPERTY(qreal xPos READ xPos WRITE setXPos)
    Q_PROPERTY(qreal yPos READ yPos WRITE setYPos)

public:
    explicit MovingLocomotive(const qreal &x, const qreal &y, QGraphicsObject *parent = nullptr);

    [[nodiscard]] QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


    [[nodiscard]] qreal xPos() const { return pos().x(); };
    [[nodiscard]] qreal yPos() const { return pos().y(); };
    void setXPos(const qreal &x) { setPos(x, pos().y()); }
    void setYPos(const qreal &y) { setPos(pos().x(), y); }

    void moveRight(const qreal &distance, const int &duration = 1000);
    void stop();

private:
    void createBody();
    void createWheels();
    void emitSmoke();
    QPointF chimneyPos() const;

    QVector<MovingRectangle*>        _body_parts;
    QVector<QGraphicsItem*>          _wheels;
    QParallelAnimationGroup          *_animation_group;

    QTimer                           *_smoke_timer = nullptr;
    QVector<SmokeParticle*>          _active_smoke;

};


#endif //LR9_MOVINGLOCOMOTIVE_H