import QtQuick 2.7

Image {
    property int number
    property int spawnValue

    width: 20
    height: 20
    source: "qrc:/res/img/com.badlogic.androidgames.tank1990.png"
    visible: number > spawnValue ? false : true
}
