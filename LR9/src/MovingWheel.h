//
// Created by define on 19.02.2026.
//

#ifndef LR9_MOVINGWHEEL_H
#define LR9_MOVINGWHEEL_H


#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsEllipseItem>

class MovingWheel : public QGraphicsObject {
    Q_OBJECT
    Q_PROPERTY(qreal xPos READ xPos WRITE setXPos)
    Q_PROPERTY(qreal yPos READ yPos WRITE setYPos)

public:
    // explicit MovingWheel(QGraphicsObject *parent = nullptr);
    explicit MovingWheel(const qreal &x, const qreal &y, const qreal &radius, const QColor &color = Qt::green, QGraphicsObject *parent = nullptr);

    [[nodiscard]] QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    [[nodiscard]] qreal xPos() const { return pos().x(); };
    [[nodiscard]] qreal yPos() const { return pos().y(); };
    void setXPos(const qreal &x) { setPos(x, pos().y()); }
    void setYPos(const qreal &y) { setPos(pos().x(), y); }

    Q_INVOKABLE void moveRight(const qreal &distance, const int &duration = 1000);
    Q_INVOKABLE void stop();

private:
    QGraphicsEllipseItem             _circle;
    qreal                            _circle_radius;
    QColor                           _circle_color;
    QParallelAnimationGroup          *_animation_group = nullptr;
};


#endif //LR9_MOVINGWHEEL_H