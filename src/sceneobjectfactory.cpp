#include "unit.h"
#include "projectile.h"

QList<SceneObject*> *SceneObjectFactory::sceneObjectList = Q_NULLPTR;

UnitFactory::UnitFactory(QList<SceneObject*> *unitList, QObject *parent)
    : SceneObjectFactory(parent)
{
    if (unitList)
        SceneObjectFactory::sceneObjectList = unitList;
}

ProjectileFactory::ProjectileFactory(QList<SceneObject*> *unitList, QObject *parent)
    : SceneObjectFactory(parent)
{
    if (unitList != Q_NULLPTR && !sceneObjectList)
        SceneObjectFactory::sceneObjectList = unitList;
}

SceneObject * UnitFactory::create(int params)
{
    int lives = 0, direction = DEFAULT_UNIT_DIRECTION;

    Unit * factoryObject = new Unit;

    if (params != 0) {
        RETRIEVE_FACTORY_PARAMS(params, lives, direction);
    }
    factoryObject->lives_count = lives;
    factoryObject->current_direction = direction;

    auto it = sceneObjectList->insert(sceneObjectList->end(), dynamic_cast<SceneObject*>(factoryObject));
    return *it;
}

SceneObject * ProjectileFactory::create(int params)
{
    int speed = MOVE_SPEED + 3, direction = DEFAULT_UNIT_DIRECTION;

    Projectile * factoryObject = new Projectile;

    if (params != 0) {
        RETRIEVE_FACTORY_PARAMS(params, speed, direction);
    }
    factoryObject->speed = speed;
    factoryObject->direction = direction;

    auto it = sceneObjectList->insert(sceneObjectList->end(), dynamic_cast<SceneObject*>(factoryObject));
    return *it;
}
