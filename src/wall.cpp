#include "wall.h"

Wall::Wall()
{
    setFlag(ItemHasContents, true);
}

//Wall::Wall()
//{
//    QQuickWindow::connect(this, &QQuickItem::windowChanged, this, &Wall::windowChanged);
//}

//void Wall::sync()
//{
//    if (!p_renderer) {
//        p_renderer = new WallRenderer();
//        connect(QQuickItem::window(), &QQuickWindow::beforeRendering, p_renderer, &WallRenderer::paint, Qt::DirectConnection);
//    }
//    p_renderer->setWindow(QQuickItem::window());
//}

//void Wall::windowChanged(QQuickWindow *window)
//{
//    if (window) {
//        QQuickWindow::connect(window, &QQuickWindow::beforeSynchronizing, this, &Wall::sync, Qt::DirectConnection);
//        QQuickWindow::connect(window, &QQuickWindow::sceneGraphInvalidated, this, &Wall::cleanup, Qt::DirectConnection);
//        // If we allow QML to do the clearing it would clear what we paint
//        // and nothing would show.
//        window->setClearBeforeRendering(false);
//    }
//}

//void Wall::cleanup()
//{
//    if (p_renderer) {
//        delete p_renderer;
//        p_renderer = nullptr;
//    }
//}
