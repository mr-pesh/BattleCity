#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QtQuick/QQuickView>
#include <QtQuick/QSGTexture>

#include "unit.h"
#include "sceneobjectfactory.h"

class BattleScene : public QQuickView
{
    // Property for accessing the Player class from QML
    //Q_PROPERTY(Unit* player READ player WRITE setPlayer)

    // List of interactive objects holded by a scene
    QList<SceneObject*> itemList;
    // Manages the enemy unit creation
    UnitFactory *unitFactory;

public:
    BattleScene(QWindow *parent = Q_NULLPTR);
    BattleScene(QQmlEngine *engine, QWindow *parent);
    BattleScene(const QUrl &source, QWindow *parent = Q_NULLPTR);
   ~BattleScene();

    /* Getters and setters for 'player' property */
    Unit * player() const { return p_player; }
    void setPlayer(Unit *p) { p_player = p; }

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);

private:
    void initView();

//private slots:
//    void loadTextures();

private:
    Unit *p_player = Q_NULLPTR;
};

#endif // BATTLESCENE_H
