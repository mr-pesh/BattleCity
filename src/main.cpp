#include <QGuiApplication>

#include "unit.h"
#include "wall.h"
#include "battleview.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Player>("SceneGraphObjects", 1, 0, "Player");
    qmlRegisterType<Enemy>("SceneGraphObjects", 1, 0, "Enemy");
    qmlRegisterType<Wall>("SceneGraphObjects", 1, 0, "Wall");

    BattleView view(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    // Resize main window to the size of the view
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
