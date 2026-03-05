//
// Created by define on 05.03.2026.
//

#ifndef LR9_SECOND_GRAPHICSVIEW_H
#define LR9_SECOND_GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class GraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    explicit GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);

    signals:
        void sceneClicked(const QPointF& pos);
        void itemSelected(QGraphicsItem* item);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
};


#endif //LR9_SECOND_GRAPHICSVIEW_H