#ifndef WALLRENDERER_H
#define WALLRENDERER_H

#include <QObject>

class WallRenderer : public QObject
{
    Q_OBJECT
public:
    explicit WallRenderer(QObject *parent = 0);

signals:

public slots:
};

#endif // WALLRENDERER_H