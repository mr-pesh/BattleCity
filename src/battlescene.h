#pragma once

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
    // An array of predefined points for unit spawn
    static QPointF unitSpawnPoints[];


public:
    BattleScene(QWindow *parent = Q_NULLPTR);
    BattleScene(QQmlEngine *engine, QWindow *parent);
    BattleScene(const QUrl &source, QWindow *parent = Q_NULLPTR);
   ~BattleScene();

signals:
    void enemiesToSpawnCountChanged(int);
    void runningEnemiesCountChanged(int);
    void victory();

protected:
    virtual void timerEvent(QTimerEvent *);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);

private:
    void initScene();
    // Create a new enemy at a random spawn point
    void spawnEnemy();
    // Create the initial amount of enemies at their base spawn points
    void createEnemies();
    // Initialize right status panel with the defined values
    void initStatusPanel();
    // Initialize the MediaPlayer instance
    void setVictoryEvent();
    // Set a pointer to a player instance; does nothing if the item already exists
    void setPlayer(Unit *p);
    // Check the enemies count and spawns another one if necessary
    void checkRunningEnemies();
    // Remove the given SceneObject item in appropriate way
    void removeItem(SceneObject *item);
    // Create new enemy at the given coordinate
    Unit * directSpawn(const QPointF &position);
    // Return a pointer to the player instance. The player object is always the first in item list
    Unit * player() { return dynamic_cast<Unit*>(itemList.first()); }

public:
    int enemiesToSpawn() const { return enemies_to_spawn; }
    int runningEnemies() const { return running_enemies;  }

    void setEnemiesToSpawnCount(int count);
    void setRunningEnemiesCount(int count);

private:
    int enemies_to_spawn;
    int running_enemies;
};
