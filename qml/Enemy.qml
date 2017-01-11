import QtQuick 2.0
import BattleSceneObjects 1.0

Unit {
    id: enemy
    lives: 0

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/res/com.badlogic.androidgames.tank1990.png"
        rotation: enemy.direction
    }
}
