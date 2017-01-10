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
    // Engine for instantiating the QML components
    static QQmlEngine *engine;
    //
    static QQmlContext *itemContext;
    // A pointer to a list of all scene object
    static QList<SceneObject*> *sceneObjectList;

protected:
    SceneObjectFactory() = default;
    SceneObjectFactory(const SceneObjectFactory &) = default;

public:
    //virtual SceneObject * create(int params) = 0;
    virtual ~SceneObjectFactory() = default;

public:
    static void setEngine(QQmlEngine *);
    static void setItemContext(QQmlContext *);
    static void setSceneObjectList(QList<SceneObject*> *);
};


class UnitFactory : public SceneObjectFactory
{
public:
    UnitFactory(QList<SceneObject*> *unitList = Q_NULLPTR);

public:
    virtual SceneObject * create(int params = 0);
};


class ShellFactory : public SceneObjectFactory
{
public:
    ShellFactory(QList<SceneObject*> *unitList = Q_NULLPTR);

public:
    virtual SceneObject * create(int speed, int direction, const QRectF &geometry, QQuickItem *sceneContext);
};

#endif // SCENEOBJECTFACTORY_H
