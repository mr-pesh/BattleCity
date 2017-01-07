#include "battlescene.h"

BattleScene::BattleScene(QWindow *parent) : QQuickView(parent) { initView(); }

BattleScene::BattleScene(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent) { initView(); }

BattleScene::BattleScene(const QUrl &source, QWindow *parent) : QQuickView(source, parent) { initView(); }

BattleScene::~BattleScene()
{
//    for (const auto &texture : textureList)
//        if (texture)
//            delete texture;
}

inline void BattleScene::initView()
{
    // Set the pointer to a player QML item
    setPlayer(rootObject()->findChild<Unit*>("player"));
    // Creating textures is only available after the scene graph has been initialized
    //connect(this, &QQuickWindow::sceneGraphInitialized, this, &BattleScene::loadTextures, Qt::DirectConnection);
}

//void BattleScene::loadTextures()
//{
//    QSGTexture *playerTexture = createTextureFromImage(QImage(QStringLiteral(":/textures/Pz. Kpfw. IV.gif"), "GIF"), TextureCanUseAtlas);

//    textureList << playerTexture;
//}

void BattleScene::keyPressEvent(QKeyEvent *e)
{
    if (e && player()) {
        switch(e->key()) {
        case Qt::Key_Up:
            player()->move(Direction::North);
            break;
        case Qt::Key_Down:
            player()->move(Direction::South);
            break;
        case Qt::Key_Left:
            player()->move(Direction::West);
            break;
        case Qt::Key_Right:
            player()->move(Direction::East);
            break;
        case Qt::Key_Space:
            player()->fire();
        }
    }
    //this->findChildren()
}

void BattleScene::keyReleaseEvent(QKeyEvent *e)
{
    Q_UNUSED(e);
}
