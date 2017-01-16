#include "unit.h"
#include "shell.h"

QQmlEngine * SceneObjectFactory::engine = Q_NULLPTR;

QQmlContext * SceneObjectFactory::itemContext = Q_NULLPTR;

SceneObjectList * SceneObjectFactory::sceneObjectList = Q_NULLPTR;

SceneObjectFactory::SceneObjectFactory(const QUrl &qmlDefinition) : qmlInstance(qmlDefinition) {  }

void SceneObjectFactory::setEngine(QQmlEngine *e)
{
    SceneObjectFactory::engine = e;
}

void SceneObjectFactory::setItemContext(QQmlContext *context)
{
    SceneObjectFactory::itemContext = context;
}

void SceneObjectFactory::setSceneObjectList(SceneObjectList *list)
{
    SceneObjectFactory::sceneObjectList = list;
}

/**
 *  Creates a scene object and sets the common properties for it
 */
SceneObject * SceneObjectFactory::create(int speed, int direction, const QRectF &geometry, QQuickItem *sceneContext)
{
    if (sceneObjectList && engine)
    {
        QQmlComponent component(engine, qmlInstance);

        QQuickItem *factoryObject = qobject_cast<QQuickItem*>(component.create(itemContext));

        factoryObject->setParentItem(sceneContext);
        factoryObject->setProperty("x", geometry.x());
        factoryObject->setProperty("y", geometry.y());
        factoryObject->setProperty("moveSpeed", speed);
        factoryObject->setProperty("direction", direction);
        factoryObject->setProperty("width", geometry.width());
        factoryObject->setProperty("height", geometry.height());

        return *(sceneObjectList->insert(sceneObjectList->end(), (SceneObject*)factoryObject));
    }
    return Q_NULLPTR;
}
