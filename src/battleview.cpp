#include "battleview.h"

BattleView::BattleView(QWindow *parent) : QQuickView(parent) { initView(); }

BattleView::BattleView(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent) { initView(); }

BattleView::BattleView(const QUrl &source, QWindow *parent) : QQuickView(source, parent) { initView(); }

BattleView::~BattleView()
{
    for (const auto &texture : textureList)
        if (texture)
            delete texture;
}

inline void BattleView::initView()
{
    // Creating textures is only available after the scene graph has been initialized
    connect(this, &QQuickWindow::sceneGraphInitialized, this, &BattleView::loadTextures, Qt::DirectConnection);
}

void BattleView::loadTextures()
{
    textureList += createTextureFromImage(QImage(QStringLiteral(":/textures/Pz. Kpfw. IV.gif"), "GIF"), TextureCanUseAtlas);
}

void BattleView::keyPressEvent(QKeyEvent *e)
{
    if (e) {
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
        }
    }
}

void BattleView::keyReleaseEvent(QKeyEvent *e)
{
    Q_UNUSED(e);
}
