#include "shell.h"
#include "unit.h"

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
    SceneObject * dynamicItem = dynamic_cast<SceneObject*>(barrier);
    // Check if item is a SceneObject (so it can be destroyed)
    if (dynamicItem)
    {
        Unit * unit = dynamic_cast<Unit*>(dynamicItem);
        // Check if item is a Unit (so it has the amount of lives)
        if (unit)
            unit->setLivesCount(unit->livesLeft() - 1);
        else
            unit->setLiveState(false);
    }
    setLiveState(false);
}
