#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "sceneobject.h"

class Projectile : public SceneObject
{
    Q_OBJECT
    
public:
    Projectile(QQuickItem *parent = Q_NULLPTR);
    Projectile(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

signals:

public slots:
};

#endif // PROJECTILE_H
