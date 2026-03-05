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
    // explicit MovingRectangle(QGraphicsObject *parent = nullptr);
    explicit MovingRectangle(const qreal &x, const qreal &y, const qreal &width, const qreal &height, QColor color = Qt::green, QGraphicsObject *parent = nullptr);
    [[nodiscard]] QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    [[nodiscard]] qreal xPos() const { return pos().x(); };
    [[nodiscard]] qreal yPos() const { return pos().y(); };
    void setXPos(const qreal &x) { setPos(x, pos().y()); }
    void setYPos(const qreal &y) { setPos(pos().x(), y); }

    Q_INVOKABLE void moveRight(const qreal &distance, const int &duration = 1000);
    Q_INVOKABLE void stop();

protected:
    qreal                    _width;
    qreal                    _height;
    QColor                   _rectangle_color;
    QParallelAnimationGroup  *_animation_group = nullptr;
};


#endif //LR9_RECTANGLE_H