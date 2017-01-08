#include "projectile.h"

Projectile::Projectile(QQuickItem *parent) : SceneObject(parent) {  }

Projectile::Projectile(QQuickItemPrivate &dd, QQuickItem *parent) : SceneObject(dd, parent) {  }

void Projectile::setParentUnit(Unit *p)
{
    this->unit = p;
}
