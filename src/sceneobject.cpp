#include "sceneobject.h"

SceneObject::SceneObject(QQuickItem *parent) : QQuickItem(parent),
    is_alive(true),
    is_moving(false)
{  }

SceneObject::SceneObject(QQuickItemPrivate &dd, QQuickItem *parent) : QQuickItem(dd, parent),
    is_alive(true),
    is_moving(false)
{  }

QQuickItem* SceneObject::checkCollision(qreal newX, qreal newY)
{
    qreal x = this->x(), y = this->y(), width = this->width(), height = this->height();

    bool movesHorizontally = (newY - y == 0),
         movesLeft = (newX - x < 0),
           movesUp = (newY - y < 0);

    QPointF collisionPoints[] = {
        {
        /*x1*/ movesHorizontally ? (movesLeft ? (x - 1) : ((x + 1) + width)) : newX,
        /*y1*/ movesHorizontally ? newY : (movesUp ? (y - 1) : ((y + 1) + height))
        },
        {
        /*x2*/ movesHorizontally ? (movesLeft ? newX : (newX + width)) : newX,
        /*y2*/ movesHorizontally ? newY : (movesUp ? newY : (newY + height))
        },
        {
        /*x3*/ movesHorizontally ? (movesLeft ? (x - 1) : ((x + 1) + width)) : (newX + width),
        /*y3*/ movesHorizontally ? (newY + height) : (movesUp ? (y - 1) : ((y + 1) + height))
        },
        {
        /*x4*/ movesHorizontally ? (movesLeft ? newX : (newX + width)) : newX + width,
        /*y4*/ movesHorizontally ? (newY + height) : (movesUp ? newY : (newY + height))
        }
    };

    for (const QPointF &point : collisionPoints)
    {
        QQuickItem * collidingItem = parentItem()->childAt(point.x(), point.y());
        // Check if there is an item at the given point
        if (collidingItem)
            return collidingItem;
    }

    return Q_NULLPTR;
}

void SceneObject::kill()
{
    setLiveState(false);
}

void SceneObject::setLiveState(bool alive)
{
    this->is_alive = alive;
    emit liveStateChanged(alive);
}

void SceneObject::setSpeed(int newSpeedValue)
{
    current_speed = newSpeedValue;
    emit speedChanged(newSpeedValue);
}

void SceneObject::setDirection(int direction)
{
    if (current_direction != direction) {
        current_direction  = direction;
        emit directionChanged(direction);
    }
}

void SceneObject::move()
{
    switch(current_direction) {
    case Direction::North:
        setY(y() - speed());
        break;
    case Direction::South:
        setY(y() + speed());
        break;
    case Direction::East:
        setX(x() + speed());
        break;
    case Direction::West:
        setX(x() - speed());
        break;
    }
}
