#ifndef SCENEOBJECTFACTORY_H
#define SCENEOBJECTFACTORY_H

#include "sceneobject.h"

#define UNIT_PARAMS(params, lives, direction) \
    lives = ((params << (sizeof(params) / 2)) >> (sizeof(params) / 2)); \
    direction = (params >> (sizeof(params) / 2))

#define SET_UNIT_PARAMS(params, lives, direction) \
    params = lives; \
    params &= (direction << (sizeof(params) / 2))

class SceneObjectFactory
{
protected:
    // An object to manage the lifecycle of created items
    const QObject *p;
    // A pointer to a list of all scene object
    QList<SceneObject*> *sceneObjectList;

protected:
    explicit SceneObjectFactory(QObject *parent) : p(parent) {  }

public:
    virtual SceneObject * create(int params) = 0;
    virtual ~SceneObjectFactory() = default;
};


class UnitFactory : public SceneObjectFactory
{
public:
    UnitFactory(QList<SceneObject*> *unitList, QObject *parent = Q_NULLPTR);

public:
    virtual SceneObject * create(int params = 0) Q_DECL_OVERRIDE;
};


class ProjectileFactory : public SceneObjectFactory
{
public:
    ProjectileFactory(QList<SceneObject*> *unitList = Q_NULLPTR, QObject *parent = Q_NULLPTR);

public:
    virtual SceneObject * create(int params = 0) Q_DECL_OVERRIDE;
};

#endif // SCENEOBJECTFACTORY_H
