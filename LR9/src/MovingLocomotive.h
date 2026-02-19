//
// Created by define on 19.02.2026.
//

#ifndef LR9_MOVINGLOCOMOTIVE_H
#define LR9_MOVINGLOCOMOTIVE_H

#include "MovingRectangle.h"

class MovingLocomotive : public MovingRectangle {
    Q_OBJECT
    Q_PROPERTY(qreal xPos READ xPos WRITE setXPos)
    Q_PROPERTY(qreal yPos READ yPos WRITE setYPos)

public:
    explicit MovingLocomotive(const qreal &x, const qreal &y, const qreal &width, const qreal &height, QGraphicsObject *parent);

private:
    std::vector<QGraphicsObject> _circles;
};


#endif //LR9_MOVINGLOCOMOTIVE_H