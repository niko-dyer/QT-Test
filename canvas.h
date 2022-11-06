#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>

class Canvas : public QGraphicsView
{
public:
    explicit Canvas(QWidget *parent=0);
    bool eventFilter(QObject *watched, QEvent *event);
    bool isPressed;
    void updateCanvas(QPointF eventPoint);
    void setCurrentColor(QColor);

private:
    QGraphicsScene *scene;
    QImage image;
    QPixmap pixMap;
    QColor currentColor;
};

#endif // CANVAS_H
