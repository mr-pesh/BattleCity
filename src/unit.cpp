#include "unit.h"

Unit::Unit(QQuickItem *parent) : SceneObject(parent), is_alive(true)
{
    projectileFactory = new ProjectileFactory;
}


Unit::Unit(QQuickItemPrivate &dd, QQuickItem *parent) : SceneObject(dd, parent), is_alive(true)
{
    projectileFactory = new ProjectileFactory;
}

Unit::~Unit()
{
    delete projectileFactory;
}

void Unit::setAliveState(const bool alive)
{
    this->is_alive = alive;
    emit aliveStateChanged(alive);
}

void Unit::setLivesCount(const int lives)
{
    this->lives_count = lives;
    emit livesCountChanged(lives);
}

void Unit::setDirection(const int direction)
{
    if (current_direction != direction) {
        current_direction = direction;
        emit directionChanged(direction);
    }
}

void Unit::spawn(const int x, const int y)
{
    if (lives_count >= 0)
        setPosition(QPoint(x,y));
    else
        emit isDead();
}

void Unit::move()
{
    switch(current_direction) {
    case Direction::North:
        setY(y() - MOVE_SPEED);
        break;
    case Direction::South:
        setY(y() + MOVE_SPEED);
        break;
    case Direction::East:
        setX(x() + MOVE_SPEED);
        break;
    case Direction::West:
        setX(x() - MOVE_SPEED);
        break;
    }
}

void Unit::fire()
{
    //auto p = projectileFactory->create();
}
