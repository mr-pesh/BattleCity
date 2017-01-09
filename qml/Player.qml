import QtQuick 2.0
import BattleSceneObjects 1.0

Unit {
    id: player
    lives: 3
    direction: 0
    objectName: "player"

    width: 80
    height: 80

    Image {
        id: img
        anchors.fill: parent
        source: "qrc:/textures/battle.png"
        rotation: player.direction
    }
}
