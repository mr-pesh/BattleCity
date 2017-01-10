#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QtQuick/QQuickItem>

#include "global.h"

enum Direction
{
    North = 0,
    East  = 90,
    South = 180,
    West  = 270
};

/**
 *  The SceneObject class is a base class for each non-static object within a battle scene
 **/
class SceneObject : public QQuickItem
{
    SceneObject(const SceneObject &) = default;
    SceneObject & operator =(const QQuickItem&) { return *this; }

protected:
    SceneObject(QQuickItem *parent = Q_NULLPTR);
    SceneObject(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    // Provides collision detection on rectangular items
    QQuickItem *checkCollision(qreal newX, qreal newY);
    // Sets the moving event flag
    void setMoveEvent(bool isMoving) { is_moving = isMoving; }
    // Checks wether an object is at moving state
    bool isMoving() const { return is_moving.load(); }
    // Performs the move action
    virtual void move() = 0;

    void setX(qreal x);
    void setY(qreal y);

private:
    std::atomic<bool> is_moving;
};

#endif // SCENEOBJECT_H
