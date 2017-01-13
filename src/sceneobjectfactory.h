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
    // A URL to a QML item definition which will be used for factory object instantiation
    const QUrl qmlInstance;
    // Engine for instantiating the QML components
    static QQmlEngine *engine;
    // Context of creating QML items
    static QQmlContext *itemContext;
    // A pointer to a list of all scene object
    static SceneObjectList *sceneObjectList;

public:
    static void setEngine(QQmlEngine *);
    static void setItemContext(QQmlContext *);
    static void setSceneObjectList(SceneObjectList *);

private:
    SceneObjectFactory(const SceneObjectFactory &) = default;
    SceneObjectFactory & operator =(const SceneObjectFactory &) { return *this; }

public:
    SceneObjectFactory(const QUrl &qmlDefinition);

public:
    SceneObject * create(int speed, int direction, const QRectF &geometry, QQuickItem *sceneContext);
};

#endif // SCENEOBJECTFACTORY_H
