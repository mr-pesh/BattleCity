#ifndef UNIT_H
#define UNIT_H

#include <QtQuick/QQuickItem>

enum class Direction
{
    North,
    South,
    East,
    West
};

class Unit : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(quint8 lives READ livesLeft WRITE setLivesCount NOTIFY livesCountChanged)

protected:
    Unit (QQuickItem *parent = Q_NULLPTR);

public:
    quint8 livesLeft() const { return this->lives; }
    void setLivesCount(const quint8 lives) { this->lives = lives; }

public slots:
    void move(Direction d);
    void fire(Direction d);

signals:
    void livesCountChanged(const quint8 lifes);

private:
    quint8 lives;
};

class Player : public Unit
{

public:
    Player(QQuickItem *parent = Q_NULLPTR);
};

class Enemy : public Unit
{

public:
    Enemy(QQuickItem *parent = Q_NULLPTR);
};

#endif // UNIT_H
