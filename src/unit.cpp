#include "unit.h"

Unit::Unit(QQuickItem *parent) : SceneObject(parent)
{
    shellFactory = new SceneObjectFactory(QUrl(QStringLiteral("qrc:/qml/Shell.qml")));
}

Unit::Unit(QQuickItemPrivate &dd, QQuickItem *parent) : SceneObject(dd, parent)
{
    shellFactory = new SceneObjectFactory(QUrl(QStringLiteral("qrc:/qml/Shell.qml")));
}

Unit::~Unit()
{
    delete shellFactory;
}

void Unit::setLivesCount(int lives)
{
    this->lives_count = lives;

    if (lives == 0)
        setLiveState(false);
    else
        emit livesCountChanged(lives);
}

void Unit::setX(qreal x)
{
    //if ( x >= 0 && x < parentItem()->width())
    //{
        if (!checkCollision(x, this->y()))
            QQuickItem::setX(x);
    //}
}

void Unit::setY(qreal y)
{
    //if (y >= 0 && y < parentItem()->height())
    //{
        if (!checkCollision(this->x(), y))
            QQuickItem::setY(y);
    //}
}

void Unit::fire()
{
    int direction = this->direction();

    bool movesHorizontally = (direction == Direction::East || direction == Direction::West),
            movesLeft = (direction == Direction::West),
            movesUp = (direction == Direction::North);

    qreal x = this->x(), y = this->y(), width = this->width(), height = this->height();

    QRectF geometry = {
        movesHorizontally ? (movesLeft ? (x - 1) : (x + width + 1)) : (x + ((width - 4) / 2)),
        movesHorizontally ? (y + ((height - 7) / 2)) : (movesUp ? (y - 1) : (y + height + 1)),
        width / 12,
        height / 5
    };

    shellFactory->create(SHELL_SPEED, direction, geometry, parentItem());
}
