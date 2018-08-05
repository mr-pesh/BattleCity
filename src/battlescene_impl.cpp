#include "battlescene_impl.h"
#include <qqml.h>

BattleScenePrivate::BattleScenePrivate(QQuickItem *parent)
  : QQuickItem(parent)
  , m_configFile(":/qml/Level_1.json")
{
    m_configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    setConfiguration(m_configFile.readAll());
}

void BattleScenePrivate::registerQmlTypes(const char *uri, int majorVersion, int minorVersion)
{
    qmlRegisterType<BattleScenePrivate>(uri, majorVersion, minorVersion, "BattleSceneImpl");
}

void BattleScenePrivate::setConfiguration(const QString& json)
{
    m_configuration = json;
    emit configurationChanged(json);
}

QString BattleScenePrivate::configuration() const
{
    return m_configuration;
}
