#pragma once

#include <QQuickItem>

class BattleScenePrivate : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString configFile READ configuration WRITE setConfiguration NOTIFY configurationChanged)

public:
    explicit BattleScenePrivate(QQuickItem *parent = Q_NULLPTR);

    static void registerQmlTypes(const char *uri, int majorVersion, int minorVersion);

    void setConfiguration(const QString& json);
    QString configuration() const;

signals:
    void configurationChanged(const QString &json);

protected:
    QFile m_configFile;
    QString m_configuration;

private:
    Q_DISABLE_COPY(BattleScenePrivate)
};
