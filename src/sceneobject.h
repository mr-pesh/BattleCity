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
    /* Protect base class from copying */
    SceneObject(const SceneObject &) = default;
    QQuickItem & operator =(const QQuickItem&) { return *this; }

protected:
    SceneObject(QQuickItem *parent = Q_NULLPTR);
    SceneObject(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    // Provides simple collision detection method for rectangular items
    bool collidesWith(QQuickItem *sceneItem);
    // Sets the moving event flag
    void setMoveEvent(bool isMoving) { is_moving = isMoving; }
    // Checks wether an object is at moving state
    bool isMoving() const { return is_moving; }
    // Performs the move action
    virtual void move() = 0;

private:
    bool is_moving = false;
};

#endif // SCENEOBJECT_H
