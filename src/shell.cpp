#include "shell.h"

Shell::Shell(QQuickItem *parent) : SceneObject(parent)
{
    connect(this, &Shell::exploded, this, &Shell::onExplodeAction);
}

Shell::Shell(QQuickItemPrivate &dd, QQuickItem *parent) : SceneObject(dd, parent)
{
    connect(this, &Shell::exploded, this, &Shell::onExplodeAction);
}

void Shell::setX(qreal x)
{
    QQuickItem *barrier = checkCollision(x, this->y());

    if (barrier)
        emit exploded(barrier);
    else
        QQuickItem::setX(x);
}

void Shell::setY(qreal y)
{
    QQuickItem *barrier = checkCollision(this->x(), y);

    if (barrier)
        emit exploded(barrier);
    else
        QQuickItem::setY(y);
}

void Shell::onExplodeAction(QQuickItem *barrier)
{
    setLiveState(false);
    SceneObject * dynamicItem = dynamic_cast<SceneObject*>(barrier);
    // Check if item is a SceneObject (so it can be destroyed)
    if (dynamicItem)
        dynamicItem->kill();
}
