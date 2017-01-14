#include "battlescene.h"

BattleScene::BattleScene(QWindow *parent) : QQuickView(parent) { initScene(); }

BattleScene::BattleScene(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent),
             unitFactory(new SceneObjectFactory(QUrl(QStringLiteral("qrc:/qml/Enemy.qml"))))
{
    initScene();
}

BattleScene::BattleScene(const QUrl &source, QWindow *parent) : QQuickView(source, parent),
             unitFactory(new SceneObjectFactory(QUrl(QStringLiteral("qrc:/qml/Enemy.qml"))))
{
    initScene();
}

BattleScene::~BattleScene()
{
    delete unitFactory;
}

inline void BattleScene::initScene()
{
    // Initializing a unit factory
    unitFactory->setEngine(engine());
    unitFactory->setItemContext(rootContext());
    unitFactory->setSceneObjectList(&itemList);
    // Set the pointer to a player QML item
    setPlayer(rootObject()->findChild<Unit*>("player"));
    // Spawn start amount of enemies
    createEnemies();
    // Starting the timer that manages move event handling
    startTimer(FRAME_DURATION);
}

inline void BattleScene::createEnemies()
{
    spawnEnemy(15, 20);
    spawnEnemy(15, 700);
    spawnEnemy(695, 700);
    spawnEnemy(695, 20);
}

void BattleScene::spawnEnemy(qreal x, qreal y)
{
    static Unit *player = this->player();

    QRectF enemyGeometry = {
        x,
        y,
        (player->width() / 4.0) + player->width(),
        (player->height() / 4.0) + player->height(),
    };
    Direction enemyDirection = (y > (this->height() / 2)) ? Direction::North : Direction::South;

    unitFactory->create(ENEMY_SPEED, enemyDirection, enemyGeometry, rootObject());
}

void BattleScene::setPlayer(Unit *p)
{
    // The player item can be set only once
    if (itemList.isEmpty())
         itemList.append(dynamic_cast<SceneObject*>(p));
}

void BattleScene::keyPressEvent(QKeyEvent *e)
{
    static Unit *player = this->player();

    if (e && player) {
        switch(e->key()) {
        case Qt::Key_Up:
            player->setDirection(Direction::North);
            player->setMoveEvent(true);
            break;
        case Qt::Key_Down:
            player->setDirection(Direction::South);
            player->setMoveEvent(true);
            break;
        case Qt::Key_Left:
            player->setDirection(Direction::West);
            player->setMoveEvent(true);
            break;
        case Qt::Key_Right:
            player->setDirection(Direction::East);
            player->setMoveEvent(true);
            break;
        case Qt::Key_Space:
            player->fire();
        }
    }
}

void BattleScene::keyReleaseEvent(QKeyEvent *e)
{
    static Unit * player = this->player();

    if (e && player) {
        switch(e->key()) {
        case Qt::Key_Up:
            if (player->direction() == Direction::North)
                player->setMoveEvent(false);
            break;
        case Qt::Key_Down:
            if (player->direction() == Direction::South)
                player->setMoveEvent(false);
            break;
        case Qt::Key_Left:
            if (player->direction() == Direction::West)
                player->setMoveEvent(false);
            break;
        case Qt::Key_Right:
            if (player->direction() == Direction::East)
                player->setMoveEvent(false);
            break;
        }
    }
}

void BattleScene::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    for (auto it = itemList.crbegin(); it != itemList.crend(); ++it)
    {
        SceneObject *item = *it;

        if (item->alive()) {
            if (item->isMoving())
                item->move();
        } else {
            itemList.removeOne(item);
            delete item;
        }
    }
}
