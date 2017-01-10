#include "unit.h"
#include "shell.h"

QQmlEngine * SceneObjectFactory::engine = Q_NULLPTR;
QQmlContext * SceneObjectFactory::itemContext = Q_NULLPTR;
QList<SceneObject*> * SceneObjectFactory::sceneObjectList = Q_NULLPTR;

void SceneObjectFactory::setEngine(QQmlEngine *e)
{
    SceneObjectFactory::engine = e;
}

void SceneObjectFactory::setItemContext(QQmlContext *context)
{
    SceneObjectFactory::itemContext = context;
}

void SceneObjectFactory::setSceneObjectList(QList<SceneObject *> *list)
{
    SceneObjectFactory::sceneObjectList = list;
}

UnitFactory::UnitFactory(QList<SceneObject*> *unitList)
{
    if (unitList)
        SceneObjectFactory::sceneObjectList = unitList;
}

ShellFactory::ShellFactory(QList<SceneObject*> *unitList)
{
    if (unitList != Q_NULLPTR && !sceneObjectList)
        SceneObjectFactory::sceneObjectList = unitList;
}

SceneObject * UnitFactory::create(int params)
{
    int lives = 0, direction = DEFAULT_UNIT_DIRECTION;
    bool refersValidObjectList = (sceneObjectList != Q_NULLPTR);

    Unit * factoryObject = (refersValidObjectList ? new Unit : Q_NULLPTR);

    if (params != 0) {
        RETRIEVE_FACTORY_PARAMS(params, lives, direction);
    }
    factoryObject->lives_count = lives;
    factoryObject->current_direction = direction;

    return refersValidObjectList ?
                *(sceneObjectList->insert(sceneObjectList->end(), dynamic_cast<SceneObject*>(factoryObject))) : Q_NULLPTR;
}

SceneObject * ShellFactory::create(int speed, int direction, const QRectF &geometry, QQuickItem *sceneContext)
{
    if (sceneObjectList && engine)
    {
        static QQmlComponent component(engine, QUrl("qrc:/qml/Shell.qml"));
        QQuickItem *factoryObject = qobject_cast<QQuickItem*>(component.create(itemContext));

        factoryObject->setParentItem(sceneContext);
        factoryObject->setProperty("moving", true);
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
