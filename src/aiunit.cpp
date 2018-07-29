#include "aiunit.h"
#include "directiontype.h"

AIUnit::AIUnit(QQuickItem *parent) : Unit(parent) { initAI(); }

AIUnit::AIUnit(QQuickItemPrivate &dd, QQuickItem *parent) : Unit(dd, parent) { initAI(); }


inline void AIUnit::initAI()
{
    startTimer(AI_TICK_INTERVAL);
}

inline void AIUnit::rotate()
{
    int newDirection = 0;
    int rotationClockwise = qrand() % 2;


    if (rotationClockwise) {
        newDirection = this->direction() == DirectionType::West
                ? DirectionType::North
                : this->direction() + 90;
    }
    else {
        newDirection = this->direction() == DirectionType::North
                ? DirectionType::West
                : this->direction() - 90;
    }
    this->setDirection(newDirection);
}

void AIUnit::setX(qreal x)
{
    if (!checkCollision(x, this->y())) {
        QQuickItem::setX(x);
    }
    else {
        // Occasional rotate
        int occasionalRotate = qrand() % 2;
        if (occasionalRotate) {
            this->rotate();
        }
    }
}

void AIUnit::setY(qreal y)
{
    if (!checkCollision(this->x(), y)) {
        QQuickItem::setY(y);
    }
    else {
        // Occasional rotate
        int occasionalRotate = qrand() % 2;
        if (occasionalRotate) {
            this->rotate();
        }
    }
}

void AIUnit::timerEvent(QTimerEvent *)
{
    this->move();
    this->fire();
}
