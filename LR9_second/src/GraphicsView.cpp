//
// Created by define on 05.03.2026.
//

#include "GraphicsView.h"

#include <QGraphicsItem>

GraphicsView::GraphicsView(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent) {
    setRubberBandSelectionMode(Qt::ContainsItemShape);
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setDragMode(QGraphicsView::NoDrag);
    setInteractive(true);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
}

void GraphicsView::mousePressEvent(QMouseEvent* event) {
    const QPointF scenePos = mapToScene(event->pos());

    if (event->button() == Qt::LeftButton) {
        auto* item = scene()->itemAt(scenePos, QTransform());

        if (item) {
            item->setSelected(true);
            emit itemSelected(item);
        } else {
            scene()->clearSelection();
            emit itemSelected(nullptr);
        }

        emit sceneClicked(scenePos);
    }

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    QGraphicsView::mouseReleaseEvent(event);
}