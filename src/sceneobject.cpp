#include "sceneobject.h"

SceneObject::SceneObject(QQuickItem *parent) : QQuickItem(parent) {  }

SceneObject::SceneObject(QQuickItemPrivate &dd, QQuickItem *parent) : QQuickItem(dd, parent) {  }

bool SceneObject::collidesWith(QQuickItem *sceneItem)
{
    if (this->x() < sceneItem->x() + sceneItem->width()
            && this->x() + this->width() > sceneItem->x()
            && this->y() + this->height() > sceneItem->y()
            && this->y() < sceneItem->y() + sceneItem->height()) {   // collision detected!
        return true;
    }
    return false;
}
