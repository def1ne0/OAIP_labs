//
// Created by define on 19.02.2026.
//

#include "MovingLocomotive.h"


MovingLocomotive::MovingLocomotive(const qreal &x, const qreal &y, const qreal &width, const qreal &height, QGraphicsObject *parent)
      : MovingRectangle(x, y, width, height, Qt::green, parent),
        _circles(std::vector(4, QGraphicsObject(this))){
}
