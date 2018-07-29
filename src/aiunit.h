#pragma once

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
    // Performs the AI rotation
    void rotate();
};
