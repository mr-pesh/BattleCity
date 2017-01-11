#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QtQuick/QQuickView>
#include <QtQuick/QSGTexture>

#include "unit.h"
#include "sceneobjectfactory.h"

class BattleScene : public QQuickView
{
    // List of interactive objects holded by a scene
    SceneObjectList itemList;
    // Manages the enemy unit creation
    SceneObjectFactory *unitFactory;

public:
    BattleScene(QWindow *parent = Q_NULLPTR);
    BattleScene(QQmlEngine *engine, QWindow *parent);
    BattleScene(const QUrl &source, QWindow *parent = Q_NULLPTR);
   ~BattleScene();

    // Sets a pointer to a player instance; does nothing if the item already exists
    void setPlayer(Unit *p);
    // Returns a pointer to the player instance. The player object is always the first in item list
    Unit * player() { return dynamic_cast<Unit*>(itemList.first()); }

protected:
    virtual void timerEvent(QTimerEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);

private:
    void initScene();
};

#endif // BATTLESCENE_H
