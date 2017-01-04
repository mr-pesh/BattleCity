#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H

#include <QtQuick/QQuickView>
#include <QtQuick/QSGTexture>

#include "unit.h"

class BattleView : public QQuickView
{
    // Property for accessing the Player class from QML
    Q_PROPERTY(Player* player READ player WRITE setPlayer)
    // List of textures loaded after the scene graph initialization
    QVector<QSGTexture*> textureList;

public:
    BattleView(QWindow *parent = Q_NULLPTR);
    BattleView(QQmlEngine *engine, QWindow *parent);
    BattleView(const QUrl &source, QWindow *parent = Q_NULLPTR);
   ~BattleView();

    /* Getters and setters for 'player' property */
    Player * player() const { return p_player; }
    void setPlayer(Player *p) { p_player = p; }

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);

private:
    void initView();

private slots:
    void loadTextures();

private:
    Player *p_player;
};

#endif // BATTLEVIEW_H
