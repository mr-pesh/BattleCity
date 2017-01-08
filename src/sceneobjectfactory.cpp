#include "unit.h"
#include "projectile.h"

UnitFactory::UnitFactory(QList<SceneObject*> *unitList, QObject *parent)
    : SceneObjectFactory(parent)
{
    this->sceneObjectList = unitList;
}

ProjectileFactory::ProjectileFactory(QList<SceneObject*> *unitList, QObject *parent)
    : SceneObjectFactory(parent)
{
    this->sceneObjectList = unitList;
}

SceneObject * UnitFactory::create(int params)
{
    int lives = 0, direction = 0;

    Unit * factoryObject = new Unit;

    if (params != 0) {
        UNIT_PARAMS(params, lives, direction);
    }
    factoryObject->lives_count = lives;
    factoryObject->current_direction = direction;

    return dynamic_cast<SceneObject*>(factoryObject);
}

SceneObject * ProjectileFactory::create(int params)
{
    Q_UNUSED(params);
    return dynamic_cast<SceneObject*>(new Projectile);
}
