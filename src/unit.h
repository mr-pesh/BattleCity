#ifndef UNIT_H
#define UNIT_H

#include "sceneobjectfactory.h"

class Unit : public SceneObject
{
    Q_OBJECT

    Q_PROPERTY(bool alive READ isAlive WRITE setAliveState NOTIFY aliveStateChanged)
    Q_PROPERTY(int  lives READ livesLeft WRITE setLivesCount NOTIFY livesCountChanged)

    friend class UnitFactory;

    ShellFactory shellFactory;

protected:
    Unit(QQuickItem *parent = Q_NULLPTR);
    Unit(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    ~Unit();

    bool isAlive()   const { return is_alive; }
    int  livesLeft() const { return lives_count; }

    void setAliveState(const bool alive);
    void setLivesCount(const int  lives);

    virtual void setX(qreal x);
    virtual void setY(qreal y);


public slots:
    void fire ();

signals:
    void aliveStateChanged(const bool alive);
    void livesCountChanged(const int lives);

    void isDead();

private:
    bool is_alive;
    int  lives_count;
};

#endif // UNIT_H
