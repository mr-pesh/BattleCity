#ifndef WALLRENDERER_H
#define WALLRENDERER_H

#include <QtQuick/QQuickWindow>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>

class WallRenderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit WallRenderer(QObject *parent = Q_NULLPTR);
    ~WallRenderer();

    void setWindow(QQuickWindow *window) { p_window = window; }

signals:

public slots:
    void paint();

private:
    QQuickWindow *p_window;
    QOpenGLShaderProgram *p_shader = nullptr;
};

#endif // WALLRENDERER_H
