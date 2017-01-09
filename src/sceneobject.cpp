#include "sceneobject.h"

SceneObject::SceneObject(QQuickItem *parent) : QQuickItem(parent), is_moving(false) {  }

SceneObject::SceneObject(QQuickItemPrivate &dd, QQuickItem *parent) : QQuickItem(dd, parent), is_moving(false) {  }

QQuickItem* SceneObject::checkCollisions(qreal newX, qreal newY)
{
    bool movesHorizontally = (newY - this->y() == 0),
         movesLeft = (newX - this->x() < 0),
           movesUp = (newY - this->y() < 0);

    QPointF collidePoints[4] = {
        {
        /*x*/ movesHorizontally ? (movesLeft ? (this->x() - 1) : ((this->x() + 1) + this->width())) : newX,
        /*y*/ movesHorizontally ? newY : (movesUp ? (this->y() - 1) : ((this->y() + 1) + this->height()))
        },
        {
        /*x*/ movesHorizontally ? (movesLeft ? newX : (newX + this->width())) : newX,
        /*y*/ movesHorizontally ? newY : (movesUp ? newY : (newY + this->height()))
        },
        {
        /*x*/ movesHorizontally ? (movesLeft ? (this->x() - 1) : ((this->x() + 1) + this->width())) : (newX + this->width()),
        /*y*/ movesHorizontally ? (newY + this->height()) : (movesUp ? (this->y() - 1) : ((this->y() + 1) + this->height()))
        },
        {
        /*x*/ movesHorizontally ? (movesLeft ? newX : (newX + this->width())) : newX + this->width(),
        /*y*/ movesHorizontally ? (newY + this->height()) : (movesUp ? newY : (newY + this->height()))
        }
    };

    for (const QPointF &collidePoint : collidePoints)
    {
        QQuickItem * collidingItem = parentItem()->childAt(collidePoint.x(), collidePoint.y());

        if (collidingItem)
            return collidingItem;
    }

    return Q_NULLPTR;
}

void SceneObject::setX(qreal x)
{
    if ( x >= 0 && x < parentItem()->width())
    {
        if (!checkCollisions(x, this->y()))
                QQuickItem::setX(x);
    }
}

void SceneObject::setY(qreal y)
{
    if (y >= 0 && y < parentItem()->height())
    {
        if (!checkCollisions(this->x(), y))
            QQuickItem::setY(y);
    }
}
