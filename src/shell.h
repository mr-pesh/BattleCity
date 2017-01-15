#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "sceneobject.h"

class Shell : public SceneObject
{
    Q_OBJECT

protected:
    Shell(QQuickItem *parent = Q_NULLPTR);
    Shell(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

signals:
    void exploded(QQuickItem *);

private slots:
    void onExplodeAction(QQuickItem *);

public:
    virtual void setX(qreal);
    virtual void setY(qreal);
    virtual void kill();
};

#endif // PROJECTILE_H
