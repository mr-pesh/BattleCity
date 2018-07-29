#pragma once

#include "sceneobjectfactory.h"

class Unit : public SceneObject
{
    Q_OBJECT
    Q_PROPERTY(int lives READ livesLeft WRITE setLivesCount NOTIFY livesCountChanged)

    SceneObjectFactory *shellFactory;

protected:
    Unit(QQuickItem *parent = Q_NULLPTR);
    Unit(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    ~Unit();

signals:
    void livesCountChanged(int value);
    void fired();

public slots:
    void fire();

public:
    void setLivesCount(int lives);
    int  livesLeft() const { return lives_count; }
    // setX and setY should be overriden for each subclass of SceneObject to implement
    // the appropriate collision handling
    virtual void setX(qreal x);
    virtual void setY(qreal y);
    // Peform the kill operation on current unit
    virtual void kill();

private:
    int lives_count;
};
