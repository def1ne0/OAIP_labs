//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_RHOMBUS_H
#define LR9_SECOND_RHOMBUS_H

#include "Polygon.h"

class Rhombus : public Polygon {
    Q_OBJECT
    Q_PROPERTY(qreal side READ side WRITE setSide)
    Q_PROPERTY(qreal acuteAngle READ acuteAngle WRITE setAcuteAngle)

public:
    Rhombus(qreal x, qreal y, qreal side, qreal angleDegrees,
            QGraphicsItem* parent = nullptr);

    qreal side() const { return _side; }
    qreal acuteAngle() const { return _angle; }

    void setSide(qreal s);
    void setAcuteAngle(qreal angle);

protected:
    qreal _side, _angle;
    void updateVertices();
    void updateCenterOfMass() override;
};

#endif //LR9_SECOND_RHOMBUS_H