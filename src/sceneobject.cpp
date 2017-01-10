#include "sceneobject.h"

SceneObject::SceneObject(QQuickItem *parent) : QQuickItem(parent), is_moving(false) {  }

SceneObject::SceneObject(QQuickItemPrivate &dd, QQuickItem *parent) : QQuickItem(dd, parent), is_moving(false) {  }

QQuickItem* SceneObject::checkCollision(qreal newX, qreal newY)
{
    qreal x = this->x(), y = this->y(), width = this->width(), height = this->height();

    bool movesHorizontally = (newY - y == 0),
         movesLeft = (newX - x < 0),
           movesUp = (newY - y < 0);

    QPointF collisionPoints[4] = {
        {
        /*x*/ movesHorizontally ? (movesLeft ? (x - 1) : ((x + 1) + width)) : newX,
        /*y*/ movesHorizontally ? newY : (movesUp ? (y - 1) : ((y + 1) + height))
        },
        {
        /*x*/ movesHorizontally ? (movesLeft ? newX : (newX + width)) : newX,
        /*y*/ movesHorizontally ? newY : (movesUp ? newY : (newY + height))
        },
        {
        /*x*/ movesHorizontally ? (movesLeft ? (x - 1) : ((x + 1) + width)) : (newX + width),
        /*y*/ movesHorizontally ? (newY + height) : (movesUp ? (y - 1) : ((y + 1) + height))
        },
        {
        /*x*/ movesHorizontally ? (movesLeft ? newX : (newX + width)) : newX + width,
        /*y*/ movesHorizontally ? (newY + height) : (movesUp ? newY : (newY + height))
        }
    };

    for (const QPointF &point : collisionPoints)
    {
        QQuickItem * collidingItem = parentItem()->childAt(point.x(), point.y());

        if (collidingItem)
            return collidingItem;
    }

    return Q_NULLPTR;
}

void SceneObject::setX(qreal x)
{
    if ( x >= 0 && x < parentItem()->width())
    {
        if (!checkCollision(x, this->y()))
                QQuickItem::setX(x);
    }
}

void SceneObject::setY(qreal y)
{
    if (y >= 0 && y < parentItem()->height())
    {
        if (!checkCollision(this->x(), y))
            QQuickItem::setY(y);
    }
}
