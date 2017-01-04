#ifndef WALL_H
#define WALL_H

#include "wallrenderer.h"
#include <QQuickItem>

class Wall : public QQuickItem
{
    Q_OBJECT

public:
    Wall();

//signals:
//    void gotHit(quint32 x, quint32 y);

//public slots:
//    void sync();
//    void cleanup();

//private slots:
//    void windowChanged(QQuickWindow *window);

//private:
//    WallRenderer *p_renderer = Q_NULLPTR;
};

#endif // WALL_H
