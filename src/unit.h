#ifndef UNIT_H
#define UNIT_H

#include "sceneobjectfactory.h"

class Unit : public SceneObject
{
    Q_OBJECT

    Q_PROPERTY(bool alive READ isAlive WRITE setAliveState NOTIFY aliveStateChanged)
    Q_PROPERTY(int  lives READ livesLeft WRITE setLivesCount NOTIFY livesCountChanged)
    Q_PROPERTY(int  direction READ direction WRITE setDirection NOTIFY directionChanged)

    friend class UnitFactory;

    ProjectileFactory *projectileFactory;

protected:
    Unit(QQuickItem *parent = Q_NULLPTR);
    Unit(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    ~Unit();

    bool isAlive()   const { return is_alive; }
    int  livesLeft() const { return lives_count; }
    int  direction() const { return current_direction; }

    void setAliveState(const bool alive);
    void setLivesCount(const int  lives);
    void setDirection (const int  newDirection);


public slots:
    void spawn(const int x, const int y);
    void move () override;
    void fire ();

signals:
    void directionChanged (const int direction);
    void aliveStateChanged(const bool alive);
    void livesCountChanged(const int lives);

    void isDead();

private:
    bool is_alive;
    int  lives_count;
    int  current_direction;
};

#endif // UNIT_H
