#include "battlescene.h"
#include <QTimer>
#include <algorithm>

QPointF BattleScene::unitSpawnPoints[] =
{
   /* Base player spawn points  */
    { 360,120 }, { 360,  20 },
   /* Initial enemy spawn points
    * at each corner of the map */
    { 15,  20 }, { 695,  20 },
    { 15, 700 }, { 695, 700 },
};

BattleScene::BattleScene(QWindow *parent) : QQuickView(parent) { initScene(); }

BattleScene::BattleScene(QQmlEngine *engine, QWindow *parent) : QQuickView(engine, parent),
             unitFactory(new SceneObjectFactory(QUrl(QStringLiteral("qrc:/qml/Enemy.qml")))),
             enemies_to_spawn(ENEMIES_ON_LEVEL),
             running_enemies(0)
{
    initScene();
}

BattleScene::BattleScene(const QUrl &source, QWindow *parent) : QQuickView(source, parent),
             unitFactory(new SceneObjectFactory(QUrl(QStringLiteral("qrc:/qml/Enemy.qml")))),
             enemies_to_spawn(ENEMIES_ON_LEVEL),
             running_enemies(0)
{
    initScene();
}

BattleScene::~BattleScene()
{
    delete unitFactory;
}

/**
 *  Battle scene basic initialization method
 */
inline void BattleScene::initScene()
{        
    // Initializing a unit factory
    unitFactory->setEngine(engine());
    unitFactory->setSceneObjectList(&itemList);
    unitFactory->setItemContext(rootContext());
    // Set the pointer to a player QML item
    setPlayer(rootObject()->findChild<Unit*>("player"));
    // Initialize the status panel with the scene values
    initStatusPanel();
    // Initialize the pseudo-random number generator for choosing enemy spawn points
    qsrand(time(NULL));
    // Set the 'victory' signal handlers
    setVictoryEvent();
    // Spawn initial amount of enemies
    createEnemies();
    // Starting the timer that manages move event handling
    startTimer(FRAME_DURATION);
}

/**
 *  Binds the scene values to the qml status panel
 */
inline void BattleScene::initStatusPanel()
{
    QQuickItem * panel = rootObject()->findChild<QQuickItem*>("statusPanel");

    // Bind the scene variable change to the StatusPanel property
    connect(this, &BattleScene::enemiesToSpawnCountChanged, panel, [=] (int enemiesLeft) {
        panel->setProperty("enemiesLeft", enemiesLeft);
    });

}

/**
 *  Initializes basic player properties and adds its instance to the scene list
 */
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

/**
 *  Sets the signal handlers for the win case
 */
inline void BattleScene::setVictoryEvent()
{
    QQuickItem * screen = rootObject()->findChild<QQuickItem*>("g_o_screen");

    // Set the GameOverScreen to 'Victory' state
    connect(this, &BattleScene::runningEnemiesCountChanged, screen, [=] (int enemiesLeft) {
        if (enemiesLeft == 0) {
            screen->setProperty("text", "Victory");
            screen->setProperty("visible", true);
        }
    });
}

/**
 *  Creates the initial amount of enemies
 */
inline void BattleScene::createEnemies()
{
    // Becase the initial enemy spawn points are the
    // corners of the map we starting from the 3-d point
    std::for_each(&unitSpawnPoints[2], std::end(unitSpawnPoints), [this] (const QPointF &p)
    {
        directSpawn(p);
    });
}

/**
 *  Spawn an enemy randomly at one of the predefined spawn points
 */
inline void BattleScene::spawnEnemy()
{
    // Get a random number in the range of [1; size)
    auto spawnPointIndex = (qrand() % (std::size(unitSpawnPoints) - 1)) + 1;
    directSpawn(unitSpawnPoints[spawnPointIndex]);
}

/**
 *
 * Spawn an enemy at the given point
 *
 * @return A pointer to the created item
 */
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

    auto enemy = unitFactory->create(ENEMY_SPEED, enemyDirection, enemyGeometry, rootObject());

    setRunningEnemiesCount(runningEnemies() + 1);
    setEnemiesToSpawnCount(enemiesToSpawn() - 1);

    return (Unit*)enemy;
}

/**
 *  Removes the given SceneObject item in appropriate way
 */
inline void BattleScene::removeItem(SceneObject *item)
{
    Unit * unit = dynamic_cast<Unit*>(item);

    // Check if item is an enemy unit
    if (unit) {
        setRunningEnemiesCount(runningEnemies() - 1);
        checkRunningEnemies();
    }

    delete item;
}

/**
 *  Checks the enemies count and spawns another one if necessary
 */
inline void BattleScene::checkRunningEnemies()
{
    if (runningEnemies() < MAX_RUNNING_ENEMIES && enemiesToSpawn() > 0)
    {
        QTimer::singleShot(ENEMY_RESPAWN_INTERVAL, [this] () {
            spawnEnemy();
        });
    }
}

void BattleScene::setEnemiesToSpawnCount(int count)
{
    enemies_to_spawn = count;
    emit enemiesToSpawnCountChanged(count);
}

void BattleScene::setRunningEnemiesCount(int count)
{
    running_enemies = count;
    emit runningEnemiesCountChanged(count);
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

/**
 *  Main scene event. Performs all actions on every scene object
 */
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
            removeItem(item);
        }
    }
}
