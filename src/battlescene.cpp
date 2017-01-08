#include "battlescene.h"

BattleScene::BattleScene(QWindow *parent) : QQuickView(parent) { initView(); }

BattleScene::BattleScene(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent) { initView(); }

BattleScene::BattleScene(const QUrl &source, QWindow *parent) : QQuickView(source, parent) { initView(); }

BattleScene::~BattleScene()
{
    delete unitFactory;

    for (const auto &item : itemList)
        delete item;
}

inline void BattleScene::initView()
{
    // Initializing a unit factory
    unitFactory = new UnitFactory(&itemList);
    // Set the pointer to a player QML item
    setPlayer(rootObject()->findChild<Unit*>("player"));
    // Starting the timer that manages move event handling
    startTimer(FRAME_DURATION);
}

void BattleScene::setPlayer(Unit *p)
{
     if (itemList.isEmpty())
         itemList.append(dynamic_cast<SceneObject*>(p));
}

void BattleScene::keyPressEvent(QKeyEvent *e)
{
    if (e && player()) {
        switch(e->key()) {
        case Qt::Key_Up:
            player()->setDirection(Direction::North);
            player()->setMoveEvent(true);
            break;
        case Qt::Key_Down:
            player()->setDirection(Direction::South);
            player()->setMoveEvent(true);
            break;
        case Qt::Key_Left:
            player()->setDirection(Direction::West);
            player()->setMoveEvent(true);
            break;
        case Qt::Key_Right:
            player()->setDirection(Direction::East);
            player()->setMoveEvent(true);
            break;
        case Qt::Key_Space:
            player()->fire();
        }
    }
}

void BattleScene::keyReleaseEvent(QKeyEvent *e)
{
    if (e && player()) {
        switch(e->key()) {
        case Qt::Key_Up:
            if (player()->direction() == Direction::North)
                player()->setMoveEvent(false);
            break;
        case Qt::Key_Down:
            if (player()->direction() == Direction::South)
                player()->setMoveEvent(false);
            break;
        case Qt::Key_Left:
            if (player()->direction() == Direction::West)
                player()->setMoveEvent(false);
            break;
        case Qt::Key_Right:
            if (player()->direction() == Direction::East)
                player()->setMoveEvent(false);
            break;
        }
    }
}

void BattleScene::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    for (auto &item : itemList) {
        if (item->isMoving())
            item->move();
    }
}
