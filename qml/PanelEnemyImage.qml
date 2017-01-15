import QtQuick 2.0

Image {
    property int number
    property int spawnValue

    width: 20
    height: 20
    source: "qrc:/res/com.badlogic.androidgames.tank1990.png"
    visible: number > spawnValue ? false : true
}
