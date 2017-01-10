#include "shell.h"

Shell::Shell(QQuickItem *parent) : SceneObject(parent) {  }

Shell::Shell(QQuickItemPrivate &dd, QQuickItem *parent) : SceneObject(dd, parent) {  }

void Shell::setX(qreal x)
{
    if (!checkCollision(x, this->y()))
        QQuickItem::setX(x);
}

void Shell::setY(qreal y)
{
    if (!checkCollision(this->x(), y))
        QQuickItem::setY(y);
}
