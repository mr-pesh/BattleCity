#include "battlescene.h"
#include <algorithm>

QPointF BattleScene::unitSpawnPoints[] =
{
   /* Base player spawn points  */
    { 360,540 }, { 360,  20 },
   /* Initial enemy spawn points
    * at each corner of the map */
    { 15,  20 }, { 695,  20 },
    { 15, 700 }, { 695, 700 },
};

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
    unitFactory->setSceneObjectList(&itemList);
    unitFactory->setItemContext(rootContext());
    // Set the pointer to a player QML item
    setPlayer(rootObject()->findChild<Unit*>("player"));
    // Initialize the pseudo-random number generator for choosing enemy spawn points
    qsrand(time(NULL));
    // Spawn initial amount of enemies
    createEnemies();
    // Starting the timer that manages move event handling
    startTimer(FRAME_DURATION);
}

inline void BattleScene::setPlayer(Unit *p)
{
    // The player item can be set only once
    if (itemList.isEmpty() && p != Q_NULLPTR)
    {
        p->setSpeed(PLAYER_SPEED);
        // Set the player respawn handler
        connect(p, &Unit::livesCountChanged, this, [=](int lives)
        {
            if (lives > 0) {
                p->setMoveState(false);
                p->setDirection(Direction::South);
                p->setPosition (unitSpawnPoints[0]);
            }
        });
        itemList.append(dynamic_cast<SceneObject*>(p));
    }
}

inline void BattleScene::createEnemies()
{
    // Becase the initial enemy spawn points are the
    // corners of the map we starting from the 3-d point
    std::for_each(&unitSpawnPoints[2], std::end(unitSpawnPoints), [this] (const QPointF &p)
    {
        Unit * enemyUnit = directSpawn(p);
        enemyUnit->setMoveState(true);
        connect(enemyUnit, SIGNAL(timeToFire()), enemyUnit, SLOT(fire()));
        connect(enemyUnit, SIGNAL(timeToMove()), enemyUnit, SLOT(move()));
    });
}

inline void BattleScene::spawnEnemy()
{
    directSpawn(unitSpawnPoints[(qrand() % std::size(unitSpawnPoints))]);
}

Unit* BattleScene::directSpawn(const QPointF &position)
{
    static Unit *player = this->player();

    QRectF enemyGeometry = {
         position.x(),
         position.y(),
        (player->width()  / 4.0) + player->width(),
        (player->height() / 4.0) + player->height(),
    };
    Direction enemyDirection = (position.y() > (this->height() / 2)) ? Direction::North : Direction::South;

    return (Unit*)unitFactory->create(ENEMY_SPEED, enemyDirection, enemyGeometry, rootObject());
}

void BattleScene::keyPressEvent(QKeyEvent *e)
{
    static Unit *player = this->player();

    if (e && player) {
        switch(e->key()) {
        case Qt::Key_Up:
            player->setDirection(Direction::North);
            player->setMoveState(true);
            break;
        case Qt::Key_Down:
            player->setDirection(Direction::South);
            player->setMoveState(true);
            break;
        case Qt::Key_Left:
            player->setDirection(Direction::West);
            player->setMoveState(true);
            break;
        case Qt::Key_Right:
            player->setDirection(Direction::East);
            player->setMoveState(true);
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
                player->setMoveState(false);
            break;
        case Qt::Key_Down:
            if (player->direction() == Direction::South)
                player->setMoveState(false);
            break;
        case Qt::Key_Left:
            if (player->direction() == Direction::West)
                player->setMoveState(false);
            break;
        case Qt::Key_Right:
            if (player->direction() == Direction::East)
                player->setMoveState(false);
            break;
        }
    }
}

void BattleScene::timerEvent(QTimerEvent *)
{
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
