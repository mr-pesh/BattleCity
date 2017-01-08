#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "sceneobject.h"

class Unit;

class Projectile : public SceneObject
{
    Q_OBJECT
    
    friend class ProjectileFactory;

protected:
    Projectile(QQuickItem *parent = Q_NULLPTR);
    Projectile(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

signals:
    void exploded(int x, int y);

public slots:
    virtual void move() { }

private:
    int speed;
    int direction;
};

#endif // PROJECTILE_H
