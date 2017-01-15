#ifndef UNIT_H
#define UNIT_H

#include "sceneobjectfactory.h"

class Unit : public SceneObject
{
    Q_OBJECT
    Q_PROPERTY(int lives READ livesLeft WRITE setLivesCount NOTIFY livesCountChanged)

    SceneObjectFactory *shellFactory;

protected:
    Unit(QQuickItem *parent = Q_NULLPTR);
    Unit(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    ~Unit();

    void setLivesCount(int lives);
    int  livesLeft() const { return lives_count; }

    virtual void setX(qreal x);
    virtual void setY(qreal y);

    virtual void kill();


public slots:
    void fire();
    void move();
    void rotate();

signals:
    void livesCountChanged(int value);

private:
    int lives_count;
};

#endif // UNIT_H
