#include "canvas.h"
#include <QEvent>
#include <QGraphicsScene>
#include <iostream>

Canvas::Canvas(QWidget* parent) : QGraphicsView(parent)
{
    isPressed = false;
    image = QImage(50, 50,  QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::transparent);
    pixMap.convertFromImage(image.scaled(400,400,Qt::KeepAspectRatio));

    scene = new QGraphicsScene(this);
    scene->addPixmap(pixMap);
    setScene(scene);
    currentColor = Qt::red;
    scene->installEventFilter(this);
}

bool Canvas::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == scene){
        QGraphicsSceneMouseEvent *mouseSceneEvent;
        switch(event->type()) {
            case QEvent::GraphicsSceneMousePress :
                mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
                isPressed = true;
                updateCanvas(mouseSceneEvent->scenePos());
                break;
            case QEvent::GraphicsSceneMouseMove :
                mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
                if(isPressed){
                    updateCanvas(mouseSceneEvent->scenePos());
                }
                break;
            case QEvent::GraphicsSceneMouseRelease :
                isPressed = false;
                break;
            default:
                break;
        }
    }
    return QGraphicsView::eventFilter(watched, event);
}

void Canvas::updateCanvas(QPointF eventPoint) {
    image.setPixelColor(eventPoint.x()/8, eventPoint.y()/8, currentColor);
    pixMap.convertFromImage(image.scaled(400,400,Qt::KeepAspectRatio));
    scene->addPixmap(pixMap);
    setScene(scene);
}

void Canvas::setCurrentColor(QColor color) {
    currentColor = color;
}
