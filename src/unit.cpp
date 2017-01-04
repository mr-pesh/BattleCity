#include "unit.h"

Unit::Unit(QQuickItem *parent) : QQuickItem(parent)
{

}

Player::Player(QQuickItem *parent) : Unit(parent)
{

}

Enemy::Enemy(QQuickItem *parent) : Unit(parent)
{

}

void Unit::move(Direction d)
{
    switch(d)
    {
    case Direction::North:
        setY(y() - 0.1);
        break;
    case Direction::South:
        setY(y() + 0.1);
        break;
    case Direction::East:
        setX(x() + 0.1);
        break;
    case Direction::West:
        setX(x() - 0.1);
        break;
    }
}

void Unit::fire(Direction d)
{
    Q_UNUSED(d);
}
