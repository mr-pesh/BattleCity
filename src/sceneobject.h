#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "global.h"
#include <QtQuick/QQuickItem>

enum Direction
{
    North = 0,
    East  = 90,
    South = 180,
    West  = 270
};

class SceneObject;

typedef QList<SceneObject*> SceneObjectList;

/**
 *  The SceneObject class is a base class for each non-static object within a battle scene
 **/
class SceneObject : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(bool moving READ isMoving WRITE setMoveState)
    Q_PROPERTY(int  moveSpeed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(bool alive READ alive WRITE setLiveState NOTIFY liveStateChanged)
    Q_PROPERTY(int  direction READ direction WRITE setDirection NOTIFY directionChanged)

    SceneObject(const SceneObject &) = default;
    SceneObject & operator =(const QQuickItem&) { return *this; }

protected:
    SceneObject(QQuickItem *parent = Q_NULLPTR);
    SceneObject(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    bool alive() const { return is_alive.load(); }
    int  speed() const { return current_speed;   }
    int  direction() const { return current_direction; }

    void setLiveState(bool alive);
    void setSpeed(int newSpeedValue);
    void setDirection(int newDirection);

signals:
    void liveStateChanged(const bool alive);
    void directionChanged (int direction);
    void speedChanged (int speed);

public:
    // Provides collision detection on rectangular items
    virtual QQuickItem *checkCollision(qreal newX, qreal newY);
    // Sets the moving event flag
    void setMoveState(bool isMoving) { is_moving = isMoving; }
    // Checks wether an object is at moving state
    bool isMoving() const { return is_moving.load(); }
    // Performs the move action
    void move();

    /* Override basic setX() and setY() functions
     * to perform the collision handling first */
    virtual void setX(qreal) = 0;
    virtual void setY(qreal) = 0;

    // Performs the killing action
    virtual void kill() = 0;


protected:
    int current_speed;
    int current_direction;

private:
    std::atomic_bool is_alive;
    std::atomic_bool is_moving;
};

#endif // SCENEOBJECT_H
