#ifndef SCENEOBJECTFACTORY_H
#define SCENEOBJECTFACTORY_H

#include "sceneobject.h"


#define RETRIEVE_FACTORY_PARAMS(params, var, direction) \
    var = ((params << ((sizeof(params) * 8) / 2)) >> ((sizeof(params) * 8) / 2)); \
    direction = (params >> ((sizeof(params) * 8) / 2))

#define ASSIGN_FACTORY_PARAMS(params, var, direction) \
    params = var; \
    params |= (direction << ((sizeof(params) * 8) / 2))


class SceneObjectFactory
{
protected:
    // An object to manage the lifecycle of created items
    const QObject *p;
    // A pointer to a list of all scene object
    static QList<SceneObject*> *sceneObjectList;

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
