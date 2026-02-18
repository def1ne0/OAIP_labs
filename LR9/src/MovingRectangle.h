//
// Created by define on 18.02.2026.
//

#ifndef LR9_RECTANGLE_H
#define LR9_RECTANGLE_H

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsItem>

class MovingRectangle : public QGraphicsObject {
    Q_OBJECT
    Q_PROPERTY(qreal xPos READ xPos WRITE setXPos)
    Q_PROPERTY(qreal yPos READ yPos WRITE setYPos)

public:
    explicit MovingRectangle(qreal x, qreal y, qreal width, qreal height, QColor color = Qt::green, QGraphicsObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    qreal xPos() const { return pos().x(); };
    qreal yPos() const { return pos().y(); };
    void setXPos(const qreal &x) { setPos(x, pos().y()); }
    void setYPos(const qreal &y) { setPos(pos().x(), y); }

    Q_INVOKABLE void moveRight(const qreal &distance, const int &duration = 1000);
    Q_INVOKABLE void stop();

protected:
    QRectF                   _rectangle;
    QColor                   _rectangle_color;
    QParallelAnimationGroup *_animation_group = nullptr;
};


#endif //LR9_RECTANGLE_H