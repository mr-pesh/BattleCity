#include <QGuiApplication>

#include "wall.h"
#include "unit.h"
#include "shell.h"
#include "battlescene.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Unit>("BattleSceneObjects", 1, 0, "Unit");
    qmlRegisterType<Shell>("BattleSceneObjects", 1, 0, "Shell");

    BattleScene view(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    // Resize main window to the size of the view
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
