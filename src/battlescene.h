#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QtQuick/QQuickView>
#include <QtQuick/QSGTexture>

#include "unit.h"
#include "sceneobjectfactory.h"

class BattleScene : public QQuickView
{
    Q_OBJECT

    // List of interactive objects holded by a scene
    SceneObjectList itemList;
    // Manages the enemy unit creation
    SceneObjectFactory *unitFactory;
    // An array of predefined points appropriate for unit spawn
    static QPointF unitSpawnPoints[];

public:
    BattleScene(QWindow *parent = Q_NULLPTR);
    BattleScene(QQmlEngine *engine, QWindow *parent);
    BattleScene(const QUrl &source, QWindow *parent = Q_NULLPTR);
   ~BattleScene();

protected:
    virtual void timerEvent(QTimerEvent *);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);

private:
    void initScene();
    // Creates a new enemy at a random spawn point
    void spawnEnemy();
    // Creates the initial amount of enemies at their base spawn points
    void createEnemies();
    // Sets a pointer to a player instance; does nothing if the item already exists
    void setPlayer(Unit *p);
    // Creates new enemy at the given coordinate
    Unit *directSpawn(const QPointF &position);
    // Returns a pointer to the player instance. The player object is always the first in item list
    Unit * player() { return dynamic_cast<Unit*>(itemList.first()); }

private slots:
    void onGameOverEvent();

};

#endif // BATTLESCENE_H
