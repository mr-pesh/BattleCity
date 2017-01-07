#include "unit.h"

Unit::Unit(QQuickItem *parent) : SceneObject(parent), is_alive(true) {  }

Unit::Unit(QQuickItemPrivate &dd, QQuickItem *parent) : SceneObject(dd, parent), is_alive(true) {  }

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
    current_direction = direction;
    emit directionChanged(direction);
}

void Unit::spawn(const int x, const int y)
{
    if (lives_count >= 0)
        setPosition(QPoint(x,y));
    else
        emit isDead();
}

void Unit::move(const Direction d)
{
    switch(d)
    {
    case Direction::North:
        setY(y() - SPEED_FACTOR);
        setDirection((int)d);
        break;
    case Direction::South:
        setY(y() + SPEED_FACTOR);
        setDirection((int)d);
        break;
    case Direction::East:
        setX(x() + SPEED_FACTOR);
        setDirection((int)d);
        break;
    case Direction::West:
        setX(x() - SPEED_FACTOR);
        setDirection((int)d);
        break;
    }
}

void Unit::fire()
{
}
