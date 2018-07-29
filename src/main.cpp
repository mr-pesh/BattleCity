#include <QGuiApplication>

#include "shell.h"
#include "aiunit.h"
#include "battlescene.h"
#include "directiontype.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Unit>  ("BattleSceneObjects", 1, 0, "Unit");
    qmlRegisterType<Shell> ("BattleSceneObjects", 1, 0, "Shell");
    qmlRegisterType<AIUnit>("BattleSceneObjects", 1, 0, "AIUnit");
    DirectionGadget::registerQmlTypes("BattleSceneObjects", 1, 0);

    BattleScene view(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    // Resize main window to the size of the view
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
