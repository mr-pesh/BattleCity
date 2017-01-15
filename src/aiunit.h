#ifndef AIUNIT_H
#define AIUNIT_H

#include "unit.h"

class AIUnit : public Unit
{
protected:
    AIUnit(QQuickItem *parent = Q_NULLPTR);
    AIUnit(QQuickItemPrivate &dd, QQuickItem *parent = Q_NULLPTR);

public:
    virtual void setX(qreal);
    virtual void setY(qreal);

protected:
    void timerEvent(QTimerEvent *);

private:
    void initAI();
    // Provides the AI rotation
    void rotate();
};

#endif // AIUNIT_H
