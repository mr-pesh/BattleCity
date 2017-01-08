#ifndef WALL_H
#define WALL_H

#include "wallrenderer.h"
#include <QQuickItem>

class Wall : public QQuickItem
{
    Q_OBJECT

public:
    Wall();

public slots:
    void sync();
    void cleanup();

private slots:
    void windowChanged(QQuickWindow *window);

private:
    WallRenderer *p_renderer = Q_NULLPTR;
};

#endif // WALL_H
