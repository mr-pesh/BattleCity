#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "sceneobject.h"

class Shell : public SceneObject
{
    Q_OBJECT
    
    friend class ShellFactory;

protected:
    Shell(QQuickItem *parent = Q_NULLPTR);
    Shell(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

signals:
    void exploded(int x, int y);

public:
    virtual void setX(qreal);
    virtual void setY(qreal);
};

#endif // PROJECTILE_H
